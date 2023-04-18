#include "hardwareUartStm32.h"

#ifdef FLPROG_CORE_STM32
Stream *FLProgUart::uartPort()
{
#ifdef FLPROG_STM32_USB_COM0
    if (type == FLPROG_USB_UART)
    {
        return usbPort;
    }
#endif
    return port;
}

FLProgUart::FLProgUart(HardwareSerial *hardwarePort)
{
    port = hardwarePort;
}

#ifdef FLPROG_STM32_USB_COM0
FLProgUart::FLProgUart(USBSerial *port)
{
    usbPort = port;
    type = FLPROG_USB_UART;
}
#endif

FLProgUart::FLProgUart(uint8_t portNumber)
{
#ifdef FLPROG_STM32_USB_COM0
    if (portNumber == 0)
    {
        usbPort = &Serial;
        type = FLPROG_USB_UART;
    }
#endif
#ifdef FLPROG_STM32_SERIAL1
    if (portNumber == 1)
    {
        port = &Serial1;
    }
#endif
#ifdef FLPROG_STM32_SERIAL2
    if (portNumber == 2)
    {
        port = &Serial2;
    }
#endif
#ifdef FLPROG_STM32_SERIAL3
    if (portNumber == 3)
    {
        port = &Serial3;
    }
#endif
#ifdef FLPROG_STM32_SERIAL4
    if (portNumber == 4)
    {
        port = &Serial4;
    }
#endif
#ifdef FLPROG_STM32_SERIAL5
    if (portNumber == 5)
    {
        port = &Serial5;
    }
#endif
#ifdef FLPROG_STM32_SERIAL6
    if (portNumber == 6)
    {
        port = &Serial6;
    }
#endif
#ifdef FLPROG_STM32_SERIAL7
    if (portNumber == 7)
    {
        port = &Serial7;
    }
#endif
#ifdef FLPROG_STM32_SERIAL8
    if (portNumber == 8)
    {
        port = &Serial8;
    }
#endif
#ifdef FLPROG_STM32_SERIAL9
    if (portNumber == 9)
    {
        port = &Serial9;
    }
#endif
#ifdef FLPROG_STM32_SERIAL10
    if (portNumber == 10)
    {
        port = &Serial10;
    }
#endif
#ifdef FLPROG_STM32_SERIAL_LP1
    if (portNumber == 11)
    {
        port = &SerialLP1;
    }
#endif
#ifdef FLPROG_STM32_SERIAL_LP2
    if (portNumber == 12)
    {
        port = &SerialLP2;
    }
#endif
}

bool FLProgUart::hasPort()
{
#ifdef FLPROG_STM32_USB_COM0
    if (type == FLPROG_USB_UART)
    {
        return !(usbPort == 0);
    }
#endif
    return !(port == 0);
}

void FLProgUart::restartPort()
{
#ifdef FLPROG_STM32_USB_COM0
    if (type == FLPROG_USB_UART)
    {
        if (hasPort())
        {
            usbPort->end();
            begin();
            return;
        }
    }
#endif
    if (hasPort())
    {
        port->end();
        begin();
    }
}

void FLProgUart::begin()
{
#ifdef FLPROG_STM32_USB_COM0
    if (type == FLPROG_USB_UART)
    {
        if (hasPort())
        {
            usbPort->begin(speedFromCode(), serialModeFromParametrs());
            return;
        }
    }
#endif
    if (hasPort())
    {
        port->begin(speedFromCode(), serialModeFromParametrs());
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
