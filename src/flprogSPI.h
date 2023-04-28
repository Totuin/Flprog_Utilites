#pragma once
#include "Arduino.h"
#include <SPI.h>
#include "flprogUtilites.h"

class AbstractFLProgSPI
{
public:
    virtual bool begin() { return false; };
    virtual bool begin(int pinMOSI, int pinMISO, int pinSCLK, int pinSSEL) { return begin(); };
    uint8_t getErrorCode() { return codeErr; };
    uint8_t transfer(uint8_t data);

protected:
    bool checkBus();
    uint8_t status = 0;
    uint8_t codeErr = 0;
    SPIClass *spi;
};

#include "spi\flprogSpiSelect.h"