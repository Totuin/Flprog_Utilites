#pragma once
#include <Arduino.h>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//							 32.Контроллеры программной среды (D) STM32F4
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACK_F407VE) //====BOARD (D)Black F407VE-->DevEBox STM32F407VET6 Mini
#define FLPROG_CORE_CODE 131                                    //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)Black F407VE"                      //--Наименование платы;
#define FLPROG_CORE_DEVEBOX_STM32F407VET6_D                     //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                       //--Идентификатор программной среды                                 //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10

#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_DEVEBOX_STM32F407V_H_) //====BOARD (M)Generic STM32F407V series-->DevEBox STM32F407VET6 Mini;
#define FLPROG_CORE_CODE 132                                            //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(M)DevEBox STM32F407VET6 Mini++"              //--Наименование платы;
#define FLPROG_CORE_DEVEBOX_STM32F407VET6_M                             //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                               //--Идентификатор программной среды                                        //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10

#define FLPROG_NEED_CREATE_UART2
#define FLPROG_UART2_RX PA3
#define FLPROG_UART2_TX PA2

#define FLPROG_NEED_CREATE_UART3
#define FLPROG_UART3_RX PD9
#define FLPROG_UART3_TX PD8

#define FLPROG_NEED_CREATE_UART4
#define FLPROG_UART4_RX PC11
#define FLPROG_UART4_TX PC10

#define FLPROG_NEED_CREATE_UART5
#define FLPROG_UART5_RX PD2
#define FLPROG_UART5_TX PC12

#define FLPROG_NEED_CREATE_UART6
#define FLPROG_UART6_RX PC7
#define FLPROG_UART6_TX PC6
#endif
//=================================================================================================
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACK_F407VG) //====BOARD (D)Black F407VG-->STM32F4xx_F4VE
#define FLPROG_CORE_CODE 133                                    //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)STM32_F4VE_V2.0 BLACK STM32F4XX "  //--Наименование платы;
#define FLPROG_CORE_STM32F4XX_F4VE_D                            //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                       //--Идентификатор программной среды                              //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10

#define FLPROG_NEED_CREATE_UART2
#define FLPROG_UART2_RX PA3
#define FLPROG_UART2_TX PA2

#define FLPROG_NEED_CREATE_UART3
#define FLPROG_UART3_RX PD9
#define FLPROG_UART3_TX PD8

#define FLPROG_NEED_CREATE_UART4
#define FLPROG_UART4_RX PC11
#define FLPROG_UART4_TX PC10

#define FLPROG_NEED_CREATE_UART5
#define FLPROG_UART5_RX PD2
#define FLPROG_UART5_TX PC12

#define FLPROG_NEED_CREATE_UART6
#define FLPROG_UART6_RX PC7
#define FLPROG_UART6_TX PC6

#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_F407V_H_) //====Board (M)_BOARD_GENERIC_F407V_H_-->STM32F4xx_F4VE;
#define FLPROG_CORE_CODE 134                                       //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(M)STM32_F4VE_V2.0 BLACK STM32F4XX"      //--Наименование платы;
#define FLPROG_CORE_STM32F4XX_F4VE_M                               //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                          //--Идентификатор программной среды                                    //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10

#define FLPROG_NEED_CREATE_UART2
#define FLPROG_UART2_RX PA3
#define FLPROG_UART2_TX PA2

#define FLPROG_NEED_CREATE_UART3
#define FLPROG_UART3_RX PD9
#define FLPROG_UART3_TX PD8

#define FLPROG_NEED_CREATE_UART4
#define FLPROG_UART4_RX PC11
#define FLPROG_UART4_TX PC10

#define FLPROG_NEED_CREATE_UART5
#define FLPROG_UART5_RX PD2
#define FLPROG_UART5_TX PC12

#define FLPROG_NEED_CREATE_UART6
#define FLPROG_UART6_RX PC7
#define FLPROG_UART6_TX PC6
#endif
//=================================================================================================

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_F407VETX) //====Board (M)_GENERIC_F407VETX-->STM32F4xx_F4VE;
#define FLPROG_CORE_CODE 134                                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "GENERIC_F407VETX"                         //--Наименование платы;
#define FLPROG_CORE_STM32_GENERIC_F407VETX                          //--Идентификатор типа платы;
#define FLPROG_CORE_STM32                                           //--Идентификатор программной среды                                  //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10

#define FLPROG_NEED_CREATE_UART1
#define FLPROG_UART1_RX PA10
#define FLPROG_UART1_TX PA9

#define FLPROG_NEED_CREATE_UART2
#define FLPROG_UART2_RX PA3
#define FLPROG_UART2_TX PA2

#define FLPROG_NEED_CREATE_UART3
#define FLPROG_UART3_RX PD9
#define FLPROG_UART3_TX PD8

#define FLPROG_NEED_CREATE_UART4
#define FLPROG_UART4_RX PC11
#define FLPROG_UART4_TX PC10

#define FLPROG_NEED_CREATE_UART5
#define FLPROG_UART5_RX PD2
#define FLPROG_UART5_TX PC12

#define FLPROG_NEED_CREATE_UART6
#define FLPROG_UART6_RX PC7
#define FLPROG_UART6_TX PC6
#endif

//=================================================================================================

