#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_ANON_SELECT_UART

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart();
    FLProgUart(uint8_t portNumber);
    virtual void begin();
    void begin(int32_t speed, int mode);
    virtual bool hasPort() { return true; };
    virtual void restartPort();

protected:
    virtual Stream *uartPort() { return &Serial; };
    int serialModeFromParametrs();
    void setSerialMode(int16_t mode);
};

#endif