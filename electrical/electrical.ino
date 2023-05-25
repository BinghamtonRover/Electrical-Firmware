#include "src/utils/BURT_utils.h"
#include "src/electrical.pb.h"

#include "pinouts.h"

#define ELECTRICAL_COMMAND_ID 0x63
#define ELECTRICAL_DATA_ID    0x13

#define CAN_SEND_INTERVAL 500

void handleCommand(const uint8_t* data, int length);
BurtCan can(ELECTRICAL_COMMAND_ID, handleCommand);
BurtSerial serial(handleCommand, Device::Device_ELECTRICAL);
unsigned long nextSendTime;

void setup() { 
	Serial.begin(9600);
	Serial.println("Initializing Electrical subsystem");

	Serial.println("Initializing communications...");
	can.setup();
	nextSendTime = millis() + CAN_SEND_INTERVAL;

	Serial.println("Initializing LED buttons...");
	red.setup();
	yellow.setup();
	green.setup();

	Serial.println("Initializing sensors...");
	currentSensor.setup();

	Serial.println("Electrical firmware initialized.");
}

void loop() {
	can.update();
	serial.update();

	Serial.print("Current value: ");
	Serial.print(currentSensor.getCurrent());
	Serial.println(" mA");

	/* DISABLED: The LED buttons are not implemented for the '23 competition
	red.update();
	yellow.update();
	green.update();
	*/

	sendData();
}

void sendData() {
	float current = currentSensor.getCurrent();
	ElectricalData data = ElectricalData_init_zero;
	data.battery_current = current;
	can.send(ELECTRICAL_DATA_ID, &data, ElectricalData_fields);
}

void handleCommand(const uint8_t* data, int length) {
	auto command = BurtProto::decode<ElectricalCommand>(data, length, ElectricalCommand_fields);
  Serial.println(command.status);
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
