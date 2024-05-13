#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd[4] = {
  LiquidCrystal_I2C(0x27, 16, 2),
  LiquidCrystal_I2C(0x26, 16, 2),
  LiquidCrystal_I2C(0x25, 16, 2),
  LiquidCrystal_I2C(0x24, 16, 2)
};

int const LCD_W = 16;
int const LCD_H = 2;
int const LCD_N = 4;
int X = 0;
int Y = 0;
int N = 0;
String message = "Hello, I'm moving";
int L = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  for (int i = 0; i < 4; i++) {
    lcd[i].init();
    lcd[i].backlight();
    lcd[i].clear();
  }
  L = message.length();
}

void loop() {
  for (int i = 0; i < 4; i++) {
    lcd[i].clear();
  }
  if (X + L <= LCD_W) {
    lcd[N].setCursor(X, Y);
    lcd[N].print(message);
  } else if (X + L > LCD_W) {
    int next_Y = calculateNextY();
    int next_N = calculateNextNFromY(next_Y);
    lcd[N].setCursor(X, Y);
    lcd[N].print(message.substring(0, LCD_W - X));
    lcd[next_N].setCursor(0, next_Y);
    lcd[next_N].print(message.substring(LCD_W - X));
  }

  if (X < LCD_W - 1) {
    X++;
  } else {
    X = 0;
    Y = calculateNextY();
    N = calculateNextNFromY(Y);
  }
  delay(500);
}

int calculateNextNFromY(int next_Y) {
  if ((N % 2 == 1 && next_Y == 0) || (N % 2 == 0)) {
    return calculateNextN();
  } else {
    return N - 1;
  }
}

int calculateNextN() {
  if (N < LCD_N - 1) {
    return N + 1;
  } else {
    return 0;
  }
}

int calculateNextY() {
  if (Y < LCD_H - 1 && N % 2 == 1) {
    return Y + 1;
  } else if (N % 2 == 0) {
    return Y;
  } else {
    return 0;
  }
}