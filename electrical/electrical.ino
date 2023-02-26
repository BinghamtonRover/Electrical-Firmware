#include <BURT_utils.h>

#include "src/led_button.h"
#include "src/electrical.pb.h"

#define RED_LED_PIN       1
#define YELLOW_LED_PIN    2
#define GREEN_LED_PIN     3

#define RED_BUTTON_PIN    6
#define YELLOW_BUTTON_PIN 7
#define GREEN_BUTTON_PIN  8

#define ELECTRICAL_COMMAND_ID 0x63
#define ELECTRICAL_DATA_ID    0x13

LedButton red(RED_LED_PIN, RED_BUTTON_PIN);
LedButton yellow(YELLOW_LED_PIN, YELLOW_BUTTON_PIN);
LedButton green(GREEN_LED_PIN, GREEN_BUTTON_PIN);

void handleElectricalCommand(const uint8_t* data, int length) {
	auto command = BurtProto::decode<ElectricalCommand>(data, length, ElectricalCommand_fields);
	if (command.mode == RoverMode::RoverMode_IDLE) {
		red.turnOff();
		yellow.turnOn();
		green.turnOff();
	} else if (command.mode == RoverMode::RoverMode_ACTIVE) {
		red.turnOff();
		yellow.turnOff();
		green.turnOn();		
	}
}

BurtCan can(ELECTRICAL_COMMAND_ID, handleElectricalCommand);

void setup() { 
	Serial.begin(9600);
	Serial.println("Initializing...");

	can.setup();

	red.setup();
	yellow.setup();
	green.setup();

	Serial.println("Electrical firmware initialized.");
}

void loop() {
	can.update();

	red.update();
	yellow.update();
	green.update();

	sendData();
}

void sendData() {
	if (red.state) {
		ElectricalData data;
		data.mode = RoverMode::RoverMode_OFF;
		can.send(ELECTRICAL_DATA_ID, &data, ElectricalData_fields);
	} else if (yellow.state) {
		ElectricalData data;
		data.mode = RoverMode::RoverMode_IDLE;
		can.send(ELECTRICAL_DATA_ID, &data, ElectricalData_fields);
	} else if (green.state) {
		ElectricalData data;
		data.mode = RoverMode::RoverMode_ACTIVE;
		can.send(ELECTRICAL_DATA_ID, &data, ElectricalData_fields);
	}
}
