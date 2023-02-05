#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_CAN_USE_BLUETOOTH_SERIAL

#include "BluetoothSerial.h"


class FLProgBluetoothUart : public FLProgUartBasic
{
public:
    FLProgBluetoothUart(String name);
    void setDeviceName(String name);
    void setPartnerName(String name);
    void beBluetoothMaster();
    void beBluetoothSlave();
    virtual bool hasPort();
    virtual void restartPort();
    virtual void begin();

protected:
    BluetoothSerial *bluetoothPort;
    String deviceName;
    String partnerName;
    bool isMaster = false;
    virtual Stream *uartPort() { return bluetoothPort; };
};
#endif