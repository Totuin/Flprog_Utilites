#include "flprogI2C_Esp8266.h"

#ifdef FLPROG_CORE_ESP8266

FLProgI2C::FLProgI2C(byte busNumber)
{
    bus = busNumber;
    speed = FLPROG_I2CSPEED;
}

bool FLProgI2C::checkBus()
{
    return bus == 0;
}

bool FLProgI2C::begin(int pinSDA, int pinSCL)
{
    sda = pinSDA;
    scl = pinSCL;
    return begin();
}

bool FLProgI2C::begin()
{
    codeErr = 0; //--Очистка кода ошибки;
    if (!checkBus())
    {
        codeErr = 65;
        return false;
    }
    if (status == 1)
    {
        return true;
    }
    return beginWire0();
}

bool FLProgI2C::beginWire0()
{
    if ((sda < 0) || (scl < 0))
    {
        Wire.begin();
    }
    else
    {
        Wire.begin(sda, scl);
    }
    Wire.setClockStretchLimit(260);
    status = 1;
    return true;
}

void FLProgI2C::beginTransmission(uint8_t addr)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    Wire.beginTransmission(addr);
}

void FLProgI2C::write(const uint8_t *data, uint8_t quantity)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    Wire.write(data, quantity);
}

uint8_t FLProgI2C::endTransmission()
{
    if (!checkBus())
    {
        codeErr = 65;
        return codeErr;
    }
    return Wire.endTransmission();
}

int FLProgI2C::available()
{
    if (!checkBus())
    {
        codeErr = 65;
        return 0;
    }
    return Wire.available();
}

int FLProgI2C::read()
{
    if (!checkBus())
    {
        codeErr = 65;
        return 0;
    }
    return Wire.read();
}

uint8_t FLProgI2C::requestFrom(uint8_t address, uint8_t quantity)
{
    if (!checkBus())
    {
        codeErr = 65;
        return codeErr;
    }
    return Wire.requestFrom(address, quantity);
}

void FLProgI2C::write(uint8_t data)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    Wire.write(data);
}

void FLProgI2C::setSpeed(uint32_t newSpeed)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    if (newSpeed == speed)
    {
        return;
    }
    Wire.setClock(newSpeed);
}

void FLProgI2C::resetSpeedFrom(uint32_t newSpeed)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    if (newSpeed == speed)
    {
        return;
    }
    Wire.setClock(speed);
}
#endif