#include "flprogUartDUE.h"

#ifdef FLPROG_CORE_AVR_DUE

UARTClass::UARTModes flprog::serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity)
{
    return serialModeFromInt(serialCodeForParametrs(portDataBits, portStopBits, portParity));
}

UARTClass::UARTModes flprog::serialModeFromInt(int16_t code)
{
    switch (code)
    {
    case 0x06:
        return SERIAL_8N1;
        break;
    case 0x26:
        return SERIAL_8E1;
        break;
    case 0x36:
        return SERIAL_8O1;
        break;
    }
    return SERIAL_8N1;
}
#endif