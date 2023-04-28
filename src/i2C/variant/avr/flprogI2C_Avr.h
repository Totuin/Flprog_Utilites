#pragma once
#include "Arduino.h"
#include <Wire.h>
#include "flprogI2C.h"

#ifdef FLPROG_CORE_AVR

class FLProgI2C : public AbstractFLProgI2C
{
public:
    FLProgI2C(uint8_t busNumber = 0);
    virtual bool begin(int pinSDA, int pinSCL) { return begin(); };
    virtual bool begin();
};
#endif