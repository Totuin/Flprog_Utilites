#pragma once
#include "Arduino.h"
#include <Wire.h>
#include "./flprogUtilites.h"

#ifdef CORE_ESP8266
#define FLPROG_I2CSPEED 100000UL;
#else
#define FLPROG_I2CSPEED 400000UL;
#endif

#if defined(CORE_ESP32) || defined(CORE_STM32)
#define FLPROG_CAN_USE_I2C_1
#endif

#ifdef CORE_STM32
   #define FLPROG_CAN_USE_I2C_2
#endif


class FLProgI2C
{
public:
    // FLProgI2C() { FLProgI2C(0); };
    FLProgI2C(byte busNumber);
    bool begin();
    bool begin(int pinSDA, int pinSCL);
    bool findAddr(uint8_t addr);
    uint8_t getErrorCode() { return codeErr; };
    void beginTransmission(uint8_t addr);
    void write(const uint8_t *data, size_t quantity);
    void write(uint8_t data);
    uint8_t endTransmission();
    int available();
    int read();
    uint8_t requestFrom(uint8_t address, uint8_t quantity);
    uint8_t waitingForData(uint8_t count);
    void setSpeed(uint32_t newSpeed);
    void resetSpeedFrom(uint32_t newSpeed);

private:
    bool checkBus();
    uint8_t bus;
    bool busy = false;
    uint8_t status = 0;
    uint8_t codeErr = 0;
    int sda = -1;
    int scl = -1;
    uint32_t speed = FLPROG_I2CSPEED;
    bool beginWire0();
#if defined(CORE_ESP32) || defined(CORE_STM32)
    bool beginWire1();
#endif
#ifdef CORE_STM32
    bool beginWire2();
#endif
};
