#include "FlprogPin.h"

bool FlprogDiscreteInputPin::digitalRead()
{
    if (_structure.pin == 255)
    {
        return 0;
    }
    return RT_HW_Base.pinDigitalRead(_structure);
}

bool FlprogBounceDiscreteInputPin::digitalRead()
{
    if (_structure.pin == 255)
    {
        return 0;
    }
    return RT_HW_Base.pinDigitalRead(_structure);
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

// -----------------------------------------------FlprogAnalogInputPin---------------------------------------------
uint16_t FlprogAnalogInputPin::analogRead()
{
    RT_HW_Base.pinAnalogRead(_structure);
    return _structure.vNorm;
}
