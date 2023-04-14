#pragma once
#include "Arduino.h"
#include <Wire.h>
#include "flprogI2C.h"

#ifdef FLPROG_CORE_STM8

#define FLPROG_I2CSPEED 400000UL;

class FLProgI2C : public AbstractFLProgI2C
{
public:
    FLProgI2C(byte busNumber = 0);
    virtual bool begin();
    bool begin(int pinSDA, int pinSCL);
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

protected:
    bool beginWire0();
    bool beginWire1();
};

#endif