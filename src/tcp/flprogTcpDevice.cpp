#include "flprogTcpDevice.h" 

#ifdef FLPROG_EXISTS_SELECT_TCP
//------------FLProgTcpDevice--------
void FLProgTcpDevice::setPort(int port)
{
    if (tcpPort == port)
        return;
    tcpPort = port;
    restart();
}

void FLProgTcpDevice::beClient()
{
    if (!mode)
        return;
    mode = FLPROG_TSP_CLIENT_MODE;
    restart();
}

void FLProgTcpDevice::beServer()
{
    if (mode)
        return;
    mode = FLPROG_TCP_SERVER_MODE;
    restart();
}

void FLProgTcpDevice::restart()
{
    stop();
    if (mode && (hasServer()))
    {
        begin();
    }
}

void FLProgTcpDevice::stop()
{
    tcpClient()->stop();
}

uint8_t FLProgTcpDevice::read()
{
    return tcpClient()->read();
}

int FLProgTcpDevice::read(uint8_t *buf, size_t size)
{
    return tcpClient()->read(buf, size);
}

bool FLProgTcpDevice::connected()
{
    return tcpClient()->connected();
}

int FLProgTcpDevice::connect(uint16_t ipFirst, uint16_t ipSecond, uint16_t ipThird, uint16_t ipFourth, int newPort)
{
    workIp[0] = ipFirst;
    workIp[1] = ipSecond;
    workIp[2] = ipThird;
    workIp[3] = ipFourth;

    return connect(workIp, newPort);
}

int FLProgTcpDevice::connect(IPAddress newIp, int newPort)
{
    if (mode)
    {
        if (!tcpClient()->connected())
        {
            setAvalibleClientFromServer();
            return 1;
        }
        return 1;
    }
    if (tcpClient()->connected())
    {
        if (clientRemoteIp() == newIp)
        {
            if (clientRemotePort() == newPort)
            {
                return 1;
            }
        }
    }
    stop();
    return tcpClient()->connect(newIp, newPort);
}

int FLProgTcpDevice::connect(const char *host, uint16_t newPort)
{
    return tcpClient()->connect(host, newPort);
}
#endif