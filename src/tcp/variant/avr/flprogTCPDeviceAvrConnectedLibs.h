#pragma once
#include "Arduino.h"

#ifdef FLPROG_CORE_AVR
#define FLPROG_W5100_TCP_DEVICE
#include "Ethernet.h"
#include "SPI.h"
#endif
