#include "hardwareUartEsp32_Basic.h"

#ifdef FLPROG_CORE_ESP32_BASIC
FLProgUart::FLProgUart()
{
    port = &Serial;
}
FLProgUart::FLProgUart(uint8_t portNumber)
{
#ifdef FLPROG_HAS_UART0
    if (portNumber == 0)
    {
#ifdef FLPROG_UART0_RX
        rxPin = FLPROG_UART1_RX;
#endif
#ifdef FLPROG_UART0_TX
        txPin = FLPROG_UART1_TX;
#endif
        port = &Serial;
    }
#endif
#ifdef FLPROG_HAS_UART1
    if (portNumber == 1)
    {
#ifdef FLPROG_UART1_RX
        rxPin = FLPROG_UART1_RX;
#endif
#ifdef FLPROG_UART1_TX
        txPin = FLPROG_UART1_TX;
#endif
        port = &Serial1;
    }
#endif
#ifdef FLPROG_HAS_UART2
    if (portNumber == 2)
    {
#ifdef FLPROG_UART2_RX
        rxPin = FLPROG_UART2_RX;
#endif
#ifdef FLPROG_UART2_TX
        txPin = FLPROG_UART2_TX;
#endif
        port = &Serial2;
    }
#endif
}

void FLProgUart::restartPort()
{
    if (hasPort())
    {
        port->end();
        begin();
    }
}

void FLProgUart::begin()
{
    if (hasPort())
    {
        if ((rxPin > -1) && (txPin > 0))
        {
            port->begin(speedFromCode(), serialModeFromParametrs(), rxPin, txPin);
        }
        else
        {
            port->begin(speedFromCode(), serialModeFromParametrs());
        }
    }
}

void FLProgUart::begin(int32_t speed, int mode)
{
    setCodeFromSpeed(speed);
    setSerialMode(mode);
    begin();
}

int FLProgUart::serialModeFromParametrs()
{
    return flprog::serialModeFromInt(serialCodeForParametrs());
}

void FLProgUart::setSerialMode(int16_t mode)
{
    switch (mode)
    {
    case 0x00:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x02:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x04:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x06:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x08:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x0A:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x0C:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x0E:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x20:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x22:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x24:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x26:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x28:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x2A:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x2C:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x2E:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x30:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x32:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x34:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x36:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x38:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x3A:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x3C:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x3E:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    }
    portDataBits = FLPROG_PORT_DATA_BITS_8;
    portStopBits = FLPROG_PORT_STOP_BITS_1;
    portParity = FLPROG_PORT_PARITY_NONE;
}

#endif