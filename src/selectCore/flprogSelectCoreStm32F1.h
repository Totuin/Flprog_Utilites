#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							 22.Контроллеры программной среды (D) STM32F1
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLUEPILL_F103CB) 
#define FLPROG_CORE_CODE 110                                       
#define FLPROG_CORE_NAME "(D)BluePill F103CB"                      
#define FLPROG_CORE_ADD "Memory ROM=128k,RAM=20k"                  
#define FLPROG_CORE_STM32_BLUEPILL_F103CB
#define FLPROG_CORE_STM32_F103
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLUEPILL_F103C8) 
#define FLPROG_CORE_CODE 111                                       
#define FLPROG_CORE_NAME "BluePill F103C8"                        
#define FLPROG_CORE_ADD "Memory ROM=128k,RAM=20k"                 
#define FLPROG_CORE_STM32_BluePill F103C8
#define FLPROG_CORE_STM32_F103 
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACKPILL_F103C8) 
#define FLPROG_CORE_CODE 112                                        
#define FLPROG_CORE_NAME "(D)BlackPill F103C8"                     
#define FLPROG_CORE_ADD "Memory ROM=128k,RAM=20k"                   
#define FLPROG_CORE_STM32_BLACKPILL_F103C8                          
#define FLPROG_CORE_STM32_F103
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACKPILL_F103CB) 
#define FLPROG_CORE_CODE 113                                        
#define FLPROG_CORE_NAME "(D)BlackPill F103CB"                      
#define FLPROG_CORE_ADD "Memory ROM=128k,RAM=20k"                  
#define FLPROG_CORE_STM32_BLACKPILL_F103CB 
#define FLPROG_CORE_STM32_F103
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_F103CBTX) 
#define FLPROG_CORE_CODE 115                                        
#define FLPROG_CORE_NAME "(D)Generic F103CBTx"                     
#define FLPROG_CORE_ADD "Memory ROM=128k,RAM=20k"                   
#define FLPROG_CORE_STM32_GENERIC_F103CBTX 
#define FLPROG_CORE_STM32_F103
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_STM32F103C) 
#define FLPROG_CORE_CODE 116                                          
#define FLPROG_CORE_NAME "(М)Generic STM32F103C series"               
#define FLPROG_CORE_ADD "Memory ROM=128k,RAM=20k"                     
#define FLPROG_CORE_STM32_GENERIC_STM32F103C
#define FLPROG_CORE_STM32_F103             
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_F103RETX) 
#define FLPROG_CORE_CODE 117                                        
#define FLPROG_CORE_NAME "(D)Generic F103RETx"                      
#define FLPROG_CORE_STM32_GENERIC_F103RETX                          
#define FLPROG_CORE_STM32_F103
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_STM32F103R)
#define FLPROG_CORE_CODE 118
#define FLPROG_CORE_NAME "(M)Generic STM32F103R series"
#define FLPROG_CORE_STM32_GENERIC_STM32F103R
#define FLPROG_CORE_STM32_F103
#endif
//=================================================================================================
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_F103VETX)
#define FLPROG_CORE_CODE 120
#define FLPROG_CORE_NAME "(D)Generic F103VETx"
#define FLPROG_CORE_STM32_GENERIC_F103VETX
#define FLPROG_CORE_STM32_F103
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_STM32F103V)
#define FLPROG_CORE_CODE 121
#define FLPROG_CORE_NAME "(M)Generic STM32F103V series"
#define FLPROG_CORE_STM32_GENERIC_STM32F103V
#define FLPROG_CORE_STM32_F103
#endif
//=================================================================================================

#ifdef FLPROG_CORE_STM32_F103

#define FLPROG_CORE_STM32
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10

#define FLPROG_NEED_CREATE_UART2
#define FLPROG_UART2_RX PA3
#define FLPROG_UART2_TX PA2

#define FLPROG_NEED_CREATE_UART3
#define FLPROG_UART3_RX PA11
#define FLPROG_UART3_TX PA10
#endif
