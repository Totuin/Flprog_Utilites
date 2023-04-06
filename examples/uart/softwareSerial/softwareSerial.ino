#include "flprogUtilites.h"
FLProgUart uart0(&Serial);
FLProgSoftwareUart uart1(2, 4); // Rx pin, Tx pin

void setup()
{
    /*
      Параметрирузируем порт:
      Вызовы не обязательны по умолчанию параметры порта 9600 8N1
      Параметры порта можно менять во время исполнения программы

      Задаём скорость порта допустимые константы:
      FLPROG_SPEED_300
      FLPROG_SPEED_600
      FLPROG_SPEED_1200
      FLPROG_SPEED_2400
      FLPROG_SPEED_4800
      FLPROG_SPEED_9600
      FLPROG_SPEED_14400
      FLPROG_SPEED_19200
      FLPROG_SPEED_28800
      FLPROG_SPEED_38400
      FLPROG_SPEED_57600
      FLPROG_SPEED_115200
    */
    // uart1.setPortSpeed(FLPROG_SPEED_19200);

    // Инициализируем порт
    uart0.begin();
    uart1.begin();

    // uart1.begin();
}

void loop()
{

    while (uart1.available())
    {
        uart0.write(uart1.read());
    }

     while (uart0.available())
    {
        uart1.write(uart0.read());
    }
}