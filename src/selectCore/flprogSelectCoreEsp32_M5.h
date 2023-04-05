#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								3.1.Контроллеры программной среды ESP32S M5Stack
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5Stack_Core_ESP32) //====КОНТРОЛЛЕР M5Stack-Core-ESP32
#define FLPROG_CORE_CODE 120                                          //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "M5Stack-Core-ESP32"                         //--Наименование платы;
#define FLPROG_CORE_M5Stack_Core_ESP32                                //--Идентификатор типа платы [variant.m5_stack_core_esp32];
#define FLPROG_CORE_ESP                                               //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                             //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32S                                            //--Идентификатор программной среды для контроллеров ESP32S;
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5Stack_Fire) //====КОНТРОЛЛЕР M5Stack-Fire
#define FLPROG_CORE_CODE 121                                    //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "M5Stack-Fire"                         //--Наименование платы;
#define FLPROG_CORE_M5Stack_ATOM                                //--Идентификатор типа платы [variant.d1_mini32];
#define FLPROG_CORE_ESP                                         //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                       //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32S                                      //--Идентификатор программной среды для контроллеров ESP32S;
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5Stick_C) //====КОНТРОЛЛЕР M5Stick-C
#define FLPROG_CORE_CODE 122                                 //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "M5Stick-C"                         //--Наименование платы;
#define FLPROG_CORE_M5Stick_C                                //--Идентификатор типа платы [variant.d1_mini32];
#define FLPROG_CORE_ESP                                      //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                    //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32S                                   //--Идентификатор программной среды для контроллеров ESP32S;
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5Stack_ATOM) //====КОНТРОЛЛЕР WEMOS D1 MINI ESP32
#define FLPROG_CORE_CODE 123                                    //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "M5Stack_ATOM"                         //--Наименование платы;
#define FLPROG_CORE_M5Stack_ATOM                                //--Идентификатор типа платы [variant.d1_mini32];
#define FLPROG_CORE_ESP                                         //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                       //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32S                                      //--Идентификатор программной среды для контроллеров ESP32S;
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5Stack_Core2) //====КОНТРОЛЛЕР WEMOS D1 MINI ESP32
#define FLPROG_CORE_CODE 124                                     //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "M5Stack-Core2"                         //--Наименование платы;
#define FLPROG_CORE_M5Stack_Core2                                //--Идентификатор типа платы [variant.d1_mini32];
#define FLPROG_CORE_ESP                                          //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                        //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32S                                       //--Идентификатор программной среды для контроллеров ESP32S;
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5Stack_Time_CAM) //====КОНТРОЛЛЕР WEMOS D1 MINI ESP32
#define FLPROG_CORE_CODE 125                                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "M5Stack-Time-CAM"                         //--Наименование платы;
#define FLPROG_CORE_M5Stack_Time_CAM                                //--Идентификатор типа платы [variant.d1_mini32];
#define FLPROG_CORE_ESP                                             //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                           //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32S                                          //--Идентификатор программной среды для контроллеров ESP32S;
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5Stack_CoreInk) //====КОНТРОЛЛЕР WEMOS D1 MINI ESP32
#define FLPROG_CORE_CODE 126                                       //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "M5Stack-CoreInk"                         //--Наименование платы;
#define FLPROG_CORE_M5Stack_CoreInk                                //--Идентификатор типа платы [variant.d1_mini32];
#define FLPROG_CORE_ESP                                            //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                          //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32S                                         //--Идентификатор программной среды для контроллеров ESP32S;
#endif
//=================================================================================================
//									ESP32-PICO
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_STAMP_PICO) //====КОНТРОЛЛЕР WEMOS D1 MINI ESP32
#define FLPROG_CORE_CODE 127                                  //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "STAMP-PICO"                         //--Наименование платы;
#define FLPROG_CORE_STAMP -PICO                               //--Идентификатор типа платы [variant.d1_mini32];
#define FLPROG_CORE_ESP                                       //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                     //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32S                                    //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32PICO                                 //--Идентификатор программной среды для контроллеров ESP32S;
#endif
//=================================================================================================