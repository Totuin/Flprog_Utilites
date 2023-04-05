#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								3.Контроллеры программной среды esp32
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_DEV) //====КОНТРОЛЛЕР ESP32 Dev Module;
#define FLPROG_CORE_CODE (uint8_t)110                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "ESP32 Dev Module"                  //--Наименование платы;
#define FLPROG_CORE_ESP32S_DEV                               //--Идентификатор типа платы [variant.esp32]
#define FLPROG_CORE_ESP                                      //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                    //--Идентификатор программной среды
#define FLPROG_CORE_ESP32S                                   //--Идентификатор программной среды
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								4.Контроллеры программной среды esp32
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32S_DEV_BTH_EIS) //====КОНТРОЛЛЕР ESP32S DEV BTH EIS;
#define FLPROG_CORE_CODE (uint8_t)111                                 //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "ESP32 Dev Module BlueTooth EIS"             //--Наименование платы;
#define FLPROG_CORE_ESP32S_DEV_BTH_EIS                                //--Идентификатор типа платы [variant.esp32]
#define FLPROG_CORE_ESP                                               //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                             //--Идентификатор программной среды
#define FLPROG_CORE_ESP32S                                            //--Идентификатор программной среды
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TTGO_T1) //====КОНТРОЛЛЕР TTGO T-Display [подобранный аналог]
#define FLPROG_CORE_CODE (uint8_t)112                      //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "TTGO T1-Display"                 //--Наименование платы;
#define FLPROG_CORE_ESP32_TTGO_T1                          //--Идентификатор типа платы [variant.ttgo-t1];
#define FLPROG_CORE_ESP                                    //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                  //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32S                                 //--Идентификатор программной среды
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOLIN_D32) //====КОНТРОЛЛЕР LOLIN32;
#define FLPROG_CORE_CODE (uint8_t)113                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "LOLIN D32"                         //--Наименование платы;
#define FLPROG_CORE_ESP32_LOLIN_D32                          //--Идентификатор типа платы [variant.d32];
#define FLPROG_CORE_ESP                                      //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                    //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32S                                   //--Идентификатор программной среды
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_D1_MINI32) //====КОНТРОЛЛЕР WEMOS D1 MINI ESP32
#define FLPROG_CORE_CODE (uint8_t)114                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "WEMOS D1 MINI ESP32"               //--Наименование платы;
#define FLPROG_CORE_ESP32S_D1_MINI32                         //--Идентификатор типа платы [variant.d1_mini32];
#define FLPROG_CORE_ESP                                      //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                    //--Идентификатор программной среды для контроллеров ESP32;
#define FLPROG_CORE_ESP32S                                   //--Идентификатор программной среды
#endif
//=================================================================================================