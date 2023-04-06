#include "flprogUtilites.h"
FLProgUart uart1(&Serial);

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
    uart1.setPortSpeed(FLPROG_SPEED_14400);

    // Задаем количество дата бит
    uart1.setPortDataBits(8);

    // Задаем количество стоп бит
    uart1.setPortStopBits(2);

    /*
      Задаем четность
      Значения 0 (NONE), 1 (EVEN), 2 (ODD)
    */
    uart1.setPortParity(2);

    // Инициализируем порт
    //  uart1.begin(9600);
    uart1.begin(9600, SERIAL_8N1);
    // uart1.begin();
}

void loop()
{

    while (uart1.available())
    {
        uart1.write(uart1.read());
    }
}