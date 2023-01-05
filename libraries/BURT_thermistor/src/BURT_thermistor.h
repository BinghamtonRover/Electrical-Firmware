#ifndef BURT_thermistor_h
#define BURT_thermistor_h

#include <Arduino.h>

class Thermistor {
	private:
		int pin;

	public: 
		Thermistor(int pin) : pin(pin) { }
		float read();
		void setup();
};

#endif
