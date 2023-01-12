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
    begin();
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

void FLProgW5100TcpDevice::connect(byte ipFirst, byte ipSecond, byte ipThird, byte ipFourth)
{
    if (!client.connected())
    {
        if (mode)
        {
            client = server->available();
        }
        else
        {
            client.connect(IPAddress(ipFirst, ipSecond, ipThird, ipFourth), tcpPort);
        }
    }
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

void FLProgWiFiTcpDevice::connect(byte ipFirst, byte ipSecond, byte ipThird, byte ipFourth)
{
    if (!client.connected())
    {
        if (mode)
        {
            client = server->available();
        }
        else
        {
            client.connect(IPAddress(ipFirst, ipSecond, ipThird, ipFourth), tcpPort);
        }
    }
}
#endif