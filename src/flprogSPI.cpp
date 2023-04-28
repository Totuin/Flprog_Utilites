#include "flprogSPI.h"

uint8_t AbstractFLProgSPI::transfer(uint8_t data)
{
    if (!checkBus())
    {
        codeErr = 65;
        return 0;
    }
    return spi->transfer(data);
}

bool AbstractFLProgSPI::checkBus()
{
    return !(spi == 0);
}