#pragma once
#include "Arduino.h"
#include <Wire.h>
#include "flprogI2C.h"

#ifdef FLPROG_CORE_ESP

#ifdef FLPROG_CORE_ESP8266
#include "esp8266/flprogI2C_Esp8266.h"
#endif

#ifdef FLPROG_CORE_ESP32
#include "esp32/flprogI2C_Esp32.h"
#endif

#endif