#include "flprogUartSoft.h"

void FlprogSoftUartExecutor::beginUart(uint8_t number)
{
    if (number == 200)
    {
        return;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        if (flprogSoftUart.port == 0)
        {
            flprogSoftUart.port = new SoftwareSerial(flprogSoftUart.rx, flprogSoftUart.tx);
        }
        if (flprogSoftUart.status == 0)
        {
            flprogSoftUart.port->begin(flprogSoftUart.speed);
            flprogSoftUart.status = 1;
        }
#endif
        return;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    Serial.begin(flprogCompactUart.speed);
    flprogCompactUart.status = 1;
#else
    RT_HW_Base.uartBegin(number);
#endif
}

void FlprogSoftUartExecutor::endUart(uint8_t number)
{
    if (number == 200)
    {
        return;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        if (flprogSoftUart.port != 0)
        {
            flprogSoftUart.port->end();
        }
        flprogSoftUart.status = 0;
#endif
        return;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    Serial.end();
    flprogCompactUart.status = 0;
#else
    RT_HW_Base.uartEnd(number);

#endif
}

int FlprogSoftUartExecutor::availableUart(uint8_t number)
{
    if (number == 200)
    {
        return 0;
    }
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return 0;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        if (flprogSoftUart.port == 0)
        {
            endUart(100);
            return 0;
        }
        else
        {
            return flprogSoftUart.port->available();
        }
#else
        return 0;
#endif
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    return Serial.available();
#else
    return RT_HW_Base.uartAvailable(number);
#endif
}

uint8_t FlprogSoftUartExecutor::readUart(uint8_t number)
{
    if (number == 200)
    {
        return 0;
    }
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return 0;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        if (flprogSoftUart.port == 0)
        {
            endUart(100);
            return 0;
        }
        else
        {
            return flprogSoftUart.port->read();
        }
#else
        return 0;
#endif
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    return Serial.read();
#else
    return RT_HW_Base.uartRead(number);
#endif
}

void FlprogSoftUartExecutor::writeUart(uint8_t val, uint8_t number)
{
    if (number == 200)
    {
        return;
    }
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        if (flprogSoftUart.port == 0)
        {
            endUart(100);
            return;
        }
        else
        {
            flprogSoftUart.port->write(val);
        }
#endif
        return;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    Serial.write(val);
#else
    RT_HW_Base.uartWrite(val, number);
#endif
}

void FlprogSoftUartExecutor::printUart(String val, uint8_t number)
{
    for (uint16_t i = 0; i < val.length(); i++)
    {
        writeUart(((uint8_t)val.charAt(i)), number);
    }
}

void FlprogSoftUartExecutor::writeUart(uint8_t *buffer, uint16_t size, uint8_t number)
{
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return;
    }
    for (uint16_t i = 0; i < size; i++)
    {
        writeUart(buffer[i], number);
    }
}

void FlprogSoftUartExecutor::setSpeedUart(uint32_t speed, uint8_t number)
{
    if (number == 200)
    {
        return;
    }
    uint32_t newSpeed;
    if (speed < 50)
    {
        newSpeed = flprog::speedFromCode(speed);
    }
    else
    {
        newSpeed = speed;
    }

    if (getSpeedUart(number) == newSpeed)
    {
        return;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        flprogSoftUart.speed = speed;
        endUart(100);
#endif
        return;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    flprogCompactUart.speed = speed;
#else
    RT_HW_Base.uartSetSpeed(newSpeed, number);
#endif
    endUart(number);
}

void FlprogSoftUartExecutor::setDataBitUart(uint8_t value, uint8_t number)
{
    if ((number == 200) || (number == 100))
    {
        return;
    }
    if (getDataBitUart(number) == value)
    {
        return;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    flprogCompactUart.dataBit = value;
#else
    RT_HW_Base.uartSetDataBit(value, number);
#endif
    endUart(number);
}

void FlprogSoftUartExecutor::setStopBitUart(uint8_t value, uint8_t number)
{
    if ((number == 200) || (number == 100))
    {
        return;
    }
    if (getStopBitUart(number) == value)
    {
        return;
    }

#ifdef FLPROG_COMPACT_LIBRARY_MODE
    flprogCompactUart.stopBit = value;
#else
    RT_HW_Base.uartSetStopBit(value, number);
#endif
    endUart(number);
}

void FlprogSoftUartExecutor::setParityUart(uint8_t value, uint8_t number)
{
    if ((number == 200) || (number == 100))
    {
        return;
    }
    if (getParityUart(number) == value)
    {
        return;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    flprogCompactUart.parity = value;
#else
    RT_HW_Base.uartSetParity(value, number);
#endif
    endUart(number);
}

void FlprogSoftUartExecutor::setPinRxUart(uint8_t pin, uint8_t number)
{
    if (number == 200)
    {
        return;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        if (getPinRxUart(100) == pin)
        {
            return;
        }
        flprogSoftUart.rx = pin;
        endUart(100);
        flprogSoftUart.port = 0;
#endif
        return;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)pin;
    (void)number;
#else
    if (getPinRxUart(number) == pin)
    {
        return;
    }
    RT_HW_Base.uartSetPinRX(pin, number);
    endUart(number);
#endif
}

void FlprogSoftUartExecutor::setPinTxUart(uint8_t pin, uint8_t number)
{
    if (number == 200)
    {
        return;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        if (getPinTxUart(100) == pin)
        {
            return;
        }
        flprogSoftUart.tx = pin;
        endUart(100);
        flprogSoftUart.port = 0;
#endif
        return;
    }

#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)pin;
    (void)number;
#else
    if (getPinTxUart(number) == pin)
    {
        return;
    }
    RT_HW_Base.uartSetPinTX(pin, number);
    endUart(number);
#endif
}

void FlprogSoftUartExecutor::setPinsUart(uint8_t pinRx, uint8_t pinTx, uint8_t number)
{
    if (number == 200)
    {
        return;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        setPinRxUart(pinRx, 100);
        setPinTxUart(pinTx, 100);
#endif
        return;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)pinRx;
    (void)pinTx;
    (void)number;
#else
    if (getPinRxUart(number) == pinRx)
    {
        if (getPinTxUart(number) == pinTx)
        {
            return;
        }
    }
    RT_HW_Base.uartSetPins(pinRx, pinTx, number);
    endUart(number);
#endif
}

uint32_t FlprogSoftUartExecutor::getSpeedUart(uint8_t number)
{
    if (number == 200)
    {
        return 115200;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        return flprogSoftUart.speed;
#else
        return 115200;
#endif
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.speed;
#else
    return RT_HW_Base.uartGetSpeed(number);
#endif
}

uint8_t FlprogSoftUartExecutor::getDataBitUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.dataBit;
#else
    return RT_HW_Base.uartGetDataBit(number);
#endif
}

uint8_t FlprogSoftUartExecutor::getStopBitUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.stopBit;

#else
    return RT_HW_Base.uartGetStopBit(number);
#endif
}

uint8_t FlprogSoftUartExecutor::getParityUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.parity;
#else
    return RT_HW_Base.uartGetParity(number);
#endif
}

uint8_t FlprogSoftUartExecutor::getPinRxUart(uint8_t number)
{
    if (number == 200)
    {
        return 0;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        return flprogSoftUart.rx;
#else
        return 0;
#endif
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return 0;
#else
    return RT_HW_Base.uartGetPinRX(number);
#endif
}

uint8_t FlprogSoftUartExecutor::getPinTxUart(uint8_t number)
{
    if (number == 200)
    {
        return 0;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        return flprogSoftUart.tx;
#else
        return 0;
#endif
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return 1;
#else
    return RT_HW_Base.uartGetPinTX(number);
#endif
}

uint8_t FlprogSoftUartExecutor::getStatusUart(uint8_t number)
{
    if (number == 200)
    {
        return 0;
    }
    if (number == 100)
    {
#ifdef FLPROG_SOFTWARE_SERIAL
        return flprogSoftUart.status;
#else
        return 0;
#endif
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.status;
#else
    return RT_HW_Base.uartGetStatus(number);
#endif
}

