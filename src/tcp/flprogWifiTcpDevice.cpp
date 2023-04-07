#include "flprogWifiTcpDevice.h"
#ifdef FLPROG_WIFI_TCP_DEVICE

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