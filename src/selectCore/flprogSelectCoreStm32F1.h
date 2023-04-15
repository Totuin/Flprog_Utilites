#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							 22.Контроллеры программной среды (D) STM32F1
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLUEPILL_F103C8) //====КОНТРОЛЛЕР (D)BluePill F103C8
#define FLPROG_CORE_CODE 110                                       //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)BluePill F103C8"                      //--Наименование платы;
#define FLPROG_CORE_ADD "Memory ROM=64k,RAM=20k"                   //--Дополнительные параметры;
#define FLPROG_CORE_D_GENERIC_F103CXX                              //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                          //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                        //--Идентификатор программной среды
#define FLPROG_CORE_STM32F1_D
#define FLPROG_CORE_STM 
 #define FLPROG_I2CSPEED 400000UL;  
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLUEPILL_F103CB) //====КОНТРОЛЛЕР (D)BluePill F103CB
#define FLPROG_CORE_CODE 110                                       //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)BluePill F103CB"                      //--Наименование платы;
#define FLPROG_CORE_ADD "Memory ROM=128k,RAM=20k"                  //--Дополнительные параметры;
#define FLPROG_CORE_D_GENERIC_F103CXX                              //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                          //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                        //--Идентификатор программной среды
#define FLPROG_CORE_STM32F1_D
#define FLPROG_CORE_STM 
 #define FLPROG_I2CSPEED 400000UL;  
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACKPILL_F103C8) //====КОНТРОЛЛЕР (D)BlackPill F103C8
#define FLPROG_CORE_CODE 110                                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)BlackPill F103C8"                      //--Наименование платы;
#define FLPROG_CORE_ADD "Memory ROM=128k,RAM=20k"                   //--Дополнительные параметры;
#define FLPROG_CORE_D_GENERIC_F103CXX                               //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                         //--Идентификатор программной среды
#define FLPROG_CORE_STM32F1_D
#define FLPROG_CORE_STM 
 #define FLPROG_I2CSPEED 400000UL;  
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACKPILL_F103CB) //====КОНТРОЛЛЕР (D)BlackPill F103CB
#define FLPROG_CORE_CODE 110                                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)BlackPill F103CB"                      //--Наименование платы;
#define FLPROG_CORE_ADD "Memory ROM=128k,RAM=20k"                   //--Дополнительные параметры;
#define FLPROG_CORE_D_GENERIC_F103CXX                               //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                         //--Идентификатор программной среды
#define FLPROG_CORE_STM32F1_D
#define FLPROG_CORE_STM
 #define FLPROG_I2CSPEED 400000UL;  
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_F103CBTX) //====КОНТРОЛЛЕР (D)Generic F103CBTx
#define FLPROG_CORE_CODE 110                                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)Generic F103CBTx"                      //--Наименование платы;
#define FLPROG_CORE_ADD "Memory ROM=128k,RAM=20k"                   //--Дополнительные параметры;
#define FLPROG_CORE_D_GENERIC_F103CXX                               //--Идентификатор типа платы [variant.STM32F1(xxx/F10CB(T-U)];
#define FLPROG_CORE_STM32                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                         //--Идентификатор программной среды
#define FLPROG_CORE_STM32F1_D
#define FLPROG_CORE_STM 
 #define FLPROG_I2CSPEED 400000UL;  
#endif
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_STM32F103C) //====КОНТРОЛЛЕР (M)Generic_STM32F103C_series;
#define FLPROG_CORE_CODE 111                                          //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(М)Generic STM32F103C series"               //--Наименование платы;
#define FLPROG_CORE_ADD "Memory ROM=128k,RAM=20k"                     //--Дополнительные параметры;
#define FLPROG_CORE_M_GENERIC_F103CXX                                 //--Идентификатор типа платы [variant.generic_stm32f103c];
#define FLPROG_CORE_STM32                                             //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M_F1
#define FLPROG_CORE_STM 
 #define FLPROG_I2CSPEED 400000UL;  
#endif
//=================================================================================================
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_F103RETX) //====КОНТРОЛЛЕР (D)Generic F103RETx
#define FLPROG_CORE_CODE 112                                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)Generic F103RETx"                      //--Наименование платы;
#define FLPROG_CORE_D_GENERIC_F103RXX                               //--Идентификатор типа платы [variant.STM32F1(xxx/F103R(C-D-E)Y)];
#define FLPROG_CORE_STM32                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                         //--Идентификатор программной среды
#define FLPROG_CORE_STM32F1_D
#define FLPROG_CORE_STM 
 #define FLPROG_I2CSPEED 400000UL;  
#endif
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_STM32F103R) //====КОНТРОЛЛЕР (M)Generic_STM32F103R series;
#define FLPROG_CORE_CODE 113                                          //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(M)Generic STM32F103R series"               //--Наименование платы;
#define FLPROG_CORE_M_GENERIC_F103RXX                                 //--Идентификатор типа платы [variant.generic_stm32f103r];
#define FLPROG_CORE_STM32                                             //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_F1_M
#define FLPROG_CORE_STM 
 #define FLPROG_I2CSPEED 400000UL;  
#endif
//=================================================================================================
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_F103VETX) //====КОНТРОЛЛЕР (D)Generic F103VETx
#define FLPROG_CORE_CODE 130                                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)Generic F103VETx"                      //--Наименование платы;
#define FLPROG_CORE_D_GENERIC_F103VETX                              //--Идентификатор типа платы [variant.STM32F1(xxx/F103V(C-D-E)H-T)];
#define FLPROG_CORE_STM32                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                         //--Идентификатор программной среды
#define FLPROG_CORE_STM32F1_D
#define FLPROG_CORE_STM 
 #define FLPROG_I2CSPEED 400000UL;  
#endif
//--------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_STM32F103V) //====КОНТРОЛЛЕР (M)Generic_STM32F103V series;
#define FLPROG_CORE_CODE 131                                          //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(M)Generic STM32F103V series"               //--Наименование платы;
#define FLPROG_CORE_M_GENERIC_STM32F103V                              //--Идентификатор типа платы [variant.generic_stm32f103v];
#define FLPROG_CORE_STM32                                             //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M_F1
#define FLPROG_CORE_STM 
 #define FLPROG_I2CSPEED 400000UL;  
#endif
//=================================================================================================
