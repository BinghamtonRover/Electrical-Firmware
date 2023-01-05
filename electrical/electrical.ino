#include <BURT_thermistor.h>

Thermistor thermistor(A0);

void setup() { 
	thermistor.setup();
}

void loop() {
	delay(500);
	float celsius = thermistor.read();
	Serial.print("Temperature in Celsius: ");
	Serial.println(celsius);
}
