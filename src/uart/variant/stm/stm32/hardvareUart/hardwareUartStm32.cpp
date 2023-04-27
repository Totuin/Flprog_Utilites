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

FLProgUart::FLProgUart()
{
#ifdef FLPROG_HAS_UART0
#ifdef FLPROG_STM32_USB_COM0
    usbPort = &Serial;
    type = FLPROG_USB_UART;
#endif
#endif
}

FLProgUart::FLProgUart(uint8_t portNamber)
{
#ifdef FLPROG_HAS_UART0
#ifdef FLPROG_STM32_USB_COM0
    if (portNamber == 0)
    {
        usbPort = &Serial;
        type = FLPROG_USB_UART;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART1
#ifdef FLPROG_STM32_SERIAL1
    if (portNamber == 1)
    {
#ifdef FLPROG_NEED_CREATE_UART1
        HardwareSerial Serial1(FLPROG_UART1_RX, FLPROG_UART1_TX);
#endif
        port = &Serial1;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART2
#ifdef FLPROG_STM32_SERIAL2
    if (portNamber == 2)
    {
#ifdef FLPROG_NEED_CREATE_UART2
        HardwareSerial Serial2(FLPROG_UART2_RX, FLPROG_UART2_TX);
#endif
        port = &Serial2;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART3
#ifdef FLPROG_STM32_SERIAL3
    if (portNamber == 3)
    {
#ifdef FLPROG_NEED_CREATE_UART2
        HardwareSerial Serial3(FLPROG_UART3_RX, FLPROG_UART3_TX);
#endif
        port = &Serial3;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART4
#ifdef FLPROG_STM32_SERIAL4
    if (portNamber == 4)
    {
#ifdef FLPROG_NEED_CREATE_UART4
        HardwareSerial Serial4(FLPROG_UART4_RX, FLPROG_UART4_TX);
#endif
        port = &Serial4;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART5
#ifdef FLPROG_STM32_SERIAL5
    if (portNamber == 5)
    {
#ifdef FLPROG_NEED_CREATE_UART5
        HardwareSerial Serial5(FLPROG_UART5_RX, FLPROG_UART5_TX);
#endif
        port = &Serial5;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART6
#ifdef FLPROG_STM32_SERIAL6
    if (portNamber == 6)
    {
#ifdef FLPROG_NEED_CREATE_UART6
        HardwareSerial Serial6(FLPROG_UART6_RX, FLPROG_UART6_TX);
#endif
        port = &Serial6;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART7
#ifdef FLPROG_STM32_SERIAL7
    if (portNamber == 7)
    {
#ifdef FLPROG_NEED_CREATE_UART7
        HardwareSerial Serial7(FLPROG_UART7_RX, FLPROG_UART7_TX);
#endif
        port = &Serial7;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART8
#ifdef FLPROG_STM32_SERIAL8
    if (portNamber == 8)
    {
#ifdef FLPROG_NEED_CREATE_UART8
        HardwareSerial Serial8(FLPROG_UART8_RX, FLPROG_UART8_TX);
#endif
        port = &Serial8;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART9
#ifdef FLPROG_STM32_SERIAL9
    if (portNamber == 9)
    {
#ifdef FLPROG_NEED_CREATE_UART9
        HardwareSerial Serial9(FLPROG_UART9_RX, FLPROG_UART9_TX);
#endif
        port = &Serial9;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART10
#ifdef FLPROG_STM32_SERIAL10
    if (portNamber == 10)
    {
#ifdef FLPROG_NEED_CREATE_UART10
        HardwareSerial Serial10(FLPROG_UART10_RX, FLPROG_UART10_TX);
#endif
        port = &Serial10;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART11
#ifdef FLPROG_STM32_SERIAL_LP1
    if (portNamber == 11)
    {
#ifdef FLPROG_NEED_CREATE_UART_LP1
        HardwareSerial SerialLP1(FLPROG_UART_LP1_RX, FLPROG_UART_LP1_TX);
#endif
        port = &SerialLP1;
    }
#endif
#endif
#ifdef FLPROG_HAS_UART12
#ifdef FLPROG_STM32_SERIAL_LP2
    if (portNamber == 12)
    {
#ifdef FLPROG_NEED_CREATE_UART_LP2
        HardwareSerial SerialLP2(FLPROG_UART_LP2_RX, FLPROG_UART_LP2_TX);
#endif
        port = &SerialLP2;
    }
#endif
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
