#include "flprogSystemParametr.h"

//-----------------------------------------------------------bool---------------------------------------------------------------------------
FLProgBooleanSystemParametr::FLProgBooleanSystemParametr(FLProgSetBoolValueCallback setCallBack, FLProgGetBoolValueCallback getCallBack, bool value)
{
    _setCallBack = setCallBack;
    _getCallBack = getCallBack;
    set(value);
}
void FLProgBooleanSystemParametr::set(bool value)
{
    if (_setCallBack == 0)
    {
        return;
    }
    _setCallBack(value);
}

bool FLProgBooleanSystemParametr::get()
{
    if (_getCallBack == 0)
    {
        return false;
    }
    return _getCallBack();
}

//-----------------------------------------------------------uint8_t---------------------------------------------------------------------------
FLProgUint8SystemParametr::FLProgUint8SystemParametr(FLProgSetUint8ValueCallback setCallBack, FLProgGetUint8ValueCallback getCallBack, uint8_t value)
{
    _setCallBack = setCallBack;
    _getCallBack = getCallBack;
    set(value);
}
void FLProgUint8SystemParametr::set(uint8_t value)
{
    if (_setCallBack == 0)
    {
        return;
    }
    _setCallBack(value);
}

uint8_t FLProgUint8SystemParametr::get()
{
    if (_getCallBack == 0)
    {
        return 0;
    }
    return _getCallBack();
}

//-----------------------------------------------------------int16_t---------------------------------------------------------------------------
FLProgInt16SystemParametr::FLProgInt16SystemParametr(FLProgSetInt16ValueCallback setCallBack, FLProgGetInt16ValueCallback getCallBack, int16_t value)
{
    _setCallBack = setCallBack;
    _getCallBack = getCallBack;
    set(value);
}
void FLProgInt16SystemParametr::set(int16_t value)
{
    if (_setCallBack == 0)
    {
        return;
    }
    _setCallBack(value);
}

int16_t FLProgInt16SystemParametr::get()
{
    if (_getCallBack == 0)
    {
        return 0;
    }
    return _getCallBack();
}

//-----------------------------------------------------------int32_t---------------------------------------------------------------------------
FLProgInt32SystemParametr::FLProgInt32SystemParametr(FLProgSetInt32ValueCallback setCallBack, FLProgGetInt32ValueCallback getCallBack, int32_t value)
{
    _setCallBack = setCallBack;
    _getCallBack = getCallBack;
    set(value);
}
void FLProgInt32SystemParametr::set(int32_t value)
{
    if (_setCallBack == 0)
    {
        return;
    }
    _setCallBack(value);
}

int32_t FLProgInt32SystemParametr::get()
{
    if (_getCallBack == 0)
    {
        return 0;
    }
    return _getCallBack();
}

//-----------------------------------------------------------uint32_t---------------------------------------------------------------------------
FLProgUint32SystemParametr::FLProgUint32SystemParametr(FLProgSetUint32ValueCallback setCallBack, FLProgGetUint32ValueCallback getCallBack, uint32_t value)
{
    _setCallBack = setCallBack;
    _getCallBack = getCallBack;
    set(value);
}
void FLProgUint32SystemParametr::set(uint32_t value)
{
    if (_setCallBack == 0)
    {
        return;
    }
    _setCallBack(value);
}

uint32_t FLProgUint32SystemParametr::get()
{
    if (_getCallBack == 0)
    {
        return 0;
    }
    return _getCallBack();
}

//-----------------------------------------------------------String---------------------------------------------------------------------------
FLProgStringSystemParametr::FLProgStringSystemParametr(FLProgSetStringValueCallback setCallBack, FLProgGetStringValueCallback getCallBack, String value)
{
    _setCallBack = setCallBack;
    _getCallBack = getCallBack;
    set(value);
}
void FLProgStringSystemParametr::set(String value)
{
    if (_setCallBack == 0)
    {
        return;
    }
    _setCallBack(value);
}

String FLProgStringSystemParametr::get()
{
    if (_getCallBack == 0)
    {
        return "";
    }
    return _getCallBack();
}