#include "GyverTimers.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void setup()
{
    Timer1.setPeriod(30000);
    Timer1.enableISR();
}

void loop()
{
  
}

ISR(TIMER1_A) {
    asm("jmp 0"); 
}








