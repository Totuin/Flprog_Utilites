#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_STM

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart(){};
    FLProgUart(HardwareSerial *hardwarePort);
#ifdef FLPROG_STM32_USB_COM0
    FLProgUart(USBSerial *port);
#endif
    virtual void begin();
    void begin(int32_t speed, int mode);
    virtual bool hasPort();
    virtual void restartPort();

protected:
    virtual Stream *uartPort();
    HardwareSerial *port;
#ifdef FLPROG_STM32_USB_COM0
    USBSerial *usbPort;
#endif
    byte type = FLPROG_HARDWARE_UART;
    int serialModeFromParametrs();
    void setSerialMode(int16_t mode);
};

#endif
