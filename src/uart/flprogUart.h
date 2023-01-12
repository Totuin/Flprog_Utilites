#pragma once
#include "Arduino.h"
#include "./flprogUtilites.h"

#ifdef ESP32
#include "BluetoothSerial.h"
#else
#include "SoftwareSerial.h"
#endif

#define FLPROG_HARDWARE_UART 0
#define FLPROG_SOFTWARE_UART 1
#define FLPROG_USB_UART 2
#define FLPROG_BLUETOOTH_UART 3

#define SPEED_300 0
#define SPEED_600 1
#define SPEED_1200 2
#define SPEED_2400 3
#define SPEED_4800 4
#define SPEED_9600 5
#define SPEED_14400 6
#define SPEED_19200 7
#define SPEED_28800 8
#define SPEED_38400 9
#define SPEED_57600 10
#define SPEED_115200 11

#define PORT_STOP_BITS_1 1
#define PORT_STOP_BITS_2 2

#define PORT_DATA_BITS_5 5
#define PORT_DATA_BITS_6 6
#define PORT_DATA_BITS_7 7
#define PORT_DATA_BITS_8 8

#define PORT_PARITY_NONE 0
#define PORT_PARITY_EVEN 1
#define PORT_PARITY_ODD 2

class FLProgUart
{
public:
    FLProgUart(){};
    FLProgUart(HardwareSerial *hardwarePort);
#if defined(_STM32_DEF_) && defined(USBCON) && defined(USBD_USE_CDC)
    FLProgUart(USBSerial *port);
#endif

    virtual void begin();
    void begin(int32_t speed);
#ifdef ESP8266
    void begin(int32_t speed, SerialConfig mode);
#else
    void begin(int32_t speed, int mode);
#endif
    byte available()
    {
        return uartPort()->available();
    };
    byte read() { return uartPort()->read(); };
    byte write(byte *buffer, byte size) { return uartPort()->write(buffer, size); };
    virtual bool hasPort();
    virtual void restartPort();
    void setPortSpeed(byte speed);
    void setPortDataBits(byte dataBits);
    void setPortStopBits(byte stopBits);
    void setPortParity(byte parity);
    byte getPortSpeed() { return portSpeed; };
    byte getPortDataBits() { return portDataBits; };
    byte getPortStopBits() { return portStopBits; };
    byte getPortParity() { return portParity; };

    void print(String str);
    void print(const char str[]);
    void print(char str);
    void print(byte val, int mode = DEC);
    void print(int val, int mode = DEC);
    void print(long val, int mode = DEC);
    void print(unsigned long val, int mode = DEC);
    void print(float val, int mode = 2);

    void println(String str);
    void println(char str);
    void println(const char str[]);
    void println(byte val, int mode = DEC);
    void println(int val, int mode = DEC);
    void println(long val, int mode = DEC);
    void println(unsigned long val, int mode = DEC);
    void println(float val, int mode = 2);
    void println();

private:
    byte portSpeed = SPEED_9600;
    byte portDataBits = PORT_DATA_BITS_8;
    byte portStopBits = PORT_STOP_BITS_1;
    byte portParity = PORT_PARITY_NONE;

protected:
    virtual Stream *uartPort();
    HardwareSerial *port;
#if defined(_STM32_DEF_) && defined(USBCON) && defined(USBD_USE_CDC)
    USBSerial *usbPort;
#endif
    byte type = FLPROG_HARDWARE_UART;
    int serialCodeForParametrs();
#ifdef ESP8266
    SerialConfig serialModeFromInt(int16_t code);
    SerialConfig serialModeFromParametrs();
    void setSerialMode(SerialConfig mode);
#else
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs();
    void setSerialMode(int16_t mode);
#endif
    long speedFromCode();
    void setCodeFromSpeed(int32_t speed);
};

#ifdef ESP32
class FLProgBluetoothUart : public FLProgUart
{
public:
    FLProgBluetoothUart(String name);
    void setDeviceName(String name);
    void setPartnerName(String name);
    void beBluetoothMaster();
    void beBluetoothSlave();
    virtual bool hasPort();
    virtual void restartPort();
    virtual void begin();

protected:
    BluetoothSerial *bluetoothPort;
    String deviceName;
    String partnerName;
    bool isMaster = false;
    virtual Stream *uartPort() { return bluetoothPort; };
};

#else
class FLProgSoftwareUart : public FLProgUart
{
public:
    FLProgSoftwareUart(byte receivePin, byte transmitPin);
    virtual void restartPort();
    virtual bool hasPort();
    virtual void begin();

protected:
    SoftwareSerial *softwarePort;
    virtual Stream *uartPort() { return softwarePort; };
};
#endif
