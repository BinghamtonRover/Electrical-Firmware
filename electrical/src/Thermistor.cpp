#include "Thermistor.h"

void Thermistor::setup() {
  pinMode(pin, INPUT);
}

float Thermistor::read() {
  float temp_reading = analogRead(pin);
  float millivolts = temp_reading * (3.3/1023.0) * 1000;
  float temperature = (5.506 - sqrt(sq(-5.506) + 4 * 0.00176 * (870.6 - millivolts))) / (2 * (-0.00176)) + 30;
  return temperature;
}
