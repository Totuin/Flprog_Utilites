#pragma once
#include "Arduino.h"

#ifdef FLPROG_CORE_ESP

#ifdef FLPROG_CORE_ESP8266
#include "esp8266/flprogTCPDeviceEsp8266.h"
#endif

#ifdef FLPROG_CORE_ESP32
#include "esp32/flprogTCPDeviceEsp32.h"
#endif

#endif