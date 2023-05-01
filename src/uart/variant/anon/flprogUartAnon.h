#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#ifdef FLPROG_ANON_SELECT_UART
namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

#include  "hardvareUart\hardwareUartAnon.h"
#endif