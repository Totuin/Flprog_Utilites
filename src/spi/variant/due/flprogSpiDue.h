#pragma once
#include "Arduino.h"
#include "flprogSPI.h"

#ifdef FLPROG_CORE_AVR_DUE
class FLProgSPI : public AbstractFLProgSPI
{
public:
    FLProgSPI(uint8_t busNumber = 0);
    virtual bool begin();
};

#endif
