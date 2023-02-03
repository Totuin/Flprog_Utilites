#include "flprogI2C.h"

#ifdef CORE_STM32
TwoWire Wire1(PB11, PB10);
#endif

FLProgI2C::FLProgI2C(byte busNumber)
{
    bus = busNumber;
}

bool FLProgI2C::checkBus()
{
    if (bus == 0)
    {
        return true;
    }
#ifdef FLPROG_CAN_USE_I2C_1
    if (bus == 1)
    {

        return true;
    }
#endif
    return false;
}

bool FLProgI2C::begin(int pinSDA, int pinSCL)
{
    sda = pinSDA;
    scl = pinSCL;
    return begin();
}

// ---------BEGIN---------

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
    if (bus == 0)
    {
        return beginWire0();
    }
#ifdef FLPROG_CAN_USE_I2C_1
    if (bus == 1)
    {

        return beginWire1();
    }
#endif
    return false;
}

bool FLProgI2C::beginWire0()
{
#ifdef CORE_AVR
    Wire.begin(); //--Инициализация как Master;
#endif

#if defined(CORE_ESP8266) || defined(CORE_STM32)
    if ((sda < 0) || (scl < 0))
    {
        Wire.begin();
    }
    else
    {
        Wire.begin(sda, scl); //--Установка номеров пинов SDA,SCL и инициализация как Master;
    }

#endif
#ifdef CORE_ESP8266
    Wire.setClockStretchLimit(260); //--Ограничение лимита по времени;
#endif
#ifdef CORE_ESP32
    Wire.begin(sda, scl, speed);
#endif
#ifndef CORE_ESP32
    Wire.setClock(speed); //--Установка частоты шины;
#endif
    status = 1; //--Установка статуса Master и успешный выход;
    return true;
}

#ifdef FLPROG_CAN_USE_I2C_1
bool FLProgI2C::beginWire1()
{
#ifdef CORE_STM32
    if ((sda < 0) || (scl < 0))
    {
        Wire1.begin();
    }
    else
    {
        Wire1.begin(sda, scl); //--Установка номеров пинов SDA,SCL и инициализация как Master;
    }

    Wire1.setClock(speed); //--Установка частоты шины;
#endif
#ifdef CORE_ESP32
    Wire1.begin(sda, scl, speed);
    Wire1.setClock(speed); //--Установка частоты шины;
#endif
    status = 1; //--Установка статуса Master и успешный выход;
    return true;
}
#endif

// ---------END_BEGIN---------

bool FLProgI2C::findAddr(uint8_t addr)
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
#ifdef FLPROG_CAN_USE_I2C_1
    if (bus == 1)
    {
        Wire1.beginTransmission(addr);
    }
#endif
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
#ifdef FLPROG_CAN_USE_I2C_1
    if (bus == 1)
    {
        Wire1.write(data, quantity);
    }
#endif
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
#ifdef FLPROG_CAN_USE_I2C_1
    if (bus == 1)
    {
        return Wire1.endTransmission();
    }
#endif

    return 0;
}

int FLProgI2C::available()
{
    if (bus == 0)
    {
        return Wire.available();
    }
#ifdef FLPROG_CAN_USE_I2C_1
    if (bus == 1)
    {
        return Wire1.available();
    }
#endif
    return 0;
}

int FLProgI2C::read()
{
    if (bus == 0)
    {
        return Wire.read();
    }
#ifdef FLPROG_CAN_USE_I2C_1
    if (bus == 1)
    {
        return Wire1.read();
    }
#endif
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
#ifdef FLPROG_CAN_USE_I2C_1
    if (bus == 1)
    {
        return Wire1.requestFrom(address, quantity);
    }
#endif
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
#ifdef FLPROG_CAN_USE_I2C_1
    if (bus == 1)
    {
        Wire1.write(data);
    }
#endif
}

uint8_t FLProgI2C::waitingForData(uint8_t count)
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
#ifdef FLPROG_CAN_USE_I2C_1
    if (bus == 1)
    {
        Wire1.setClock(newSpeed);
    }
#endif
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
#ifdef FLPROG_CAN_USE_I2C_1
    if (bus == 1)
    {
        Wire1.setClock(speed);
    }
#endif
}

//--------------FLProgTCA9548A----------

FLProgTCA9548A::FLProgTCA9548A(FLProgI2C *device, uint8_t deviceAddress)
{
    i2cDevice = device;
    address = deviceAddress;
}

FLProgTCA9548A::FLProgTCA9548A(FLProgI2C *device)
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

//--------------FLProgVirtualI2C----------

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