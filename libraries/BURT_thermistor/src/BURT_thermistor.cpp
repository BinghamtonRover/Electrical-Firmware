#include "BURT_thermistor.h"

float Thermistor::read() {
  float temp_reading = analogRead(pin);    // reads in sensor data
  float interim = temp_reading * (3.3/1023.0) *1000; //converts from teensy input to millivolts
  float temperature = (5.506-sqrt(sq(-5.506)+4*.00176*(870.6-interim)))/(2*(-.00176)) +30;  // formula given by TI to calculate temperature from millivolts reading over entire temperature range
  return temperature;
}

void Thermistor::setup() {
  pinMode(pin, INPUT);
}
