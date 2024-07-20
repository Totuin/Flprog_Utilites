#include "FlprogPin.h"

// -----------------------------------------------FlprogDiscreteInputPin---------------------------------------------
FlprogDiscreteInputPin::FlprogDiscreteInputPin(uint8_t number, char pullMode, bool inverted)
{
    _number = number;
    _pullMode = pullMode;
    _inverted = inverted;
}

bool FlprogDiscreteInputPin::digitalRead()
{
    bool temp;
    temp = RT_HW_Base.pinDigitalRead(_structure, _number, _pullMode);
    if (_inverted)
    {
        return !temp;
    }
    return temp;
}

// -----------------------------------------------FlprogBounceDiscreteInputPin---------------------------------------------
FlprogBounceDiscreteInputPin::FlprogBounceDiscreteInputPin(uint8_t number, char pullMode, bool inverted)
{
    _number = number;
    _pullMode = pullMode;
    _inverted = inverted;
}

bool FlprogBounceDiscreteInputPin::digitalRead()
{
    bool temp;
    temp = RT_HW_Base.pinDigitalRead(_structure, _number, _pullMode);
    temp = RT_HW_Base.chatterDIN(_bounce, temp, 50);
    if (_inverted)
    {
        return !temp;
    }
    return temp;
}

// -----------------------------------------------FlprogDiscreteOutputPin---------------------------------------------
FlprogDiscreteOutputPin::FlprogDiscreteOutputPin(uint8_t number)
{
    _number = number;
}

void FlprogDiscreteOutputPin::digitalWrite(bool value)
{
    _cash = value;
    RT_HW_Base.pinDigitalWrite(_structure, _number, _cash, 'N');
}

// -----------------------------------------------FlprogShimOutputPin---------------------------------------------
FlprogShimOutputPin::FlprogShimOutputPin(uint8_t number)
{
    _number = number;
    _structure.freq = 1000;
    _structure.mode = 'N';
}
