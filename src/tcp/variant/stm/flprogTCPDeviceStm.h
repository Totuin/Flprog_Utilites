#pragma once
#include "Arduino.h"

#ifdef FLPROG_CORE_STM
#define FLPROG_W5100_TCP_DEVICE
#include "./tcp/flprogW5100TcpDevice.h"
#endif
