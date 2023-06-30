#pragma once
#include "Arduino.h"
#include <Wire.h>
#include "flprogUtilites.h"
#include "flprogI2C.h"

#ifdef FLPROG_CORE_AVR
#define FLPROG_EXISTS_SELECT_I2C
#include "variant/avr/flprogI2C_Avr.h"
#endif

#ifdef FLPROG_CORE_AVR_DUE
#define FLPROG_EXISTS_SELECT_I2C
#include "variant/due/flprogI2C_Due.h"
#endif

#ifdef FLPROG_CORE_ESP
#define FLPROG_EXISTS_SELECT_I2C
#include "variant/esp/flprogI2C_Esp.h"
#endif

#ifdef FLPROG_CORE_STM
#define FLPROG_EXISTS_SELECT_I2C
#include "variant/stm/flprogI2C_Stm.h"
#endif

#ifndef  FLPROG_EXISTS_SELECT_I2C
#define FLPROG_EXISTS_SELECT_I2C
#define FLPROG_ANON_SELECT_I2C
#include "variant/anon/flprogI2C_Anon.h"
#endif


