#pragma once
#include <Arduino.h>

#define SPEED_300 0
#define SPEED_600 1
#define SPEED_1200 2
#define SPEED_2400 3
#define SPEED_4800 4
#define SPEED_9600 5
#define SPEED_14400 6
#define SPEED_19200 7
#define SPEED_28800 8
#define SPEED_38400 9
#define SPEED_57600 10
#define SPEED_115200 11

namespace flprog
{
    bool isTimer(unsigned long startTime, unsigned long period);
    int serialCodeForParametrs(byte portDataBits, byte portStopBits, byte portParity);
#ifdef ESP8266
    SerialConfig serialModeFromInt(int code);
    SerialConfig serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
#else
    int serialModeFromInt(int code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
#endif

    long speedFromCode(byte code);
};
