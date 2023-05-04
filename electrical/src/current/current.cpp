#include "current.h"

CurrentSensor::CurrentSensor(int pin) : pin(pin) { }

void CurrentSensor::setup() {
	pinMode(pin, INPUT);
}

float CurrentSensor::getCurrent() {
	return (float) analogRead(pin) * 5.0 / 122;
}
