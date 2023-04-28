#pragma once
#include <Arduino.h>
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_NUCLEO_8L152R8) 
#define FLPROG_CORE_NAME "Nucleo 8L152R8"
#define FLPROG_CORE_CODE 314
#define FLPROG_CORE_NUCLEO_8L152R8
#define FLPROG_CORE_STM8       
#define FLPROG_CORE_STM        
 #define FLPROG_I2CSPEED 400000UL  
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_HAS_SPI0
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_NUCLEO_8S208RB) 
#define FLPROG_CORE_NAME "Nucleo 8S208RB"
#define FLPROG_CORE_CODE 316
#define FLPROG_CORE_NUCLEO_8S208RB
#define FLPROG_CORE_STM8       
#define FLPROG_CORE_STM        
 #define FLPROG_I2CSPEED 400000UL  
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_HAS_SPI0
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
