#include <Arduino.h>
#define LED_PIN 2
void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // GPIO8 - встроенный LED
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}