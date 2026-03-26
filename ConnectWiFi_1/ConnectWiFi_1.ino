#include <WiFi.h>

#define LED_PIN 8  

const char* ssid = "TP-Link_49A3";
const char* password = "75298227";

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  // Подключение к Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Мигание при подключении
  }
  
  Serial.println("\nConnected! IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_PIN, HIGH); // Постоянно горит при подключении
}

void loop() 
{
  // Проверка соединения
  if (WiFi.status() == WL_CONNECTED) 
  {
    Serial.println("WiFi connected");
  } 
  else 
  {
    Serial.println("WiFi disconnected");
    digitalWrite(LED_PIN, LOW);
  }
  delay(5000);
}
