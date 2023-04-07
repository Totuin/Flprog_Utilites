#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_AVR_DUE


class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart(){};
    FLProgUart(UARTClass *hardwarePort);
    virtual void begin();
    void begin(int32_t speed, UARTClass::UARTModes mode);
    virtual bool hasPort() { return !(port == 0); };
    virtual void restartPort();

protected:
    virtual Stream *uartPort() { return port; };
    UARTClass *port;
    UARTClass::UARTModes serialModeFromParametrs();
    void setSerialMode(UARTClass::UARTModes mode);
    bool portIsInit = false;
};

#endif