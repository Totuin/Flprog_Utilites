#include "flprogModbusUtilites.h"

int flprogModus::modbusCalcCRC(byte length, byte bufferArray[])
{
    unsigned int temp, temp2, flag;
    temp = 0xFFFF;
    for (unsigned char i = 0; i < length; i++)
    {
        temp = temp ^ bufferArray[i];
        for (unsigned char j = 1; j <= 8; j++)
        {
            flag = temp & 0x0001;
            temp >>= 1;
            if (flag)
                temp ^= 0xA001;
        }
    }
    temp2 = temp >> 8;
    temp = (temp << 8) | temp2;
    temp &= 0xFFFF;
    return temp;
}

byte flprogModus::t35TimeForSpeed(byte speed)
{
    switch (speed)
    {
    case SPEED_300:
        return 75;
        break;
    case SPEED_600:
        return 75;
        break;
    case SPEED_1200:
        return 38;
        break;
    case SPEED_2400:
        return 19;
        break;

    case SPEED_4800:
        return 10;
        break;
    case SPEED_9600:
        return 5;
        break;
    case SPEED_14400:
        return 4;
        break;
    case SPEED_19200:
        return 3;
        break;
    case SPEED_28800:
        return 3;
        break;

    case SPEED_38400:
        return 2;
        break;
    default:
        return 1;
        break;
    }
}

int flprogModus::timeForSendBytes(byte portDataBits, byte portStopBits, byte portParity, byte portSpeed, int dataSize)
{
    byte temp = 1 + portDataBits + portStopBits;
    if (portParity > 0)
    {
        temp = temp + 1;
    }
    float temp1 = (temp / portDataBits);

    temp1 = temp1 * (flprog::speedFromCode(portSpeed));
    temp1 = 1000 / temp1;
    return ceil(temp1 * dataSize * 8);
}