#pragma once
#include "Arduino.h"
#include "flprogSPI.h"

#ifdef FLPROG_CORE_ESP8266
class FLProgSPI : public AbstractFLProgSPI
{
public:
    FLProgSPI(uint8_t busNumber = 0);
    virtual bool begin();
};

#endif
