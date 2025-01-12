#include "flprogUtilites.h"
#include "flprogUart.h"

FlprogUartExecutor FLProgUart;
#define UART_NUMBER 1
#ifndef LED_BUILTIN
#define LED_BUILTIN PA1
#endif

uint32_t startTime;
uint32_t coutner;

void setup()
{
    startTime = millis();
    coutner = 1;
    FLProgUart.setSpeedUart(115200, UART_NUMBER);
    FLProgUart.setDataBitUart(8, UART_NUMBER);
    FLProgUart.setParityUart(0, UART_NUMBER);
    FLProgUart.setStopBitUart(1, UART_NUMBER);
    pinMode(PA1, OUTPUT);
    digitalWrite(PA1, HIGH);
}
void loop()
{

    if (flprog::isTimer(startTime, 2000))
    {
        coutner++;
        startTime = millis();
        FLProgUart.printUart(("Тест УАРТ - " + String(coutner, DEC)), UART_NUMBER);
        FLProgUart.printUart("\n", UART_NUMBER);
        digitalWrite(PA1, !(digitalRead(PA1)));
    }
}
