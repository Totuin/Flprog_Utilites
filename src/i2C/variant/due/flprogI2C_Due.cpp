#include "flprogI2C_Due.h"

#ifdef FLPROG_CORE_AVR_DUE

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
    oneWare->begin();
    status = 1;
    return true;
}

#endif