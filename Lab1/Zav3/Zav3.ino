void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, turnOn, RISING);
  attachInterrupt(1, turnOff, RISING);
}

void loop() {

}

void turnOn() {
  digitalWrite(4, HIGH);
}

void turnOff() {
  digitalWrite(4, LOW);
}