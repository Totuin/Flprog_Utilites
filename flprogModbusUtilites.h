#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#define MODBUS_READY 0
#define MODBUS_WAITING_SENDING 1
#define MODBUS_WAITING_ANSWER 2


namespace flprogModus
{
    int modbusCalcCRC(byte length, byte bufferArray[]);
    byte t35TimeForSpeed(byte speed);
    int timeForSendBytes(byte portDataBits, byte portStopBits, byte portParity, byte portSpeed, int dataSize);
};