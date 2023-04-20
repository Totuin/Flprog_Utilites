#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef FLPROG_CORE_STM32
// HardwareSerial Serial2(FLPROG_UART2_RX, FLPROG_UART2_TX);

#if defined(USBCON) && defined(USBD_USE_CDC)
#define FLPROG_STM32_USB_COM0
#endif

#if defined(USART1)
#define FLPROG_STM32_SERIAL1
#endif

#if defined(USART2)
#define FLPROG_STM32_SERIAL2
#endif

#if defined(USART3)
#define FLPROG_STM32_SERIAL3
#endif

#if defined(UART4) || defined(USART4)
#define FLPROG_STM32_SERIAL4
#endif

#if defined(UART5) || defined(USART5)
#define FLPROG_STM32_SERIAL5
#endif

#if defined(USART6)
#define FLPROG_STM32_SERIAL6
#endif

#if defined(UART7) || defined(USART7)
#define FLPROG_STM32_SERIAL7
#endif

#if defined(UART8) || defined(USART8)
#define FLPROG_STM32_SERIAL8
#endif

#if defined(UART9)
#define FLPROG_STM32_SERIAL9
#endif

#if defined(UART10) || defined(USART10)
#define FLPROG_STM32_SERIAL10
#endif

#if defined(LPUART1)
#define FLPROG_STM32_SERIAL_LP1 // SerialLP1;
#endif

#if defined(LPUART2)
#define FLPROG_STM32_SERIAL_LP2 // SerialLP2;
#endif

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart();
    FLProgUart(uint8_t portNamber);
    virtual void begin();
    void begin(int32_t speed, int mode);
    virtual bool hasPort();
    virtual void restartPort();

protected:
    virtual Stream *uartPort();
    HardwareSerial *port;
#ifdef FLPROG_STM32_USB_COM0
    USBSerial *usbPort;
#endif
    byte type = FLPROG_HARDWARE_UART;
    int serialModeFromParametrs();
    void setSerialMode(int16_t mode);
};

#endif