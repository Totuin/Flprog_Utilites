#pragma once
#include <Arduino.h>
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_LARDU_328E) 
#define FLPROG_CORE_NAME " Larduino w/ LGT8F328D,  LGT8F328P-SSOP20 MiniEVB,  LGT8F328P-LQFP32 MiniEVB,  Larduino w/ LGT8F328D-SSOP20, AVR LARDU 328E"
#define FLPROG_CORE_CODE 1464
#define FLPROG_CORE_AVR_LARDU_328E
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_LARDU_88DS20) 
#define FLPROG_CORE_NAME " Larduino w/ LGT8F88D-SSOP20"
#define FLPROG_CORE_CODE 1466
#define FLPROG_CORE_AVR_LARDU_88DS20
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA88
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
