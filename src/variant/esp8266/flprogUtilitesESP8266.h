#pragma once
#include <Arduino.h>
#include "RT_HW_BASE.h"

#ifdef RT_HW_CORE_ESP8266

namespace flprog
{
    uint32_t freeMemory();
};
#endif