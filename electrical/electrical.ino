#include "src/utils/BURT_utils.h"
#include "src/electrical.pb.h"

#include "pinouts.h"

#define ELECTRICAL_COMMAND_ID 0x63
#define ELECTRICAL_DATA_ID    0x13

void handleCommand(const uint8_t* data, int length);
BurtCan can(ELECTRICAL_COMMAND_ID, handleCommand);
BurtSerial serial(handleCommand, Device::Device_ELECTRICAL);

void setup() { 
	Serial.begin(9600);
	Serial.println("Initializing...");

	can.setup();

	red.setup();
	yellow.setup();
	green.setup();

	currentSensor.setup();

	Serial.println("Electrical firmware initialized.");
}

void loop() {
	can.update();
	serial.update();

	red.update();
	yellow.update();
	green.update();

	sendData();
}

void sendData() {
	float current = currentSensor.getCurrent();
	ElectricalData data;
	data.battery_current = current;
	can.send(ELECTRICAL_DATA_ID, &data, ElectricalData_fields);
}

void handleCommand(const uint8_t* data, int length) {
	auto command = BurtProto::decode<ElectricalCommand>(data, length, ElectricalCommand_fields);
	switch(command.status) {
		case RoverStatus_DISCONNECTED: break;
		case RoverStatus_IDLE: 
			red.turnOff();
			yellow.turnOn();
			green.turnOff();
			break;
		case RoverStatus_MANUAL: 
		case RoverStatus_AUTONOMOUS:
			red.turnOff();
			yellow.turnOff();
			green.turnOn();
			break;
		case RoverStatus_POWER_OFF: 
			red.turnOn();
			yellow.turnOff();
			green.turnOff();
			break;
	}
}

