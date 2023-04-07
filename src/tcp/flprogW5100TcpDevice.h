#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_W5100_TCP_DEVICE

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