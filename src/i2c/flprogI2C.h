#pragma once
#include "Arduino.h"
#include <Wire.h>
#include "./flprogUtilites.h"

#ifdef CORE_ESP8266
#define FLPROG_I2CSPEED 100000UL;
#else
#define FLPROG_I2CSPEED 400000UL;
#endif

#if defined(CORE_ESP32) || defined(CORE_STM32)
#define FLPROG_CAN_USE_I2C_1
#endif

class FLProgI2C
{
public:
    FLProgI2C() { FLProgI2C(0); };
    FLProgI2C(byte busNumber);
    virtual bool begin();
    bool begin(int pinSDA, int pinSCL);
    bool findAddr(uint8_t addr);
    uint8_t getErrorCode() { return codeErr; };
    uint8_t fullWrite(uint8_t addr, uint8_t data);
    uint8_t fullWrite(uint8_t addr, const uint8_t *data, uint8_t quantity);
    uint8_t fullRequestFrom(uint8_t address, uint8_t quantity);

    virtual void beginTransmission(uint8_t addr);
    virtual void write(const uint8_t *data, uint8_t quantity);
    virtual void write(uint8_t data);
    virtual uint8_t endTransmission();
    virtual int available();
    virtual int read();
    virtual uint8_t requestFrom(uint8_t address, uint8_t quantity);
    virtual uint8_t waitingForData(uint8_t count);
    virtual void setSpeed(uint32_t newSpeed);
    virtual void resetSpeedFrom(uint32_t newSpeed);
    virtual bool checkBus();

protected:
    uint8_t bus;
    bool busy = false;
    uint8_t status = 0;
    uint8_t codeErr = 0;
    int sda = -1;
    int scl = -1;
    uint32_t speed = FLPROG_I2CSPEED;
    bool beginWire0();
#ifdef FLPROG_CAN_USE_I2C_1
    bool beginWire1();
#endif
};

class FLProgTCA9548A
{
public:
    FLProgTCA9548A(FLProgI2C *device, uint8_t deviceAddress);
    FLProgTCA9548A(FLProgI2C *device);
    void beginTransmission(uint8_t addr, uint8_t chanel);
    void write(const uint8_t *data, uint8_t quantity, uint8_t chanel);
    void write(uint8_t data, uint8_t chanel);
    uint8_t endTransmission();
    int available(uint8_t chanel);
    int read(uint8_t chanel);
    uint8_t requestFrom(uint8_t address, uint8_t quantity, uint8_t chanel);
    void setSpeed(uint32_t newSpeed, uint8_t chanel);
    void resetSpeedFrom(uint32_t newSpeed, uint8_t chanel);
    bool checkBus();

private:
    void switchToChanel(uint8_t chanel);
    FLProgI2C *i2cDevice;
    uint8_t address;
    uint8_t currentChanel = 10;
    uint8_t errorCode = 0;
};

class FLProgVirtualI2C : public FLProgI2C
{
public:
    FLProgVirtualI2C(FLProgTCA9548A *parentDevice, uint8_t chanelOnParent);
    virtual bool begin();
    virtual void beginTransmission(uint8_t addr);
    virtual void write(const uint8_t *data, uint8_t quantity);
    virtual void write(uint8_t data);
    virtual uint8_t endTransmission();
    virtual int available();
    virtual int read();
    virtual uint8_t requestFrom(uint8_t address, uint8_t quantity);
    virtual void setSpeed(uint32_t newSpeed);
    virtual void resetSpeedFrom(uint32_t newSpeed);
    virtual bool checkBus();

private:
    FLProgTCA9548A *parent;
    uint8_t chanel;
};
