#include <Arduino.h>

// This is the header file for the voltage sensor on the relay board
// The voltage sensor consists of a voltage divider where the power 
// is the 24V battery; the Teensy has an analog pin that reads the voltage at the divider point
// [Schematic placeholder link]

// This code is similar to the Drive voltage sensor code and uses it as an example

class VoltageSensor