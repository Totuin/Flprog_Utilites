#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_WIFI_TCP_DEVICE
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