#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_GENERIC_F407ZETX) //====Board GENERIC_F407ZETX
#define FLPROG_CORE_CODE 134                                       //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "GENERIC_F407ZETX"
#define FLPROG_CORE_STM32_GENERIC_F407ZETX
#define FLPROG_CORE_STM32
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB11
#define FLPROG_I2C1_SCL PB10

#define FLPROG_NEED_CREATE_UART1
#define FLPROG_UART1_RX PA10
#define FLPROG_UART1_TX PA9

#define FLPROG_NEED_CREATE_UART2
#define FLPROG_UART2_RX PA3
#define FLPROG_UART2_TX PA2

#define FLPROG_NEED_CREATE_UART3
#define FLPROG_UART3_RX PD9
#define FLPROG_UART3_TX PD8

#define FLPROG_NEED_CREATE_UART4  
#define FLPROG_UART4_RX PC11
#define FLPROG_UART4_TX PC10

#define FLPROG_NEED_CREATE_UART5
#define FLPROG_UART5_RX PD2
#define FLPROG_UART5_TX PC12

#define FLPROG_NEED_CREATE_UART6
#define FLPROG_UART6_RX PC7
#define FLPROG_UART6_TX PC6
#endif

//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACKPILL_F401CC) //====КОНТРОЛЛЕР (D)BlackPill F401CC
#define FLPROG_CORE_CODE 135                                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)BlackPill F401CC"                      //--Наименование платы;
#define FLPROG_CORE_D_BLACKPILL_F401CC                              //--Идентификатор типа платы [variant.STM32F4xx/_F401C];
#define FLPROG_CORE_STM32                                           //--Идентификатор программной среды                                    //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB3
#define FLPROG_I2C1_SCL PB10

#define FLPROG_NEED_CREATE_UART2
#define FLPROG_UART2_RX PA3
#define FLPROG_UART2_TX PA2

#define FLPROG_NEED_CREATE_UART6
#define FLPROG_UART6_RX PA12
#define FLPROG_UART6_TX PA11
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BLACKPILL_F411CE) //====КОНТРОЛЛЕР (D)BlackPill F411CE
#define FLPROG_CORE_CODE 136                                        //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)BlackPill F411CE"                      //--Наименование платы;
#define FLPROG_CORE_D_BLACKPILL_F411CE                              //--Идентификатор типа платы [variant.STM32F4xx/_F411C];
#define FLPROG_CORE_STM32                                           //--Идентификатор программной среды                                    //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB3
#define FLPROG_I2C1_SCL PB10

#define FLPROG_NEED_CREATE_UART2
#define FLPROG_UART2_RX PA3
#define FLPROG_UART2_TX PA2

#define FLPROG_NEED_CREATE_UART6
#define FLPROG_UART6_RX PA12
#define FLPROG_UART6_TX PA11
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && (defined(ARDUINO_GENERIC_F401CBUX) || defined(ARDUINO_GENERIC_F401CCUX) || defined(ARDUINO_GENERIC_F401CBYX) || \
                                   defined(ARDUINO_GENERIC_F401CYXX) || defined(ARDUINO_GENERIC_F401CDUX) || defined(ARDUINO_GENERIC_F401CEUX) || \
                                   defined(ARDUINO_GENERIC_F401CDYX) || defined(ARDUINO_GENERIC_F401CEYX) || defined(ARDUINO_GENERIC_F401CCFX))
#define FLPROG_CORE_CODE 137                  //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)GENERIC F401CXX" //--Наименование платы;
#define FLPROG_CORE_D_GENERIC_F401CXXX        //--Идентификатор типа платы [variant.STM32F4xx/_F411C];
#define FLPROG_CORE_STM32                     //--Идентификатор программной среды              //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB3
#define FLPROG_I2C1_SCL PB10

#define FLPROG_NEED_CREATE_UART2
#define FLPROG_UART2_RX PA3
#define FLPROG_UART2_TX PA2

#define FLPROG_NEED_CREATE_UART6
#define FLPROG_UART6_RX PA12
#define FLPROG_UART6_TX PA11
#endif
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && (defined(ARDUINO_GENERIC_F411CCUX) || defined(ARDUINO_GENERIC_F411CCYX) || \
                                   defined(ARDUINO_GENERIC_F411CEUX) || defined(ARDUINO_GENERIC_F411CEYX))
#define FLPROG_CORE_CODE 138                  //--Идентификатор выбора платы c кодом платы;
#define FLPROG_CORE_NAME "(D)GENERIC F411CXX" //--Наименование платы;
#define FLPROG_CORE_D_GENERIC_F411CXXX        //--Идентификатор типа платы [variant.STM32F4xx/_F411C];
#define FLPROG_CORE_STM32                     //--Идентификатор программной среды             //--Идентификатор программной среды
#define FLPROG_CORE_STM

#define FLPROG_I2CSPEED 400000UL
#define FLPROG_I2C1_SDA PB3
#define FLPROG_I2C1_SCL PB10

#define FLPROG_NEED_CREATE_UART2
#define FLPROG_UART2_RX PA3
#define FLPROG_UART2_TX PA2

#define FLPROG_NEED_CREATE_UART6
#define FLPROG_UART6_RX PA12
#define FLPROG_UART6_TX PA11
#endif
//=================================================================================================
