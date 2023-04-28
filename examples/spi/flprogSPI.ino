#include "flprogSPI.h"

FLProgSPI spiBus(0);

uint32_t startTime;
byte counter = 0;
int csPin=PD6;
void setup()
{
  startTime = millis();
  spiBus.begin();
  pinMode(csPin, OUTPUT);
}

void loop()
{
  if (flprog::isTimer(startTime, 100))
  {
    digitalWrite(csPin, 0);
    counter++;
    if (counter == 255) {
      spiBus.transfer(255);
      counter = 0;
    }
    else
    {
      spiBus.transfer(counter);
    }
    digitalWrite(csPin, 1);
    startTime = millis();
  }
}