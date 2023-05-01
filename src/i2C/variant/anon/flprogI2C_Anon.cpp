#include "flprogI2C_Anon.h"

#ifdef  FLPROG_ANON_SELECT_I2C

FLProgI2C::FLProgI2C(uint8_t busNumber)
{
#ifdef FLPROG_HAS_I2C0
    if (busNumber == 0)
    {
        oneWare = &Wire;
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
    oneWare->setClock(speed);
    status = 1;
    return true;
}

#endif