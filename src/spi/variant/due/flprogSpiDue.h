#pragma once
#include "Arduino.h"
#include "flprogSPI.h"

#ifdef FLPROG_CORE_AVR_DUE

#define FLPROG_SPI_MODE0 SPI_MODE0
#define FLPROG_SPI_MODE1 SPI_MODE1
#define FLPROG_SPI_MODE2 SPI_MODE2
#define FLPROG_SPI_MODE3 SPI_MODE3

#define FLPROG_LSBFIRST LSBFIRST
#define FLPROG_MSBFIRST MSBFIRST

class FLProgSPI : public AbstractFLProgSPI
{
public:
    FLProgSPI(uint8_t busNumber = 0);
    virtual void setBitOrder(BitOrder mode) { spi->setBitOrder(mode); };
    virtual bool begin();
    void setDataMode(uint8_t mode) { spi->setDataMode(mode); };
    void setClockDivider(uint8_t mode) { spi->setClockDivider(mode); };
};

#endif
