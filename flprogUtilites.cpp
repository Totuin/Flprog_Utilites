#include <flprogUtilites.h>

bool flprog::isTimer(unsigned long startTime, unsigned long period)
{
    unsigned long currentTime;
    currentTime = millis();
    if (currentTime >= startTime)
    {
        return (currentTime >= (startTime + period));
    }
    else
    {
        return (currentTime >= (4294967295 - startTime + period));
    }
}

int flprog::serialModeFromInt(int code)
{
    switch (code)
    {
    case 0x00:
        return SERIAL_5N1;
        break;
    case 0x02:
        return SERIAL_6N1;
        break;
    case 0x04:
        return SERIAL_7N1;
        break;
    case 0x06:
        return SERIAL_8N1;
        break;
    case 0x08:
        return SERIAL_5N2;
        break;
    case 0x0A:
        return SERIAL_6N2;
        break;
    case 0x0C:
        return SERIAL_7N2;
        break;
    case 0x0E:
        return SERIAL_8N2;
        break;
    case 0x20:
        return SERIAL_5E1;
        break;
    case 0x22:
        return SERIAL_6E1;
        break;
    case 0x24:
        return SERIAL_7E1;
        break;
    case 0x26:
        return SERIAL_8E1;
        break;
    case 0x28:
        return SERIAL_5E2;
        break;
    case 0x2A:
        return SERIAL_6E2;
        break;
    case 0x2C:
        return SERIAL_7E2;
        break;
    case 0x2E:
        return SERIAL_8E2;
        break;
    case 0x30:
        return SERIAL_5O1;
        break;
    case 0x32:
        return SERIAL_6O1;
        break;
    case 0x34:
        return SERIAL_7O1;
        break;
    case 0x36:
        return SERIAL_8O1;
        break;
    case 0x38:
        return SERIAL_5O2;
        break;
    case 0x3A:
        return SERIAL_6O2;
        break;
    case 0x3C:
        return SERIAL_7O2;
        break;
    case 0x3E:
        return SERIAL_8O2;
        break;
    }
    return SERIAL_8N1;
}

long flprog::speedFromCode(byte code)
{
    switch (code)
    {
    case SPEED_300:
        return 300;
        break;
    case SPEED_600:
        return 600;
        break;
    case SPEED_1200:
        return 1200;
        break;
    case SPEED_2400:
        return 2400;
        break;
    case SPEED_4800:
        return 4800;
        break;
    case SPEED_9600:
        return 9600;
        break;
    case SPEED_14400:
        return 14400;
        break;
    case SPEED_19200:
        return 19200;
        break;
    case SPEED_28800:
        return 28800;
        break;
    case SPEED_38400:
        return 38400;
        break;
    case SPEED_57600:
        return 57600;
        break;
    case SPEED_115200:
        return 115200;
        break;
    default:
        return 9600;
        break;
    }
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

int flprog::serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity)
{
    return serialModeFromInt(serialCodeForParametrs(portDataBits, portStopBits, portParity));
}