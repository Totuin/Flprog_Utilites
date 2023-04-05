#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_STM8

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart(){};
    FLProgUart(HardwareSerial *hardwarePort);
    virtual void begin();
    void begin(int32_t speed, int mode);
    virtual bool hasPort();
    virtual void restartPort();

protected:
    virtual Stream *uartPort();
    HardwareSerial *port;
    int serialModeFromParametrs();
    void setSerialMode(int16_t mode);
};

#endif
