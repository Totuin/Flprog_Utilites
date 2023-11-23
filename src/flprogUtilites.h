#pragma once
#include <Arduino.h>
#include "RT_HW_BASE.h"
#include "IPAddress.h"
#include "flprog_Blocks.h"
#include "Client.h"
// Базовые константы
#define FLPROG_INADDR_NONE IPAddress(0, 0, 0, 0)

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

// Типы сетевых интерфейсов
#define FLPROG_ANON_INTERFACE 0
#define FLPROG_ETHERNET_INTERFACE 1
#define FLPROG_WIFI_INTERFACE 2

// Контсанты результатов выполнения операций
#define FLPROG_ERROR 0
#define FLPROG_SUCCESS 1
#define FLPROG_WITE 2

// Константы статусов
#define FLPROG_NOT_REDY_STATUS 0
#define FLPROG_READY_STATUS 1
#define FLPROG_WAIT_ETHERNET_HARDWARE_INIT_STATUS 2
#define FLPROG_WAIT_ETHERNET_DHCP_STATUS 3
#define FLPROG_WAIT_ETHERNET_DNS_STATUS 4
#define FLPROG_WAIT_ETHERNET_UDP_STATUS 5
#define FLPROG_WAIT_ETHERNET_CLIENT_CONNECT_STATUS 6

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
#define FLPROG_ETHERNET_DHCP_DISCOVERY_TIMEOUT_ERROR 21
#define FLPROG_ETHERNET_DHCP_DISCOVERY_ERROR_ID_ERROR 22
#define FLPROG_ETHERNET_DHCP_REREQUEST_TIMEOUT_ERROR 23
#define FLPROG_ETHERNET_DHCP_REREQUEST_ERROR_ID_ERROR 24
#define FLPROG_ETHERNET_DHCP_REREQUEST_NAK_ERROR 25
#define FLPROG_ETHERNET_DHCP_NOT_DEFINED_ERROR 26

#define FLPROG_ETHERNET_DNS_NOT_READY_ERROR 30
#define FLPROG_ETHERNET_DNS_INVALID_SERVER 31
#define FLPROG_ETHERNET_DNS_TRUNCATED 32
#define FLPROG_ETHERNET_DNS_INVALID_RESPONSE 33

#define FLPROG_ETHERNET_UDP_SOKET_START_ERROR 40
#define FLPROG_ETHERNET_UDP_TIMEOUT_ERROR 41

#define FLPROG_ETHERNET_CLIENT_SOKET_START_ERROR 50
#define FLPROG_ETHERNET_CLIENT_CONNECT_TIMEOUT_ERROR 51
#define FLPROG_ETHERNET_CLIENT_SOKET_CLOSED_ERROR 52

namespace flprog
{
    bool isTimer(uint32_t startTime, uint32_t period);
    bool isTimerMicros(uint32_t startTime, uint32_t period);
    uint32_t difference32(uint32_t start, uint32_t end);
    uint32_t timeBack(uint32_t value);
    uint32_t speedFromCode(byte code);
    uint8_t codeFromSpeed(int32_t speed);
    int serialCodeForParametrs(byte portDataBits, byte portStopBits, byte portParity);

    bool applyMac(uint8_t m0, uint8_t m1, uint8_t m2, uint8_t m3, uint8_t m4, uint8_t m5, uint8_t *target);
    bool checkMacAddres(uint8_t *target);
    void parseMacAddressString(String value, uint8_t *array);
    int hexStrToInt(String str);

    bool inet_aton(const char *aIPAddrString, IPAddress &aResult);
    void ipToArray(IPAddress ip, uint8_t *array);
    String flprogErrorCodeName(uint8_t code);
    String flprogStatusCodeName(uint8_t code);

};

class FLProgStream : public Stream
{
public:
    virtual int available();
    virtual int read();
    virtual size_t write(uint8_t data);
    virtual size_t write(uint8_t *buffer, uint8_t size);
    virtual int peek();
    virtual void flush();

protected:
    virtual Stream *stream() { return 0; };
    virtual bool hasStream() { return stream() != 0; };
};

class FLProgAbstractTcpServer;

class FLProgAbstractTcpInterface
{
public:
    void setDhcp();
    void resetDhcp();
    void dhcpMode(bool val);
    bool dhcpMode() { return _isDhcp; };

    virtual void pool(){};

    IPAddress localIP() { return _ip; };
    void localIP(IPAddress ip);
    void localIP(uint8_t ip0, uint8_t ip1, uint8_t ip2, uint8_t ip3) { localIP(IPAddress(ip0, ip1, ip2, ip3)); };

    IPAddress dns() { return _dnsIp; };
    void dns(IPAddress ip);
    void dns(uint8_t ip0, uint8_t ip1, uint8_t ip2, uint8_t ip3) { dns(IPAddress(ip0, ip1, ip2, ip3)); };

    IPAddress subnet() { return _subnetIp; };
    void subnet(IPAddress ip);
    void subnet(uint8_t ip0, uint8_t ip1, uint8_t ip2, uint8_t ip3) { subnet(IPAddress(ip0, ip1, ip2, ip3)); };

    IPAddress gateway() { return _gatewayIp; };
    void gateway(IPAddress ip);
    void gateway(uint8_t ip0, uint8_t ip1, uint8_t ip2, uint8_t ip3) { gateway(IPAddress(ip0, ip1, ip2, ip3)); };

    void mac(uint8_t m0, uint8_t m1, uint8_t m2, uint8_t m3, uint8_t m4, uint8_t m5);
    uint8_t *mac() { return _macAddress; };
    virtual void mac(uint8_t *mac_address);

    virtual bool isBusy() { return _busy; };
    virtual void isBusy(bool busy) { _busy = busy; };

    void setBusy() { _busy = true; };
    void resetBusy() { _busy = false; };

    virtual uint8_t type() { return FLPROG_ANON_INTERFACE; }

    virtual FLProgAbstractTcpServer *getServer(int port) = 0;
    virtual Client *getClient() = 0;

    virtual bool isImitation() { return true; }

    bool canStartServer() { return false; };

    uint8_t getStatus() { return _status; }
    uint8_t getError() { return _errorCode; }
    virtual bool isReady() { return _status == FLPROG_READY_STATUS; };

protected:
    bool _busy = false;
    bool _isDhcp = true;
    uint8_t _status = FLPROG_NOT_REDY_STATUS;
    uint8_t _errorCode = FLPROG_NOT_ERROR;
    bool _needUpdateData = false;
    IPAddress _ip = INADDR_NONE;
    IPAddress _dnsIp = INADDR_NONE;
    IPAddress _subnetIp = IPAddress(255, 255, 255, 0);
    IPAddress _gatewayIp = INADDR_NONE;
    uint8_t _macAddress[6] = {0, 0, 0, 0, 0, 0};
    bool _isNeedReconect = true;
};

class FLProgAbstractTcpServer
{
public:
    virtual void begin(){};
    virtual void begin(uint16_t port) = 0;
    virtual void setClient(){};
    virtual Client *client() { return 0; };
};
