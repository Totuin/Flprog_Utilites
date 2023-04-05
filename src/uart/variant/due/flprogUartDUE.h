#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_AVR_DUE

namespace flprog
{
  UARTClass::UARTModes serialModeFromInt(int16_t code);
  UARTClass::UARTModes serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

#include "hardwareUart/hardwareUartDUE.h"

#endif