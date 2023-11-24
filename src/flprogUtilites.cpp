#include "flprogUtilites.h"

//--------------namespace flprog-------------------------

uint32_t flprog::difference32(uint32_t start, uint32_t end)
{
    if (end >= start)
    {
        return end - start;
    }
    return (0xfFFFFFFF - start) + end;
}

bool flprog::isTimer(uint32_t startTime, uint32_t period)
{
    return (difference32(startTime, (millis()))) >= period;
}

bool flprog::isTimerMicros(uint32_t startTime, uint32_t period)
{
    return (difference32(startTime, (micros()))) >= period;
}

uint32_t flprog::timeBack(uint32_t value)
{
    uint32_t current = millis();
    if (value < current)
    {
        return current - value;
    }
    return (0xfFFFFFFF - value) + current;
}

uint32_t flprog::speedFromCode(byte code)
{
    switch (code)
    {
    case FLPROG_SPEED_300:
        return 300;
        break;
    case FLPROG_SPEED_600:
        return 600;
        break;
    case FLPROG_SPEED_1200:
        return 1200;
        break;
    case FLPROG_SPEED_2400:
        return 2400;
        break;
    case FLPROG_SPEED_4800:
        return 4800;
        break;
    case FLPROG_SPEED_9600:
        return 9600;
        break;
    case FLPROG_SPEED_14400:
        return 14400;
        break;
    case FLPROG_SPEED_19200:
        return 19200;
        break;
    case FLPROG_SPEED_28800:
        return 28800;
        break;
    case FLPROG_SPEED_38400:
        return 38400;
        break;
    case FLPROG_SPEED_57600:
        return 57600;
        break;
    case FLPROG_SPEED_115200:
        return 115200;
        break;
    default:
        return 9600;
        break;
    }
}

uint8_t flprog::codeFromSpeed(int32_t speed)
{
    switch (speed)
    {
    case 300:
        return FLPROG_SPEED_300;
        break;
    case 600:
        return FLPROG_SPEED_600;
        break;
    case 1200:
        return FLPROG_SPEED_1200;
        break;
    case 2400:
        return FLPROG_SPEED_2400;
        break;
    case 4800:
        return FLPROG_SPEED_4800;
        break;
    case 9600:
        return FLPROG_SPEED_9600;
        break;
    case 14400:
        return FLPROG_SPEED_14400;
        break;
    case 19200:
        return FLPROG_SPEED_19200;
        break;
    case 28800:
        return FLPROG_SPEED_28800;
        break;
    case 38400:
        return FLPROG_SPEED_38400;
        break;
    case 57600:
        return FLPROG_SPEED_57600;
        break;
    case 115200:
        return FLPROG_SPEED_115200;
        break;
    }
    return FLPROG_SPEED_9600;
}

int flprog::serialCodeForParametrs(byte portDataBits, byte portStopBits, byte portParity)
{
    int code = 0;
    if (portStopBits == 2)
    {
        code = code + 8;
    }
    if (portDataBits == 6)
    {
        code = code + 2;
    }
    if (portDataBits == 7)
    {
        code = code + 4;
    }
    if (portDataBits == 8)
    {
        code = code + 6;
    }
    if (portParity == 1)
    {
        code = code + 32;
    }
    if (portParity == 2)
    {
        code = code + 48;
    }
    return code;
}

bool flprog::applyMac(uint8_t m0, uint8_t m1, uint8_t m2, uint8_t m3, uint8_t m4, uint8_t m5, uint8_t *target)
{
    bool result = false;

    if (m0 != target[0])
    {
        target[0] = m0;
        result = true;
    }
    if (m1 != target[1])
    {
        target[1] = m1;
        result = true;
    }
    if (m2 != target[2])
    {
        target[2] = m2;
        result = true;
    }
    if (m3 != target[3])
    {
        target[3] = m3;
        result = true;
    }
    if (m4 != target[4])
    {
        target[4] = m4;
        result = true;
    }
    if (m5 != target[5])
    {
        target[5] = m5;
        result = true;
    }
    return result;
}

bool flprog::checkMacAddres(uint8_t *target)
{
    bool result = 0;
    for (uint8_t i = 0; i < 6; i++)
    {
        if (target[i] == 255)
        {
            return false;
        }
        if (target[i] > 0)
        {
            result = true;
        }
    }
    return result;
}

