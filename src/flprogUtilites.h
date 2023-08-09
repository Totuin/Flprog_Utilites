#pragma once
#include <Arduino.h>

#include "flprog_Blocks.h"

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

#define FLPROG_USB_UART 0
#define FLPROG_UART_UART 1
#define FLPROG_USART_UART 2

#define FLPROG_SPEED_300 0
#define FLPROG_SPEED_600 1
#define FLPROG_SPEED_1200 2
#define FLPROG_SPEED_2400 3
#define FLPROG_SPEED_4800 4
#define FLPROG_SPEED_9600 5
#define FLPROG_SPEED_14400 6
#define FLPROG_SPEED_19200 7
#define FLPROG_SPEED_28800 8
#define FLPROG_SPEED_38400 9
#define FLPROG_SPEED_57600 10
#define FLPROG_SPEED_115200 11

#define FLPROG_PORT_STOP_BITS_1 1
#define FLPROG_PORT_STOP_BITS_2 2

#define FLPROG_PORT_DATA_BITS_5 5
#define FLPROG_PORT_DATA_BITS_6 6
#define FLPROG_PORT_DATA_BITS_7 7
#define FLPROG_PORT_DATA_BITS_8 8

#define FLPROG_PORT_PARITY_NONE 0
#define FLPROG_PORT_PARITY_EVEN 1
#define FLPROG_PORT_PARITY_ODD 2

class FLProgStream
{
public:
    virtual uint8_t available();
    virtual uint8_t read();
    virtual uint8_t write(uint8_t data);
    uint8_t write(uint8_t *buffer, uint8_t size);

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
    virtual bool hasStream() { return stream() != 0; };
};

namespace flprog
{
    bool isTimer(uint32_t startTime, uint32_t period);
    bool isTimerMicros(uint32_t startTime, uint32_t period);
    uint32_t difference32(uint32_t start, uint32_t end);
    uint32_t timeBack(uint32_t value);
    uint32_t speedFromCode(byte code);
    uint8_t codeFromSpeed(int32_t speed);
    int serialCodeForParametrs(byte portDataBits, byte portStopBits, byte portParity);
};
