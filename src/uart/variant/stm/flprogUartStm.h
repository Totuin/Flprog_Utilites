#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_STM

#ifdef FLPROG_CORE_STM32
#include "stm32/flprogUartStm32.h"
#endif

#ifdef FLPROG_CORE_STM8
#include "stm8/flprogUartStm8.h"
#endif

#endif