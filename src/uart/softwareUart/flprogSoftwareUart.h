#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_CAN_USE_SOFTWARE_SERIAL

#include "SoftwareSerial.h"

class FLProgSoftwareUart : public FLProgUartBasic
{
public:
    FLProgSoftwareUart(byte receivePin, byte transmitPin);
    virtual void restartPort();
    virtual bool hasPort();
    virtual void begin();

protected:
    SoftwareSerial *softwarePort;
    virtual Stream *uartPort() { return softwarePort; };
};
#endif
