#pragma once
#include "Arduino.h"
#include <Wire.h>
#include "flprogUtilites.h"
#include "flprogI2C.h"

#ifdef FLPROG_CORE_AVR
#include "variant/avr/flprogI2C_Avr.h"
#endif

#ifdef FLPROG_CORE_AVR_DUE
#include "variant/due/flprogI2C_Due.h"
#endif

#ifdef FLPROG_CORE_ESP
#include "variant/esp/flprogI2C_Esp.h"
#endif

#ifdef FLPROG_CORE_STM
#include "variant/stm/flprogI2C_Stm.h"
#endif


