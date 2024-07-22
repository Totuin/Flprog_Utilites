#pragma once
#include <Arduino.h>
#include "IPAddress.h"

// #ifdef FLPROG_BLUETOOTH_SERIAL

// #endif

#ifdef ARDUINO_ARCH_AVR
#define FLPROG_SOFTWARE_SERIAL
#define FLPROG_WRITE_BUFFER_SIZE 100
#if !(defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega1281__) || defined(__AVR_ATmega640__) || defined(__AVR_ATmega641__) || defined(ARDUINO_AVR_MEGA2560))
#define FLPROG_COMPACT_LIBRARY_MODE
#endif
#else
#define FLPROG_WRITE_BUFFER_SIZE 800
#endif

#ifndef FLPROG_COMPACT_LIBRARY_MODE
#include "RT_HW_BASE.h"
#endif
// #include "flprogUart.h"
#include "RT_HW_SHEDULER.h"
#include "flprog_Blocks.h"
#include "pin\FlprogPin.h"


// Базовые константы
#define FLPROG_INADDR_NONE IPAddress(0, 0, 0, 0)

#ifndef FLPROG_ETHERNET_MAX_SOCK_NUM
#if defined(RAMEND) && defined(RAMSTART) && ((RAMEND - RAMSTART) <= 2048)
#define FLPROG_ETHERNET_MAX_SOCK_NUM 4
#else
#define FLPROG_ETHERNET_MAX_SOCK_NUM 8
#endif
#endif

#ifdef FLPROG_COMPACT_LIBRARY_MODE
#define FLPROG_MODBUS_BUFER_SIZE 64
#define FLPROG_HOST_NAME_LENGTH 64
#define FLPROG_LED_PIN 13
#else
#define FLPROG_MODBUS_BUFER_SIZE 250
#define FLPROG_HOST_NAME_LENGTH 250
#define FLPROG_LED_PIN RT_HW_Base.device.pin.led
#endif

// Константы для датчиков
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

// Типы сетевых интерфейсов
#define FLPROG_ANON_INTERFACE 0
#define FLPROG_ETHERNET_INTERFACE 1
#define FLPROG_ON_BOARD_WIFI_INTERFACE 2
#define FLPROG_ETHERNET_ON_BOARD_WIFI_ANON 3
#define FLPROG_ETHERNET_ON_BOARD_WIFI_ESP32 4
#define FLPROG_ETHERNET_ON_BOARD_WIFI_ESP8266 5
#define FLPROG_ETHERNET_ON_BOARD_WIFI_RP2040 6

// Контсанты результатов выполнения операций
#define FLPROG_ERROR 0
#define FLPROG_SUCCESS 1
#define FLPROG_WAIT 2

// Константы статусов
#define FLPROG_NOT_REDY_STATUS 0
#define FLPROG_READY_STATUS 1
#define FLPROG_WAIT_ETHERNET_HARDWARE_INIT_STATUS 2

#define FLPROG_WAIT_ETHERNET_DHCP_STATUS 3
#define FLPROG_WAIT_ETHERNET_DNS_STATUS 4
#define FLPROG_WAIT_ETHERNET_UDP_STATUS 5

#define FLPROG_WAIT_ETHERNET_CLIENT_CONNECT_STATUS 6
#define FLPROG_WAIT_ETHERNET_LINK_ON_STATUS 7
#define FLPROG_ETHERNET_HARDWARE_INIT_STATUS 8
#define FLPROG_WAIT_ETHERNET_CONNECT_STATUS 9
#define FLPROG_WAIT_WIFI_CLIENT_CONNECT_STATUS 10
#define FLPROG_WAIT_ETHERNET_START_CLIENT_CONNECT_STATUS 11
#define FLPROG_WAIT_WEB_SERVER_READ_REQEST 12
#define FLPROG_WAIT_WEB_SERVER_SEND_ANSVER 13
#define FLPROG_WAIT_SEND_UDP_PACAGE 14

// Коды статуса линии Ethernet
#define FLPROG_ETHERNET_LINK_UNKNOWN 13
#define FLPROG_ETHERNET_LINK_ON 14
#define FLPROG_ETHERNET_LINK_OFF 15

// Коды чипов
#define FLPROG_ETHERNET_NO_HARDWARE 0
#define FLPROG_ETHERNET_W5100 51
#define FLPROG_ETHERNET_W5200 52
#define FLPROG_ETHERNET_W5500 55

// Коды ошибок
#define FLPROG_NOT_ERROR 0

#define FLPROG_ETHERNET_INTERFACE_NOT_READY_ERROR 10
#define FLPROG_ETHERNET_HARDWARE_INIT_ERROR 11
#define FLPROG_ETHERNET_SOKET_INDEX_ERROR 12
#define FLPROG_ETHERNET_SOKET_NOT_INIT_ERROR 13
#define FLPROG_ETHERNET_SOKET_SEND_TIMEOUT_ERROR 14
#define FLPROG_ETHERNET_SOKET_UDP_NOT_CORRECT_DATA_ERROR 15
#define FLPROG_ETHERNET_LINK_OFF_ERROR 16

