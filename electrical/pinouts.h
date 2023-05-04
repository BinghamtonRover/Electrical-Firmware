#include "src/led_button.h"
#include "src/current/current.h"

#define RED_LED_PIN       1
#define YELLOW_LED_PIN    2
#define GREEN_LED_PIN     3

#define RED_BUTTON_PIN    6
#define YELLOW_BUTTON_PIN 7
#define GREEN_BUTTON_PIN  8

#define CURRENT_SENSOR_PIN 27

LedButton red(RED_LED_PIN, RED_BUTTON_PIN);
LedButton yellow(YELLOW_LED_PIN, YELLOW_BUTTON_PIN);
LedButton green(GREEN_LED_PIN, GREEN_BUTTON_PIN);

CurrentSensor currentSensor(CURRENT_SENSOR_PIN);
