#include <Arduino.h>
#include <FastLED.h>

#define DELAY 200

#define NUM_LEDS 1
#define DATA_PIN 8

CRGB leds[NUM_LEDS];

void setup() {
  //pinMode(LED_BUILTIN, OUTPUT); // GPIO8 - встроенный LED
  //digitalWrite(LED_BUILTIN, LOW);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

}

void loop() 
{

  //digitalWrite(LED_BUILTIN, HIGH);
  ///delay(DELAY);
  //digitalWrite(LED_BUILTIN, LOW);
  //delay(DELAY);

  leds[0] = CRGB::Red; FastLED.show(); delay(1000);
  leds[0] = CRGB::Green; FastLED.show(); delay(1000);
  leds[0] = CRGB::Blue; FastLED.show(); delay(1000);

}