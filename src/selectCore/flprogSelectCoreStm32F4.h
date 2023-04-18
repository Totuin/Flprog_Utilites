#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							 32.Контроллеры программной среды (D) STM32F4
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACK_F407VE) //====BOARD (D)Black F407VE-->DevEBox STM32F407VET6 Mini
#define FLPROG_CORE_CODE 131                                    //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)Black F407VE"                      //--Наименование платы;
#define FLPROG_CORE_DEVEBOX_STM32F407VET6_D                     //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                       //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                     //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D_F4                                  //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10

#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(_BOARD_DEVEBOX_STM32F407V_H_) //====BOARD (M)Generic STM32F407V series-->DevEBox STM32F407VET6 Mini;
#define FLPROG_CORE_CODE 132                                            //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(M)DevEBox STM32F407VET6 Mini++"              //--Наименование платы;
#define FLPROG_CORE_DEVEBOX_STM32F407VET6_M                             //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                               //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M                                             //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M_F4                                          //--Идентификатор программной среды
#define FLPROG_CORE_STM
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10
#endif
//=================================================================================================
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACK_F407VE) //====BOARD (D)Black F407VG-->STM32F4xx_F4VE
#define FLPROG_CORE_CODE 133                                    //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)STM32_F4VE_V2.0 BLACK STM32F4XX "  //--Наименование платы;
#define FLPROG_CORE_STM32F4XX_F4VE_D                            //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                       //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                     //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D_F4                                  //--Идентификатор программной среды
#define FLPROG_CORE_STM
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(_BOARD_GENERIC_F407V_H_) //====Board (M)_BOARD_GENERIC_F407V_H_-->STM32F4xx_F4VE;
#define FLPROG_CORE_CODE 134                                       //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(M)STM32_F4VE_V2.0 BLACK STM32F4XX"      //--Наименование платы;
#define FLPROG_CORE_STM32F4XX_F4VE_M                               //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                          //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M                                        //--Идентификатор программной среды
#define FLPROG_CORE_STM32_M_F4                                     //--Идентификатор программной среды
#define FLPROG_CORE_STM
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10
#endif
//=================================================================================================

//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACKPILL_F401CC) //====КОНТРОЛЛЕР (D)BlackPill F401CC
#define FLPROG_CORE_CODE 135                                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)BlackPill F401CC"                      //--Наименование платы;
#define FLPROG_CORE_D_BLACKPILL_F401CC                              //--Идентификатор типа платы [variant.STM32F4xx/_F401C];
#define FLPROG_CORE_STM32                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                         //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D_F4                                      //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB3
#define FLPROG_I2C1_SCL PB10
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACKPILL_F411CE) //====КОНТРОЛЛЕР (D)BlackPill F411CE
#define FLPROG_CORE_CODE 136                                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)BlackPill F411CE"                      //--Наименование платы;
#define FLPROG_CORE_D_BLACKPILL_F411CE                              //--Идентификатор типа платы [variant.STM32F4xx/_F411C];
#define FLPROG_CORE_STM32                                           //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                                         //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D_F4                                      //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB3
#define FLPROG_I2C1_SCL PB10
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && (defined(ARDUINO_GENERIC_F401CBUX) || defined(ARDUINO_GENERIC_F401CCUX) || defined(ARDUINO_GENERIC_F401CBYX) || \
                                   defined(ARDUINO_GENERIC_F401CYXX) || defined(ARDUINO_GENERIC_F401CDUX) || defined(ARDUINO_GENERIC_F401CEUX) || \
                                   defined(ARDUINO_GENERIC_F401CDYX) || defined(ARDUINO_GENERIC_F401CEYX) || defined(ARDUINO_GENERIC_F401CCFX))
#define FLPROG_CORE_CODE 137                  //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)GENERIC F401CXX" //--Наименование платы;
#define FLPROG_CORE_D_GENERIC_F401CXXX        //--Идентификатор типа платы [variant.STM32F4xx/_F411C];
#define FLPROG_CORE_STM32                     //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                   //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D_F4                //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB3
#define FLPROG_I2C1_SCL PB10
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && (defined(ARDUINO_GENERIC_F411CCUX) || defined(ARDUINO_GENERIC_F411CCYX) || \
                                   defined(ARDUINO_GENERIC_F411CEUX) || defined(ARDUINO_GENERIC_F411CEYX))
#define FLPROG_CORE_CODE 138                  //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)GENERIC F411CXX" //--Наименование платы;
#define FLPROG_CORE_D_GENERIC_F411CXXX        //--Идентификатор типа платы [variant.STM32F4xx/_F411C];
#define FLPROG_CORE_STM32                     //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D                   //--Идентификатор программной среды
#define FLPROG_CORE_STM32_D_F4                //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB3
#define FLPROG_I2C1_SCL PB10
#endif
//=================================================================================================
