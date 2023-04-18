#pragma once
#include <Arduino.h>

// #define      FLPROG_CORE_PI_PICO_2											//--Идентификатор программной среды
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								9.Контроллеры программной среды RASPBERRIY PI
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_RASPBERRY_PI_PICO) //====КОНТРОЛЛЕР Raspberry Pi Pico;
#define FLPROG_CORE_CODE (uint8_t)130                                //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Raspberry Pi Pico"                         //--Наименование платы;
#define FLPROG_CORE_RP2040                                           //--Идентификатор типа платы;
#define FLPROG_CORE_RP2040 
 #define FLPROG_I2CSPEED 400000UL                                       
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_KB2040_RP2040) //====КОНТРОЛЛЕР Adafruit KB2040(подмена для RP2040 ZERO);
#define FLPROG_CORE_CODE (uint8_t)131                                     //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Adafruit KB2040"                                //--Наименование платы;
#define FLPROG_CORE_RP2040_ZERO                                           //--Идентификатор типа платы;
#define FLPROG_CORE_RP2040       
 #define FLPROG_I2CSPEED 400000UL                                          
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_RASPBERRY_PI_PICO_W) //====КОНТРОЛЛЕР Raspberry Pi Pico W;
#define FLPROG_CORE_CODE (uint8_t)132                                  //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Raspberry Pi Pico W"                         //--Наименование платы;
#define FLPROG_CORE_RP2040_W                                           //--Идентификатор типа платы;
#define FLPROG_CORE_RP2040      
 #define FLPROG_I2CSPEED 400000UL                                       
#endif
//------Идентификация к группе контроллеров RASPBERRY PI-------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ARCH_RP2040) //--Не опознанный контроллер RP2040;
#define FLPROG_CORE_CODE (uint8_t)139                          //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Raspberry Pi Pico ANON"              //--Наименование платы;
#define FLPROG_CORE_RP2040_ANON                                //--Идентификатор типа платы ;
#define FLPROG_CORE_RP2040    
 #define FLPROG_I2CSPEED 400000UL                              
#endif
//=================================================================================================