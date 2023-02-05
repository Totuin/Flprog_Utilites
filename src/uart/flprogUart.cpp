#include "flprogUart.h"

void FLProgUartBasic::setPortSpeed(byte speed)
{
    if (portSpeed == speed)
    {
        return;
    }
    portSpeed = speed;
    if (!hasPort())
    {
        return;
    }
    restartPort();
}

void FLProgUartBasic::setPortDataBits(byte dataBits)
{
    if ((dataBits < 5) || (dataBits > 8))
    {
        return;
    }
    if (portDataBits == dataBits)
    {
        return;
    }
    portDataBits = dataBits;
    if (!hasPort())
    {
        return;
    }
    restartPort();
}

void FLProgUartBasic::setPortStopBits(byte stopBits)
{
    if ((stopBits < 1) || (stopBits > 2))
    {
        return;
    }

    if (portStopBits == stopBits)
    {
        return;
    }
    portStopBits = stopBits;
    if (!hasPort())
    {
        return;
    }
    restartPort();
}

void FLProgUartBasic::setPortParity(byte parity)
{
    if ((parity < 0) || (parity > 2))
    {
        return;
    }

    if (portParity == parity)
    {
        return;
    }
    portParity = parity;
    if (!hasPort())
    {
        return;
    }
    restartPort();
}

int FLProgUartBasic::serialCodeForParametrs()
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

uint32_t FLProgUartBasic::speedFromCode()
{
    return flprog::speedFromCode(portSpeed);
}

void FLProgUartBasic::setCodeFromSpeed(int32_t speed)
{
    portSpeed = flprog::codeFromSpeed(speed);
}

void FLProgUartBasic::begin(int32_t speed)
{
    setCodeFromSpeed(speed);
    begin();
}