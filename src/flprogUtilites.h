#pragma once
#include <Arduino.h>
#include "RT_HW_BASE.h"
#include "IPAddress.h"
#include "flprog_Blocks.h"
#include "Client.h"

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

#define FLPROG_USB_UART 0
#define FLPROG_UART_UART 1
#define FLPROG_USART_UART 2

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

#define FLPROG_PORT_STOP_BITS_1 1
#define FLPROG_PORT_STOP_BITS_2 2
#define FLPROG_PORT_DATA_BITS_5 5
#define FLPROG_PORT_DATA_BITS_6 6
#define FLPROG_PORT_DATA_BITS_7 7
#define FLPROG_PORT_DATA_BITS_8 8
#define FLPROG_PORT_PARITY_NONE 0
#define FLPROG_PORT_PARITY_EVEN 1
#define FLPROG_PORT_PARITY_ODD 2

#define FLPROG_ANON_INTERFACE 0
#define FLPROG_ETHERNET_INTERFACE 1
#define FLPROG_WIFI_INTERFACE 2

#define FLPROG_NOT_REDY_STATUS 0
#define FLPROG_READY_STATUS 1
#define FLPROG_WAIT_STATUS 2
#define FLPROG_SUCCESS 3
#define FLPROG_TIMED_OUT 4

#define FLPROG_EHERNET_ERROR 5
#define FLPROG_DNS_INVALID_SERVER 6
#define FLPROG_DNS_TRUNCATED 7
#define FLPROG_DNS_INVALID_RESPONSE 8
#define FLPROG_DNS_INVALID_UDP 9



#define FLPROG_W5100_NOT_INIT_STATUS 10
#define FLPROG_W5100_WHITE_INIT_STATUS 11
#define FLPROG_W5100_INIT_STATUS 12

#define FLPROG_ETHERNET_LINK_UNKNOWN 13
#define FLPROG_ETHERNET_LINK_ON 14
#define FLPROG_ETHERNET_LINK_OFF 15

#define FLPROG_ETHERNET_NO_HARDWARE 16
#define FLPROG_ETHERNET_W5100 17
#define FLPROG_ETHERNET_W5200 18
#define FLPROG_ETHERNET_W5500 19

#define FLPROG_HARDWARE_INIT_STATUS 20
#define FLPROG_ETHERNET_STATUS_WHITE_DHCP 21


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
    String flprogCodeName(uint8_t code);

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
    bool dhcpMode() { return isDhcp; };

    virtual void pool(){};

    IPAddress localIP() { return ip; };
    void localIP(IPAddress _ip);
    void localIP(uint8_t ip0, uint8_t ip1, uint8_t ip2, uint8_t ip3) { localIP(IPAddress(ip0, ip1, ip2, ip3)); };

    IPAddress dns() { return dnsIp; };
    void dns(IPAddress _ip);
    void dns(uint8_t ip0, uint8_t ip1, uint8_t ip2, uint8_t ip3) { dns(IPAddress(ip0, ip1, ip2, ip3)); };

    IPAddress subnet() { return subnetIp; };
    void subnet(IPAddress _ip);
    void subnet(uint8_t ip0, uint8_t ip1, uint8_t ip2, uint8_t ip3) { subnet(IPAddress(ip0, ip1, ip2, ip3)); };

    IPAddress gateway() { return gatewayIp; };
    void gateway(IPAddress _ip);
    void gateway(uint8_t ip0, uint8_t ip1, uint8_t ip2, uint8_t ip3) { gateway(IPAddress(ip0, ip1, ip2, ip3)); };

    void mac(uint8_t m0, uint8_t m1, uint8_t m2, uint8_t m3, uint8_t m4, uint8_t m5);
    uint8_t *mac() { return macAddress; };
    virtual void mac(uint8_t *mac_address);

    virtual bool isBusy() { return busy; };
    virtual void isBusy(bool val) { busy = val; };

    void setBusy() { busy = true; };
    void resetBusy() { busy = false; };

    virtual bool isReady() { return false; };

    virtual uint8_t type() { return FLPROG_ANON_INTERFACE; }

    virtual FLProgAbstractTcpServer *getServer(int port) = 0;
    virtual Client *getClient() = 0;

    virtual bool isImitation() { return true; }

    bool canStartServer() { return true; };

protected:
    bool busy = false;
    bool isDhcp = true;
    IPAddress ip = IPAddress(0, 0, 0, 0);
    IPAddress dnsIp = IPAddress(0, 0, 0, 0);
    IPAddress subnetIp = IPAddress(255, 255, 255, 0);
    IPAddress gatewayIp = IPAddress(0, 0, 0, 0);
    uint8_t macAddress[6] = {0, 0, 0, 0, 0, 0};
    bool isNeedReconect = false;
};

class FLProgAbstractTcpServer
{
public:
    virtual void begin(){};
    virtual void begin(uint16_t port) = 0;
    virtual void setClient(){};
    virtual Client *client() { return 0; };
};
