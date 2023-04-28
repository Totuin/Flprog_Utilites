#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"
#include "flprogSPI.h"

#ifdef FLPROG_CORE_STM

#ifdef FLPROG_CORE_STM32
#include "stm32/flprogSpiStm32.h"
#endif

#ifdef FLPROG_CORE_STM8
#include "stm8/flprogSpiStm8.h"
#endif

#endif