void flprog::parseMacAddressString(String value, uint8_t *array)
{
    int index;
    uint8_t buffer[6] = {255, 255, 255, 255, 255, 255};
    uint8_t raz = 0;
    String tempString;
    while ((value.length() > 0) && (raz <= 6))
    {
        index = value.indexOf(":");
        if (index == -1)
        {
            tempString = value;
            value = "";
        }
        else
        {
            tempString = value.substring(0, index);
            value = value.substring(index + 1);
        }
        buffer[raz] = byte(flprog::hexStrToInt(tempString));
        raz++;
    }
    if (flprog::checkMacAddres(buffer))
    {
        for (byte i = 0; i < 6; i++)
        {
            array[i] = buffer[i];
        }
    }
}

int flprog::hexStrToInt(String str)
{
    uint8_t len = str.length();
    if (len == 0)
        return 0;
    int result = 0;
    for (uint8_t i = 0; i < 8; i++) // только первые 8 цыфар влезуть в uint32
    {
        char ch = str[i];
        if (ch == 0)
            break;
        result <<= 4;
        if (isdigit(ch))
            result = result | (ch - '0');
        else
            result = result | (ch - 'A' + 10);
    }
    return result;
}

bool flprog::inet_aton(const char *address, IPAddress &result)
{
    uint16_t acc = 0;
    uint8_t dots = 0;
    while (*address)
    {
        char c = *address++;
        if (c >= '0' && c <= '9')
        {
            acc = acc * 10 + (c - '0');
            if (acc > 255)
            {
                return false;
            }
        }
        else if (c == '.')
        {
            if (dots == 3)
            {
                return false;
            }
            result[dots++] = acc;
            acc = 0;
        }
        else
        {
            return false;
        }
    }
    if (dots != 3)
    {
        return false;
    }
    result[3] = acc;
    return true;
}

void flprog::ipToArray(IPAddress ip, uint8_t *array)
{
    array[0] = ip[0];
    array[1] = ip[1];
    array[2] = ip[2];
    array[3] = ip[3];
}

String flprog::flprogErrorCodeName(uint8_t code)
{
    if (code == FLPROG_NOT_ERROR)
    {
        return "FLPROG_NOT_ERROR";
    }
    if (code == FLPROG_ETHERNET_HARDWARE_INIT_ERROR)
    {
        return "FLPROG_ETHERNET_HARDWARE_INIT_ERROR";
    }
    if (code == FLPROG_ETHERNET_INTERFACE_NOT_READY_ERROR)
    {
        return "FLPROG_ETHERNET_INTERFACE_NOT_READY_ERROR";
    }
    if (code == FLPROG_ETHERNET_SOKET_INDEX_ERROR)
    {
        return "FLPROG_ETHERNET_SOKET_INDEX_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_NOT_CORRECT_RESULT_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_NOT_CORRECT_RESULT_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_DISCOVERY_TIMEOUT_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_DISCOVERY_TIMEOUT_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_DISCOVERY_ERROR_ID_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_DISCOVERY_ERROR_ID_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_REREQUEST_TIMEOUT_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_REREQUEST_TIMEOUT_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_REREQUEST_ERROR_ID_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_REREQUEST_ERROR_ID_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_REREQUEST_NAK_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_REREQUEST_NAK_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_NOT_DEFINED_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_NOT_DEFINED_ERROR";
    }
    if (code == FLPROG_ETHERNET_DNS_NOT_READY_ERROR)
    {
        return "FLPROG_ETHERNET_DNS_NOT_READY_ERROR";
    }
    if (code == FLPROG_ETHERNET_DNS_INVALID_SERVER)
    {
        return "FLPROG_ETHERNET_DNS_INVALID_SERVER";
    }
    if (code == FLPROG_ETHERNET_DNS_TRUNCATED)
    {
        return "FLPROG_ETHERNET_DNS_TRUNCATED";
    }
    if (code == FLPROG_ETHERNET_DNS_INVALID_RESPONSE)
    {
        return "FLPROG_ETHERNET_DNS_INVALID_RESPONSE";
    }
    if (code == FLPROG_ETHERNET_UDP_SOKET_START_ERROR)
    {
        return "FLPROG_ETHERNET_UDP_SOKET_START_ERROR";
    }
    if (code == FLPROG_ETHERNET_UDP_TIMEOUT_ERROR)
    {
        return "FLPROG_ETHERNET_UDP_TIMEOUT_ERROR";
    }
    if (code == FLPROG_ETHERNET_SOKET_NOT_INIT_ERROR)
    {
        return "FLPROG_ETHERNET_SOKET_NOT_INIT_ERROR";
    }
    if (code == FLPROG_ETHERNET_SOKET_UDP_NOT_CORRECT_DATA_ERROR)
    {
        return "FLPROG_ETHERNET_SOKET_UDP_NOT_CORRECT_DATA_ERROR";
    }
    if (code == FLPROG_ETHERNET_SOKET_SEND_TIMEOUT_ERROR)
    {
        return "FLPROG_ETHERNET_SOKET_SEND_TIMEOUT_ERROR";
    }
    if (code == FLPROG_ETHERNET_LINK_OFF_ERROR)
    {
        return "FLPROG_ETHERNET_LINK_OFF_ERROR";
    }
    if (code == FLPROG_ETHERNET_CLIENT_SOKET_START_ERROR)
    {
        return "FLPROG_ETHERNET_CLIENT_SOKET_START_ERROR";
    }
    if (code == FLPROG_ETHERNET_CLIENT_CONNECT_TIMEOUT_ERROR)
    {
        return "FLPROG_ETHERNET_CLIENT_CONNECT_TIMEOUT_ERROR";
    }
    if (code == FLPROG_ETHERNET_CLIENT_SOKET_CLOSED_ERROR)
    {
        return "FLPROG_ETHERNET_CLIENT_SOKET_CLOSED_ERROR";
    }
    if (code == FLPROG_ETHERNET_SERVER_NOT_CALLBACK_ERROR)
    {
        return "FLPROG_ETHERNET_SERVER_NOT_CALLBACK_ERROR";
    }
    if (code == FLPROG_ETHERNET_SERVER_SOKET_ERROR)
    {
        return "FLPROG_ETHERNET_SERVER_SOKET_ERROR";
    }
    return "Unknown error code: " + String(code);
}

