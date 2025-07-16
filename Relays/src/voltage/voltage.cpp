#include "voltage.h"

// This cpp file is for the voltage sensor on the relay board, check the header file for a description of the sensor
// Assumes volage is being read using a digital reading from a 10-bit ADC converter

VoltageSensor::VoltageSensor(int pin) : pin(pin)
{
}

void VoltageSensor::setup() // Sets up the Teensy to read from the voltage sensor
{
    pinMode(pin, INPUT); // Setting Teensy pinmode to INPUT so that it reads from the voltage sensor
}

float VoltageSensor::read() // Reads voltage and returns the voltage of the battery
{
    float raw;      // Declaring the variable for the voltage at the voltage sensor (this value is scaled down from battery voltage using a voltage divider)
    float vbattery; // Declaring the variable for the voltage of the battery (scales the reading to match the battery voltage)

     //   analogReadResolution(10);       // Setting resolution of ADC to 10 bits (0 to 1023), however, this is the default resolution (for Teensy 4.1) so this line is commented out for now

    raw = analogRead(pin); // Reading the raw value of the pin, this value will be between 0 and 1023 and needs to be scaled to the actual voltage value
                           //  analogReference(DEFAULT);   // Sets the maximum voltgae that can be read (i.e. 3.3V = 1023); this does nothing on the Teensy so this line is commented

    vbattery = (raw / 1023) * 3.3;      // Scaling the analog value (0 - 1023) to the corresponding voltage between 0 and 3.3V
    vbattery = vbattery * 11;           // Scaling the voltage sensor(divider) voltage (0 - 3.3V) to battery voltage (0 - 24V)
    
                                        // Given the current voltage divider, the actual pin voltage shouldn't exceed ~2.2V since that scales to ~24V on the battery

    return vbattery;
}

    void VoltageSensor::update()
{
    data.voltageData = read();
}