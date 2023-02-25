#pragma once
#include <Arduino.h>

#define FLPROG_SENSOR_NOT_ERROR 0
#define FLPROG_SENSOR_NOT_READY_ERROR 1
#define FLPROG_SENSOR_DEVICE_NOT_FOUND_ERROR 2
#define FLPROG_SENSOR_DEVICE_NOT_CORRECT_BUS_NUMBER_ERROR 65
#define FLPROG_SENSOR_DEVICE_NOT_CORRECT_DEVICE_ADDRESS_ERROR 61
#define FLPROG_SENSOR_DEVICE_NOT_DEFINED_ERROR 5
#define FLPROG_SENSOR_DEVICE_NOT_CORRECT_DATA_ERROR 6
#define FLPROG_SENSOR_CRC_ERROR 72

#define FLPROG_SENSOR_WAITING_READ_STEP 0
#define FLPROG_SENSOR_WAITING_DELAY 1

#if defined(ESP8266) || defined(ESP32)
#define FLPROG_CORE_ESP8266_OR_ESP32
#endif

#ifdef ESP8266
#define FLPROG_CORE_ESP8266
#include "variant\esp8266\flprogUtilitesESP8266.h"
#endif

#ifdef ESP32
#define FLPROG_CORE_ESP32
#include "variant\esp32\flprogUtilitesESP32.h"
#endif

#ifdef _STM32_DEF_
#define FLPROG_CORE_STM32
#endif

#ifdef _STM8_DEF_
#define FLPROG_CORE_STM8
#endif

#if defined(FLPROG_CORE_STM32) || defined(FLPROG_CORE_STM8)
#define FLPROG_CORE_STM
#endif

#if defined(_STM32_DEF_) && defined(USBCON) && defined(USBD_USE_CDC)
#define FLPROG_STM32_USB_COM0
#endif

#ifdef _UART_CLASS_
#define FLPROG_CORE_AVR_DUE
#include "variant\arduino\due\flprogUtilitesDUE.h"
#endif

#ifdef __AVR__
#ifndef FLPROG_CORE_AVR_DUE
#define FLPROG_CORE_AVR
#endif
#endif

#if defined(FLPROG_CORE_AVR) || defined(FLPROG_CORE_STM8) || defined(FLPROG_CORE_STM32) || defined(FLPROG_CORE_ESP32)
#define FLPROG_UNIVTRSAL_FUNCTION
#include "variant\arduino\avr\flprogUtilitesAVR.h"
#endif

#include "i2c/flprogI2C.h"
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
