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

#define TCP_SERVER_MODE 1
#define TSP_CLIENT_MODE 0

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
    void connect(byte ipFirst, byte ipSecond, byte ipThird, byte ipFourth) { connect(ipFirst, ipSecond, ipThird, ipFourth, tcpPort); };
    void connect(byte ipFirst, byte ipSecond, byte ipThird, byte ipFourth, int newPort);
    void print(String data);
    byte write(byte buffer[], byte size);
    virtual void begin(){};
    void restart();
    void stop();
    virtual bool hasClient() { return false; };
    virtual bool hasServer() { return false; };

protected:
    bool mode = TSP_CLIENT_MODE;
    int tcpPort = 502;
    virtual Client *tcpClient() { return 0; };
    virtual void setAvalibleClientFromServer(){};
    virtual IPAddress clientRemoteIp() { return IPAddress(0, 0, 0, 0); };
    virtual int clientRemotePort() { return 0; };

private:
};

#ifndef ESP32
class FLProgW5100TcpDevice : public FLProgTcpDevice
{
public:
    virtual void begin();
    virtual bool hasClient() { return client; };
    virtual bool hasServer() { return server != 0; };

protected:
    virtual Client *tcpClient() { return &client; };
    virtual void setAvalibleClientFromServer();
    virtual IPAddress clientRemoteIp() { return client.remoteIP(); };
    virtual int clientRemotePort() { return client.remotePort(); };

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
    virtual bool hasClient() { return client; };
    virtual bool hasServer() { return server != 0; };

protected:
    virtual Client *tcpClient() { return &client; };
    virtual void setAvalibleClientFromServer();
    virtual IPAddress clientRemoteIp() { return client.remoteIP(); };
    virtual int clientRemotePort() { return client.remotePort(); };

private:
    WiFiServer *server;
    WiFiClient client;
};
#endif
