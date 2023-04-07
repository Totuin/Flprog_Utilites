#pragma once
#include "Arduino.h"

#ifdef FLPROG_CORE_ESP32
#define FLPROG_WIFI_TCP_DEVICE
#include "./tcp/flprogWifiTcpDevice.h"
#endif