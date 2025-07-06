/* 
The true ESP32 chip ID is essentially its MAC address.
This sketch provides an alternate chip ID that matches
the output of the ESP.getChipId() function on ESP8266
(i.e. a 32-bit integer matching the last 3 bytes of
the MAC address. This is less unique than the
MAC address chip ID, but is helpful when you need
an identifier that can be no more than a 32-bit integer
(like for switch...case).

created 2020-06-07 by cweinhofer
with help from Cicicok 
*/

#define DELAY 350

uint32_t chipId = 0;
int Counter = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // GPIO8 - встроенный LED
  
  Serial.begin(115200);
  while(!Serial);
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DELAY);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.println("Serial test...");

}

void loop() 
{
/*
  for (int i = 0; i < 17; i = i + 8) 
  {
    chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
  }

  Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
  Serial.printf("This chip has %d cores\n", ESP.getChipCores());
  Serial.print("Chip ID: ");
  Serial.println(chipId);
  */
  Counter++;

  Serial.println("Serial test:" + String(Counter));
  
  delay(3000);
  //
  //digitalWrite(LED_BUILTIN, LOW);
  //delay(DELAY);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DELAY);
  digitalWrite(LED_BUILTIN, LOW);
}
