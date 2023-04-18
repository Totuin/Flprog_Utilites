#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							 21.Контролеры программной среды (M) STM32F4
// В ядре STM32-Master для контроллеров STM32F4 пока ограниченная поддержка контроллеров STM32F4
// Так STM32F407V нет поддержки WireSlave, Serialx.availableForWrite и др.
// Если ядро будет развиваться, в дальнейшем может быть добавлены необходимые функции
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// generic_f407v
#if !defined(RT_HW_BOARD_CODE) && defined(ARDUINO_generic_f407v_mini) //====КОНТРОЛЕР (M)Generic STM32F407V mini series;
#define FLPROG_CORE_CODE 150                                          //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(M) DevEBox STM32F407VET6 Mini"             //--Наименование платы;
#define FLPROG_CORE_DEVEBOX_STM32F407VET6_M                           //--Идентификатор типа платы [variant.generic_f407v];
#define FLPROG_CORE_STM32                                             //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M_F4                                        //--Идентификатор программной среды
#define FLPROG_CORE_STM

 #define FLPROG_I2CSPEED 400000UL
 #define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10
#endif
//-------------------------------------------------------------------------------------------------
// #if !defined(RT_HW_BOARD_CODE) && defined(_BOARD_GENERIC_F407V_H_)				//====КОНТРОЛЕР (M)Generic STM32F407V series;
// #define    FLPROG_CORE_CODE        151    								//--Идентификатор выбора платы c кодом платы;
// #define    FLPROG_CORE_NAME        "(M) STM32F4xx F4VE"					//--Наименование платы;
// #define    FLPROG_CORE_STM32F4xx_F4VE_M 									//--Идентификатор типа платы [variant.generic_f407v];
// #define      FLPROG_CORE_STM32												//--Идентификатор программной среды
// #define      FLPROG_CORE_STM32_M												//--Идентификатор программной среды
// #define      FLPROG_CORE_STM32_M_F4											//--Идентификатор программной среды
// #define FLPROG_CORE_STM
// #endif
//-------------------------------------------------------------------------------------------------
#if !defined(RT_HW_BOARD_CODE) && defined(ARDUINO_blackpill_f401) //====КОНТРОЛЛЕР (M)BlackPill F401CCU6
#define FLPROG_CORE_CODE RT_HW_CODE_M_blackpill_f401              //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(M)BlackPill F401CCU6"                  //--Наименование платы;
#define FLPROG_CORE_M_blackpill_f401                              //--Идентификатор типа платы [variant.blackpill_f401];
#define FLPROG_CORE_STM32                                         //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M                                       //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M_F4                                    //--Идентификатор программной среды
#define FLPROG_CORE_STM

 #define FLPROG_I2CSPEED 400000UL
 #define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10 
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(RT_HW_BOARD_CODE) && (defined(ARDUINO_disco_f411)) //====КОНТРОЛЛЕР (M)BlackPill F401CCU6
#define FLPROG_CORE_CODE RT_HW_CODE_M_disco_f411                //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(M)BlackPill F411CE"                  //--Наименование платы;
#define FLPROG_CORE_M_disco_f411                                //--Идентификатор типа платы [variant.disco_f411];
#define FLPROG_CORE_STM32                                       //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M                                     //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M_F4                                  //--Идентификатор программной среды
#define FLPROG_CORE_STM

 #define FLPROG_I2CSPEED 400000UL  
 #define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10
#endif
//================================================================================================