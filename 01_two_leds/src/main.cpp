#include <Arduino.h>

const int greenLedPin = 23;
const int redLedPin = 22;

void setup() {
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, HIGH);
  delay(1500);
  digitalWrite(redLedPin, LOW);
  delay(1500);
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
  delay(1500);
  digitalWrite(redLedPin, LOW);
  delay(1500);
}
