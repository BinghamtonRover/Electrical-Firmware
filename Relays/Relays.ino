#include "pinouts.h"

void setup() {
    Serial.begin(9600);
    Serial.println("Initializing Relays subsystem");
    Serial.println("Initializing software...");
    serial.setup();
    dataTimer.setup();

    Serial.println("Initializing hardware...");
    relays.setup();

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