#pragma once
#include "Arduino.h"
#include <Wire.h>
#include "flprogI2C.h"

#ifdef FLPROG_CORE_STM

#ifdef FLPROG_CORE_STM32
#include "stm32/flprogI2C_Stm32.h"
#endif

#ifdef FLPROG_CORE_STM8
#include "stm8/flprogI2C_Stm8.h"
#endif

#endif