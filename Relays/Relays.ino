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
    VoltageSensor.setup();

    Serial.println("Relays subsystem initialized");
}

void loop() {
    serial.update();
    dataTimer.update();
    relays.update();
}

void sendData() {
    serial.send(&relays.data);
}

void handleCommand(const uint8_t* data, int length) {
    auto command = BurtProto::decode<RelaysCommand>(data, length, RelaysCommand_fields);
    relays.handleCommand(command);
}