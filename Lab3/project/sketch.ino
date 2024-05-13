#include <AccelStepper.h>

const int stepPin1 = 4;
const int dirPin1 = 2;
const int stepPin2 = 21;
const int dirPin2 = 19;

const int potPin = 25;

AccelStepper stepper1(AccelStepper::DRIVER, stepPin1, dirPin1);
AccelStepper stepper2(AccelStepper::DRIVER, stepPin2, dirPin2);

void setup() {
  stepper1.setMaxSpeed(1000);
  stepper1.setAcceleration(500);
  stepper2.setMaxSpeed(1000);
  stepper2.setAcceleration(500);
}

void loop() {
  int potValue = analogRead(potPin);
  int speed = map(potValue, 0, 4095, -50, 50);
  stepper1.setSpeed(speed);
  int angle = map(potValue, 0, 4095, -50, 50);
  stepper2.moveTo(angle);
  stepper1.run();
  stepper2.run();
}