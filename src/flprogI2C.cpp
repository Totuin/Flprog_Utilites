#include "flprogI2C.h"



//-------- AbstractFLProgI2C-----------

bool AbstractFLProgI2C::begin(int pinSDA, int pinSCL)
{
    sda = pinSDA;
    scl = pinSCL;
    return begin();
}

bool AbstractFLProgI2C::checkBus()
{
    return !(oneWare == 0);
}

bool AbstractFLProgI2C::findAddr(uint8_t addr)
{
    if (!checkBus())
    {
        codeErr = 65;
        return false;
    }
    codeErr = 0;
    if (addr > 254)
    {
        codeErr = 61;
        return false;
    }
    beginTransmission(addr);
    codeErr = endTransmission();
    return (codeErr == 0);
}

uint8_t AbstractFLProgI2C::fullWrite(uint8_t addr, uint8_t data)
{
    beginTransmission(addr);
    write(data);
    codeErr = endTransmission();
    return codeErr;
}

uint8_t AbstractFLProgI2C::fullWrite(uint8_t addr, const uint8_t *data, uint8_t quantity)
{
    beginTransmission(addr);
    write(data, quantity);
    codeErr = endTransmission();
    return codeErr;
}

uint8_t AbstractFLProgI2C::fullRequestFrom(uint8_t address, uint8_t quantity)
{
    uint8_t result = requestFrom(address, quantity);
    if (quantity != result)
    {
        codeErr = 80;
        return codeErr;
    }
    return waitingForData(quantity);
}

uint8_t AbstractFLProgI2C::fullRead(uint8_t addr, uint8_t *data, uint8_t quantity)
{
    codeErr = fullRequestFrom(addr, quantity);
    if (codeErr)
    {
        return codeErr;
    }
    for (uint8_t i = 0; i < quantity; i++)
    {
        data[i] = read();
    }
    return codeErr;
}

uint8_t AbstractFLProgI2C::fullRead(uint8_t addr, uint16_t *data, uint8_t quantity)
{
    codeErr = fullRequestFrom(addr, quantity);
    if (codeErr)
    {
        return codeErr;
    }
    for (uint8_t i = 0; i < quantity; i++)
    {
        data[i] = read();
    }
    return codeErr;
}

uint8_t AbstractFLProgI2C::fullRead(uint8_t addr, uint32_t *data, uint8_t quantity)
{
    codeErr = fullRequestFrom(addr, quantity);
    if (codeErr)
    {
        return codeErr;
    }
    for (uint8_t i = 0; i < quantity; i++)
    {
        data[i] = read();
    }
    return codeErr;
}

uint8_t AbstractFLProgI2C::waitingForData(uint8_t count)
{
    uint32_t timeOut = 150 * count;
    uint32_t startTime = micros();
    do
    {
        if ((available()) >= count)
        {
            return 0;
        }
        if (flprog::isTimerMicros(startTime, timeOut))
        {
            return 6;
        }
    } while (1);
}

uint8_t AbstractFLProgI2C::fullReadReg(uint8_t addr, uint8_t reg)
{
    uint8_t data[1];
    codeErr = fullWrite(addr, reg);
    if (codeErr)
    {
        return 0;
    }
    codeErr = fullRead(addr, data, 1);
    if (codeErr)
    {
        return 0;
    }
    return data[0];
}

uint8_t AbstractFLProgI2C::fullWriteReg(uint8_t addr, uint8_t reg, uint8_t value)
{
    uint8_t data[2];
    data[0] = reg;
    data[1] = value;
    codeErr = fullWrite(addr, data, 2);
    return codeErr;
}

int AbstractFLProgI2C::available()
{
    if (!checkBus())
    {
        codeErr = 65;
        return 0;
    }
    return oneWare->available();
}

int AbstractFLProgI2C::read()
{
    if (!checkBus())
    {
        codeErr = 65;
        return 0;
    }
    return oneWare->read();
}

void AbstractFLProgI2C::write(uint8_t data)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    oneWare->write(data);
}

uint8_t AbstractFLProgI2C::requestFrom(uint8_t address, uint8_t quantity)
{
    if (!checkBus())
    {
        codeErr = 65;
        return codeErr;
    }
    return oneWare->requestFrom(address, quantity);
}

uint8_t AbstractFLProgI2C::endTransmission()
{
    if (!checkBus())
    {
        codeErr = 65;
        return codeErr;
    }
    return oneWare->endTransmission();
}

