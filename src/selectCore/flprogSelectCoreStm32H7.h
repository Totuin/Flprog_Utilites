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

#define FLPROG_NEED_CREATE_UART7
#define FLPROG_UART7_RX PC9
#define FLPROG_UART7_TX PC8

#define FLPROG_NEED_CREATE_UART8
#define FLPROG_UART8_RX PC13
#define FLPROG_UART8_TX PC12

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

#define FLPROG_NEED_CREATE_UART7
#define FLPROG_UART7_RX PC9
#define FLPROG_UART7_TX PC8

#define FLPROG_NEED_CREATE_UART8
#define FLPROG_UART8_RX PC13
#define FLPROG_UART8_TX PC12
#endif
//=================================================================================================
