void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(3)) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
}
