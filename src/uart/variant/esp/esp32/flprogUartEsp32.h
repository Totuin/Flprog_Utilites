#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_ESP32
namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

#ifdef FLPROG_CORE_ESP32_BASIC
#define FLPROG_EXISTS_SELECT_ESP32_UART
#include "esp32_Basic\bluetoothSerial\flprogUartBluetoothSerial_Basic.h"
#include "esp32_Basic\hardvareUart\hardwareUartEsp32_Basic.h"
#endif

#ifndef FLPROG_EXISTS_SELECT_ESP32_UART
#define FLPROG_EXISTS_SELECT_ESP32_UART
#define FLPROG_SELECT_ESP32_ANON_UART
#include "esp32_Anon\hardwareUartEsp32_Anon.h"
#endif

#endif
