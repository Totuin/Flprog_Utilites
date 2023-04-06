#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#define FLPROG_HARDWARE_UART 0
#define FLPROG_USB_UART 1

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

class FLProgUartBasic
{
public:
    virtual void begin(){};
    void begin(int32_t speed);
    uint8_t getPortSpeed() { return portSpeed; };
    uint8_t getPortDataBits() { return portDataBits; };
    uint8_t getPortStopBits() { return portStopBits; };
    uint8_t getPortParity() { return portParity; };
    virtual bool hasPort() { return false; };
    virtual void restartPort(){};
    void setPortSpeed(uint8_t speed);
    void setPortDataBits(uint8_t dataBits);
    void setPortStopBits(uint8_t stopBits);
    void setPortParity(uint8_t parity);
    uint8_t available() { return uartPort()->available(); };
    uint8_t read() { return uartPort()->read(); };
    uint8_t write(uint8_t *buffer, uint8_t size) { return uartPort()->write(buffer, size); };
    uint8_t write(uint8_t data) { return uartPort()->write(data); };

    void print(String str) { uartPort()->print(str); };
    void print(const char str[]) { uartPort()->print(str); };
    void print(char str) { uartPort()->print(str); };
    void print(uint8_t val, int mode = DEC) { uartPort()->print(val, mode); };
    void print(int val, int mode = DEC) { uartPort()->print(val, mode); };
    void print(long val, int mode = DEC) { uartPort()->print(val, mode); };
    void print(unsigned long val, int mode = DEC) { uartPort()->print(val, mode); };
    void print(float val, int mode = 2) { uartPort()->print(val, mode); };
    void println(String str) { uartPort()->println(str); };
    void println(char str) { uartPort()->println(str); };
    void println(const char str[]) { uartPort()->println(str); };
    void println(uint8_t val, int mode = DEC) { uartPort()->println(val, mode); };
    void println(int val, int mode = DEC) { uartPort()->println(val, mode); };
    void println(long val, int mode = DEC) { uartPort()->println(val, mode); };
    void println(unsigned long val, int mode = DEC) { uartPort()->println(val, mode); };
    void println(float val, int mode = 2) { uartPort()->println(val, mode); };
    void println() { uartPort()->println(); };

protected:
    virtual Stream *uartPort() { return 0; };
    uint32_t speedFromCode();
    int serialCodeForParametrs();
    void setCodeFromSpeed(int32_t speed);
    uint8_t portSpeed = FLPROG_SPEED_9600;
    uint8_t portDataBits = FLPROG_PORT_DATA_BITS_8;
    uint8_t portStopBits = FLPROG_PORT_STOP_BITS_1;
    uint8_t portParity = FLPROG_PORT_PARITY_NONE;
};

#ifdef FLPROG_CORE_AVR
#include "variant/avr/flprogUartAvr.h"
#endif

#ifdef FLPROG_CORE_AVR_DUE
#include "variant/due/flprogUartDUE.h"
#endif

#ifdef FLPROG_CORE_ESP
#include "variant/esp/flprogUartEsp.h"
#endif

#ifdef FLPROG_CORE_STM
#include "variant/stm/flprogUartStm.h"
#endif
