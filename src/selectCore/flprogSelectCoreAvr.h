#pragma once
#include <Arduino.h>

//-------------------------------------------------------------------------------------------------
//		1.Контроллеры программной среды AVR
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_UNO) //====КОНТРОЛЛЕР Arduino Uno;
#define FLPROG_CORE_CODE 1                                 //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Arduno Uno"                      //--Наименование платы;
#define FLPROG_CORE_AVR_UNO                                //--Идентификатор типа платы
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#endif

//---------------------------------------------------------------------------------------------------

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_NANO) //====КОНТРОЛЛЕР Arduino Nano;
#define FLPROG_CORE_CODE 2                                  //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Arduino Nano"                     //--Наименование платы;
#define FLPROG_CORE_AVR_NANO                                //--Идентификатор типа платы
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#endif

//---------------------------------------------------------------------------------------------------

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_PRO) //====КОНТРОЛЛЕР Arduino Pro or Pro Mini;
#define FLPROG_CORE_CODE 3                                 //--Идентификатор типа выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Arduino Pro or Pro mini"         //--Наименование платы;
#define FLPROG_CORE_AVR
#define FLPROG_CORE_AVR_PRO //--Идентификатор типа платы
#define FLPROG_I2CSPEED 400000UL
#endif

//---------------------------------------------------------------------------------------------------

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_MICRO) //====КОНТРОЛЛЕР Arduino Pro or Pro Mini;
#define FLPROG_CORE_CODE 6                                   //--Идентификатор типа выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Arduino Micro"                     //--Наименование платы;                                //--Идентификатор типа платы
#define FLPROG_CORE_AVR
#define FLPROG_CORE_AVR_MICRO
#define FLPROG_I2CSPEED 400000UL
#endif

//---------------------------------------------------------------------------------------------------

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_LEONARDO) //====КОНТРОЛЛЕР Arduino Pro or Pro Mini;
#define FLPROG_CORE_CODE 6                                      //--Идентификатор типа выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Arduino Leonardo"                     //--Наименование платы;
#define FLPROG_CORE_AVR                                         //--Идентификатор типа платы
#define FLPROG_CORE_AVR_LEONARDO
#define FLPROG_I2CSPEED 400000UL
#endif

//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_MEGA2560) //====КОНТРОЛЛЕР Arduino Mega 2560;
#define FLPROG_CORE_CODE 4                                      //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Arduino Mega 2560"                    //--Наименование платы;
#define FLPROG_CORE_AVR
#define FLPROG_CORE_AVR_MEGA2560                          //--Идентификатор типа платы [variant.mega]                                   //--Идентификатор программной среды
#if defined(FLPROG_CORE_AVR_MEGA2560)                     //--Корректировка
#ifdef PROGMEM                                            //		для Arduino Mega2560;
#undef PROGMEM                                            //		атрибута
#endif                                                    //		для работы
#define PROGMEM __attribute__((section(".progmem.data"))) // 		с PROGMEM для RAM>64kB;
#endif
#define FLPROG_I2CSPEED 400000UL
#endif

//------Идентификация к группе неопознанных контроллеров AVR----------------------------------------

#if !defined(FLPROG_CORE_CODE) && defined(__AVR__)
#define FLPROG_CORE_CODE 5                                //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Unknow board [near Arduno Uno]" //--Наименование платы;
#define FLPROG_CORE_AVR
#define FLPROG_CORE_AVR_UNKNOW //--Идентификатор типа платы [variant.standart]
#define FLPROG_I2CSPEED 400000UL
#endif
