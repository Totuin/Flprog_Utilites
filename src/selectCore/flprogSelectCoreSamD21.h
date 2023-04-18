#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								1.Контроллер Seeeduno XIAO M0
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_SEEED_XIAO_M0) //====КОНТРОЛЛЕР Seeeduino XIAO M0;
#define FLPROG_CORE_CODE 15                                      //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Seeeduno XIAO M0"                      //--Наименование платы;
#define FLPROG_CORE_SEEED_XIAO_M0                                //--Идентификатор типа платы [variant.XIAO_m0];
#define FLPROG_CORE_SEEED  
 #define FLPROG_I2CSPEED 400000UL
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								2.Контроллер Seeeduno Z0
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_SEEED_ZERO) //====КОНТРОЛЛЕР Seeeduino XIAO M0;
#define FLPROG_CORE_CODE 16                                   //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Seeeduno Zero"                      //--Наименование платы;
#define FLPROG_CORE_SEEED_ZERO                                //--Идентификатор типа платы [variant.XIAO_m0];
#define FLPROG_CORE_SEEED     
 #define FLPROG_I2CSPEED 400000UL
#endif

//------Идентификация к группе контроллеров SEEED--------------------------------------------------

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ARCH_SEEED) //--??? Не проверенный идентификатор
#define FLPROG_CORE_CODE 17
#define FLPROG_CORE_SEEED //--Идентификатор программной среды	
 #define FLPROG_I2CSPEED 400000UL
#endif
//=================================================================================================