#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							 10.Контроллеры программной среды STM32duino (H7)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_WeActMiniH743VITX) //====КОНТРОЛЛЕР (D)Generic H743VITX
#define FLPROG_CORE_CODE 120                                         //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)WeActMiniH743VITX"                      //--Наименование платы;
#define FLPROG_CORE_WeActMiniH743VITX_D                              //--Идентификатор типа платы [variant.STM32H7xx];
#define FLPROG_CORE_STM32                                            //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                          //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D_H7                                       //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10
#endif
//---------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_WeActMiniH750VBTX) //====КОНТРОЛЛЕР (D)Generic H743VITX
#define FLPROG_CORE_CODE 121                                         //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)WeActMiniH750VBTX"                      //--Наименование платы;
#define FLPROG_CORE_WeActMiniH750VBTX_D                              //--Идентификатор типа платы [variant.STM32H7xx];
#define FLPROG_CORE_STM32                                            //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                          //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D_H7                                       //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10
#endif
//=================================================================================================