String flprog::flprogStatusCodeName(uint8_t code)
{
    if (code == FLPROG_NOT_REDY_STATUS)
    {
        return "FLPROG_NOT_REDY_STATUS";
    }
    if (code == FLPROG_READY_STATUS)
    {
        return "FLPROG_READY_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_HARDWARE_INIT_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_HARDWARE_INIT_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_DHCP_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_DHCP_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_DNS_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_DNS_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_UDP_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_UDP_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_CLIENT_CONNECT_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_CLIENT_CONNECT_STATUS";
    }
    return "Unknown status code: " + String(code);
}
//------------------FLProgStream-----------------

int FLProgStream::available()
{
    if (hasStream())
    {
        return stream()->available();
    }
    return 0;
}

void FLProgStream::flush()
{
    if (hasStream())
    {
        stream()->flush();
    }
}

int FLProgStream::read()
{
    if (hasStream())
    {
        return stream()->read();
    }
    return 0;
}

size_t FLProgStream::write(uint8_t *buffer, uint8_t size)
{
    if (hasStream())
    {
        return stream()->write(buffer, size);
    }
    return 0;
}

size_t FLProgStream::write(uint8_t data)
{
    if (hasStream())
    {
        return stream()->write(data);
    }
    return 0;
}

int FLProgStream::peek()
{
    if (hasStream())
    {
        return stream()->peek();
    }
    return 0;
}

//--------------------FLProgAbstractTcpInterface----------------

void FLProgAbstractTcpInterface::setDhcp()
{
    if (_isDhcp)
    {
        return;
    }
    _isDhcp = true;
    _isNeedReconect = true;
}

void FLProgAbstractTcpInterface::resetDhcp()
{
    if (!_isDhcp)
    {
        return;
    }
    _isDhcp = false;
    _isNeedReconect = true;
}

void FLProgAbstractTcpInterface::dhcpMode(bool val)
{
    if (_isDhcp == val)
    {
        return;
    }
    _isDhcp = val;
    _isNeedReconect = true;
}

void FLProgAbstractTcpInterface::localIP(IPAddress ip)
{
    if (_ip == ip)
    {
        return;
    }
    _ip = ip;
    _isNeedReconect = true;
}

void FLProgAbstractTcpInterface::dns(IPAddress ip)
{
    if (_dnsIp == ip)
    {
        return;
    }
    _dnsIp = ip;
    _isNeedReconect = true;
}

void FLProgAbstractTcpInterface::subnet(IPAddress ip)
{
    if (_subnetIp == ip)
    {
        return;
    }
    _subnetIp = ip;
    _isNeedReconect = true;
}

void FLProgAbstractTcpInterface::gateway(IPAddress ip)
{
    if (_gatewayIp == _ip)
    {
        return;
    }
    _gatewayIp = _ip;
    _isNeedReconect = true;
}

void FLProgAbstractTcpInterface::mac(uint8_t m0, uint8_t m1, uint8_t m2, uint8_t m3, uint8_t m4, uint8_t m5)
{
    if (flprog::applyMac(m0, m1, m2, m3, m4, m5, _macAddress))
    {
        _isNeedReconect = true;
    }
}

void FLProgAbstractTcpInterface::mac(uint8_t *mac_address)
{
    for (uint8_t i = 0; i < 6; i++)
    {
        mac_address[i] = _macAddress[i];
    }
}
