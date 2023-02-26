#include "led_button.h"

LedButton::LedButton(int ledPin, int buttonPin) : 
	ledPin(ledPin), buttonPin(buttonPin) { }

void LedButton::setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(buttonPin, INPUT_PULLUP);
}

void LedButton::update() {
	// `buttonPin == LOW` and `buttonState == true` => button released
	if (digitalRead(buttonPin) == HIGH) {  
		// Button is being pressed, wait for release
		buttonState = true;
		return;
	} else if (!buttonState) {
		// Button was released from a press
		state = !state;
		if (state) turnOn();
		else turnOff();
	}
}

void LedButton::turnOn() { 
	digitalWrite(ledPin, HIGH);
}

void LedButton::turnOff() { 
	digitalWrite(ledPin, LOW);
}
