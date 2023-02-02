#pragma once
#include <Arduino.h>

#if defined(ESP8266) || defined(ESP32)
#define CORE_ESP8266_OR_ESP32
#endif

#ifdef ESP8266
#define CORE_ESP8266
#endif

#ifdef ESP32
#define CORE_ESP32
#endif

#ifdef _STM32_DEF_
#define CORE_STM32
#endif

#ifdef _STM8_DEF_
#define CORE_STM8
#endif

#if defined(_STM32_DEF_) && defined(USBCON) && defined(USBD_USE_CDC)
#define STM32_USB_COM0
#endif

 #if defined(__AVR__)
#define CORE_AVR
#endif

#include "uart/flprogUart.h"
#include "tcp/flprogTcpDevice.h"
#include "i2c/flprogI2C.h"

namespace flprog
{
    bool isTimer(uint32_t startTime, uint32_t period);
    int serialCodeForParametrs(byte portDataBits, byte portStopBits, byte portParity);
#ifdef ESP8266
    SerialConfig serialModeFromInt(int16_t code);
    SerialConfig serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
#else
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
#endif

    long speedFromCode(byte code);
    bool isTimerMicros(unsigned long startTime, unsigned long period);
};
