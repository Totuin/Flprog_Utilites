#include "flprogI2C_Avr.h"

#ifdef FLPROG_CORE_AVR
FLProgI2C::FLProgI2C(uint8_t busNumber)
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
    oneWare->setClock(speed);
    status = 1;
    return true;
}

#endif