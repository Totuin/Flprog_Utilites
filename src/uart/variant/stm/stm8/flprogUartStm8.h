#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_STM8
namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};


#include  "hardvareUart/hardwareUartStm32.cpp"
#endif