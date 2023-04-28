#include "flprogSpiEsp8266.h"

#ifdef FLPROG_CORE_ESP8266

FLProgSPI::FLProgSPI(uint8_t busNumber)
{
#ifdef FLPROG_HAS_SPI0
    if (busNumber == 0)
    {
        spi = &SPI;
    }
#endif
#ifdef FLPROG_HAS_SPI1
    if (busNumber == 1)
    {
        spi = &SPI1;
    }
#endif
}

bool FLProgSPI::begin()
{
    if (!checkBus())
    {
        codeErr = 65;
        return false;
    }
    spi->begin();
    return true;
}
#endif