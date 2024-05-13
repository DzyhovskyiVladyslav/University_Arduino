
#include "GyverTimers.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void setup()
{
    Timer1.setPeriod(45000);
    Timer1.enableISR();
    pinMode(5, OUTPUT);
}

void loop()
{
  
}

ISR(TIMER1_A) {
    digitalWrite(5, !digitalRead(5));

}