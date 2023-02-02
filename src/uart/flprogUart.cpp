#include "flprogUart.h"

// --------------FLProgSoftwareUart------------------------
#ifndef CORE_ESP32
FLProgSoftwareUart::FLProgSoftwareUart(byte receivePin, byte transmitPin)
{
    softwarePort = new SoftwareSerial(receivePin, transmitPin);
}

bool FLProgSoftwareUart::hasPort()
{
    return !(softwarePort == 0);
}

void FLProgSoftwareUart::restartPort()
{
    softwarePort->end();
    begin();
    return;
}

void FLProgSoftwareUart::begin()
{
    softwarePort->begin(speedFromCode());
    return;
}

#endif
//----------------------FLProgBluetoothUart---------------
#ifdef CORE_ESP32
FLProgBluetoothUart::FLProgBluetoothUart(String name)
{
    bluetoothPort = new BluetoothSerial();
    deviceName = name;
    type = FLPROG_BLUETOOTH_UART;
}

void FLProgBluetoothUart::beBluetoothMaster()
{
    if (isMaster)
    {
        return;
    }
    isMaster = true;
    restartPort();
}

void FLProgBluetoothUart::beBluetoothSlave()
{
    if (!isMaster)
    {
        return;
    }
    isMaster = false;
    restartPort();
}

void FLProgBluetoothUart::setDeviceName(String name)
{
    if (deviceName.equals(name))
    {
        return;
    }
    deviceName = name;
    restartPort();
}

void FLProgBluetoothUart::setPartnerName(String name)
{
    if (partnerName.equals(name))
    {
        return;
    }
    partnerName = name;
    restartPort();
}

bool FLProgBluetoothUart::hasPort()
{
    return !(bluetoothPort == 0);
}

void FLProgBluetoothUart::restartPort()
{
    bluetoothPort->end();
    begin();
}

void FLProgBluetoothUart::begin()
{
    bluetoothPort->begin(deviceName);
    if (isMaster)
    {
        bluetoothPort->connect(partnerName);
    }
    return;
}

#endif
//-------------FLProgUart-------------------------

