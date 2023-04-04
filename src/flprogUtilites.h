#pragma once
#include <Arduino.h>
#include "flprogSelectCore.h"

#include "uart/flprogUart.h"
#include "tcp/flprogTcpDevice.h"
#include "flprog_Blocks.h"

namespace flprog
{
    bool isTimer(uint32_t startTime, uint32_t period);
    bool isTimerMicros(unsigned long startTime, unsigned long period);
    int serialCodeForParametrs(byte portDataBits, byte portStopBits, byte portParity);
    uint32_t speedFromCode(byte code);
    uint8_t codeFromSpeed(int32_t speed);
    uint32_t difference32(uint32_t start, uint32_t end);
    uint32_t timeBack(uint32_t value);

};
