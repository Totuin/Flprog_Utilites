#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_ESP8266

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart(){};
    FLProgUart(HardwareSerial *hardwarePort);
    virtual void begin();
    
    void begin(int32_t speed, SerialConfig mode);
    virtual bool hasPort() {return !(port == 0);};
    virtual void restartPort();

protected:
    virtual Stream *uartPort() {return port;};
     HardwareSerial *port;
    SerialConfig serialModeFromParametrs();
    void setSerialMode(SerialConfig mode);
};


#endif