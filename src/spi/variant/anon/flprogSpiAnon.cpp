#include "flprogSpiAnon.h"

#ifdef FLPROG_ANON_SELECT_SPI

FLProgSPI::FLProgSPI(uint8_t busNumber)
{
#ifdef FLPROG_HAS_SPI0
    if (busNumber == 0)
    {
        spi = &SPI;
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