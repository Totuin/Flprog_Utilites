#pragma once
#include <Arduino.h>
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_FEATHER_ESP32_V2) 
#define FLPROG_CORE_NAME "Adafruit Feather ESP32 V2"
#define FLPROG_CORE_CODE 44
#define FLPROG_CORE_ADAFRUIT_FEATHER_ESP32_V2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_ITSYBITSY_ESP32) 
#define FLPROG_CORE_NAME "Adafruit ItsyBitsy ESP32"
#define FLPROG_CORE_CODE 45
#define FLPROG_CORE_ADAFRUIT_ITSYBITSY_ESP32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_QTPY_ESP32_PICO) 
#define FLPROG_CORE_NAME "Adafruit QT Py ESP32"
#define FLPROG_CORE_CODE 49
#define FLPROG_CORE_ADAFRUIT_QTPY_ESP32_PICO
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ALKS) 
#define FLPROG_CORE_NAME "ALKS ESP32"
#define FLPROG_CORE_CODE 50
#define FLPROG_CORE_ALKS
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BPI_BIT) 
#define FLPROG_CORE_NAME "BPI-BIT"
#define FLPROG_CORE_CODE 52
#define FLPROG_CORE_BPI_BIT
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_COREESP32) 
#define FLPROG_CORE_NAME "Microduino-CoreESP32"
#define FLPROG_CORE_CODE 60
#define FLPROG_CORE_COREESP32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_D1_MINI32) 
#define FLPROG_CORE_NAME "WEMOS D1 MINI ESP32"
#define FLPROG_CORE_CODE 61
#define FLPROG_CORE_D1_MINI32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_D1_UNO32) 
#define FLPROG_CORE_NAME "WEMOS D1 R32"
#define FLPROG_CORE_CODE 62
#define FLPROG_CORE_D1_UNO32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_DENKY) 
#define FLPROG_CORE_NAME "Denky"
#define FLPROG_CORE_CODE 63
#define FLPROG_CORE_DENKY
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_DFROBOT_FIREBEETLE_2_ESP32E) 
#define FLPROG_CORE_NAME "FireBeetle 2 ESP32-E"
#define FLPROG_CORE_CODE 65
#define FLPROG_CORE_DFROBOT_FIREBEETLE_2_ESP32E
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_DPU_ESP32) 
#define FLPROG_CORE_NAME "DPU ESP32"
#define FLPROG_CORE_CODE 66
#define FLPROG_CORE_DPU_ESP32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_DYDK) 
#define FLPROG_CORE_NAME "Deneyap Kart"
#define FLPROG_CORE_CODE 67
#define FLPROG_CORE_DYDK
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_DYDK1A) 
#define FLPROG_CORE_NAME "Deneyap Kart 1A"
#define FLPROG_CORE_CODE 68
#define FLPROG_CORE_DYDK1A
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_D_DUINO_32) 
#define FLPROG_CORE_NAME "D-duino-32"
#define FLPROG_CORE_CODE 73
#define FLPROG_CORE_D_DUINO_32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP320) 
#define FLPROG_CORE_NAME "Electronic SweetPeas - ESP320"
#define FLPROG_CORE_CODE 74
#define FLPROG_CORE_ESP320
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_DEV) 
#define FLPROG_CORE_NAME "Labplus mPython, FireBeetle-ESP32, SparkFun LoRa Gateway 1-Channel, DOIT ESP32 DEVKIT V1, MagicBit, VintLabs ESP32 Devkit, ESP32 DEV, DOIT ESPduino32, XinaBox CW02, AI Thinker ESP32-CAM, KB32-FT, ESP32 Dev Module, ESP32 Wrover Module"
#define FLPROG_CORE_CODE 85
#define FLPROG_CORE_ESP32_DEV
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_DEVKIT_LIPO) 
#define FLPROG_CORE_NAME "OLIMEX ESP32-DevKit-LiPo"
#define FLPROG_CORE_CODE 97
#define FLPROG_CORE_ESP32_DEVKIT_LIPO
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_EVB) 
#define FLPROG_CORE_NAME "OLIMEX ESP32-EVB"
#define FLPROG_CORE_CODE 98
#define FLPROG_CORE_ESP32_EVB
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_GATEWAY) 
#define FLPROG_CORE_NAME "OLIMEX ESP32-GATEWAY"
#define FLPROG_CORE_CODE 99
#define FLPROG_CORE_ESP32_GATEWAY
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_IOT_REDBOARD) 
#define FLPROG_CORE_NAME "SparkFun ESP32 IoT RedBoard"
#define FLPROG_CORE_CODE 100
#define FLPROG_CORE_ESP32_IOT_REDBOARD
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_MICROMOD) 
#define FLPROG_CORE_NAME "SparkFun ESP32 MicroMod"
#define FLPROG_CORE_CODE 101
#define FLPROG_CORE_ESP32_MICROMOD
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_PICO) 
#define FLPROG_CORE_NAME "KITS ESP32 EDU, CNRS AW2ETH, Turta IoT Node, ESP32 PICO-D4"
#define FLPROG_CORE_CODE 105
#define FLPROG_CORE_ESP32_PICO
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_POE) 
#define FLPROG_CORE_NAME "OLIMEX ESP32-PoE"
#define FLPROG_CORE_CODE 106
#define FLPROG_CORE_ESP32_POE
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_POE_ISO) 
#define FLPROG_CORE_NAME "OLIMEX ESP32-PoE-ISO"
#define FLPROG_CORE_CODE 107
#define FLPROG_CORE_ESP32_POE_ISO
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_THING) 
#define FLPROG_CORE_NAME "SparkFun ESP32 Thing"
#define FLPROG_CORE_CODE 110
#define FLPROG_CORE_ESP32_THING
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_THING_PLUS) 
#define FLPROG_CORE_NAME "SparkFun ESP32 Thing Plus"
#define FLPROG_CORE_CODE 111
#define FLPROG_CORE_ESP32_THING_PLUS
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_THING_PLUS_C) 
#define FLPROG_CORE_NAME "SparkFun ESP32 Thing Plus C"
#define FLPROG_CORE_CODE 112
#define FLPROG_CORE_ESP32_THING_PLUS_C
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_WROOM_DA) 
#define FLPROG_CORE_NAME "ESP32-WROOM-DA Module"
#define FLPROG_CORE_CODE 113
#define FLPROG_CORE_ESP32_WROOM_DA
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_WROVER_KIT) 
#define FLPROG_CORE_NAME "ESP32 Wrover Kit (all versions)"
#define FLPROG_CORE_CODE 114
#define FLPROG_CORE_ESP32_WROVER_KIT
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESPECTRO32) 
#define FLPROG_CORE_NAME "ESPectro32"
#define FLPROG_CORE_CODE 115
#define FLPROG_CORE_ESPECTRO32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESPEA32) 
#define FLPROG_CORE_NAME "ESPea32"
#define FLPROG_CORE_CODE 116
#define FLPROG_CORE_ESPEA32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESPINO32) 
#define FLPROG_CORE_NAME "ThaiEasyElec's ESPino32"
#define FLPROG_CORE_CODE 117
#define FLPROG_CORE_ESPINO32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ET_BOARD) 
#define FLPROG_CORE_NAME "ET-Board"
#define FLPROG_CORE_CODE 118
#define FLPROG_CORE_ET_BOARD
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_FEATHER_ESP32) 
#define FLPROG_CORE_NAME "Adafruit ESP32 Feather, unPhone 7"
#define FLPROG_CORE_CODE 124
#define FLPROG_CORE_FEATHER_ESP32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_FROG_ESP32) 
#define FLPROG_CORE_NAME "Frog Board ESP32"
#define FLPROG_CORE_CODE 127
#define FLPROG_CORE_FROG_ESP32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_HEALTHYPI_4) 
#define FLPROG_CORE_NAME "ProtoCentral HealthyPi 4"
#define FLPROG_CORE_CODE 129
#define FLPROG_CORE_HEALTHYPI_4
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_HONEYLEMON) 
#define FLPROG_CORE_NAME "HONEYLemon"
#define FLPROG_CORE_CODE 130
#define FLPROG_CORE_HONEYLEMON
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_HORNBILL_ESP32_DEV) 
#define FLPROG_CORE_NAME "Hornbill ESP32 Dev"
#define FLPROG_CORE_CODE 131
#define FLPROG_CORE_HORNBILL_ESP32_DEV
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_HORNBILL_ESP32_MINIMA) 
#define FLPROG_CORE_NAME "Hornbill ESP32 Minima"
#define FLPROG_CORE_CODE 132
#define FLPROG_CORE_HORNBILL_ESP32_MINIMA
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_IMBRIOS_LOGSENS_V1P1) 
#define FLPROG_CORE_NAME "IMBRIOS LOGSENS_V1P1"
#define FLPROG_CORE_CODE 133
#define FLPROG_CORE_IMBRIOS_LOGSENS_V1P1
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_INTOROBOT_ESP32_DEV) 
#define FLPROG_CORE_NAME "IntoRobot Fig"
#define FLPROG_CORE_CODE 134
#define FLPROG_CORE_INTOROBOT_ESP32_DEV
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOLIN32) 
#define FLPROG_CORE_NAME "WEMOS LOLIN32"
#define FLPROG_CORE_CODE 136
#define FLPROG_CORE_LOLIN32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOLIN32_LITE) 
#define FLPROG_CORE_NAME "WEMOS LOLIN32 Lite"
#define FLPROG_CORE_CODE 137
#define FLPROG_CORE_LOLIN32_LITE
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOLIN_D32) 
#define FLPROG_CORE_NAME "LOLIN D32"
#define FLPROG_CORE_CODE 139
#define FLPROG_CORE_LOLIN_D32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOLIN_D32_PRO) 
#define FLPROG_CORE_NAME "LOLIN D32 PRO"
#define FLPROG_CORE_CODE 140
#define FLPROG_CORE_LOLIN_D32_PRO
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LION_BIT_DEV_BOARD) 
#define FLPROG_CORE_NAME "Lion:Bit Dev Board"
#define FLPROG_CORE_CODE 144
#define FLPROG_CORE_LION_BIT_DEV_BOARD
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOPY) 
#define FLPROG_CORE_NAME "LoPy"
#define FLPROG_CORE_CODE 145
#define FLPROG_CORE_LOPY
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOPY4) 
#define FLPROG_CORE_NAME "LoPy4"
#define FLPROG_CORE_CODE 146
#define FLPROG_CORE_LOPY4
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5STACK_CORE2) 
#define FLPROG_CORE_NAME "M5Stack-Core2"
#define FLPROG_CORE_CODE 147
#define FLPROG_CORE_M5STACK_CORE2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5STACK_FIRE) 
#define FLPROG_CORE_NAME "M5Stack-FIRE"
#define FLPROG_CORE_CODE 148
#define FLPROG_CORE_M5STACK_FIRE
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5STACK_ATOM) 
#define FLPROG_CORE_NAME "M5Stack-ATOM"
#define FLPROG_CORE_CODE 150
#define FLPROG_CORE_M5STACK_ATOM
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5STACK_COREINK) 
#define FLPROG_CORE_NAME "M5Stack-CoreInk"
#define FLPROG_CORE_CODE 152
#define FLPROG_CORE_M5STACK_COREINK
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5STACK_CORE_ESP32) 
#define FLPROG_CORE_NAME "M5Stack-Core-ESP32"
#define FLPROG_CORE_CODE 153
#define FLPROG_CORE_M5STACK_CORE_ESP32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5STACK_STATION) 
#define FLPROG_CORE_NAME "M5Stack-Station"
#define FLPROG_CORE_CODE 154
#define FLPROG_CORE_M5STACK_STATION
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5STACK_TIMER_CAM) 
#define FLPROG_CORE_NAME "M5Stack-Timer-CAM"
#define FLPROG_CORE_CODE 149
#define FLPROG_CORE_M5STACK_TIMER_CAM
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5STICK_C) 
#define FLPROG_CORE_NAME "M5Stick-C"
#define FLPROG_CORE_CODE 155
#define FLPROG_CORE_M5STICK_C
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_MGBOT_IOTIK32A) 
#define FLPROG_CORE_NAME "MGBOT IOTIK 32A"
#define FLPROG_CORE_CODE 158
#define FLPROG_CORE_MGBOT_IOTIK32A
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_MGBOT_IOTIK32B) 
#define FLPROG_CORE_NAME "MGBOT IOTIK 32B"
#define FLPROG_CORE_CODE 159
#define FLPROG_CORE_MGBOT_IOTIK32B
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_MH_ET_LIVE_ESP32DEVKIT) 
#define FLPROG_CORE_NAME "MH ET LIVE ESP32DevKIT"
#define FLPROG_CORE_CODE 160
#define FLPROG_CORE_MH_ET_LIVE_ESP32DEVKIT
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_MH_ET_LIVE_ESP32MINIKIT) 
#define FLPROG_CORE_NAME "MH ET LIVE ESP32MiniKit"
#define FLPROG_CORE_CODE 161
#define FLPROG_CORE_MH_ET_LIVE_ESP32MINIKIT
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_METRO) 
#define FLPROG_CORE_NAME "Metro ESP-32"
#define FLPROG_CORE_CODE 163
#define FLPROG_CORE_METRO
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_NANO32) 
#define FLPROG_CORE_NAME "Nano32"
#define FLPROG_CORE_CODE 164
#define FLPROG_CORE_NANO32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_NODE32S) 
#define FLPROG_CORE_NAME "Node32s"
#define FLPROG_CORE_CODE 165
#define FLPROG_CORE_NODE32S
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_NODEMCU_32S) 
#define FLPROG_CORE_NAME "NodeMCU-32S"
#define FLPROG_CORE_CODE 166
#define FLPROG_CORE_NODEMCU_32S
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ODROID_ESP32) 
#define FLPROG_CORE_NAME "ODROID ESP32"
#define FLPROG_CORE_CODE 167
#define FLPROG_CORE_ODROID_ESP32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ONEHORSE_ESP32_DEV) 
#define FLPROG_CORE_NAME "Onehorse ESP32 Dev Module"
#define FLPROG_CORE_CODE 168
#define FLPROG_CORE_ONEHORSE_ESP32_DEV
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_OROCA_EDUBOT) 
#define FLPROG_CORE_NAME "OROCA EduBot"
#define FLPROG_CORE_CODE 169
#define FLPROG_CORE_OROCA_EDUBOT
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_PYCOM_GPY) 
#define FLPROG_CORE_NAME "Pycom GPy"
#define FLPROG_CORE_CODE 171
#define FLPROG_CORE_PYCOM_GPY
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_PIRANHA) 
#define FLPROG_CORE_NAME "Piranha ESP-32"
#define FLPROG_CORE_CODE 172
#define FLPROG_CORE_PIRANHA
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_POCKET32) 
#define FLPROG_CORE_NAME "WeMos WiFi&Bluetooth Battery, Dongsen Tech Pocket 32"
#define FLPROG_CORE_CODE 173
#define FLPROG_CORE_POCKET32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_QUANTUM) 
#define FLPROG_CORE_NAME "Noduino Quantum"
#define FLPROG_CORE_CODE 175
#define FLPROG_CORE_QUANTUM
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_SONOFF_DUALR3) 
#define FLPROG_CORE_NAME "Sonoff DUALR3"
#define FLPROG_CORE_CODE 178
#define FLPROG_CORE_SONOFF_DUALR3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TBEAM) 
#define FLPROG_CORE_NAME "T-Beam"
#define FLPROG_CORE_CODE 180
#define FLPROG_CORE_TBEAM
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TINYPICO) 
#define FLPROG_CORE_NAME "UM TinyPICO"
#define FLPROG_CORE_CODE 181
#define FLPROG_CORE_TINYPICO
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TTGO_LORA32) 
#define FLPROG_CORE_NAME "TTGO LoRa32-OLED"
#define FLPROG_CORE_CODE 185
#define FLPROG_CORE_TTGO_LORA32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TTGO_T1) 
#define FLPROG_CORE_NAME "TTGO T1"
#define FLPROG_CORE_CODE 186
#define FLPROG_CORE_TTGO_T1
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TTGO_T7_V13_MINI32) 
#define FLPROG_CORE_NAME "TTGO T7 V13 Mini32"
#define FLPROG_CORE_CODE 187
#define FLPROG_CORE_TTGO_T7_V13_MINI32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TTGO_T7_V14_MINI32) 
#define FLPROG_CORE_NAME "TTGO T7 V14 Mini32"
#define FLPROG_CORE_CODE 188
#define FLPROG_CORE_TTGO_T7_V14_MINI32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TWATCH) 
#define FLPROG_CORE_NAME "TTGO T-Watch"
#define FLPROG_CORE_CODE 189
#define FLPROG_CORE_TWATCH
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TRUEVERIT_ESP32_UNIVERSAL_IOT_DRIVER) 
#define FLPROG_CORE_NAME "Trueverit ESP32 Universal IoT Driver"
#define FLPROG_CORE_CODE 190
#define FLPROG_CORE_TRUEVERIT_ESP32_UNIVERSAL_IOT_DRIVER
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TRUEVERIT_ESP32_UNIVERSAL_IOT_DRIVER_MK_II) 
#define FLPROG_CORE_NAME "Trueverit ESP32 Universal IoT Driver MK II"
#define FLPROG_CORE_CODE 191
#define FLPROG_CORE_TRUEVERIT_ESP32_UNIVERSAL_IOT_DRIVER_MK_II
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_UBLOX_NINA_W10) 
#define FLPROG_CORE_NAME "u-blox NINA-W10 series (ESP32)"
#define FLPROG_CORE_CODE 192
#define FLPROG_CORE_UBLOX_NINA_W10
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_WATCHY) 
#define FLPROG_CORE_NAME "Watchy"
#define FLPROG_CORE_CODE 196
#define FLPROG_CORE_WATCHY
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_WESP32) 
#define FLPROG_CORE_NAME "Silicognition wESP32"
#define FLPROG_CORE_CODE 197
#define FLPROG_CORE_WESP32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_WIDORA_AIR) 
#define FLPROG_CORE_NAME "Widora AIR"
#define FLPROG_CORE_CODE 198
#define FLPROG_CORE_WIDORA_AIR
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_WIPY3) 
#define FLPROG_CORE_NAME "WIPY3"
#define FLPROG_CORE_CODE 199
#define FLPROG_CORE_WIPY3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_WT32_ETH01) 
#define FLPROG_CORE_NAME "WT32-ETH01 Ethernet Module"
#define FLPROG_CORE_CODE 200
#define FLPROG_CORE_WT32_ETH01
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_WIFIDUINO32) 
#define FLPROG_CORE_NAME "WiFiduino32"
#define FLPROG_CORE_CODE 203
#define FLPROG_CORE_WIFIDUINO32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_CONNAXIO_ESPOIR) 
#define FLPROG_CORE_NAME "Connaxio's Espoir"
#define FLPROG_CORE_CODE 206
#define FLPROG_CORE_CONNAXIO_ESPOIR
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32VN_IOT_UNO) 
#define FLPROG_CORE_NAME "ESP32vn IoT Uno"
#define FLPROG_CORE_CODE 207
#define FLPROG_CORE_ESP32VN_IOT_UNO
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_FM_DEVKIT) 
#define FLPROG_CORE_NAME "ESP32 FM DevKit"
#define FLPROG_CORE_CODE 208
#define FLPROG_CORE_FM_DEVKIT
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_HELTEC_WIFI_KIT_32) 
#define FLPROG_CORE_NAME "Heltec WiFi Kit 32"
#define FLPROG_CORE_CODE 210
#define FLPROG_CORE_HELTEC_WIFI_KIT_32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_HELTEC_WIFI_LORA_32) 
#define FLPROG_CORE_NAME "Heltec WiFi LoRa 32"
#define FLPROG_CORE_CODE 212
#define FLPROG_CORE_HELTEC_WIFI_LORA_32
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_HELTEC_WIFI_LORA_32_V2) 
#define FLPROG_CORE_NAME "Heltec WiFi LoRa 32(V2)"
#define FLPROG_CORE_CODE 213
#define FLPROG_CORE_HELTEC_WIFI_LORA_32_V2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_HELTEC_WIRELESS_STICK) 
#define FLPROG_CORE_NAME "Heltec Wireless Stick"
#define FLPROG_CORE_CODE 214
#define FLPROG_CORE_HELTEC_WIRELESS_STICK
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_HELTEC_WIRELESS_STICK_LITE) 
#define FLPROG_CORE_NAME "Heltec Wireless Stick Lite"
#define FLPROG_CORE_CODE 215
#define FLPROG_CORE_HELTEC_WIRELESS_STICK_LITE
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_OPENKB) 
#define FLPROG_CORE_NAME "INEX OpenKB"
#define FLPROG_CORE_CODE 216
#define FLPROG_CORE_OPENKB
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ROBOHEART_HERCULES) 
#define FLPROG_CORE_NAME "RoboHeart Hercules"
#define FLPROG_CORE_CODE 217
#define FLPROG_CORE_ROBOHEART_HERCULES
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_SENSESIOT_WEIZEN) 
#define FLPROG_CORE_NAME "Senses's WEIZEN"
#define FLPROG_CORE_CODE 218
#define FLPROG_CORE_SENSESIOT_WEIZEN
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_UPESY_WROOM) 
#define FLPROG_CORE_NAME "uPesy ESP32 Wroom DevKit"
#define FLPROG_CORE_CODE 219
#define FLPROG_CORE_UPESY_WROOM
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_UPESY_WROVER) 
#define FLPROG_CORE_NAME "uPesy ESP32 Wrover DevKit"
#define FLPROG_CORE_CODE 220
#define FLPROG_CORE_UPESY_WROVER
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_BASIC

