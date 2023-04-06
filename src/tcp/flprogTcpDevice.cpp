#include "flprogTcpDevice.h"
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

byte FLProgTcpDevice::available()
{
    if (!tcpClient()->connected())
    {
        return 0;
    }
    return tcpClient()->available();
}

byte FLProgTcpDevice::read()
{

    return tcpClient()->read();
}

bool FLProgTcpDevice::connected()
{
    return tcpClient()->connected();
}

void FLProgTcpDevice::print(String data)
{
    tcpClient()->print(data);
}

byte FLProgTcpDevice::write(byte buffer[], byte size)
{
    return tcpClient()->write(buffer, size);
}

void FLProgTcpDevice::connect(uint16_t ipFirst, uint16_t ipSecond, uint16_t ipThird, uint16_t ipFourth, int newPort)
{
    workIp[0] = ipFirst;
    workIp[1] = ipSecond;
    workIp[2] = ipThird;
    workIp[3] = ipFourth;

    connect(workIp, newPort);
}

void FLProgTcpDevice::connect(IPAddress newIp, int newPort)
{
    if (mode)
    {
        if (!tcpClient()->connected())
        {
            setAvalibleClientFromServer();
            return;
        }
        return;
    }
    if (tcpClient()->connected())
    {
        if (clientRemoteIp() == newIp)
        {
            if (clientRemotePort() == newPort)
            {
                return;
            }
        }
    }
    stop();
    tcpClient()->connect(newIp, newPort);
}

//----------FLProgW5100TcpDevice--------
#ifndef FLPROG_CORE_ESP
void FLProgW5100TcpDevice::begin()
{
    if (mode)
    {
        server = new EthernetServer(tcpPort);
        server->begin();
    }
}

void FLProgW5100TcpDevice::setAvalibleClientFromServer()
{
    if (server == 0)
        return;
    client = server->available();
}

#endif

//-------------FLProgWiFiTcpDevice-----------
#ifdef FLPROG_CORE_ESP
void FLProgWiFiTcpDevice::begin()
{
    if (mode)
    {
        server = new WiFiServer(tcpPort);
        server->begin();
    }
}

void FLProgWiFiTcpDevice::setAvalibleClientFromServer()
{
    if (server == 0)
        return;
    client = server->available();
}

#endif