#include <Arduino.h>

//#define LED 2
#define DELAY 20

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // GPIO8 - встроенный LED
  digitalWrite(LED_BUILTIN, LOW);

  //pinMode(LED, OUTPUT); // GPIO8 - встроенный LED
  ///digitalWrite(LED, LOW);

}

void loop() 
{

  digitalWrite(LED_BUILTIN, HIGH);
  delay(DELAY);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY);

}