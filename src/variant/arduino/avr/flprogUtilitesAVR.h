#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#ifdef FLPROG_UNIVTRSAL_FUNCTION
namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};
#endif