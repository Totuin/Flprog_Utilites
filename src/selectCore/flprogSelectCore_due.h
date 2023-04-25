#pragma once
#include <Arduino.h>
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_SAM_DUE) 
#define FLPROG_CORE_NAME "Arduino Due (Programming Port)"
#define FLPROG_CORE_CODE 3
#define FLPROG_CORE_SAM_DUE
#define FLPROG_CORE_AVR_DUE_SAM                         
#define FLPROG_CORE_AVR_DUE    
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