Stream *FLProgUart::uartPort()
{
#ifdef STM32_USB_COM0
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

#ifdef STM32_USB_COM0
FLProgUart::FLProgUart(USBSerial *port)
{
    usbPort = port;
    type = FLPROG_USB_UART;
}
#endif

bool FLProgUart::hasPort()
{
#ifdef STM32_USB_COM0
    if (type == FLPROG_USB_UART)
    {
        return !(usbPort == 0);
    }
#endif
    return !(port == 0);
}

void FLProgUart::restartPort()
{
#ifdef STM32_USB_COM0
    if (type == FLPROG_USB_UART)
    {
        usbPort->end();
        begin();
        return;
    }
#endif
    port->end();
    begin();
}

void FLProgUart::begin()
{
#ifdef STM32_USB_COM0
    if (type == FLPROG_USB_UART)
    {
        usbPort->begin(speedFromCode(), serialModeFromParametrs());
        return;
    }
#endif
    port->begin(speedFromCode(), serialModeFromParametrs());
}

void FLProgUart::begin(int32_t speed)
{
    setCodeFromSpeed(speed);
    begin();
}

#ifdef CORE_ESP8266
void FLProgUart::begin(int32_t speed, SerialConfig mode)
{
    setCodeFromSpeed(speed);
    begin();
}
#else
void FLProgUart::begin(int32_t speed, int mode)
{
    setCodeFromSpeed(speed);
    begin();
}
#endif

void FLProgUart::setPortSpeed(byte speed)
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

void FLProgUart::setPortDataBits(byte dataBits)
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

void FLProgUart::setPortStopBits(byte stopBits)
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

void FLProgUart::setPortParity(byte parity)
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

#ifdef CORE_ESP8266
SerialConfig FLProgUart::serialModeFromParametrs()
{
    return serialModeFromInt(serialCodeForParametrs());
}

void FLProgUart::setSerialMode(SerialConfig mode)
{
    switch (mode)
    {
    case SERIAL_5N1:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_6N1:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_7N1:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_8N1:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_5N2:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_6N2:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_7N2:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_8N2:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_5E1:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_6E1:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_7E1:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_8E1:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_5E2:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_6E2:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_7E2:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_8E2:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_5O1:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_6O1:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_7O1:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_8O1:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_5O2:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_6O2:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_7O2:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_8O2:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    }
    portDataBits = PORT_DATA_BITS_8;
    portStopBits = PORT_STOP_BITS_1;
    portParity = PORT_PARITY_NONE;
}

SerialConfig FLProgUart::serialModeFromInt(int16_t code)
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

#else

int FLProgUart::serialModeFromParametrs()
{
    return serialModeFromInt(serialCodeForParametrs());
}

int FLProgUart::serialModeFromInt(int16_t code)
{
    switch (code)
    {
#ifdef CORE_STM32
#ifdef UART_WORDLENGTH_7B
    case 0x04:
        return SERIAL_7N1;
        break;
    case 0x0C:
        return SERIAL_7N2;
        break;
    case 0x22:
        return SERIAL_6E1;
        break;
    case 0x2A:
        return SERIAL_6E2;
        break;
    case 0x32:
        return SERIAL_6O1;
        break;
    case 0x3A:
        return SERIAL_6O2;
        break;
#endif
#endif

#ifdef CORE_STM8
#ifdef UART_WORDLENGTH_7B
    case 0x04:
        return SERIAL_7N1;
        break;
    case 0x0C:
        return SERIAL_7N2;
        break;
    case 0x22:
        return SERIAL_6E1;
        break;
    case 0x2A:
        return SERIAL_6E2;
        break;
    case 0x32:
        return SERIAL_6O1;
        break;
    case 0x3A:
        return SERIAL_6O2;
        break;
#endif
#endif

#ifndef CORE_STM32
#ifndef CORE_STM8
    case 0x00:
        return SERIAL_5N1;
        break;
    case 0x02:
        return SERIAL_6N1;
        break;
    case 0x04:
        return SERIAL_7N1;
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
    case 0x20:
        return SERIAL_5E1;
        break;
    case 0x22:
        return SERIAL_6E1;
        break;
    case 0x28:
        return SERIAL_5E2;
        break;
    case 0x2A:
        return SERIAL_6E2;
        break;
    case 0x30:
        return SERIAL_5O1;
        break;
    case 0x32:
        return SERIAL_6O1;
        break;
    case 0x38:
        return SERIAL_5O2;
        break;
    case 0x3A:
        return SERIAL_6O2;
        break;
#endif
#endif

    case 0x06:
        return SERIAL_8N1;
        break;
    case 0x0E:
        return SERIAL_8N2;
        break;
    case 0x24:
        return SERIAL_7E1;
        break;
    case 0x26:
        return SERIAL_8E1;
        break;
    case 0x2C:
        return SERIAL_7E2;
        break;
    case 0x2E:
        return SERIAL_8E2;
        break;
    case 0x34:
        return SERIAL_7O1;
        break;
    case 0x36:
        return SERIAL_8O1;
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

void FLProgUart::setSerialMode(int16_t mode)
{
    switch (mode)
    {
    case 0x00:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case 0x02:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case 0x04:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case 0x06:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case 0x08:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case 0x0A:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case 0x0C:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case 0x0E:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_NONE;
        return;
        break;
    case 0x20:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case 0x22:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case 0x24:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case 0x26:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case 0x28:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case 0x2A:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case 0x2C:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case 0x2E:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_EVEN;
        return;
        break;
    case 0x30:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case 0x32:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case 0x34:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case 0x36:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_1;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case 0x38:
        portDataBits = PORT_DATA_BITS_5;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case 0x3A:
        portDataBits = PORT_DATA_BITS_6;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case 0x3C:
        portDataBits = PORT_DATA_BITS_7;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    case 0x3E:
        portDataBits = PORT_DATA_BITS_8;
        portStopBits = PORT_STOP_BITS_2;
        portParity = PORT_PARITY_ODD;
        return;
        break;
    }
    portDataBits = PORT_DATA_BITS_8;
    portStopBits = PORT_STOP_BITS_1;
    portParity = PORT_PARITY_NONE;
}

#endif

int FLProgUart::serialCodeForParametrs()
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

long FLProgUart::speedFromCode()
{
    switch (portSpeed)
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

void FLProgUart::setCodeFromSpeed(int32_t speed)
{
    switch (speed)
    {
    case 300:
        portSpeed = SPEED_300;
        return;
        break;
    case 600:
        portSpeed = SPEED_600;
        return;
        break;
    case 1200:
        portSpeed = SPEED_1200;
        return;
        break;
    case 2400:
        portSpeed = SPEED_2400;
        return;
        break;
    case 4800:
        portSpeed = SPEED_4800;
        return;
        break;
    case 9600:
        portSpeed = SPEED_9600;
        return;
        break;
    case 14400:
        portSpeed = SPEED_14400;
        return;
        break;
    case 19200:
        portSpeed = SPEED_19200;
        return;
        break;
    case 28800:
        portSpeed = SPEED_28800;
        return;
        break;
    case 38400:
        portSpeed = SPEED_38400;
        return;
        break;
    case 57600:
        portSpeed = SPEED_57600;
        return;
        break;
    case 115200:
        portSpeed = SPEED_115200;
        return;
        break;
    default:
        portSpeed = SPEED_9600;
        return;
        break;
    }
}

void FLProgUart::print(String str)
{
    uartPort()->print(str);
}
void FLProgUart::print(const char str[])
{
    uartPort()->print(str);
}
void FLProgUart::print(char str)
{
    uartPort()->print(str);
}
void FLProgUart::print(byte val, int mode)
{
    uartPort()->print(val, mode);
}
void FLProgUart::print(int val, int mode)
{
    uartPort()->print(val, mode);
}
void FLProgUart::print(long val, int mode)
{
    uartPort()->print(val, mode);
}
void FLProgUart::print(unsigned long val, int mode)
{
    uartPort()->print(val, mode);
}
void FLProgUart::print(float val, int mode)
{
    uartPort()->print(val, mode);
}

void FLProgUart::println(String str)
{
    uartPort()->println(str);
}
void FLProgUart::println(char str)
{
    uartPort()->println(str);
}
void FLProgUart::println(const char str[])
{
    uartPort()->println(str);
}
void FLProgUart::println(byte val, int mode)
{
    uartPort()->println(val, mode);
}
void FLProgUart::println(int val, int mode)
{
    uartPort()->println(val, mode);
}
void FLProgUart::println(long val, int mode)
{
    uartPort()->println(val, mode);
}
void FLProgUart::println(unsigned long val, int mode)
{
    uartPort()->println(val, mode);
}
void FLProgUart::println(float val, int mode)
{
    uartPort()->println(val, mode);
}
void FLProgUart::println()
{
    uartPort()->println();
}