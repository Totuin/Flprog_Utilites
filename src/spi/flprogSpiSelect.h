#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"
#include "flprogSPI.h"

#ifdef FLPROG_CORE_AVR
#define FLPROG_EXISTS_SELECT_SPI
#include "variant/avr/flprogSpiAvr.h"
#endif

#ifdef FLPROG_CORE_AVR_DUE
#define FLPROG_EXISTS_SELECT_SPI
#include "variant/due/flprogSpiDue.h"
#endif

#ifdef FLPROG_CORE_ESP
#define FLPROG_EXISTS_SELECT_SPI
#include "variant/esp/flprogSpiSelectEsp.h"
#endif

#ifdef FLPROG_CORE_STM
#define FLPROG_EXISTS_SELECT_SPI
#include "variant/stm/flprogSpiSelectStm.h"
#endif


#ifndef  FLPROG_EXISTS_SELECT_SPI
#define FLPROG_EXISTS_SELECT_SPI
#define FLPROG_ANON_SELECT_SPI
#include "variant/anon/flprogSpiAnon.h"
#endif


