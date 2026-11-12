#pragma once

// RP2040: состояние аллокатора (fordblks), не вся физически доступная память.

#include <Arduino.h>
#include "RT_HW_BASE.h"

#ifdef RT_HW_CORE_RP2040

#include <malloc.h>

namespace flprog
{
    int16_t freeMemory();
};
#endif