#pragma once
#include <Arduino.h>

#if defined(ESP8266) || defined(ESP32)
#define CORE_ESP8266_OR_ESP32
#endif

#include "uart/flprogUart.h"
#include "tcp/flprogTcpDevice.h"

namespace flprog
{
    bool isTimer(uint32_t startTime, uint32_t period);
    int serialCodeForParametrs(byte portDataBits, byte portStopBits, byte portParity);
#ifdef ESP8266
    SerialConfig serialModeFromInt(int16_t code);
    SerialConfig serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
#else
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
#endif

    long speedFromCode(byte code);
};
