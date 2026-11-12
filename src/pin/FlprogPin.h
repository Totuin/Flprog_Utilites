
#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#define FLPROG_NOT_EXIST_PIN 255

#define FLPROG_PULL_UP_MODE 'U'
#define FLPROG_PULL_DOWN_MODE 'D'
#define FLPROG_PULL_FLOAT_MODE 'F'
#define FLPROG_PULL_NOT_MODE 'I'
#define FLPROG_OPEN_COLLECTOR_OUTPUT_MODE 'O'
#define FLPROG_OPEN_NORMAL_OUTPUT_MODE 'N'


// Абстракция цифрового пина с возможностью отсутствующего вывода (255).
// Реальный доступ к GPIO реализуется через RT_HW_Base в конкретных наследниках.
class FlprogAbstractPin
{
public:
    void setPin(uint16_t number);
    bool digitalRead();
    virtual uint16_t pinNumber() { return FLPROG_NOT_EXIST_PIN; };

protected:
    virtual void privateSetPin(uint16_t number) { (void)number; };
    virtual bool privateDigitalRead() { return 0; };
};

// Цифровой вход: режим подтяжки и инверсия задаются конструктором.
class FlprogDiscreteInputPin : public FlprogAbstractPin
{
public:
    FlprogDiscreteInputPin(uint16_t number, char pullMode = RT_HW_MODE_DIN_INPUT, bool inverted = false) { _structure.setParam(number, inverted, pullMode); };
    virtual uint16_t pinNumber() { return _structure.pin; };

protected:
    virtual void privateSetPin(uint16_t number) { _structure.setPin(number); };
    virtual bool privateDigitalRead() { return RT_HW_Base.pinDigitalRead(_structure); };

    RT_HW_PIN_DIR_ID _structure;
};

// Цифровой вход с программной фильтрацией дребезга, период в RT_HW.
class FlprogBounceDiscreteInputPin : public FlprogAbstractPin
{
public:
    FlprogBounceDiscreteInputPin(uint16_t number, char pullMode = RT_HW_MODE_DIN_INPUT, bool inverted = false) { _structure.setParam(number, (_structure.period), inverted, pullMode); };
    void setPeriod(uint16_t period);
    virtual uint16_t pinNumber() { return _structure.pin; };

protected:
    virtual bool privateDigitalRead() { return RT_HW_Base.pinDigitalRead(_structure); };
    virtual void privateSetPin(uint16_t number) { _structure.setPin(number); };
    RT_HW_PIN_DIB_ID _structure;
};

// Цифровой выход: обычный либо открытый коллектор, возможна инверсия.
class FlprogDiscreteOutputPin : public FlprogAbstractPin
{
public:
    FlprogDiscreteOutputPin(uint16_t number, bool isOk = false, bool inverted = false);
    void digitalWrite(bool value) { RT_HW_Base.pinDigitalWrite(_structure, value); };
    virtual uint16_t pinNumber() { return _structure.pin; };

protected:
    virtual void privateSetPin(uint16_t number) { _structure.setPin(number); };
    virtual bool privateDigitalRead() { return _structure.cash; };
    RT_HW_PIN_DIR_ID _structure;
};

// PWM-выход, поддерживаются настройка частоты и чтение кэша.
class FlprogShimOutputPin : public FlprogAbstractPin
{
public:
    FlprogShimOutputPin(uint16_t number, bool isOk = false, bool inverted = false, uint16_t freq = 0);
    void analogWrite(uint16_t value) { RT_HW_Base.pinWritePWM(_structure, value); };
    uint16_t analogRead() { return _structure.cash; };
    virtual uint16_t pinNumber() { return _structure.pin; };

protected:
    virtual void privateSetPin(uint16_t number) { _structure.setPin(number); };
    RT_HW_PIN_PWM_ID _structure;
};

// АЦП-вход: аналоговое значение читается через нормализатор RT_HW.
class FlprogAnalogInputPin : public FlprogAbstractPin
{
public:
    FlprogAnalogInputPin(uint16_t number) { _structure.setParam(number); };
    uint16_t analogRead();
    virtual uint16_t pinNumber() { return _structure.pin; };
    uint16_t vPin() { return _structure.vPin; };
    uint16_t vDev() { return _structure.vDev; };

protected:
    virtual void privateSetPin(uint16_t number) { _structure.setPin(number); };
    RT_HW_PIN_ADC_ID _structure;
};

// ЦАП-выход: кешированное значение и запись в драйвер RT_HW.
class FlprogDacOutputPin
{
public:
    FlprogDacOutputPin(uint16_t number) { _structure.setParam(number); };
    uint16_t analogRead() { return _structure.cash; };
    void analogWrite(uint16_t value) { RT_HW_Base.pinWriteDAC(_structure, value); };
    void setPin(uint16_t number) { _structure.setPin(number); };

protected:
    RT_HW_PIN_DAC_ID _structure;
};
