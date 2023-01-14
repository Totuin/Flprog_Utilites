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
    mode = TSP_CLIENT_MODE;
    restart();
}

void FLProgTcpDevice::beServer()
{
    if (mode)
        return;
    mode = TCP_SERVER_MODE;
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

void FLProgTcpDevice::connect(byte ipFirst, byte ipSecond, byte ipThird, byte ipFourth, int newPort)
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
    IPAddress ip = IPAddress(ipFirst, ipSecond, ipThird, ipFourth);
    if (tcpClient()->connected())
    {
        if (clientRemoteIp() == ip)
        {
            if (clientRemotePort() == newPort)
            {
                return;
            }
        }
    }
    stop();

    tcpClient()->connect(ip, newPort);
}

//----------FLProgW5100TcpDevice--------
#ifndef ESP32
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
#if defined(ESP8266) || defined(ESP32)
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