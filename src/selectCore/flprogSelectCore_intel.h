#pragma once
#include <Arduino.h>
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GALILEO) 
#define FLPROG_CORE_NAME "GALILEO"
#define FLPROG_CORE_CODE 4
#define FLPROG_CORE_GALILEO
#define FLPROG_CORE_INTEL 
#define FLPROG_I2CSPEED 400000UL 
#define FLPROG_HAS_UART0
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GALILEOGEN2) 
#define FLPROG_CORE_NAME "GALILEOGEN2"
#define FLPROG_CORE_CODE 5
#define FLPROG_CORE_GALILEOGEN2
#define FLPROG_CORE_INTEL 
#define FLPROG_I2CSPEED 400000UL 
#define FLPROG_HAS_UART0
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
