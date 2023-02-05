#include "flprogUartBluetoothSerial.h"
#ifdef FLPROG_CAN_USE_BLUETOOTH_SERIAL

FLProgBluetoothUart::FLProgBluetoothUart(String name)
{
    bluetoothPort = new BluetoothSerial();
    deviceName = name;
}

void FLProgBluetoothUart::beBluetoothMaster()
{
    if (isMaster)
    {
        return;
    }
    isMaster = true;
    restartPort();
}

void FLProgBluetoothUart::beBluetoothSlave()
{
    if (!isMaster)
    {
        return;
    }
    isMaster = false;
    restartPort();
}

void FLProgBluetoothUart::setDeviceName(String name)
{
    if (deviceName.equals(name))
    {
        return;
    }
    deviceName = name;
    restartPort();
}

void FLProgBluetoothUart::setPartnerName(String name)
{
    if (partnerName.equals(name))
    {
        return;
    }
    partnerName = name;
    restartPort();
}

bool FLProgBluetoothUart::hasPort()
{
    return !(bluetoothPort == 0);
}

void FLProgBluetoothUart::restartPort()
{
    bluetoothPort->end();
    begin();
}

void FLProgBluetoothUart::begin()
{
    bluetoothPort->begin(deviceName);
    if (isMaster)
    {
        bluetoothPort->connect(partnerName);
    }
    return;
}

#endif