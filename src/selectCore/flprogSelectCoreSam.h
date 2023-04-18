#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								4.Контроллеры программной среды SAM
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_SAM_DUE) //====КОНТРОЛЛЕР Arduino DUE;
#define FLPROG_CORE_CODE 8                                 //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Arduino DUE"                     //--Наименование платы;
#define FLPROG_CORE_AVR_DUE_SAM                            //--Идентификатор типа платы
#define FLPROG_CORE_AVR_DUE   
 #define FLPROG_I2CSPEED 400000UL
#endif
//=================================================================================================