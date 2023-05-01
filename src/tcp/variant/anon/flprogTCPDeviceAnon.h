#pragma once
#include "Arduino.h"

#ifdef FLPROG_ANON_SELECT_TCP

class FLProgTcpDevice : public FLProgStream
{
public:
    void beClient(){};
    void beServer(){};
    uint8_t read() { return 0; };
    int read(uint8_t *buf, size_t size) { return 0; };
    void setPort(int port){};
    bool connected() { return false; };
    void connect() { connect(0, 0, 0, 0); };
    void connect(byte ipFirst, byte ipSecond, byte ipThird, byte ipFourth) { connect(ipFirst, ipSecond, ipThird, ipFourth, tcpPort); };
    virtual int connect(uint16_t ipFirst, uint16_t ipSecond, uint16_t ipThird, uint16_t ipFourth, int newPort) { return 0; };
    virtual int connect(const char *host, uint16_t newPort) { return 0; };
    virtual void begin(){};
    void restart(){};
    void stop(){};
    virtual bool hasClient() { return false; };
    virtual bool hasServer() { return false; };

protected:
    bool mode = FLPROG_TSP_CLIENT_MODE;
    int tcpPort = 502;
    virtual Stream *stream() { return 0; };
    virtual bool hasStream() { return false; };
    virtual void setAvalibleClientFromServer(){};
    virtual int clientRemotePort() { return 0; };
};

class FLProgW5100TcpDevice : public FLProgTcpDevice
{
};

#endif
