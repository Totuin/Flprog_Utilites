#include "flprogW5100TcpDevice.h"

#ifdef FLPROG_W5100_TCP_DEVICE
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