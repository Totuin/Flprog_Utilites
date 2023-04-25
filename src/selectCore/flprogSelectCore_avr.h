#pragma once
#include <Arduino.h>
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_MEGA) 
#define FLPROG_CORE_NAME "AVR MEGA"
#define FLPROG_CORE_CODE 22
#define FLPROG_CORE_AVR_MEGA
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA1280
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_ADK) 
#define FLPROG_CORE_NAME "Arduino Mega ADK"
#define FLPROG_CORE_CODE 9
#define FLPROG_CORE_AVR_ADK
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA2560
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_MEGA2560) 
#define FLPROG_CORE_NAME "AVR MEGA2560"
#define FLPROG_CORE_CODE 24
#define FLPROG_CORE_AVR_MEGA2560
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA2560
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_BT) 
#define FLPROG_CORE_NAME "Arduino BT"
#define FLPROG_CORE_CODE 10
#define FLPROG_CORE_AVR_BT
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_DUEMILANOVE) 
#define FLPROG_CORE_NAME "Arduino Duemilanove or Diecimila"
#define FLPROG_CORE_CODE 12
#define FLPROG_CORE_AVR_DUEMILANOVE
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_ETHERNET) 
#define FLPROG_CORE_NAME "Arduino Ethernet"
#define FLPROG_CORE_CODE 2
#define FLPROG_CORE_AVR_ETHERNET
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_FIO) 
#define FLPROG_CORE_NAME "Arduino Fio"
#define FLPROG_CORE_CODE 14
#define FLPROG_CORE_AVR_FIO
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_LILYPAD) 
#define FLPROG_CORE_NAME "LilyPad Arduino"
#define FLPROG_CORE_CODE 19
#define FLPROG_CORE_AVR_LILYPAD
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_MINI) 
#define FLPROG_CORE_NAME "Arduino Mini"
#define FLPROG_CORE_CODE 26
#define FLPROG_CORE_AVR_MINI
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_NANO) 
#define FLPROG_CORE_NAME "Arduino Nano"
#define FLPROG_CORE_CODE 27
#define FLPROG_CORE_AVR_NANO
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_NG) 
#define FLPROG_CORE_NAME "Arduino NG or older"
#define FLPROG_CORE_CODE 28
#define FLPROG_CORE_AVR_NG
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_PRO) 
#define FLPROG_CORE_NAME "Arduino Pro or Pro Mini"
#define FLPROG_CORE_CODE 29
#define FLPROG_CORE_AVR_PRO
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_UNO) 
#define FLPROG_CORE_NAME "Arduino Uno, Arduino Uno Mini"
#define FLPROG_CORE_CODE 32
#define FLPROG_CORE_AVR_UNO
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_UNO_WIFI_DEV_ED) 
#define FLPROG_CORE_NAME "Arduino Uno WiFi"
#define FLPROG_CORE_CODE 34
#define FLPROG_CORE_AVR_UNO_WIFI_DEV_ED
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA328P
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_CIRCUITPLAY) 
#define FLPROG_CORE_NAME "Adafruit Circuit Playground"
#define FLPROG_CORE_CODE 11
#define FLPROG_CORE_AVR_CIRCUITPLAY
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_ESPLORA) 
#define FLPROG_CORE_NAME "Arduino Esplora"
#define FLPROG_CORE_CODE 13
#define FLPROG_CORE_AVR_ESPLORA
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_INDUSTRIAL101) 
#define FLPROG_CORE_NAME "Arduino Industrial 101"
#define FLPROG_CORE_CODE 16
#define FLPROG_CORE_AVR_INDUSTRIAL101
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_LEONARDO) 
#define FLPROG_CORE_NAME "Arduino Leonardo"
#define FLPROG_CORE_CODE 17
#define FLPROG_CORE_AVR_LEONARDO
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_LEONARDO_ETH) 
#define FLPROG_CORE_NAME "Arduino Leonardo ETH"
#define FLPROG_CORE_CODE 18
#define FLPROG_CORE_AVR_LEONARDO_ETH
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_LILYPAD_USB) 
#define FLPROG_CORE_NAME "LilyPad Arduino USB"
#define FLPROG_CORE_CODE 20
#define FLPROG_CORE_AVR_LILYPAD_USB
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_LININO_ONE) 
#define FLPROG_CORE_NAME "Linino One"
#define FLPROG_CORE_CODE 21
#define FLPROG_CORE_AVR_LININO_ONE
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_MICRO) 
#define FLPROG_CORE_NAME "Arduino Micro"
#define FLPROG_CORE_CODE 25
#define FLPROG_CORE_AVR_MICRO
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_ROBOT_CONTROL) 
#define FLPROG_CORE_NAME "Arduino Robot Control"
#define FLPROG_CORE_CODE 30
#define FLPROG_CORE_AVR_ROBOT_CONTROL
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_ROBOT_MOTOR) 
#define FLPROG_CORE_NAME "Arduino Robot Motor"
#define FLPROG_CORE_CODE 31
#define FLPROG_CORE_AVR_ROBOT_MOTOR
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_YUN) 
#define FLPROG_CORE_NAME "Arduino Yún"
#define FLPROG_CORE_CODE 35
#define FLPROG_CORE_AVR_YUN
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_YUNMINI) 
#define FLPROG_CORE_NAME "Arduino Yún Mini"
#define FLPROG_CORE_CODE 36
#define FLPROG_CORE_AVR_YUNMINI
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATMEGA32U4
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AVR_GEMMA) 
#define FLPROG_CORE_NAME "Arduino Gemma"
#define FLPROG_CORE_CODE 15
#define FLPROG_CORE_AVR_GEMMA
#define FLPROG_CORE_AVR
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_CORE_AVR_ATTINY85
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
