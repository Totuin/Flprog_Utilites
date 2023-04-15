#pragma once
#include "Arduino.h"
#include <Wire.h>
#include "flprogUtilites.h"

class AbstractFLProgI2C
{
public:
    uint8_t getErrorCode() { return codeErr; };
    bool findAddr(uint8_t addr);
    uint8_t fullWrite(uint8_t addr, uint8_t data);
    uint8_t fullWrite(uint8_t addr, const uint8_t *data, uint8_t quantity);
    uint8_t fullRequestFrom(uint8_t address, uint8_t quantity);
    uint8_t fullRead(uint8_t addr, uint8_t *data, uint8_t quantity);
    uint8_t fullRead(uint8_t addr, uint16_t *data, uint8_t quantity);
    uint8_t fullRead(uint8_t addr, uint32_t *data, uint8_t quantity);
    uint8_t waitingForData(uint8_t count);
    uint8_t fullReadReg(uint8_t addr, uint8_t reg);
    uint8_t fullWriteReg(uint8_t addr, uint8_t reg, uint8_t value);

    virtual void beginTransmission(uint8_t addr){};
    virtual uint8_t endTransmission() { return 0; };
    virtual int available() { return 0; };
    virtual bool checkBus() { return false; };
    virtual void write(const uint8_t *data, uint8_t quantity){};
    virtual void write(uint8_t data){};
    virtual int read() { return 0; };
    virtual uint8_t requestFrom(uint8_t address, uint8_t quantity) { return 0; };
    virtual void setSpeed(uint32_t newSpeed){};
    virtual void resetSpeedFrom(uint32_t newSpeed){};

protected:
    uint8_t bus;
    bool busy = false;
    uint8_t status = 0;
    uint8_t codeErr = 0;
    int sda = -1;
    int scl = -1;
    uint32_t speed ;
};

class FLProgTCA9548A
{
public:
    FLProgTCA9548A(AbstractFLProgI2C *device, uint8_t deviceAddress);
    FLProgTCA9548A(AbstractFLProgI2C *device);
    void beginTransmission(uint8_t addr, uint8_t chanel);
    void write(const uint8_t *data, uint8_t quantity, uint8_t chanel);
    void write(uint8_t data, uint8_t chanel);
    uint8_t endTransmission();
    int available(uint8_t chanel);
    int read(uint8_t chanel);
    uint8_t requestFrom(uint8_t address, uint8_t quantity, uint8_t chanel);
    void setSpeed(uint32_t newSpeed, uint8_t chanel);
    void resetSpeedFrom(uint32_t newSpeed, uint8_t chanel);
    bool checkBus();

private:
    void switchToChanel(uint8_t chanel);
    AbstractFLProgI2C *i2cDevice;
    uint8_t address;
    uint8_t currentChanel = 10;
    uint8_t errorCode = 0;
};


class FLProgVirtualI2C : public AbstractFLProgI2C
{
public:
    FLProgVirtualI2C(FLProgTCA9548A *parentDevice, uint8_t chanelOnParent);
    virtual bool begin();
    virtual void beginTransmission(uint8_t addr);
    virtual void write(const uint8_t *data, uint8_t quantity);
    virtual void write(uint8_t data);
    virtual uint8_t endTransmission();
    virtual int available();
    virtual int read();
    virtual uint8_t requestFrom(uint8_t address, uint8_t quantity);
    virtual void setSpeed(uint32_t newSpeed);
    virtual void resetSpeedFrom(uint32_t newSpeed);
    virtual bool checkBus();

private:
    FLProgTCA9548A *parent;
    uint8_t chanel;
};



#include "i2C/flprogI2C_Base.h"
#include "i2C/flprogI2C_sensorsBasic.h"

