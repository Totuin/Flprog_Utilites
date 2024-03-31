#include "flprogUartBt.h"

void FlprogBtUartExecutor::beginUart(uint8_t number)
{
    if (number == 100)
    {
        return;
    }
    if (number == 200)
    {
#ifdef FLPROG_BLUETOOTH_SERIAL
        if (flprogBluetoothUart.port == 0)
        {
            flprogBluetoothUart.port = new BluetoothSerial();
        }
        if (flprogBluetoothUart.status == 0)
        {
            flprogBluetoothUart.port->begin(flprogBluetoothUart.name, flprogBluetoothUart.isMaster);
            if (flprogBluetoothUart.isMaster)
            {
                flprogBluetoothUart.port->connect(flprogBluetoothUart.parentName);
            }
            flprogBluetoothUart.status = 1;
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

void FlprogBtUartExecutor::endUart(uint8_t number)
{
    if (number == 100)
    {
        return;
    }
    if (number == 200)
    {
#ifdef FLPROG_BLUETOOTH_SERIAL
        if (flprogBluetoothUart.port != 0)
        {
            flprogBluetoothUart.port->end();
        }
        flprogBluetoothUart.status = 0;
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

int FlprogBtUartExecutor::availableUart(uint8_t number)
{
    if (number == 100)
    {
        return 0;
    }

    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return 0;
    }
    if (number == 200)
    {
#ifdef FLPROG_BLUETOOTH_SERIAL
        if (flprogBluetoothUart.port == 0)
        {
            endUart(200);
            return 0;
        }
        else
        {
            return flprogBluetoothUart.port->available();
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

uint8_t FlprogBtUartExecutor::readUart(uint8_t number)
{
    if (number == 100)
    {
        return 0;
    }
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return 0;
    }
    if (number == 200)
    {
#ifdef FLPROG_BLUETOOTH_SERIAL
        if (flprogBluetoothUart.port == 0)
        {
            endUart(200);
            return 0;
        }
        else
        {
            return flprogBluetoothUart.port->read();
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

void FlprogBtUartExecutor::writeUart(uint8_t val, uint8_t number)
{
    if (number == 100)
    {
        return;
    }
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return;
    }
    if (number == 200)
    {
#ifdef FLPROG_BLUETOOTH_SERIAL
        if (flprogBluetoothUart.port == 0)
        {
            endUart(200);
            return;
        }
        else
        {
            flprogBluetoothUart.port->write(val);
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

void FlprogBtUartExecutor::printUart(String val, uint8_t number)
{
    for (uint16_t i = 0; i < val.length(); i++)
    {
        writeUart(((uint8_t)val.charAt(i)), number);
    }
}

void FlprogBtUartExecutor::writeUart(uint8_t *buffer, uint16_t size, uint8_t number)
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

void FlprogBtUartExecutor::setSpeedUart(uint32_t speed, uint8_t number)
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

void FlprogBtUartExecutor::setDataBitUart(uint8_t value, uint8_t number)
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

void FlprogBtUartExecutor::setStopBitUart(uint8_t value, uint8_t number)
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

void FlprogBtUartExecutor::setParityUart(uint8_t value, uint8_t number)
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

void FlprogBtUartExecutor::setPinRxUart(uint8_t pin, uint8_t number)
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

void FlprogBtUartExecutor::setPinTxUart(uint8_t pin, uint8_t number)
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

void FlprogBtUartExecutor::setPinsUart(uint8_t pinRx, uint8_t pinTx, uint8_t number)
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

uint32_t FlprogBtUartExecutor::getSpeedUart(uint8_t number)
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

uint8_t FlprogBtUartExecutor::getDataBitUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.dataBit;
#else
    return RT_HW_Base.uartGetDataBit(number);
#endif
}

uint8_t FlprogBtUartExecutor::getStopBitUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.stopBit;

#else
    return RT_HW_Base.uartGetStopBit(number);
#endif
}

uint8_t FlprogBtUartExecutor::getParityUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.parity;
#else
    return RT_HW_Base.uartGetParity(number);
#endif
}

uint8_t FlprogBtUartExecutor::getPinRxUart(uint8_t number)
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

uint8_t FlprogBtUartExecutor::getPinTxUart(uint8_t number)
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

uint8_t FlprogBtUartExecutor::getStatusUart(uint8_t number)
{
    if (number == 100)
    {
        return 0;
    }
    if (number == 200)
    {
#ifdef FLPROG_BLUETOOTH_SERIAL
        return flprogBluetoothUart.status;
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

void FlprogBtUartExecutor::setBluetoothName(String name)
{
#ifdef FLPROG_BLUETOOTH_SERIAL
    flprogBluetoothUart.name = name;
    endUart(200);
    flprogBluetoothUart.port = 0;
#else
    (void)name;
#endif
}
void FlprogBtUartExecutor::setBluetoothTargetName(String name)
{
#ifdef FLPROG_BLUETOOTH_SERIAL
    flprogBluetoothUart.parentName = name;
    endUart(200);
#else
    (void)name;
#endif
}
void FlprogBtUartExecutor::setBluetoothIsMasterName(bool isMaster)
{
#ifdef FLPROG_BLUETOOTH_SERIAL
    flprogBluetoothUart.isMaster = isMaster;
    endUart(200);
#else
    (void)isMaster;
#endif
}
