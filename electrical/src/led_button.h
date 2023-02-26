#include <Arduino.h>

class LedButton {
	private:
		int ledPin;
		int buttonPin;
		bool buttonState = false;

	public: 
		bool state = false;

		LedButton(int ledPin, int buttonPin);
		void setup();
		void update();

		void turnOn();
		void turnOff();
};
