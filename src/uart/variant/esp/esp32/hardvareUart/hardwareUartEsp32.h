#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_ESP32

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart();
    FLProgUart(uint8_t portNumber);
    virtual void begin();
    void begin(int32_t speed, int mode);
    virtual bool hasPort() { return !(port == 0); };
    virtual void restartPort();

protected:
    virtual Stream *uartPort() { return port; };
    HardwareSerial *port;
    int serialModeFromParametrs();
    void setSerialMode(int16_t mode);
};

#endif