#define FLPROG_ETHERNET_DHCP_NOT_CORRECT_RESULT_ERROR 20
#define FLPROG_ETHERNET_DHCP_TIMEOUT_ERROR 21
#define FLPROG_ETHERNET_DHCP_DISCOVERY_ERROR_ID_ERROR 22
#define FLPROG_ETHERNET_DHCP_REREQUEST_ERROR_ID_ERROR 24
#define FLPROG_ETHERNET_DHCP_REREQUEST_NAK_ERROR 24
#define FLPROG_ETHERNET_DHCP_NOT_DEFINED_ERROR 25
#define FLPROG_ETHERNET_DHCP_NOT_READY_ERROR 25

#define FLPROG_ETHERNET_DNS_NOT_READY_ERROR 30
#define FLPROG_ETHERNET_DNS_INVALID_SERVER 31
#define FLPROG_ETHERNET_DNS_TRUNCATED 32
#define FLPROG_ETHERNET_DNS_INVALID_RESPONSE 33

#define FLPROG_ETHERNET_UDP_SOKET_START_ERROR 40
#define FLPROG_ETHERNET_UDP_TIMEOUT_ERROR 41

#define FLPROG_ETHERNET_CLIENT_SOKET_START_ERROR 50
#define FLPROG_ETHERNET_CLIENT_CONNECT_TIMEOUT_ERROR 51
#define FLPROG_ETHERNET_CLIENT_SOKET_CLOSED_ERROR 52

#define FLPROG_ETHERNET_SERVER_NOT_CALLBACK_ERROR 60
#define FLPROG_ETHERNET_SERVER_SOKET_ERROR 61


// Типы UART-ов
#define FLPROG_USB_UART 0
#define FLPROG_UART_UART 1
#define FLPROG_USART_UART 2

// Константы скоростей UART
#define FLPROG_SPEED_300 0
#define FLPROG_SPEED_600 1
#define FLPROG_SPEED_1200 2
#define FLPROG_SPEED_2400 3
#define FLPROG_SPEED_4800 4
#define FLPROG_SPEED_9600 5
#define FLPROG_SPEED_14400 6
#define FLPROG_SPEED_19200 7
#define FLPROG_SPEED_28800 8
#define FLPROG_SPEED_38400 9
#define FLPROG_SPEED_57600 10
#define FLPROG_SPEED_115200 11

// Константы Stop Bits UART
#define FLPROG_PORT_STOP_BITS_1 1
#define FLPROG_PORT_STOP_BITS_2 2

// Константы Data Bits UART
#define FLPROG_PORT_DATA_BITS_5 5
#define FLPROG_PORT_DATA_BITS_6 6
#define FLPROG_PORT_DATA_BITS_7 7
#define FLPROG_PORT_DATA_BITS_8 8

// Константы четности UART
#define FLPROG_PORT_PARITY_NONE 0
#define FLPROG_PORT_PARITY_EVEN 1
#define FLPROG_PORT_PARITY_ODD 2

// gfgdfgfg

namespace flprog
{
    //-------------Тестирование--------------------
    bool isNumberChar(char value);
    bool isHexNumberChar(char value);

    //-------------Конвертация------------------------
    bool stringToBool(String value);
    char stringToChar(String value);
    int32_t hexStringToLong(String value);
    uint32_t hexStringToUnsignedLong(String value);
    int32_t binStringToLong(String value);
    uint32_t binStringToUnsignedLong(String value);

    //-------------Таймера------------------------
    bool isTimer(uint32_t startTime, uint32_t period);
    bool isTimerMicros(uint32_t startTime, uint32_t period);
    uint32_t difference32(uint32_t start, uint32_t end);
    uint32_t timeBack(uint32_t value);

    //---------------Сеть---------------------------------------------
    bool applyMac(uint8_t m0, uint8_t m1, uint8_t m2, uint8_t m3, uint8_t m4, uint8_t m5, uint8_t *target);
    bool checkMacAddres(uint8_t *target);
    void parseMacAddressString(String value, uint8_t *array);
    String macAddresToString(uint8_t *array);
    bool checkMacAddresString(String value);
    bool compareMacAddresWithString(uint8_t *array, String value);
    bool compareMacAddreses(uint8_t *array1, uint8_t *array2);
    int hexStrToInt(String str);
    bool inet_aton(const char *aIPAddrString, IPAddress &aResult);
    void ipToArray(IPAddress ip, uint8_t *array);
    uint32_t ipToNumber(IPAddress value);
    String ipToString(const IPAddress &ipAddress);
    IPAddress numberToIp(uint32_t value);
    IPAddress stringToIp(String value);
    bool checkIPAdressString(String value);
    String flprogErrorCodeName(uint8_t code);
    String flprogStatusCodeName(uint8_t code);
    //void printConsole(String title = "");

};

/*
 RT_HW_Base.void uartSetConfig(uint32_t config, uint8_t num = 0)
*/