#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

class FLProgI2cBasicSensor
{
public:
    uint8_t getError() { return codeError; };

protected:
    FLProgI2C *i2cDevice;
    uint8_t addres;
    uint32_t speed = FLPROG_I2CSPEED;
    uint8_t codeError = FLPROG_SENSOR_NOT_ERROR;
};

class FLProgI2cStepWorkSensor : public FLProgI2cBasicSensor
{
public:
    void read();
    void setReadPeriod(uint32_t period);

protected:
    virtual void readSensor(){};
    void checkDelay();
    void checkReadPeriod();
    void gotoStepWithDelay(uint8_t newStep, uint32_t delay);
    void checkNeededRead();
    uint32_t startDelay;
    uint32_t sizeDelay;
    uint8_t stepAfterDelay;
    bool isNeededRead = true;
    uint32_t readPeriod = 0;
    uint32_t startReadPeriod = 0;
    uint8_t step = FLPROG_SENSOR_WAITING_READ_STEP;
};