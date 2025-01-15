#include "FlprogPin.h"

// -----------------------------------------------FlprogDiscreteInputPin---------------------------------------------
FlprogDiscreteInputPin::FlprogDiscreteInputPin(uint8_t number, char pullMode, bool inverted)
{
    _structure.setParam(number, inverted, pullMode);
}

bool FlprogDiscreteInputPin::digitalRead()
{
    return RT_HW_Base.pinDigitalRead(_structure);
}

void FlprogDiscreteInputPin::setPin(uint8_t number)
{
    _structure.setPin(number);
}

// -----------------------------------------------FlprogBounceDiscreteInputPin---------------------------------------------
FlprogBounceDiscreteInputPin::FlprogBounceDiscreteInputPin(uint8_t number, char pullMode, bool inverted)
{
    _structure.setParam(number, (_structure.period), inverted, pullMode);
}

bool FlprogBounceDiscreteInputPin::digitalRead()
{

    return RT_HW_Base.pinDigitalRead(_structure);
}

void FlprogBounceDiscreteInputPin::setPin(uint8_t number)
{
    _structure.setPin(number);
}

// -----------------------------------------------FlprogDiscreteOutputPin---------------------------------------------
FlprogDiscreteOutputPin::FlprogDiscreteOutputPin(uint8_t number, bool isOk, bool inverted)
{
    if (isOk)
    {
        _structure.setParam(number, inverted, RT_HW_MODE_DOT_OPEN);
        return;
    }
    _structure.setParam(number, inverted, RT_HW_MODE_DOT_NORMAL);
}

void FlprogDiscreteOutputPin::digitalWrite(bool value)
{
    RT_HW_Base.pinDigitalWrite(_structure, value);
}

void FlprogDiscreteOutputPin::setPin(uint8_t number)
{
    _structure.setPin(number);
}

// -----------------------------------------------FlprogShimOutputPin---------------------------------------------
FlprogShimOutputPin::FlprogShimOutputPin(uint8_t number, bool isOk, bool inverted, uint16_t freq)
{
    _structure.setInv(inverted);
    if (isOk)
    {
        _structure.mode = RT_HW_MODE_DOT_OPEN;
    }
    if (freq > 0)
    {
        _structure.setParam(number, freq);
    }
    else
    {
        _structure.setParam(number);
    }
}

void FlprogShimOutputPin::analogWrite(uint16_t value)
{

    RT_HW_Base.pinWritePWM(_structure, value);
}

void FlprogShimOutputPin::setPin(uint8_t number)
{
    _structure.setPin(number);
}

// -----------------------------------------------FlprogAnalogInputPin---------------------------------------------
FlprogAnalogInputPin::FlprogAnalogInputPin(uint8_t number)
{
    _structure.setParam(number);
}

uint16_t FlprogAnalogInputPin::analogRead()
{
    RT_HW_Base.pinAnalogRead(_structure);
    return _structure.vNorm;
}

void FlprogAnalogInputPin::setPin(uint8_t number)
{
    _structure.setPin(number);
}

// -----------------------------------------------FlprogAnalogInputPin---------------------------------------------
FlprogDacOutputPin::FlprogDacOutputPin(uint8_t number)
{
    
    _structure.setParam(number);
}

void FlprogDacOutputPin::analogWrite(uint16_t value)
{
    RT_HW_Base.pinWriteDAC(_structure, value);
}

void FlprogDacOutputPin::setPin(uint8_t number)
{
    _structure.setPin(number);
}
