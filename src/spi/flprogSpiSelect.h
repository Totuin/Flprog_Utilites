#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"
#include "flprogSPI.h"

#ifdef FLPROG_CORE_AVR
#include "variant\avr\flprogSpiAvr.h"
#endif

#ifdef FLPROG_CORE_AVR_DUE
#include "variant\due\flprogSpiDue.h"
#endif

#ifdef FLPROG_CORE_ESP
#include "variant/esp/flprogSpiSelectEsp.h"
#endif

#ifdef FLPROG_CORE_STM
#include "variant/stm/flprogSpiSelectStm.h"
#endif


