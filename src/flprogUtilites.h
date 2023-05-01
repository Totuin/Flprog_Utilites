#pragma once
#include <Arduino.h>

#define FLPROG_SENSOR_NOT_ERROR 0
#define FLPROG_SENSOR_NOT_READY_ERROR 1
#define FLPROG_SENSOR_DEVICE_NOT_FOUND_ERROR 2
#define FLPROG_SENSOR_DEVICE_NOT_CORRECT_BUS_NUMBER_ERROR 65
#define FLPROG_SENSOR_DEVICE_NOT_CORRECT_DEVICE_ADDRESS_ERROR 61
#define FLPROG_SENSOR_DEVICE_NOT_DEFINED_ERROR 5
#define FLPROG_SENSOR_DEVICE_NOT_CORRECT_DATA_ERROR 6
#define FLPROG_SENSOR_CRC_ERROR 72

#define FLPROG_SENSOR_WAITING_READ_STEP 0
#define FLPROG_SENSOR_WAITING_DELAY 1

class FLProgStream
{
public:
    uint8_t available();
    virtual uint8_t read();
    uint8_t write(uint8_t *buffer, uint8_t size);
    uint8_t write(uint8_t data);

    void print(String str);
    void print(const char str[]);
    void print(char str);
    void print(uint8_t val, int mode = DEC);
    void print(int val, int mode = DEC);
    void print(long val, int mode = DEC);
    void print(unsigned long val, int mode = DEC);
    void print(float val, int mode = 2);
    void println(String str);
    void println(char str);
    void println(const char str[]);
    void println(uint8_t val, int mode = DEC);
    void println(int val, int mode = DEC);
    void println(long val, int mode = DEC);
    void println(unsigned long val, int mode = DEC);
    void println(float val, int mode = 2);
    void println();

protected:
    virtual Stream *stream() { return 0; };
    virtual bool hasStream() { return false; };
};

#include "flprogSelectCore.h"
#include "uart/flprogUart.h"
#include "tcp/flprogTcpDevice.h"
#include "flprog_Blocks.h"

namespace flprog
{
    bool isTimer(uint32_t startTime, uint32_t period);
    bool isTimerMicros(unsigned long startTime, unsigned long period);
    int serialCodeForParametrs(byte portDataBits, byte portStopBits, byte portParity);
    uint32_t speedFromCode(byte code);
    uint8_t codeFromSpeed(int32_t speed);
    uint32_t difference32(uint32_t start, uint32_t end);
    uint32_t timeBack(uint32_t value);

};
