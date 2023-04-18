#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//								2.Контроллеры программной среды esp8266
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP8266_GENERIC) //====КОНТРОЛЛЕР Generic ESP8266 Module;
// В generic.variant определено толькo: A0=17;
// enum {D0=16,D1=5, D2=4,D3=0, D4=2, D5=14, D6=12,D7=13,D8=15,D9=3,D10=1};	//--Дополнительное определение номеров пинов;
// enum {RX=3, RX0=3,TX=1,TX0=1,TX1=2,RX2=13,TX2=15};							//--Дополнительное определение номеров пинов;
#define FLPROG_CORE_CODE 20                       //--Идентификатор выбора платы c кодом платы;
#define RT_HW_BOARD_NAME "Generic ESP8266 Module" //--Наименование платы;
#define FLPROG_CORE_ESP8266_GENERIC               //--Идентификатор типа платы [variant.generic]
#define FLPROG_CORE_ESP                           //--Идентификатор программной среды
#define FLPROG_CORE_ESP8266
#define FLPROG_I2CSPEED 100000UL; //--Идентификатор программной среды
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP8266_WEMOS_D1MINILITE) //====КОНТРОЛЛЕР LOLIN(WEMOS) D1 Lite;
// В d1_mini.variant определено толькo: D0=16,D1=5,D2=4,D3=0,D4=2,D5=14,D6=12,D7=13,D8=15,RX=3,TX=1;
// enum {D9=3, D10=1,RX0=3,TX0=1,TX1=2,RX2=13,TX2=15};							//--Дополнительное определение номеров пинов;
#define FLPROG_CORE_CODE 21                          //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "LOLIN(WEMOS) D1 mini Lite" //--Наименование платы;
#define FLPROG_CORE_ESP8266_WEMOS_D1MINILITE         //--Идентификатор типа платы [variant.d1_mini]
#define FLPROG_CORE_ESP                              //--Идентификатор программной среды
#define FLPROG_CORE_ESP8266                          //--Идентификатор программной среды
#define FLPROG_I2CSPEED 100000UL;
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP8266_WEMOS_D1MINIPRO) //====КОНТРОЛЛЕР LOLIN(WEMOS) D1 Pro;
// В d1_mini.variant определено толькo: D0=16,D1=5,D2=4,D3=0,D4=2,D5=14,D6=12,D7=13,D8=15,RX=3,TX=1;
// enum {D9=3, D10=1,RX0=3,TX0=1,TX1=2,RX2=13,TX2=15};							//--Дополнительное определение номеров пинов;
#define FLPROG_CORE_CODE 22                         //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "LOLIN(WEMOS) D1 mini Pro" //--Наименование платы;
#define FLPROG_CORE_ESP8266_WEMOS_D1MINIPRO         //--Идентификатор типа платы [variant.d1_mini]
#define FLPROG_CORE_ESP                             //--Идентификатор программной среды
#define FLPROG_CORE_ESP8266                         //--Идентификатор программной среды
#define FLPROG_I2CSPEED 100000UL
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP8266_NODEMCU_ESP12) //====КОНТРОЛЛЕР NodeMCU 0.9 (ESP12 Module);
// В nodemcu.variant определено толькo: D0=16,D1=5,D2=4,D3=0,D4=2,D5=14,D6=12,D7=13,D8=15,D9=3,D10=1;
// enum {RX=3, TX=1,RX0=3,TX0=1,TX1=2,RX2=13,TX2=15};							//--Дополнительное определение номеров пинов;
#define FLPROG_CORE_CODE 23                            //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "NodeMCU 0.9 (ESP-12 Module)" //--Наименование платы;
#define FLPROG_CORE_ESP8266_NODEMCU_ESP12              //--Идентификатор типа платы [variant.d1_mini]
#define FLPROG_CORE_ESP                                //--Идентификатор программной среды
#define FLPROG_CORE_ESP8266                            //--Идентификатор программной среды
#define FLPROG_I2CSPEED 100000UL
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP8266_NODEMCU_ESP12E) //====КОНТРОЛЛЕР NodeMCU 1.0 (ESP12E Module);
// В nodemcu.variant определено толькo: D0=16,D1=5,D2=4,D3=0,D4=2,D5=14,D6=12,D7=13,D8=15,D9=3,D10=1;
// enum {RX=3, TX=1,RX0=3,TX0=1,TX1=2,RX2=13,TX2=15};							//--Дополнительное определение номеров пинов;
#define FLPROG_CORE_CODE 24                             //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "NodeMCU 1.0 (ESP-12E Module)" //--Наименование платы;
#define FLPROG_CORE_ESP8266_NODEMCU_ESP12E              //--Идентификатор типа платы [variant.d1_mini]
#define FLPROG_CORE_ESP                                 //--Идентификатор программной среды
#define FLPROG_CORE_ESP8266                             //--Идентификатор программной среды
#define FLPROG_I2CSPEED 100000UL
#endif
//------Идентификация к группе контроллеров ESP8266---------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ARCH_ESP8266)
#define FLPROG_CORE_CODE 25                                    //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "Unknow board [near Generic ESP8266]" //--Наименование платы;
#define FLPROG_CORE_ESP8266_UNKNOW                             //--Идентификатор типа платы [variant.standart]
#define FLPROG_CORE_ESP                                        //--Идентификатор программной среды
#define FLPROG_CORE_ESP8266                                    //--Идентификатор программной среды
#define FLPROG_I2CSPEED 100000UL
#endif
//=================================================================================================