#include "flprogI2C_Stm32.h"

#ifdef FLPROG_CORE_STM32

#ifdef FLPROG_HAS_I2C0
#ifdef FLPROG_NEED_CREATE_I2C0
TwoWire Wire(FLPROG_I2C0_SDA, FLPROG_I2C0_SCL);
#endif
#endif

#ifdef FLPROG_HAS_I2C1
#ifdef FLPROG_NEED_CREATE_I2C1
TwoWire Wire1(FLPROG_I2C1_SDA, FLPROG_I2C1_SCL);
#endif
#endif

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

bool FLProgI2C::begin(uint32_t pinSDA, uint32_t pinSCL)
{
    sda = pinSDA;
    scl = pinSCL;
    return begin();
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
    if (!(sda < 0))
    {
        oneWare->setSDA(sda);
    }
    if (!(scl < 0))
    {
        oneWare->setSCL(scl);
    }
    oneWare->begin();
    oneWare->setClock(speed);
    status = 1;
    return true;
}

#endif