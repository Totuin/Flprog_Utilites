#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_ESP8266

namespace flprog
{
    SerialConfig serialModeFromInt(int16_t code);
    SerialConfig serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

#include "hardwareUart/hardwareUartEsp8266.h"
#include "softwareUart/flprogSoftwareUartEsp8266.h"

#endif