void AbstractFLProgI2C::write(const uint8_t *data, uint8_t quantity)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    oneWare->write(data, quantity);
}

void AbstractFLProgI2C::beginTransmission(uint8_t addr)
{
    if (!checkBus())
    {
        codeErr = 65;
        return;
    }
    oneWare->beginTransmission(addr);
}

void AbstractFLProgI2C::setSpeed(uint32_t newSpeed)
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
    oneWare->setClock(newSpeed);
}

void AbstractFLProgI2C::resetSpeedFrom(uint32_t newSpeed)
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
    oneWare->setClock(speed);
}
//------------------------FLProgTCA9548A------------------

FLProgTCA9548A::FLProgTCA9548A(AbstractFLProgI2C *device, uint8_t deviceAddress)
{
    i2cDevice = device;
    address = deviceAddress;
}

FLProgTCA9548A::FLProgTCA9548A(AbstractFLProgI2C *device)
{
    i2cDevice = device;
    address = 0x70;
}

void FLProgTCA9548A::beginTransmission(uint8_t addr, uint8_t chanel)
{
    switchToChanel(chanel);
    i2cDevice->beginTransmission(addr);
}

void FLProgTCA9548A::write(const uint8_t *data, uint8_t quantity, uint8_t chanel)
{
    i2cDevice->write(data, quantity);
}

void FLProgTCA9548A::write(uint8_t data, uint8_t chanel)
{
    i2cDevice->write(data);
}

uint8_t FLProgTCA9548A::endTransmission()
{

    return i2cDevice->endTransmission();
}

int FLProgTCA9548A::available(uint8_t chanel)
{
    switchToChanel(chanel);
    return i2cDevice->available();
}

int FLProgTCA9548A::read(uint8_t chanel)
{
    switchToChanel(chanel);
    return i2cDevice->read();
}

uint8_t FLProgTCA9548A::requestFrom(uint8_t address, uint8_t quantity, uint8_t chanel)
{
    switchToChanel(chanel);
    return i2cDevice->requestFrom(address, quantity);
}

void FLProgTCA9548A::setSpeed(uint32_t newSpeed, uint8_t chanel)
{
    switchToChanel(chanel);
    return i2cDevice->setSpeed(newSpeed);
}

void FLProgTCA9548A::resetSpeedFrom(uint32_t newSpeed, uint8_t chanel)
{
    switchToChanel(chanel);
    return i2cDevice->resetSpeedFrom(newSpeed);
}

bool FLProgTCA9548A::checkBus()
{
    return i2cDevice->checkBus();
}

void FLProgTCA9548A::switchToChanel(uint8_t chanel)
{
    if (chanel == currentChanel)
    {
        return;
    }

    if (chanel > 7)
    {
        errorCode = 80;
        return;
    }

    i2cDevice->beginTransmission(address);
    i2cDevice->write(1 << chanel);
    errorCode = i2cDevice->endTransmission();
    currentChanel = chanel;
}

//------------------------------FLProgVirtualI2C------------------

FLProgVirtualI2C::FLProgVirtualI2C(FLProgTCA9548A *parentDevice, uint8_t chanelOnParent)
{
    parent = parentDevice;
    chanel = chanelOnParent;
}

bool FLProgVirtualI2C::begin()
{
    return true;
}

void FLProgVirtualI2C::beginTransmission(uint8_t addr)
{
    parent->beginTransmission(addr, chanel);
}

void FLProgVirtualI2C::write(const uint8_t *data, uint8_t quantity)
{
    parent->write(data, quantity, chanel);
}

void FLProgVirtualI2C::write(uint8_t data)
{
    parent->write(data, chanel);
}

uint8_t FLProgVirtualI2C::endTransmission()
{
    return parent->endTransmission();
}

int FLProgVirtualI2C::available()
{
    return parent->available(chanel);
}

int FLProgVirtualI2C::read()
{
    return parent->read(chanel);
}

uint8_t FLProgVirtualI2C::requestFrom(uint8_t address, uint8_t quantity)
{
    return parent->requestFrom(address, quantity, chanel);
}

void FLProgVirtualI2C::setSpeed(uint32_t newSpeed)
{
    parent->setSpeed(newSpeed, chanel);
}

void FLProgVirtualI2C::resetSpeedFrom(uint32_t newSpeed)
{
    parent->resetSpeedFrom(newSpeed, chanel);
}

bool FLProgVirtualI2C::checkBus()
{
    return parent->checkBus();
}