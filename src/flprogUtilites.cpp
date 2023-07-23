#include "flprogUtilites.h"

//------------------FLProgStream-----------------

uint8_t FLProgStream::available()
{
    if (hasStream())
    {
        return stream()->available();
    }
    return 0;
}

uint8_t FLProgStream::read()
{
    if (hasStream())
    {
        return stream()->read();
    }
    return 0;
}

uint8_t FLProgStream::write(uint8_t *buffer, uint8_t size)
{
    if (hasStream())
    {
        return stream()->write(buffer, size);
    }
    return 0;
}

uint8_t FLProgStream::write(uint8_t data)
{
    if (hasStream())
    {
        return stream()->write(data);
    }
    return 0;
}

void FLProgStream::print(String str)
{
    if (hasStream())
    {
        stream()->print(str);
    }
}

void FLProgStream::print(const char str[])
{
    if (hasStream())
    {
        stream()->print(str);
    }
}

void FLProgStream::print(char str)
{
    if (hasStream())
    {
        stream()->print(str);
    }
}

void FLProgStream::print(uint8_t val, int mode)
{
    if (hasStream())
    {
        stream()->print(val, mode);
    }
}

void FLProgStream::print(int val, int mode)
{
    if (hasStream())
    {
        stream()->print(val, mode);
    }
}

void FLProgStream::print(long val, int mode)
{
    if (hasStream())
    {
        stream()->print(val, mode);
    }
}

void FLProgStream::print(unsigned long val, int mode)
{
    if (hasStream())
    {
        stream()->print(val, mode);
    }
}

void FLProgStream::print(float val, int mode)
{
    if (hasStream())
    {
        stream()->print(val, mode);
    }
}

void FLProgStream::println(String str)
{
    if (hasStream())
    {
        stream()->println(str);
    }
}

void FLProgStream::println(char str)
{
    if (hasStream())
    {
        stream()->println(str);
    }
}

void FLProgStream::println(const char str[])
{
    if (hasStream())
    {
        stream()->println(str);
    }
}

void FLProgStream::println(uint8_t val, int mode)
{
    if (hasStream())
    {
        stream()->println(val, mode);
    }
}

void FLProgStream::println(int val, int mode)
{
    if (hasStream())
    {
        stream()->println(val, mode);
    }
}

void FLProgStream::println(long val, int mode)
{
    if (hasStream())
    {
        stream()->println(val, mode);
    }
}

void FLProgStream::println(unsigned long val, int mode)
{
    if (hasStream())
    {
        stream()->println(val, mode);
    }
}

void FLProgStream::println(float val, int mode)
{
    if (hasStream())
    {
        stream()->println(val, mode);
    }
}

void FLProgStream::println()
{
    if (hasStream())
    {
        stream()->println();
    }
}

//--------------namespace flprog-------------------------


uint32_t flprog::difference32(uint32_t start, uint32_t end)
{
    if (end >= start)
    {
        return end - start;
    }
    return (0xfFFFFFFF - start) + end;
}

bool flprog::isTimer(uint32_t startTime, uint32_t period)
{
    return (difference32(startTime, (millis()))) >= period;
}

bool flprog::isTimerMicros(unsigned long startTime, unsigned long period)
{
    return (difference32(startTime, (micros()))) >= period;
}

uint32_t flprog::timeBack(uint32_t value)
{
    uint32_t current = millis();
    if (value < current)
    {
        return current - value;
    }
    return (0xfFFFFFFF - value) + current;
}


