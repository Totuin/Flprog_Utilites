#include "flprogI2C_Stm32.h"

#ifdef FLPROG_CORE_STM32
TwoWire Wire1(PB11, PB10);

FLProgI2C::FLProgI2C(byte busNumber)
{
    bus = busNumber;
    speed = FLPROG_I2CSPEED;
}

bool FLProgI2C::checkBus()
{
    if (bus == 0)
    {
        return true;
    }
    if (bus == 1)
    {

        return true;
    }
    return false;
}

bool FLProgI2C::begin(int pinSDA, int pinSCL)
{
    sda = pinSDA;
    scl = pinSCL;
    return begin();
}

bool FLProgI2C::begin()
{
    codeErr = 0;
    if (!checkBus())
    {
        codeErr = 65;
        return false;
    }
    if (status == 1)
    {
        return true;
    }
    if (bus == 0)
    {
        return beginWire0();
    }
    if (bus == 1)
    {

        return beginWire1();
    }
    return false;
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
    Wire1.setClock(speed);
    status = 1;
    return true;
}

bool FLProgI2C::beginWire1()
{
    if ((sda < 0) || (scl < 0))
    {
        Wire1.begin();
    }
    else
    {
        Wire1.begin(sda, scl);
    }

    Wire1.setClock(speed);
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
    if (bus == 0)
    {
        Wire.beginTransmission(addr);
    }
    if (bus == 1)
    {
        Wire1.beginTransmission(addr);
    }
}

void FLProgI2C::write(const uint8_t *data, uint8_t quantity)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    if (bus == 0)
    {
        Wire.write(data, quantity);
    }
    if (bus == 1)
    {
        Wire1.write(data, quantity);
    }
}

uint8_t FLProgI2C::endTransmission()
{
    if (!checkBus())
    {
        codeErr = 65;
        return codeErr;
    }
    if (bus == 0)
    {
        return Wire.endTransmission();
    }
    if (bus == 1)
    {
        return Wire1.endTransmission();
    }
    return 0;
}

int FLProgI2C::available()
{
    if (!checkBus())
    {
        codeErr = 65;
        return 0;
    }
    if (bus == 0)
    {
        return Wire.available();
    }
    if (bus == 1)
    {
        return Wire1.available();
    }
    return 0;
}

int FLProgI2C::read()
{
    if (!checkBus())
    {
        codeErr = 65;
        return 0;
    }
    if (bus == 0)
    {
        return Wire.read();
    }
    if (bus == 1)
    {
        return Wire1.read();
    }
    return 0;
}

uint8_t FLProgI2C::requestFrom(uint8_t address, uint8_t quantity)
{
    if (!checkBus())
    {
        codeErr = 65;
        return codeErr;
    }
    if (bus == 0)
    {
        return Wire.requestFrom(address, quantity);
    }
    if (bus == 1)
    {
        return Wire1.requestFrom(address, quantity);
    }
    return 0;
}

void FLProgI2C::write(uint8_t data)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    if (bus == 0)
    {
        Wire.write(data);
    }
    if (bus == 1)
    {
        Wire1.write(data);
    }
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
    if (bus == 0)
    {
        Wire.setClock(newSpeed);
    }
    if (bus == 1)
    {
        Wire1.setClock(newSpeed);
    }
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
    if (bus == 0)
    {
        Wire.setClock(speed);
    }

    if (bus == 1)
    {
        Wire1.setClock(speed);
    }
}
#endif