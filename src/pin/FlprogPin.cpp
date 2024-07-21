#include "FlprogPin.h"

// -----------------------------------------------FlprogAbstractDiscreteInputPin---------------------------------------

bool FlprogAbstractDiscreteInputPin::checkInvert(bool value)
{
    if (_inverted)
    {
        return !value;
    }
    return value;
}

#ifdef FLPROG_COMPACT_LIBRARY_MODE
bool FlprogAbstractDiscreteInputPin::init()
{
    if (_pullMode == FLPROG_PULL_UP_MODE)
    {
        pinMode(number, INPUT_PULLUP);
    }
    else
    {
        if (_pullMode == FLPROG_PULL_DOWN_MODE)
        {
            pinMode(number, INPUT_PULLDOWN);
        }
        else
        {
            pinMode(number, INPUT);
        }
    }
    _isInit = true;
}
#endif

// -----------------------------------------------FlprogDiscreteInputPin---------------------------------------------
FlprogDiscreteInputPin::FlprogDiscreteInputPin(uint8_t number, char pullMode, bool inverted)
{
    _number = number;
    _pullMode = pullMode;
    _inverted = inverted;
}

bool FlprogDiscreteInputPin::digitalRead()
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    if (!_isInit)
    {
        init();
    }
    return checkInvert(digitalRead(_number));
#else
    return checkInvert(RT_HW_Base.pinDigitalRead(_structure, _number, _pullMode));
#endif
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
#ifdef FLPROG_COMPACT_LIBRARY_MODE

    if (!_isInit)
    {
        init();
        _result = digitalRead(_number);
        _oldValue = _result;
        return checkInvert(_result);
    }
    bool temp = digitalRead(_number);
    if (!(_oldValue == temp))
    {
        _startTime = millis();
        _oldValue = temp;
        return checkInvert(_result);
    }
    if (_oldValue == temp)
    {
        if (_oldValue == _result)
        {
            return checkInvert(_result);
        }
    }
    if (flprog::isTimer(_startTime, 40))
    {
        if (_oldValue == temp)
        {
            _result = temp;
            return checkInvert(_result);
        }
    }
#else
    return checkInvert(RT_HW_Base.chatterDIN(_bounce, (RT_HW_Base.pinDigitalRead(_structure, _number, _pullMode)), 50));
#endif
}

// -----------------------------------------------FlprogDiscreteOutputPin---------------------------------------------
FlprogDiscreteOutputPin::FlprogDiscreteOutputPin(uint8_t number)
{
    _number = number;
}

void FlprogDiscreteOutputPin::digitalWrite(bool value)
{
    _cash = value;
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    if (!_isInit)
    {
        pinMode(number, OUTPUT);
        _isInit = true;
    }
    digitalWrite(number, _cash);
#else
    RT_HW_Base.pinDigitalWrite(_structure, _number, _cash, 'N');
#endif
}

// -----------------------------------------------FlprogShimOutputPin---------------------------------------------
FlprogShimOutputPin::FlprogShimOutputPin(uint8_t number)
{
    _number = number;
#ifndef FLPROG_COMPACT_LIBRARY_MODE
    _structure.freq = 1000;
    _structure.mode = 'N';
#endif
}

void FlprogShimOutputPin::analogWrite(uint16_t value)
{
    _cash = value;
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    analogWrite(_number, _cash);
#else
    RT_HW_Base.pinPWM(_structure, _number, _cash);
#endif
}

// -----------------------------------------------FlprogAnalogInputPin---------------------------------------------
FlprogAnalogInputPin::FlprogAnalogInputPin(uint8_t number)
{
    _number = number;
}

uint16_t FlprogAnalogInputPin::analogRead()
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    return analogRead(_number)
#else
    return RT_HW_Base.pinAnalogRead(_structure, _number);
#endif
}

// -----------------------------------------------FlprogAnalogInputPin---------------------------------------------
#ifndef FLPROG_COMPACT_LIBRARY_MODE
FlprogDacOutputPin::FlprogDacOutputPin(uint8_t number)
{
    _number = number;
}

void FlprogDacOutputPin::analogWrite(uint16_t value)
{
    _cash = value;
    RT_HW_Base.pinDAC(_structure, _number, _cash);
}
#endif