#pragma once
#include <Arduino.h>

#define FLPROG_SENSOR_NOT_ERROR 0
#define FLPROG_SENSOR_NOT_READY_ERROR 1
#define FLPROG_SENSOR_DEVICE_NOT_FOUND_ERROR 2
#define FLPROG_SENSOR_DEVICE_NOT_CORRECT_BUS_NUMBER_ERROR 65
#define FLPROG_SENSOR_DEVICE_NOT_CORRECT_DEVICE_ADDRESS_ERROR 61
#define FLPROG_SENSOR_DEVICE_NOT_DEFINED_ERROR 5
#define FLPROG_SENSOR_DEVICE_NOT_CORRECT_DATA_ERROR 6
#define FLPROG_SENSOR_CRC_ERROR 72

#define FLPROG_SENSOR_WAITING_READ_STEP 0
#define FLPROG_SENSOR_WAITING_DELAY 1

//-------------------------------------------------------------------------------------------------
//								SAMX (DUE)
// Как-то необычно идентифицируется DUE - наверное можно иначе?
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(UART_CLASS)
#define FLPROG_CORE_CODE       2					//--Код CORE;
#define FLPROG_CORE_NAME       "SAMX(DUE)"			//--Имя CORE;
#define FLPROG_CORE_AVR_DUE	
#include "variant/arduino/due/flprogUtilitesDUE.h"						//--Идентификатор CORE;
#endif
//-------------------------------------------------------------------------------------------------
//								AVR
//  Как-то необычно идентифицируется DUE - наверное можно иначе?
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(__AVR__)
#define FLPROG_CORE_CODE       1					//--Код CORE;
#define FLPROG_CORE_NAME       "AVR"				//--Имя CORE;
#define FLPROG_CORE_AVR								//--Идентификатор CORE;
#define FLPROG_UNIVTRSAL_FUNCTION
#include "variant\arduino\avr\flprogUtilitesAVR.h"
#endif

//-------------------------------------------------------------------------------------------------
//								ESP8266
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ESP8266)
#define FLPROG_CORE_CODE             3				//--Код CORE;
#define FLPROG_CORE_NAME       "ESP8266"			//--Имя CORE;
#define FLPROG_CORE_ESP8266							//--Идентификатор CORE;
#define FLPROG_CORE_ESP8266_OR_ESP32				//--Идентификатор CORE групповой;
#define FLPROG_CORE_ESP		
#include "variant/esp8266/flprogUtilitesESP8266.h"							//--Идентификатор CORE групповой - я бы сделал такое имя...
#endif

//-------------------------------------------------------------------------------------------------
//								ESP32
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ESP32)
#define FLPROG_CORE_CODE             4				//--Код CORE;
#define FLPROG_CORE_NAME       "ESP32"				//--Имя CORE;
#define FLPROG_CORE_ESP32							//--Идентификатор CORE;
#define FLPROG_CORE_ESP8266_OR_ESP32				//--Идентификатор CORE групповой;
#define FLPROG_CORE_ESP		
#include "variant/esp32/flprogUtilitesESP32.h"		
#include "variant\arduino\avr\flprogUtilitesAVR.h"					
#endif


//-------------------------------------------------------------------------------------------------
//							   STM32(CORE STMduino)
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(_STM32_DEF_)
#define FLPROG_CORE_CODE             5				//--Код CORE;
#define FLPROG_CORE_NAME       "STM32duino"			//--Имя CORE;
#define FLPROG_CORE_STM32							//--Идентификатор CORE;
#define FLPROG_CORE_STM								//--Идентификатор CORE групповой; 
  #if defined(USBCON) && defined(USBD_USE_CDC)		//----
  #define FLPROG_STM32_USB_COM0						//--Идентификатор для работы с USB STM32
  #endif  
  #include "variant\arduino\avr\flprogUtilitesAVR.h" 		 							
#endif

//-------------------------------------------------------------------------------------------------
//							   STM8
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(_STM8_DEF_)
#define FLPROG_CORE_CODE             6				//--Код CORE;
#define FLPROG_CORE_NAME       "STM8"			    //--Имя CORE;
#define FLPROG_CORE_STM8							//--Идентификатор CORE;
#define FLPROG_CORE_STM								//--Идентификатор CORE групповой;
#define FLPROG_UNIVTRSAL_FUNCTION
#include "variant\arduino\avr\flprogUtilitesAVR.h"
#endif

//-------------------------------------------------------------------------------------------------
//							Raspberry Pi Pico
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE) && defined(ARDUINO_ARCH_RP2040)
#define FLPROG_CORE_CODE             8				//--Код CORE;
#define FLPROG_CORE_NAME       "RaspBerry Pi Pico"	//--Имя CORE;
#define FLPROG_CORE_RP2040							//--Идентификатор CORE;
#include "variant/arduino/avr/flprogUtilitesAVR.h"	//--Подключение библиотек для RP2040;
#endif

//-------------------------------------------------------------------------------------------------
//							ANON (не опознанное CORE)
//-------------------------------------------------------------------------------------------------
#if !defined(FLPROG_CORE_CODE)
#define FLPROG_CORE_CODE            90				//--Код CORE;
#define FLPROG_CORE_NAME       "ANON"				//--Имя CORE;
#define FLPROG_CORE_ANON							//--Идентификатор CORE;
#include "variant/arduino/avr/flprogUtilitesAVR.h"	//--Подключение библиотек для ANON;
#endif