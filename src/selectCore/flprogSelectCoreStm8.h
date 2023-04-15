#pragma once
#include <Arduino.h>

//-------------------------------------------------------------------------------------------------
//							   STM8
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(_STM8_DEF_)
#define FLPROG_CORE_CODE 40     //--Код CORE;
#define FLPROG_CORE_NAME "STM8" //--Имя CORE;
#define FLPROG_CORE_STM8        //--Идентификатор CORE;
#define FLPROG_CORE_STM         //--Идентификатор CORE групповой;
 #define FLPROG_I2CSPEED 400000UL;  
#endif
