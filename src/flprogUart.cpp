#include "flprogUart.h"

void FlprogUartExecutor::beginUart(uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
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

void FlprogUartExecutor::endUart(uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
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

int FlprogUartExecutor::availableUart(uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
        return 0;
    }
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return 0;
    }

#ifdef FLPROG_COMPACT_LIBRARY_MODE
    return Serial.available();
#else
    return RT_HW_Base.uartAvailable(number);
#endif
}

uint8_t FlprogUartExecutor::readUart(uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
        return 0;
    }
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return 0;
    }

#ifdef FLPROG_COMPACT_LIBRARY_MODE
    return Serial.read();
#else
    return RT_HW_Base.uartRead(number);
#endif
}

void FlprogUartExecutor::writeUart(uint8_t val, uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
        return;
    }
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return;
    }

#ifdef FLPROG_COMPACT_LIBRARY_MODE
    Serial.write(val);
#else
    RT_HW_Base.uartWrite(val, number);
#endif
}

void FlprogUartExecutor::printUart(String val, uint8_t number)
{
    for (uint16_t i = 0; i < val.length(); i++)
    {
        writeUart(((uint8_t)val.charAt(i)), number);
    }
}

void FlprogUartExecutor::writeUart(uint8_t *buffer, uint16_t size, uint8_t number)
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

void FlprogUartExecutor::setSpeedUart(uint32_t speed, uint8_t number)
{
    if ((number == 100) || (number == 200))
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

#ifdef FLPROG_COMPACT_LIBRARY_MODE
    flprogCompactUart.speed = speed;
#else
    RT_HW_Base.uartSetSpeed(newSpeed, number);
#endif
    endUart(number);
}

void FlprogUartExecutor::setDataBitUart(uint8_t value, uint8_t number)
{
    if ((number == 100) || (number == 200))
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

void FlprogUartExecutor::setStopBitUart(uint8_t value, uint8_t number)
{
    if ((number == 100) || (number == 200))
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

void FlprogUartExecutor::setParityUart(uint8_t value, uint8_t number)
{
    if ((number == 100) || (number == 200))
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

void FlprogUartExecutor::setPinRxUart(uint8_t pin, uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
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

void FlprogUartExecutor::setPinTxUart(uint8_t pin, uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
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

void FlprogUartExecutor::setPinsUart(uint8_t pinRx, uint8_t pinTx, uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
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

uint32_t FlprogUartExecutor::getSpeedUart(uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
        return 115200;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.speed;
#else
    return RT_HW_Base.uartGetSpeed(number);
#endif
}

uint8_t FlprogUartExecutor::getDataBitUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.dataBit;
#else
    return RT_HW_Base.uartGetDataBit(number);
#endif
}

uint8_t FlprogUartExecutor::getStopBitUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.stopBit;

#else
    return RT_HW_Base.uartGetStopBit(number);
#endif
}

uint8_t FlprogUartExecutor::getParityUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.parity;
#else
    return RT_HW_Base.uartGetParity(number);
#endif
}

uint8_t FlprogUartExecutor::getPinRxUart(uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
        return 0;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return 0;
#else
    return RT_HW_Base.uartGetPinRX(number);
#endif
}

uint8_t FlprogUartExecutor::getPinTxUart(uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
        return 0;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return 1;
#else
    return RT_HW_Base.uartGetPinTX(number);
#endif
}

uint8_t FlprogUartExecutor::getStatusUart(uint8_t number)
{
    if ((number == 100) || (number == 200))
    {
        return 0;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.status;
#else
    return RT_HW_Base.uartGetStatus(number);
#endif
}
