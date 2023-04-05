#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								3.Контроллеры программной среды esp32
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32S2_DEV) //====КОНТРОЛЛЕР ESP32S2 Dev Module;
#define FLPROG_CORE_CODE (uint8_t)120                          //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "ESP32S2 Dev Module"                  //--Наименование платы;
#define FLPROG_CORE_ESP32S2_DEV                                //--Идентификатор типа платы
#define FLPROG_CORE_ESP                                        //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                      //--Идентификатор программной среды
#define FLPROG_CORE_ESP32S2                                    //--Идентификатор программной среды
#endif

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOLIN_S2_PRO) //====КОНТРОЛЛЕР LOLIN S2 PRO;
#define FLPROG_CORE_CODE (uint8_t)122                           //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "LOLIN S2 PRO"                         //--Наименование платы;
#define FLPROG_CORE_LOLIN_S2_PRO                                //--Идентификатор типа платы
#define FLPROG_CORE_ESP                                         //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                       //--Идентификатор программной среды
#define FLPROG_CORE_ESP32S2                                     //--Идентификатор программной среды
#endif

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOLIN_S2_MINI) //====КОНТРОЛЛЕР LOLIN S2 MINI;
#define FLPROG_CORE_CODE (uint8_t)121                            //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "LOLIN S2 MINI"                         //--Наименование платы;
#define FLPROG_CORE_LOLIN_S2_MINI                                //--Идентификатор типа платы
#define FLPROG_CORE_ESP                                          //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                        //--Идентификатор программной среды
#define FLPROG_CORE_ESP32S2                                      //--Идентификатор программной среды
#endif

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
