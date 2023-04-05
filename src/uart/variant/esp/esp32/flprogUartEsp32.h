#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_ESP32
namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};


#include  "hardvareUart/hardwareUartEsp32.cpp"
#include "bluetoothSerial/flprogUartBluetoothSerial.h"
#endif