#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								3.Контроллеры программной среды ESP32S3
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32S3_DEV) //====КОНТРОЛЛЕР ESP32S3 Dev Module;
#define FLPROG_CORE_CODE (uint8_t)150                          //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "ESP32S3 Dev Module"                  //--Наименование платы;
#define FLPROG_CORE_ESP32S3_DEV                                //--Идентификатор типа платы [variant.esp32]
#define FLPROG_CORE_ESP                                        //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                      //--Идентификатор программной среды
#define FLPROG_CORE_ESP32S3     
 #define FLPROG_I2CSPEED 400000UL
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								3.Контроллеры программной среды esp32
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BANANA_PI_PICO_W_S3) //====КОНТРОЛЛЕР BANANA PI PICO W S3;
#define FLPROG_CORE_CODE (uint8_t)152                                  //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "ESP32S3 BananaPi PicoW"                      //--Наименование платы;
#define FLPROG_CORE_BPI_PICO_W_S3                                      //--Идентификатор типа платы [variant.esp32]
#define FLPROG_CORE_ESP                                                //--Идентификатор программной среды для контроллеров ESP;
#define FLPROG_CORE_ESP32                                              //--Идентификатор программной среды
#define FLPROG_CORE_ESP32S3        
 #define FLPROG_I2CSPEED 400000UL
#endif
//=================================================================================================