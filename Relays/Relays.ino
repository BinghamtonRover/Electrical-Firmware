#include "pinouts.h"

#define DATA_SEND_INTERVAL 250  // ms

void handleCommand(const uint8_t* data, int length);
void sendData();

BurtSerial serial(Device::Device_RELAY, handleCommand, RelaysData_fields, RelaysData_size); 
BurtTimer dataTimer(DATA_SEND_INTERVAL, sendData);

void setup() {
    Serial.begin(9600);
    Serial.println("Initializing Relays subsystem");
    Serial.println("Initializing software...");
    serial.setup();
    dataTimer.setup();

    Serial.println("Initializing hardware...");
    relays.setup();

    Serial.println("Relays subsystem initialized");

    // Testing:
    // Flash Error Pin:
    
    // digitalWrite(errorPin, HIGH);
    // delay(1000);
    // digitalWrite(errorPin, LOW);

    // Test Relays:
    delay(1000);
    Serial.println("Activating Right Rear Motor");
    relays.backRightMotor.turnOn();

    delay(1000);
    Serial.println("Activating Left Rear Motor");
    relays.backLeftMotor.turnOn();

    delay(1000);
    Serial.println("Activating Right Front Motor");
    relays.frontRightMotor.turnOn();

    delay(1000);
    Serial.println("Activating Left Front Motor");
    relays.frontLeftMotor.turnOn();

    delay(1000);
    Serial.println("Activating Science");
    relays.science.turnOn();

    delay(1000);
    Serial.println("Activating Drive Control");
    relays.drive.turnOn();

    delay(1000);
    Serial.println("Activating Arm");
    relays.arm.turnOn();

    relays.updateError();
}

void loop() {
    serial.update();
    dataTimer.update();
    // relays.update();
}

void sendData() {
    serial.send(&relays.data);
}

void handleCommand(const uint8_t* data, int length) {
    auto command = BurtProto::decode<RelaysCommand>(data, length, RelaysCommand_fields);
    relays.handleCommand(command);
}