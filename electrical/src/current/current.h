#include <Arduino.h>

class CurrentSensor {
	private: 
		int pin;

	public:
		CurrentSensor(int pin);
		void setup();
		float getCurrent();
};
