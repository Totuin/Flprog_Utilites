#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								1.Контроллеры программной среды esp32_C3
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32C3_DEV) //====КОНТРОЛЛЕР ESP32C3 Dev Module;
#define FLPROG_CORE_CODE (uint8_t)130                          //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "ESP32C3 Dev Module"                  //--Наименование платы;
#define FLPROG_CORE_ESP32C3_DEV                                //--Идентификатор типа платы [variant.esp32];
#define FLPROG_CORE_ESP                                        //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                      //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32C3     
 #define FLPROG_I2CSPEED 400000UL;                                 //--Идентификатор программной среды для контроллеров ESP32C3;
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32C3_STAMP_C3_EIS) //====КОНТРОЛЛЕР ESP32C3 STAMP C3 EIS
#define FLPROG_CORE_CODE (uint8_t)131                                   //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "ESP32C3 STAMP-C3 EIS"                         //--Наименование платы;
#define FLPROG_CORE_ESP32C3_STAMP_C3_EIS                                //--Идентификатор типа платы [variant.esp32];
#define FLPROG_CORE_ESP                                                 //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                               //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32C3    
 #define FLPROG_I2CSPEED 400000UL;                                           //--Идентификатор программной среды для контроллеров ESP32C3;
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32C3_STAMP_C3U_EIS) //====КОНТРОЛЛЕР ESP32C3 STAMP C3U EIS;
#define FLPROG_CORE_CODE (uint8_t)132                                    //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "ESP32C3 STAMP-C3U EIS"                         //--Наименование платы;
#define FLPROG_CORE_ESP32C3_STAMP_C3U_EIS                                //--Идентификатор типа платы [variant.esp32];
#define FLPROG_CORE_ESP                                                  //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                                //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32C3    
 #define FLPROG_I2CSPEED 400000UL;                                            //--Идентификатор программной среды для контроллеров ESP32C3;
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32C3_TTGO_T_OI_PLUS_EIS) //====КОНТРОЛЛЕР ESP32C3 TTGO T OI PLUS EIS;
#define FLPROG_CORE_CODE (uint8_t)133                                         //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "ESP32C3 TTGO-T-OI-PLUS EIS"                         //--Наименование платы;
#define FLPROG_CORE_ESP32C3_TTGO_T_OI_PLUS_EIS                                //--Идентификатор типа платы [variant.esp32];
#define FLPROG_CORE_ESP                                                       //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                                     //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32C3  
 #define FLPROG_I2CSPEED 400000UL;                                                   //--Идентификатор программной среды для контроллеров ESP32C3;
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32C3_LUATOS_USB_EIS) //====КОНТРОЛЛЕР ESP32C3 LUATOS USB EIS;
#define FLPROG_CORE_CODE (uint8_t)134                                     //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "ESP32C3 LuatOS USB EIS "                        //--Наименование платы;
#define FLPROG_CORE_ESP32C3_LUATOS_USB_EIS                                //--Идентификатор типа платы [variant.esp32];
#define FLPROG_CORE_ESP                                                   //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                                 //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32C3   
 #define FLPROG_I2CSPEED 400000UL;                                              //--Идентификатор программной среды для контроллеров ESP32C3;
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32C3_LUATOS_CLASSIC_EIS) //====КОНТРОЛЛЕР ESP32C3 LUATOS CLASSIC EIS;
#define FLPROG_CORE_CODE (uint8_t)135                                         //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "ESP32C3 LuatOS Classic EIS"                         //--Наименование платы;
#define FLPROG_CORE_ESP32C3_LUATOS_CLASSIC_EIS                                //--Идентификатор типа платы [variant.esp32];
#define FLPROG_CORE_ESP                                                       //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                                     //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32C3 
 #define FLPROG_I2CSPEED 400000UL;                                                    //--Идентификатор программной среды для контроллеров ESP32C3;
#endif
