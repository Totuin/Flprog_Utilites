
#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#define FLPROG_PULL_UP_MODE 'U'
#define FLPROG_PULL_DOWN_MODE 'D'
#define FLPROG_PULL_FLOAT_MODE 'F'
#define FLPROG_PULL_NOT_MODE 'I'
#define FLPROG_OPEN_COLLECTOR_OUTPUT_MODE 'O'
#define FLPROG_OPEN_NORMAL_OUTPUT_MODE 'N'

class FlprogDiscreteInputPin
{
public:
    FlprogDiscreteInputPin(uint8_t number, char pullMode = RT_HW_MODE_DIN_INPUT, bool inverted = false);
    bool digitalRead();

protected:
    RT_HW_PIN_DIR_ID _structure;
};

class FlprogBounceDiscreteInputPin
{
public:
    FlprogBounceDiscreteInputPin(uint8_t number, char pullMode = RT_HW_MODE_DIN_INPUT, bool inverted = false);
    void setPeriod(uint16_t period) { _structure.setPeriod(period); };
    bool digitalRead();

protected:
    RT_HW_PIN_DIB_ID _structure;
};

class FlprogDiscreteOutputPin
{
public:
    FlprogDiscreteOutputPin(uint8_t number, bool isOk = false, bool inverted = false);
    virtual bool digitalRead() { return _structure.cash; };
    void digitalWrite(bool value);

protected:
    RT_HW_PIN_DIR_ID _structure;
};

class FlprogShimOutputPin
{
public:
    FlprogShimOutputPin(uint8_t number, bool isOk = false, bool inverted = false, uint16_t freq = 0);
    void analogWrite(uint16_t value);
    uint16_t analogRead() { return _structure.cash; };

protected:
    RT_HW_PIN_PWM_ID _structure;
};

class FlprogAnalogInputPin
{
public:
    FlprogAnalogInputPin(uint8_t number);
    uint16_t analogRead();

protected:
    RT_HW_PIN_ADC_ID _structure;
};

class FlprogDacOutputPin
{
public:
    FlprogDacOutputPin(uint8_t number);
    uint16_t analogRead() { return _structure.cash; };
    void analogWrite(uint16_t value);

protected:
    RT_HW_PIN_DAC_ID _structure;
};
