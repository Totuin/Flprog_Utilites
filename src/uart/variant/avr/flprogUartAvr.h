#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_AVR
namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};


#include  "hardvareUart/hardwareUartAVR.h"
#include  "softwareUart/flprogSoftwareUartAVR.h"
#endif