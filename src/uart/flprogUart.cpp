#include "flprogUart.h"

void FLProgUartBasic::setPortSpeed(uint8_t speed)
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

void FLProgUartBasic::setPortDataBits(uint8_t dataBits)
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

void FLProgUartBasic::setPortStopBits(uint8_t stopBits)
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

void FLProgUartBasic::setPortParity(uint8_t parity)
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

uint8_t FLProgUartBasic::available()
{
    if (hasPort())
    {
        return uartPort()->available();
    }
    return 0;
}

uint8_t FLProgUartBasic::read()
{
    if (hasPort())
    {
        return uartPort()->read();
    }
    return 0;
}

uint8_t FLProgUartBasic::write(uint8_t *buffer, uint8_t size)
{
    if (hasPort())
    {
        return uartPort()->write(buffer, size);
    }
    return 0;
}

uint8_t FLProgUartBasic::write(uint8_t data)
{
    if (hasPort())
    {
        return uartPort()->write(data);
    }
    return 0;
}

void FLProgUartBasic::print(String str)
{
    if (hasPort())
    {
        uartPort()->print(str);
    }
}

void FLProgUartBasic::print(const char str[])
{
    if (hasPort())
    {
        uartPort()->print(str);
    }
}

void FLProgUartBasic::print(char str)
{
    if (hasPort())
    {
        uartPort()->print(str);
    }
}

void FLProgUartBasic::print(uint8_t val, int mode)
{
    if (hasPort())
    {
        uartPort()->print(val, mode);
    }
}

void FLProgUartBasic::print(int val, int mode)
{
    if (hasPort())
    {
        uartPort()->print(val, mode);
    }
}

void FLProgUartBasic::print(long val, int mode)
{
    if (hasPort())
    {
        uartPort()->print(val, mode);
    }
}

void FLProgUartBasic::print(unsigned long val, int mode)
{
    if (hasPort())
    {
        uartPort()->print(val, mode);
    }
}

void FLProgUartBasic::print(float val, int mode)
{
    if (hasPort())
    {
        uartPort()->print(val, mode);
    }
}

void FLProgUartBasic::println(String str)
{
    if (hasPort())
    {
        uartPort()->println(str);
    }
}

void FLProgUartBasic::println(char str)
{
    if (hasPort())
    {
        uartPort()->println(str);
    }
}

void FLProgUartBasic::println(const char str[])
{
    if (hasPort())
    {
        uartPort()->println(str);
    }
}

void FLProgUartBasic::println(uint8_t val, int mode)
{
    if (hasPort())
    {
        uartPort()->println(val, mode);
    }
}

void FLProgUartBasic::println(int val, int mode)
{
    if (hasPort())
    {
        uartPort()->println(val, mode);
    }
}

void FLProgUartBasic::println(long val, int mode)
{
    if (hasPort())
    {
        uartPort()->println(val, mode);
    }
}

void FLProgUartBasic::println(unsigned long val, int mode)
{
    if (hasPort())
    {
        uartPort()->println(val, mode);
    }
}

void FLProgUartBasic::println(float val, int mode)
{
    if (hasPort())
    {
        uartPort()->println(val, mode);
    }
}

void FLProgUartBasic::println()
{
    if (hasPort())
    {
        uartPort()->println();
    }
}