#include "flprogI2C_Stm8.h"
#ifdef FLPROG_CORE_STM8
FLProgI2C::FLProgI2C(byte busNumber)
{
#ifdef FLPROG_HAS_I2C0
    if (busNumber == 0)
    {
       
        oneWare = &Wire;
    }
#endif
#ifdef FLPROG_HAS_I2C1
    if (busNumber == 1)
    {
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
    if ((sda < 0) || (scl < 0))
    {
        oneWare->begin();
    }
    else
    {
        oneWare->begin(sda, scl);
    }
    oneWare->setClock(speed);
    status = 1;
    return true;
}

#endif