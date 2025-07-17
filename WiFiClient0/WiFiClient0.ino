#include <WiFi.h>
#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 8

// Конфигурация Wi-Fi
const char* ssid = "TP-Link_49A3";          // Название вашей Wi-Fi сети
const char* password = "75298227";          // Пароль от сети

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  leds[0] = CRGB::Blue; FastLED.show();

  Serial.begin(115200);
  delay(1000);

  // Инициализация Wi-Fi в режиме станции
  WiFi.mode(WIFI_STA);
  
  // Отключение сохранения конфигурации Wi-Fi в flash (опционально)
  WiFi.persistent(false);
  
  // Настройка мощности передачи (от 0 до 84, по умолчанию 84)
  WiFi.setTxPower(WIFI_POWER_8_5dBm); // Пример для экономии энергии

  Serial.println("\nПодключение к: " + String(ssid));

  // Запуск подключения
  WiFi.begin(ssid, password);

  // Ожидание подключения с анимацией
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (++attempts > 30) { // Таймаут 15 секунд
      Serial.println("\nОшибка подключения! Перезагрузка...");
      ESP.restart();
      
    }
    leds[0] = CRGB::Red; FastLED.show(); 
  }
  leds[0] = CRGB::Green; FastLED.show(); 

  // Вывод информации о подключении
  Serial.println("\nПодключение успешно!");
  Serial.print("IP-адрес: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC-адрес: ");
  Serial.println(WiFi.macAddress());
  Serial.print("Канал Wi-Fi: ");
  Serial.println(WiFi.channel());
  Serial.print("Мощность сигнала (RSSI): ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
}

void loop() {
  // Проверка соединения каждые 10 секунд
  static unsigned long lastCheck = 0;
  if (millis() - lastCheck > 10000) {
    lastCheck = millis();
    
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Потеряно соединение! Переподключение...");
      WiFi.reconnect();
    } else {
      Serial.print("Статус: Подключено | RSSI: ");
      Serial.print(WiFi.RSSI());
      Serial.println(" dBm");
    }
  }
}