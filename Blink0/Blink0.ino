#include <Arduino.h>

#define DELAY 350

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // GPIO8 - встроенный LED
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DELAY);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY);
}