
#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#define FLPROG_PULL_UP_MODE 'U'
#define FLPROG_PULL_DOWN_MODE 'D'
#define FLPROG_PULL_NOT_MODE 'F'

class FlprogDiscreteInputPin
{
public:
    FlprogDiscreteInputPin(uint8_t number, char pullMode = FLPROG_PULL_NOT_MODE, bool inverted = false);
    bool digitalRead();

private:
    char _pullMode;
    uint8_t _number;
    bool _inverted;
    RT_HW_PIN_DIR_ID _structure;
};

class FlprogBounceDiscreteInputPin
{
public:
    FlprogBounceDiscreteInputPin(uint8_t number, char pullMode = FLPROG_PULL_NOT_MODE, bool inverted = false);
    virtual bool digitalRead();

private:
    uint8_t _number;
    char _pullMode;
    bool _inverted;
    RT_HW_PIN_DIR_ID _structure;
    RT_HW_CHATTER_DIN _bounce;
};

class FlprogDiscreteOutputPin
{
public:
    FlprogDiscreteOutputPin(uint8_t number);
    virtual bool digitalRead() { return _cash; };
    void digitalWrite(bool value);

private:
    bool _cash = 0;
    uint8_t _number;
    RT_HW_PIN_DIR_ID _structure;
};

class FlprogShimOutputPin
{
public:
    FlprogShimOutputPin(uint8_t number);

private:
    uint8_t _number;
    RT_HW_PIN_PWM_ID _structure;
};