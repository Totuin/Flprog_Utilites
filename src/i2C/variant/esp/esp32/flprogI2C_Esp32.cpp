#include "flprogI2C_Esp32.h"

#ifdef FLPROG_CORE_ESP32

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
    oneWare->begin(sda, scl, speed);
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