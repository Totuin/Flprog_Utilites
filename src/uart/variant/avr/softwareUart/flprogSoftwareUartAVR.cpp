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
    softwarePort->end();
    begin();
    return;
}

void FLProgSoftwareUart::begin()
{
    softwarePort->begin(speedFromCode());
    return;
}

#endif
