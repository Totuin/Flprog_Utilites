#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							 20.Контроллеры программной среды (M) STM32F1
// Generic STM32F103C6/fake STM32F103C8
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_STM32F103C) //====КОНТРОЛЛЕР (M)Generic_STM32F103C_series;
#define FLPROG_CORE_CODE 30                                           //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(М)Generic STM32F103C series"               //--Наименование платы;
#define FLPROG_CORE_GENERIC_STM32F103C_M                              //--Идентификатор типа платы [variant.generic_stm32f103c];
#define FLPROG_CORE_STM32                                             //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M_F1                                        //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10
#endif
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_STM32F103R) //====КОНТРОЛЛЕР (M)Generic_STM32F103R series;
#define FLPROG_CORE_CODE 31                                           //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(M)Generic STM32F103R series"               //--Наименование платы;
#define FLPROG_CORE_GENERIC_STM32F103R_M                              //--Идентификатор типа платы [variant.generic_stm32f103r];
#define FLPROG_CORE_STM32                                             //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M_F1                                        //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_STM32F103V) //====КОНТРОЛЛЕР (M)Generic_STM32F103V series;
#define FLPROG_CORE_CODE 32                                           //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(M)Generic STM32F103V series"               //--Наименование платы;
#define FLPROG_CORE_GENERIC_STM32F103V_M                              //--Идентификатор типа платы [variant.generic_stm32f103v];
#define FLPROG_CORE_STM32                                             //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M_F1                                        //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10
#endif
//=================================================================================================