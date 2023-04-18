#pragma once
#include <Arduino.h>
#include "flprogSelectCoreAvr.h"
#include "flprogSelectCoreSam.h"
#include "flprogSelectCoreSamD21.h"
#include "flprogSelectCoreEsp8266.h"
#include "flprogSelectCoreEsp32_M5.h"
#include "flprogSelectCoreEsp32_Pico.h"
#include "flprogSelectCoreEsp32C3.h"
#include "flprogSelectCoreEsp32S.h"
#include "flprogSelectCoreEsp32S2.h"
#include "flprogSelectCoreEsp32S3.h"
#include "flprogSelectCore_Rp_Pico.h"
#include "flprogSelectCoreStm32F1.h"
#include "flprogSelectCoreStm32F4.h"
#include "flprogSelectCoreStm32H7.h"
#include "flprogSelectCoreStm32_M_F1.h"
#include "flprogSelectCoreStm32_M_F4.h"
#include "flprogSelectCoreStm8.h"

#if !defined(FLPROG_CORE_CODE)
#define FLPROG_CORE_CODE 90     //--Код CORE;
#define FLPROG_CORE_NAME "ANON" //--Имя CORE;
#define FLPROG_CORE_ANON        //--Идентификатор CORE;
#define FLPROG_I2CSPEED 400000UL;
#endif

