
#ifndef ESPIRDRIVER_H
#define ESPIRDRIVER_H

#include <IRremoteESP8266.h>
// #define RECV_PIN 12
// IRrecv irReceiver(RECV_PIN);
// #include "IRCommands.h"
// #include <IRCommands.h>
#include <ESPFastLedDriver.h>

class ESPIRDriver
{
public:
  ESPIRDriver(IRrecv* irReceiver, ESPFastLedDriver* ledDriver);
  void run();
private:
  ESPFastLedDriver* _ledDriver;
  IRrecv* _irReceiver;
};

#endif
