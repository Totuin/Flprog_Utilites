#pragma once
#include <Arduino.h>
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_PORTENTA_X8) 
#define FLPROG_CORE_NAME "Arduino Portenta H7"
#define FLPROG_CORE_CODE 1
#define FLPROG_CORE_PORTENTA_X8
#define FLPROG_CORE_PORTENTA
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
