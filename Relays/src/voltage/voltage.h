#include <Arduino.h>

// This is the header file for the voltage sensor on the relay board
// The voltage sensor consists of a voltage divider where the power 
// is the 24V battery; the Teensy has an analog pin that reads the voltage at the divider point
// [Schematic placeholder link]

// This code is similar to the Drive voltage sensor code and uses it as an example

class VoltageSensor
{
private:
    int pin;    // Analog pin that will read the voltage sensor output

public:
    // data struct that is updated with voltage sensor data
    RelaysData data;

    VoltageSensor(int pin);     // Constructing the VoltageSensor class

    void setup();   // Sets up pin so it knows to read from the voltage sensor

    float read();       // Reading voltage and returns it as a float

    void update();      // Updates RelaysData with battery voltage
}