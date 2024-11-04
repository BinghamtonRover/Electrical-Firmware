#ifndef PINOUTS_H
#define PINOUTS_H

#include "src/switch/switch.h"
#include "src/utils/BURT_utils.h"
#include "src/relays.pb.h"

#define DATA_SEND_INTERVAL 250  // ms
#define RELAY_UPDATE_INTERVAL 0  // ms

void handleCommand(const uint8_t* data, int length);
void sendData();

Relays relays;
BurtSerial serial(Device::Device_RELAY, handleCommand, RelaysData_fields, RelaysData_size); 
BurtTimer dataTimer(DATA_SEND_INTERVAL, sendData);

#endif