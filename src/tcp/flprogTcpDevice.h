#pragma once
#include "Arduino.h"
#include "./flprogUtilites.h"
#ifndef ESP32
#include "Ethernet.h"
#include "SPI.h"
#endif
#ifdef ESP8266
#include <ESP8266WiFi.h>
#endif
#ifdef ESP32
#include "WiFi.h"
#endif

#define TCP_SERVER_MODE true
#define TSP_CLIENT_MODE false

class FLProgTcpDevice
{
public:
    void beClient();
    void beServer();
    byte available();
    byte read();
    void setPort(int port);
    bool connected();
    void connect() { connect(0, 0, 0, 0); };
    void print(String data);
    byte write(byte buffer[], byte size);
    virtual void connect(byte ipFirst, byte ipSecond, byte ipThird, byte ipFourth){};
    virtual void begin(){};
    void restart();
    void stop();

protected:
    bool mode = TSP_CLIENT_MODE;
    int tcpPort = 502;
    virtual Client *tcpClient() { return 0; };

private:
};

#ifndef ESP32
class FLProgW5100TcpDevice : public FLProgTcpDevice
{
public:
    virtual void begin();
    virtual void connect(byte ipFirst, byte ipSecond, byte ipThird, byte ipFourth);

protected:
    virtual Client *tcpClient() { return &client; };

private:
    EthernetServer *server;
    EthernetClient client;
};
#endif

#if defined(ESP8266) || defined(ESP32)
class FLProgWiFiTcpDevice : public FLProgTcpDevice
{
public:
    virtual void begin();
    virtual void connect(byte ipFirst, byte ipSecond, byte ipThird, byte ipFourth);

protected:
    virtual Client *tcpClient() { return &client; };

private:
    WiFiServer *server;
    WiFiClient client;
};
#endif
