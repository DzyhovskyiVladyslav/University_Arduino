#include "GyverTimers.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void setup()
{
    Serial.begin(9600);
    Timer1.setPeriod(30000);
    Timer1.enableISR();
}

void loop()
{
  
}

ISR(TIMER1_A) {
    Serial.println("Stop time: " + String(double(micros())/1000) + "ms");
    Timer1.stop();
}
