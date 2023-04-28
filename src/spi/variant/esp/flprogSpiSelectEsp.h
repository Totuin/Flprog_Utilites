#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"
#include "flprogSPI.h"

#ifdef FLPROG_CORE_ESP

#ifdef FLPROG_CORE_ESP8266
#include "esp8266/flprogSpiEsp8266.h"
#endif

#ifdef FLPROG_CORE_ESP32
#include "esp32/flprogSpiEsp32.h"
#endif

#endif