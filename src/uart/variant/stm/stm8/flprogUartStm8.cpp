#include "flprogUartStm8.h"
#ifdef FLPROG_CORE_STM8
int flprog::serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity)
{
    return serialModeFromInt(serialCodeForParametrs(portDataBits, portStopBits, portParity));
}

int flprog::serialModeFromInt(int16_t code)
{
    switch (code)
    {

#ifdef UART_WORDLENGTH_7B
    case 0x04:
        return SERIAL_7N1;
        break;
    case 0x0C:
        return SERIAL_7N2;
        break;
    case 0x22:
        return SERIAL_6E1;
        break;
    case 0x2A:
        return SERIAL_6E2;
        break;
    case 0x32:
        return SERIAL_6O1;
        break;
    case 0x3A:
        return SERIAL_6O2;
        break;
#endif
    case 0x06:
        return SERIAL_8N1;
        break;
    case 0x0E:
        return SERIAL_8N2;
        break;
    case 0x24:
        return SERIAL_7E1;
        break;
    case 0x26:
        return SERIAL_8E1;
        break;
    case 0x2C:
        return SERIAL_7E2;
        break;
    case 0x2E:
        return SERIAL_8E2;
        break;
    case 0x34:
        return SERIAL_7O1;
        break;
    case 0x36:
        return SERIAL_8O1;
        break;
    case 0x3C:
        return SERIAL_7O2;
        break;
    case 0x3E:
        return SERIAL_8O2;
        break;
    }
    return SERIAL_8N1;
}
#endif