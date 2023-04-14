#include "flprogI2C_sensorsBasic.h"

void FLProgI2cStepWorkSensor::checkDelay()
{

    if (step == FLPROG_SENSOR_WAITING_DELAY)
    {
        if (flprog::isTimer(startDelay, sizeDelay))
        {
            step = stepAfterDelay;
        }
    }
}

void FLProgI2cStepWorkSensor::read()
{
    isNeededRead = true;
}

void FLProgI2cStepWorkSensor::setReadPeriod(uint32_t period)
{
    readPeriod = period;
}

void FLProgI2cStepWorkSensor::checkReadPeriod()
{
    if (readPeriod > 0)
    {
        if (flprog::isTimer(startReadPeriod, readPeriod))
        {
            startReadPeriod = millis();
            read();
        }
    }
}

void FLProgI2cStepWorkSensor::gotoStepWithDelay(uint8_t newStep, uint32_t delay)
{
    startDelay = millis();
    sizeDelay = delay;
    stepAfterDelay = newStep;
    step = FLPROG_SENSOR_WAITING_DELAY;
}

void FLProgI2cStepWorkSensor::checkNeededRead()
{
    if (step == FLPROG_SENSOR_WAITING_READ_STEP)
    {

        if (isNeededRead)
        {
            readSensor();
            isNeededRead = false;
        }
    }
}