#define FLPROG_I2C0_SDA 21
#define FLPROG_I2C0_SCL 22
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_QTPY_ESP32C3) 
#define FLPROG_CORE_NAME "Adafruit QT Py ESP32-C3"
#define FLPROG_CORE_CODE 46
#define FLPROG_CORE_ADAFRUIT_QTPY_ESP32C3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_AIRM2M_CORE_ESP32C3) 
#define FLPROG_CORE_NAME "AirM2M_CORE_ESP32C3"
#define FLPROG_CORE_CODE 51
#define FLPROG_CORE_AIRM2M_CORE_ESP32C3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BEE_MOTION_MINI) 
#define FLPROG_CORE_NAME "Bee Motion Mini"
#define FLPROG_CORE_CODE 56
#define FLPROG_CORE_BEE_MOTION_MINI
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_DYG) 
#define FLPROG_CORE_NAME "Deneyap Kart G"
#define FLPROG_CORE_CODE 70
#define FLPROG_CORE_DYG
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32C3_DEV) 
#define FLPROG_CORE_NAME "ESP32C3 Dev Module, ESP32C3 DEV"
#define FLPROG_CORE_CODE 76
#define FLPROG_CORE_ESP32C3_DEV
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32C3_M1_I_KIT) 
#define FLPROG_CORE_NAME "ESP-C3-M1-I-Kit"
#define FLPROG_CORE_CODE 77
#define FLPROG_CORE_ESP32C3_M1_I_KIT
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOLIN_C3_MINI) 
#define FLPROG_CORE_NAME "LOLIN C3 Mini"
#define FLPROG_CORE_CODE 138
#define FLPROG_CORE_LOLIN_C3_MINI
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TTGO_T_OI_PLUS_DEV) 
#define FLPROG_CORE_NAME "TTGO T-OI PLUS RISC-V ESP32-C3"
#define FLPROG_CORE_CODE 184
#define FLPROG_CORE_TTGO_T_OI_PLUS_DEV
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_VALTRACK_V4_MFW_ESP32_C3) 
#define FLPROG_CORE_NAME "VALTRACK_V4_MFW_ESP32_C3"
#define FLPROG_CORE_CODE 194
#define FLPROG_CORE_VALTRACK_V4_MFW_ESP32_C3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_VALTRACK_V4_VTS_ESP32_C3) 
#define FLPROG_CORE_NAME "VALTRACK_V4_VTS_ESP32_C3"
#define FLPROG_CORE_CODE 195
#define FLPROG_CORE_VALTRACK_V4_VTS_ESP32_C3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_WIFIDUINOV2) 
#define FLPROG_CORE_NAME "WiFiduinoV2"
#define FLPROG_CORE_CODE 202
#define FLPROG_CORE_WIFIDUINOV2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_XIAO_ESP32C3) 
#define FLPROG_CORE_NAME "XIAO_ESP32C3"
#define FLPROG_CORE_CODE 204
#define FLPROG_CORE_XIAO_ESP32C3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_C3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S2) 
#define FLPROG_CORE_NAME "Adafruit Feather ESP32-S2"
#define FLPROG_CORE_CODE 37
#define FLPROG_CORE_ADAFRUIT_FEATHER_ESP32S2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S2_REVTFT) 
#define FLPROG_CORE_NAME "Adafruit Feather ESP32-S2 Reverse TFT"
#define FLPROG_CORE_CODE 38
#define FLPROG_CORE_ADAFRUIT_FEATHER_ESP32S2_REVTFT
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S2_TFT) 
#define FLPROG_CORE_NAME "Adafruit Feather ESP32-S2 TFT"
#define FLPROG_CORE_CODE 39
#define FLPROG_CORE_ADAFRUIT_FEATHER_ESP32S2_TFT
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_QTPY_ESP32S2) 
#define FLPROG_CORE_NAME "Adafruit QT Py ESP32-S2"
#define FLPROG_CORE_CODE 47
#define FLPROG_CORE_ADAFRUIT_QTPY_ESP32S2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BEE_MOTION) 
#define FLPROG_CORE_NAME "Bee Motion"
#define FLPROG_CORE_CODE 55
#define FLPROG_CORE_BEE_MOTION
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_DEPARTMENT_OF_ALCHEMY_MINIMAIN_ESP32S2) 
#define FLPROG_CORE_NAME "Department of Alchemy MiniMain ESP32-S2"
#define FLPROG_CORE_CODE 64
#define FLPROG_CORE_DEPARTMENT_OF_ALCHEMY_MINIMAIN_ESP32S2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_DYM) 
#define FLPROG_CORE_NAME "Deneyap Mini"
#define FLPROG_CORE_CODE 71
#define FLPROG_CORE_DYM
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_DYMV2) 
#define FLPROG_CORE_NAME "Deneyap Mini v2"
#define FLPROG_CORE_CODE 72
#define FLPROG_CORE_DYMV2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32S2_DEV) 
#define FLPROG_CORE_NAME "ESP32S2 Dev Module"
#define FLPROG_CORE_CODE 78
#define FLPROG_CORE_ESP32S2_DEV
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32S2_THING_PLUS) 
#define FLPROG_CORE_NAME "SparkFun ESP32-S2 Thing Plus"
#define FLPROG_CORE_CODE 79
#define FLPROG_CORE_ESP32S2_THING_PLUS
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32S2_USB) 
#define FLPROG_CORE_NAME "ESP32S2 Native USB"
#define FLPROG_CORE_CODE 80
#define FLPROG_CORE_ESP32S2_USB
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_FEATHERS2) 
#define FLPROG_CORE_NAME "UM FeatherS2"
#define FLPROG_CORE_CODE 120
#define FLPROG_CORE_FEATHERS2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_FEATHERS2NEO) 
#define FLPROG_CORE_NAME "UM FeatherS2 Neo"
#define FLPROG_CORE_CODE 121
#define FLPROG_CORE_FEATHERS2NEO
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_FRANZININHO_WIFI) 
#define FLPROG_CORE_NAME "Franzininho WiFi"
#define FLPROG_CORE_CODE 125
#define FLPROG_CORE_FRANZININHO_WIFI
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_FRANZININHO_WIFI_MSC) 
#define FLPROG_CORE_NAME "Franzininho WiFi MSC"
#define FLPROG_CORE_CODE 126
#define FLPROG_CORE_FRANZININHO_WIFI_MSC
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_FUNHOUSE_ESP32S2) 
#define FLPROG_CORE_NAME "Adafruit FunHouse"
#define FLPROG_CORE_CODE 128
#define FLPROG_CORE_FUNHOUSE_ESP32S2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOLIN_S2_MINI) 
#define FLPROG_CORE_NAME "LOLIN S2 Mini"
#define FLPROG_CORE_CODE 141
#define FLPROG_CORE_LOLIN_S2_MINI
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOLIN_S2_PICO) 
#define FLPROG_CORE_NAME "LOLIN S2 PICO"
#define FLPROG_CORE_CODE 142
#define FLPROG_CORE_LOLIN_S2_PICO
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_MAGTAG29_ESP32S2) 
#define FLPROG_CORE_NAME "MAGTAG29 ESP32S2"
#define FLPROG_CORE_CODE 156
#define FLPROG_CORE_MAGTAG29_ESP32S2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_METRO_ESP32S2) 
#define FLPROG_CORE_NAME "Adafruit Metro ESP32-S2"
#define FLPROG_CORE_CODE 157
#define FLPROG_CORE_METRO_ESP32S2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_MICROS2) 
#define FLPROG_CORE_NAME "microS2"
#define FLPROG_CORE_CODE 162
#define FLPROG_CORE_MICROS2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_RMP) 
#define FLPROG_CORE_NAME "UM RMP"
#define FLPROG_CORE_CODE 177
#define FLPROG_CORE_RMP
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TINYS2) 
#define FLPROG_CORE_NAME "UM TinyS2"
#define FLPROG_CORE_CODE 182
#define FLPROG_CORE_TINYS2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ATMEGAZERO_ESP32S2) 
#define FLPROG_CORE_NAME "ATMegaZero ESP32-S2"
#define FLPROG_CORE_CODE 205
#define FLPROG_CORE_ATMEGAZERO_ESP32S2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S2
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S3) 
#define FLPROG_CORE_NAME "Adafruit Feather ESP32-S3 2MB PSRAM"
#define FLPROG_CORE_CODE 40
#define FLPROG_CORE_ADAFRUIT_FEATHER_ESP32S3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S3_NOPSRAM) 
#define FLPROG_CORE_NAME "Adafruit Feather ESP32-S3 No PSRAM"
#define FLPROG_CORE_CODE 41
#define FLPROG_CORE_ADAFRUIT_FEATHER_ESP32S3_NOPSRAM
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S3_REVTFT) 
#define FLPROG_CORE_NAME "Adafruit Feather ESP32-S3 Reverse TFT"
#define FLPROG_CORE_CODE 42
#define FLPROG_CORE_ADAFRUIT_FEATHER_ESP32S3_REVTFT
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S3_TFT) 
#define FLPROG_CORE_NAME "Adafruit Feather ESP32-S3 TFT"
#define FLPROG_CORE_CODE 43
#define FLPROG_CORE_ADAFRUIT_FEATHER_ESP32S3_TFT
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ADAFRUIT_QTPY_ESP32S3_NOPSRAM) 
#define FLPROG_CORE_NAME "Adafruit QT Py ESP32-S3 No PSRAM"
#define FLPROG_CORE_CODE 48
#define FLPROG_CORE_ADAFRUIT_QTPY_ESP32S3_NOPSRAM
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BPI_LEAF_S3) 
#define FLPROG_CORE_NAME "BPI-Leaf-S3"
#define FLPROG_CORE_CODE 53
#define FLPROG_CORE_BPI_LEAF_S3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BEEMOTIONS3) 
#define FLPROG_CORE_NAME "Bee Motion S3"
#define FLPROG_CORE_CODE 54
#define FLPROG_CORE_BEEMOTIONS3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_BEE_S3) 
#define FLPROG_CORE_NAME "Bee S3"
#define FLPROG_CORE_CODE 57
#define FLPROG_CORE_BEE_S3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_CRABIK_SLOT_ESP32_S3) 
#define FLPROG_CORE_NAME "Crabik Slot ESP32-S3"
#define FLPROG_CORE_CODE 58
#define FLPROG_CORE_CRABIK_SLOT_ESP32_S3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_CYTRON_MAKER_FEATHER_AIOT_S3) 
#define FLPROG_CORE_NAME "Cytron Maker Feather AIoT S3"
#define FLPROG_CORE_CODE 59
#define FLPROG_CORE_CYTRON_MAKER_FEATHER_AIOT_S3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_DYDK1AV2) 
#define FLPROG_CORE_NAME "Deneyap Kart 1A v2"
#define FLPROG_CORE_CODE 69
#define FLPROG_CORE_DYDK1AV2
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32S3_CAM_LCD) 
#define FLPROG_CORE_NAME "ESP32S3 CAM LCD"
#define FLPROG_CORE_CODE 81
#define FLPROG_CORE_ESP32S3_CAM_LCD
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32S3_DEV) 
#define FLPROG_CORE_NAME "ESP32S3 Dev Module, ESP32S3 DEV"
#define FLPROG_CORE_CODE 82
#define FLPROG_CORE_ESP32S3_DEV
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_S3_BOX) 
#define FLPROG_CORE_NAME "ESP32-S3-Box"
#define FLPROG_CORE_CODE 108
#define FLPROG_CORE_ESP32_S3_BOX
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ESP32_S3_USB_OTG) 
#define FLPROG_CORE_NAME "ESP32-S3-USB-OTG"
#define FLPROG_CORE_CODE 109
#define FLPROG_CORE_ESP32_S3_USB_OTG
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_EDGEBOX_ESP_100) 
#define FLPROG_CORE_NAME "Edgebox-ESP-100"
#define FLPROG_CORE_CODE 119
#define FLPROG_CORE_EDGEBOX_ESP_100
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_FEATHERS3) 
#define FLPROG_CORE_NAME "UM FeatherS3"
#define FLPROG_CORE_CODE 122
#define FLPROG_CORE_FEATHERS3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LILYGO_T_DISPLAY_S3) 
#define FLPROG_CORE_NAME "LilyGo T-Display-S3"
#define FLPROG_CORE_CODE 135
#define FLPROG_CORE_LILYGO_T_DISPLAY_S3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_LOLIN_S3) 
#define FLPROG_CORE_NAME "LOLIN S3"
#define FLPROG_CORE_CODE 143
#define FLPROG_CORE_LOLIN_S3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_M5STACK_ATOMS3) 
#define FLPROG_CORE_NAME "M5Stack-ATOMS3"
#define FLPROG_CORE_CODE 151
#define FLPROG_CORE_M5STACK_ATOMS3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_PROS3) 
#define FLPROG_CORE_NAME "UM PROS3"
#define FLPROG_CORE_CODE 170
#define FLPROG_CORE_PROS3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_REDPILL_ESP32S3) 
#define FLPROG_CORE_NAME "RedPill(+) ESP32-S3"
#define FLPROG_CORE_CODE 176
#define FLPROG_CORE_REDPILL_ESP32S3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TAMC_TERMOD_S3) 
#define FLPROG_CORE_NAME "TAMC Termod S3"
#define FLPROG_CORE_CODE 179
#define FLPROG_CORE_TAMC_TERMOD_S3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_TINYS3) 
#define FLPROG_CORE_NAME "UM TinyS3"
#define FLPROG_CORE_CODE 183
#define FLPROG_CORE_TINYS3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_UBLOX_NORA_W10) 
#define FLPROG_CORE_NAME "u-blox NORA-W10 series (ESP32-S3)"
#define FLPROG_CORE_CODE 193
#define FLPROG_CORE_UBLOX_NORA_W10
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_WIFIDUINO32S3) 
#define FLPROG_CORE_NAME "WiFiduino32S3"
#define FLPROG_CORE_CODE 201
#define FLPROG_CORE_WIFIDUINO32S3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_HELTEC_WIFI_32_LORA_V3) 
#define FLPROG_CORE_NAME "Heltec WiFi LoRa 32(V3) / Wireless shell(V3) / Wireless stick lite (V3)"
#define FLPROG_CORE_CODE 209
#define FLPROG_CORE_HELTEC_WIFI_32_LORA_V3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_HELTEC_WIFI_KIT_32_V3) 
#define FLPROG_CORE_NAME "Heltec WiFi Kit 32(V3)"
#define FLPROG_CORE_CODE 211
#define FLPROG_CORE_HELTEC_WIFI_KIT_32_V3
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_UNPHONE8) 
#define FLPROG_CORE_NAME "unPhone 8"
#define FLPROG_CORE_CODE 221
#define FLPROG_CORE_UNPHONE8
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_UNPHONE9) 
#define FLPROG_CORE_NAME "unPhone 9"
#define FLPROG_CORE_CODE 222
#define FLPROG_CORE_UNPHONE9
#define FLPROG_CORE_ESP                                  
#define FLPROG_CORE_ESP32 
#define FLPROG_I2CSPEED 400000UL
#define FLPROG_HAS_UART0
#define FLPROG_HAS_I2C0
#define FLPROG_CORE_ESP32_S3
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
