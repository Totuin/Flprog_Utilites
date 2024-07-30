#pragma once
#include <Arduino.h>

typedef void (*FLProgSetBoolValueCallback)(bool);
typedef void (*FLProgSetUint8ValueCallback)(uint8_t);
typedef void (*FLProgSetUint16ValueCallback)(uint16_t);
typedef void (*FLProgSetInt16ValueCallback)(int16_t);
typedef void (*FLProgSetUint32ValueCallback)(uint32_t);
typedef void (*FLProgSetInt32ValueCallback)(int32_t);
typedef void (*FLProgSetStringValueCallback)(String);

typedef bool (*FLProgGetBoolValueCallback)();
typedef uint8_t (*FLProgGetUint8ValueCallback)();
typedef uint16_t (*FLProgGetUint16ValueCallback)();
typedef int16_t (*FLProgGetInt16ValueCallback)();
typedef uint32_t (*FLProgGetUint32ValueCallback)();
typedef int32_t (*FLProgGetInt32ValueCallback)();
typedef String (*FLProgGetStringValueCallback)();

class FLProgBooleanSystemParametr
{
public:
    FLProgBooleanSystemParametr(FLProgSetBoolValueCallback setCallBack, FLProgGetBoolValueCallback getCallBack, bool value);
    void set(bool value);
    bool get();

protected:
    FLProgSetBoolValueCallback _setCallBack = 0;
    FLProgGetBoolValueCallback _getCallBack = 0;
};

class FLProgUint8SystemParametr
{
public:
    FLProgUint8SystemParametr(FLProgSetUint8ValueCallback setCallBack, FLProgGetUint8ValueCallback getCallBack, uint8_t value);
    void set(uint8_t value);
    uint8_t get();

protected:
    FLProgSetUint8ValueCallback _setCallBack = 0;
    FLProgGetUint8ValueCallback _getCallBack = 0;
};

class FLProgInt16SystemParametr
{
public:
    FLProgInt16SystemParametr(FLProgSetInt16ValueCallback setCallBack, FLProgGetInt16ValueCallback getCallBack, int16_t value);
    void set(int16_t value);
    int16_t get();

protected:
    FLProgSetInt16ValueCallback _setCallBack = 0;
    FLProgGetInt16ValueCallback _getCallBack = 0;
};

class FLProgInt32SystemParametr
{
public:
    FLProgInt32SystemParametr(FLProgSetInt32ValueCallback setCallBack, FLProgGetInt32ValueCallback getCallBack, int32_t value);
    void set(int32_t value);
    int32_t get();

protected:
    FLProgSetInt32ValueCallback _setCallBack = 0;
    FLProgGetInt32ValueCallback _getCallBack = 0;
};

class FLProgUint32SystemParametr
{
public:
    FLProgUint32SystemParametr(FLProgSetUint32ValueCallback setCallBack, FLProgGetUint32ValueCallback getCallBack, uint32_t value);
    void set(uint32_t value);
    uint32_t get();

protected:
    FLProgSetUint32ValueCallback _setCallBack = 0;
    FLProgGetUint32ValueCallback _getCallBack = 0;
};

class FLProgStringSystemParametr
{
public:
    FLProgStringSystemParametr(FLProgSetStringValueCallback setCallBack, FLProgGetStringValueCallback getCallBack, String value);
    void set(String value);
    String get();

protected:
    FLProgSetStringValueCallback _setCallBack = 0;
    FLProgGetStringValueCallback _getCallBack = 0;
};