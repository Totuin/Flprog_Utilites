#include "flprogSoftwareUartAVR.h"
#ifdef FLPROG_CORE_AVR

FLProgSoftwareUart::FLProgSoftwareUart(byte receivePin, byte transmitPin)
{
    softwarePort = new SoftwareSerial(receivePin, transmitPin);
}

bool FLProgSoftwareUart::hasPort()
{
    return !(softwarePort == 0);
}

void FLProgSoftwareUart::restartPort()
{
    if (hasPort())
    {
        softwarePort->end();
        begin();
    }
}

void FLProgSoftwareUart::begin()
{
    if (hasPort())
    {
        softwarePort->begin(speedFromCode());
    }
}

#endif
