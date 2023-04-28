#include "flprogI2C_Esp8266.h"

#ifdef FLPROG_CORE_ESP8266

FLProgI2C::FLProgI2C(byte busNumber)
{
#ifdef FLPROG_HAS_I2C0
    if (busNumber == 0)
    {
#ifdef FLPROG_I2C0_SDA
        sda = FLPROG_I2C0_SDA;
#endif
#ifdef FLPROG_I2C0_SCL
        scl = FLPROG_I2C0_SCL;
#endif
        oneWare = &Wire;
    }
#endif
#ifdef FLPROG_HAS_I2C1
    if (busNumber == 1)
    {
#ifdef FLPROG_I2C1_SDA
        sda = FLPROG_I2C1_SDA;
#endif
#ifdef FLPROG_I2C1_SCL
        scl = FLPROG_I2C1_SCL;
#endif
        oneWare = &Wire1;
    }
#endif
    speed = FLPROG_I2CSPEED;
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

    if ((sda < 0) || (scl < 0))
    {
        oneWare->begin();
    }
    else
    {
        oneWare->begin(sda, scl);
    }
    oneWare->setClockStretchLimit(260);
    status = 1;
    return true;
}

bool FLProgI2C::begin(int pinSDA, int pinSCL)
{
    sda = pinSDA;
    scl = pinSCL;
    return begin();
}

#endif