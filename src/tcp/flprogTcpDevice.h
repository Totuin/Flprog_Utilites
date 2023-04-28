#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_AVR
#include "variant/avr/flprogTCPDeviceAvrConnectedLibs.h"
#endif

#ifdef FLPROG_CORE_AVR_DUE
#include "variant/due/flprogTCPDeviceDueConnectedLibs.h"
#endif

#ifdef FLPROG_CORE_ESP
#include "variant/esp/flprogTCPDeviceEspConnectedLibs.h"
#endif

#ifdef FLPROG_CORE_STM
#include "variant/stm/flprogTCPDeviceStmConnectedLibs.h"
#endif

#define FLPROG_TCP_SERVER_MODE 1
#define FLPROG_TSP_CLIENT_MODE 0

class FLProgTcpDevice : public FLProgStream
{
public:
    void beClient();
    void beServer();
    uint8_t read();
    int read(uint8_t *buf, size_t size);
    void setPort(int port);
    bool connected();
    void connect() { connect(0, 0, 0, 0); };
    void connect(byte ipFirst, byte ipSecond, byte ipThird, byte ipFourth) { connect(ipFirst, ipSecond, ipThird, ipFourth, tcpPort); };
    virtual int connect(uint16_t ipFirst, uint16_t ipSecond, uint16_t ipThird, uint16_t ipFourth, int newPort);
    virtual int connect(IPAddress newIp, int newPort);
    virtual int connect(const char *host, uint16_t newPort);
    virtual void begin(){};
    void restart();
    void stop();
    virtual bool hasClient() { return false; };
    virtual bool hasServer() { return false; };

protected:
    bool mode = FLPROG_TSP_CLIENT_MODE;
    int tcpPort = 502;

    virtual Stream *stream() { return tcpClient(); };
    virtual bool hasStream() { return tcpClient()->connected(); };

    virtual Client *tcpClient() { return 0; };
    virtual void setAvalibleClientFromServer(){};
    virtual IPAddress clientRemoteIp() { return IPAddress(0, 0, 0, 0); };
    virtual int clientRemotePort() { return 0; };
    IPAddress workIp;
};

#ifdef FLPROG_CORE_AVR
#include "variant/avr/flprogTCPDeviceAvr.h"
#endif

#ifdef FLPROG_CORE_AVR_DUE
#include "variant/due/flprogTCPDeviceDue.h"
#endif

#ifdef FLPROG_CORE_ESP
#include "variant/esp/flprogTCPDeviceEsp.h"
#endif

#ifdef FLPROG_CORE_STM
#include "variant/stm/flprogTCPDeviceStm.h"
#endif
