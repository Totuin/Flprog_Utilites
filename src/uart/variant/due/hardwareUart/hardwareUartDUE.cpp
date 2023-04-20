#include "hardwareUartDUE.h"

#ifdef FLPROG_CORE_AVR_DUE

FLProgUart::FLProgUart()
{
    port = &Serial;
}

FLProgUart::FLProgUart(uint8_t portNumber)
{
    if (portNumber == 0)
    {
        port = &Serial;
    }
    if (portNumber == 1)
    {
        port = &Serial1;
    }
    if (portNumber == 2)
    {
        port = &Serial2;
    }
    if (portNumber == 3)
    {
        port = &Serial3;
    }
}

void FLProgUart::restartPort()
{
    if (!portIsInit)
    {
        return;
    }
    if (hasPort())
    {
        port->end();
        begin();
    }
}

void FLProgUart::begin()
{
    portIsInit = true;
    if (hasPort())
    {
        if (port == &Serial1)
        {
            Serial1.begin(speedFromCode(), serialModeFromParametrs());
            return;
        }
        if (port == &Serial2)
        {
            Serial2.begin(speedFromCode(), serialModeFromParametrs());
            return;
        }
        if (port == &Serial3)
        {
            Serial3.begin(speedFromCode(), serialModeFromParametrs());
            return;
        }
        Serial.begin(speedFromCode(), serialModeFromParametrs());
    }
}

void FLProgUart::begin(int32_t speed, UARTClass::UARTModes mode)
{
    setCodeFromSpeed(speed);
    setSerialMode(mode);
    begin();
}

UARTClass::UARTModes FLProgUart::serialModeFromParametrs()
{
    return flprog::serialModeFromInt(serialCodeForParametrs());
}

void FLProgUart::setSerialMode(UARTClass::UARTModes mode)
{
    switch (mode)
    {
    case SERIAL_8N1:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_8E1:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_8O1:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    }
    portDataBits = FLPROG_PORT_DATA_BITS_8;
    portStopBits = FLPROG_PORT_STOP_BITS_1;
    portParity = FLPROG_PORT_PARITY_NONE;
}

#endif