#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifndef FLPROG_CORE_ESP32
#ifndef FLPROG_CORE_AVR_DUE
#ifndef FLPROG_CORE_STM
#define FLPROG_CAN_USE_SOFTWARE_SERIAL
#endif
#endif
#endif

#ifdef FLPROG_CORE_ESP32
#define FLPROG_CAN_USE_BLUETOOTH_SERIAL
#endif

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
     byte getPortSpeed() { return portSpeed; };
    byte getPortDataBits() { return portDataBits; };
    byte getPortStopBits() { return portStopBits; };
    byte getPortParity() { return portParity; };
    virtual bool hasPort() {return false;};
    virtual void restartPort(){};
    void setPortSpeed(byte speed);
    void setPortDataBits(byte dataBits);
    void setPortStopBits(byte stopBits);
    void setPortParity(byte parity);
    byte available(){return uartPort()->available(); };
    byte read() { return uartPort()->read(); };
    byte write(byte *buffer, byte size) { return uartPort()->write(buffer, size); };
    
    void print(String str) { uartPort()->print(str);};
    void print(const char str[]){ uartPort()->print(str);};
    void print(char str){uartPort()->print(str);};
    void print(byte val, int mode = DEC){  uartPort()->print(val, mode);};
    void print(int val, int mode = DEC){  uartPort()->print(val, mode);};
    void print(long val, int mode = DEC){  uartPort()->print(val, mode);};
    void print(unsigned long val, int mode = DEC){  uartPort()->print(val, mode);};
    void print(float val, int mode = 2){  uartPort()->print(val, mode);};
     void println(String str){uartPort()->println(str);};
    void println(char str){uartPort()->println(str);};
    void println(const char str[]){uartPort()->println(str);};
    void println(byte val, int mode = DEC){uartPort()->println(val, mode);};
    void println(int val, int mode = DEC){uartPort()->println(val, mode);};
    void println(long val, int mode = DEC){uartPort()->println(val, mode);};
    void println(unsigned long val, int mode = DEC){uartPort()->println(val, mode);};
    void println(float val, int mode = 2){uartPort()->println(val, mode);};
    void println(){uartPort()->println();};
    

   protected:
   virtual Stream *uartPort(){return 0;};
   uint32_t speedFromCode();
   int serialCodeForParametrs();
   void setCodeFromSpeed(int32_t speed);
    byte portSpeed = FLPROG_SPEED_9600;
    byte portDataBits = FLPROG_PORT_DATA_BITS_8;
    byte portStopBits = FLPROG_PORT_STOP_BITS_1;
    byte portParity = FLPROG_PORT_PARITY_NONE;

};

#ifdef FLPROG_CORE_ESP8266
#include "hardwareUart\hardwareUartESP8266\hardwareUartESP8266.h"
#endif

#ifdef FLPROG_CORE_AVR_DUE
#include "hardwareUart\hardwareUartDUE\hardwareUartDUE.h"
#endif

#ifdef FLPROG_CORE_AVR
#include  "hardwareUart\hardwareUartAVR\hardwareUartAVR.h"
#endif

#ifdef  FLPROG_CORE_ESP32
#include  "hardwareUart\hardwareUartESP32\hardwareUartESP32.h"
#endif

#ifdef FLPROG_CORE_STM
#include  "hardwareUart\hardwareUartSTM\hardwareUartSTM.h"
#endif

#ifdef FLPROG_CAN_USE_BLUETOOTH_SERIAL
#include "bluetoothSerial\flprogUartBluetoothSerial.h"
#endif

#ifdef FLPROG_CAN_USE_SOFTWARE_SERIAL
#include "softwareUart\flprogSoftwareUart.h"
#endif
