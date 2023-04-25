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
#if !defined(FLPROG_CORE_CODE)
#define FLPROG_CORE_CODE 0
#define FLPROG_CORE_NAME "ANON"
#define FLPROG_CORE_ANON 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#endif
