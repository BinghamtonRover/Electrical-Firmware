CurrentSensor::CurrentSensor(int pin) : pin(pin) { }

void CurrentSensor::setup() {
	pinMode(pin, INPUT);
}

float getCurrent() {
	return (float) analogRead(pin) * 5.0 / 122;
}
