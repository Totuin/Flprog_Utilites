#pragma once
#include <Arduino.h>
#include "flprogSelectCore_poterna.h"
#include "flprogSelectCore_avr.h"
#include "flprogSelectCore_due.h"
#include "flprogSelectCore_esp32.h"
#include "flprogSelectCore_esp8266.h"
#include "flprogSelectCore_intel.h"
#include "flprogSelectCore_rp2040.h"
#include "flprogSelectCore_stm8.h"
#include "flprogSelectCore_stm32.h"
#include "flprogSelectCore_larduino.h"

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ARCH_AVR) 
#define FLPROG_CORE_CODE 20000
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_NAME "AVR ANON"
#define FLPROG_CORE_AVR_ANON 
#endif

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ARCH_ESP8266) 
#define FLPROG_CORE_CODE 20001
#define FLPROG_CORE_ESP   
#define FLPROG_CORE_ESP8266
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_NAME "ESP8266 ANON"
#define FLPROG_CORE_ESP_ANON 
#endif

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ARCH_ESP32) 
#define FLPROG_CORE_CODE 20001
#define FLPROG_CORE_ESP   
#define FLPROG_CORE_ESP32
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_NAME "ESP32 ANON"
#define FLPROG_CORE_ESP_ANON 
#endif


#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ARCH_STM32) 
#define FLPROG_CORE_CODE 20002
#define FLPROG_CORE_STM
#define FLPROG_CORE_STM32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_NAME "STM32 ANON"
#define FLPROG_CORE_STM32_ANON 
#endif
#if !defined(FLPROG_CORE_CODE)
#define FLPROG_CORE_CODE 0
#define FLPROG_CORE_NAME "ANON"
#define FLPROG_CORE_ANON 
#define FLPROG_I2CSPEED 400000UL
#endif
