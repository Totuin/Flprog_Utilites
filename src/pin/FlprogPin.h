
#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#define FLPROG_PULL_UP_MODE 'U'
#define FLPROG_PULL_DOWN_MODE 'D'
#define FLPROG_PULL_NOT_MODE 'F'

class FlprogAbstractDiscreteInputPin
{
protected:
    char _pullMode;
    uint8_t _number;
    bool _inverted;
    bool checkInvert(bool value);
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    bool _isInit = false;
    void init();
#else
    RT_HW_PIN_DIR_ID _structure;
#endif
};

class FlprogDiscreteInputPin : public FlprogAbstractDiscreteInputPin
{
public:
    FlprogDiscreteInputPin(uint8_t number, char pullMode = FLPROG_PULL_NOT_MODE, bool inverted = false);
    bool digitalRead();
};

class FlprogBounceDiscreteInputPin : public FlprogAbstractDiscreteInputPin
{
public:
    FlprogBounceDiscreteInputPin(uint8_t number, char pullMode = FLPROG_PULL_NOT_MODE, bool inverted = false);
    bool digitalRead();

protected:
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    bool _oldValue = false;
    uint32_t _startTime;
    bool _result;
#else
    RT_HW_CHATTER_DIN _bounce;
#endif
};

class FlprogDiscreteOutputPin
{
public:
    FlprogDiscreteOutputPin(uint8_t number, bool isOk = false, bool inverted = false);
    virtual bool digitalRead() { return _cash; };
    void digitalWrite(bool value);

protected:
    bool _cash = 0;
    uint8_t _number;
    bool _isInit = false;

    bool _inverted = false;
#ifndef FLPROG_COMPACT_LIBRARY_MODE
    RT_HW_PIN_DIR_ID _structure;
#endif
};

class FlprogShimOutputPin
{
public:
    FlprogShimOutputPin(uint8_t number, bool isOk = false, bool inverted = false, uint16_t freq = 0);
    void analogWrite(uint16_t value);
    uint16_t analogRead() { return _cash; };

protected:
    bool isInit = false;
    void init();
    uint8_t _number;

    bool _inverted = false;
    uint16_t _cash = 0;
#ifndef FLPROG_COMPACT_LIBRARY_MODE
    RT_HW_PIN_PWM_ID _structure;
#endif
};

class FlprogAnalogInputPin
{
public:
    FlprogAnalogInputPin(uint8_t number);
    uint16_t analogRead();

protected:
    uint8_t _number;
#ifndef FLPROG_COMPACT_LIBRARY_MODE
    RT_HW_PIN_ADC_ID _structure;
#endif
};

#ifdef FLPROG_COMPACT_LIBRARY_MODE
class FlprogDacOutputPin
{
public:
    FlprogDacOutputPin(uint8_t number) { (void)number; };
    uint16_t analogRead() { return 0; };
    void analogWrite(uint16_t value) { (void)value; };
};
#else
class FlprogDacOutputPin
{
public:
    FlprogDacOutputPin(uint8_t number);
    uint16_t analogRead() { return _cash; };
    void analogWrite(uint16_t value);

protected:
    bool isInit = false;
    void init();
    uint8_t _number;
    uint16_t _cash = 0;
    RT_HW_PIN_DAC_ID _structure;
};
#endif