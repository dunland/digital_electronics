#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println(1);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println(0);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
}