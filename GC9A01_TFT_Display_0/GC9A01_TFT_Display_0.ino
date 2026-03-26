#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() 
{
  Serial.begin(115200);
  
  // Инициализация дисплея
  tft.init();
  tft.setRotation(2); // Ориентация (0-3)
  tft.fillScreen(TFT_BLACK);
  
  // Включение подсветки
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH); // Или analogWrite для ШИМ
  
  Serial.println("GC9A01 Initialized");
  
  // Тестовый экран
  showStartupScreen();
  
}

void showStartupScreen() 
{
  tft.fillScreen(TFT_BLACK);
  
  // Круглая рамка
  tft.drawCircle(120, 120, 119, TFT_WHITE);
  tft.drawCircle(120, 120, 118, TFT_WHITE);
  
  // Заголовок
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(40, 50);
  tft.println("ESP32-C3 Mini");
  
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setCursor(60, 80);
  tft.println("GC9A01");
  
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.setTextSize(1);
  tft.setCursor(30, 110);
  tft.println("240 x 240 Round Display");
  
  delay(3000);
}

void loop() 
{

  // Демонстрация возможностей
  demoCircles();
  delay(2000);
  
  demoText();
  delay(2000);
  
  demoGraphics();
  delay(2000);
  
  demoAnimation();
  delay(2000);
}

void demoCircles() {
  tft.fillScreen(TFT_BLACK);
  
  // Концентрические круги
  for(int r = 10; r < 120; r += 15) {
    uint16_t color = tft.color565(random(255), random(255), random(255));
    tft.drawCircle(120, 120, r, color);
  }
  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  tft.setCursor(80, 10);
  tft.println("Circles Demo");
}

void demoText() {
  tft.fillScreen(TFT_NAVY);
  
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 30);
  tft.println("Text Demo");
  
  tft.setTextSize(1);
  tft.setCursor(10, 70);
  tft.setTextColor(TFT_RED);
  tft.println("Red Text Example");
  
  tft.setCursor(10, 90);
  tft.setTextColor(TFT_GREEN);
  tft.println("Green Text Example");
  
  tft.setCursor(10, 110);
  tft.setTextColor(TFT_BLUE);
  tft.println("Blue Text Example");
  
  tft.setCursor(10, 130);
  tft.setTextColor(TFT_YELLOW);
  tft.println("Yellow Text Example");
  
  tft.setCursor(10, 150);
  tft.setTextColor(TFT_CYAN);
  tft.println("Cyan Text Example");
  
  // Вращающийся текст
  tft.setCursor(60, 180);
  tft.setTextColor(TFT_MAGENTA);
  tft.println("Rotating...");
}

void demoGraphics() {
  tft.fillScreen(TFT_BLACK);
  
  // Линии
  for(int i = 0; i < 240; i += 10) {
    tft.drawLine(0, i, i, 0, TFT_RED);
    tft.drawLine(239, i, 239-i, 239, TFT_BLUE);
  }
  
  // Прямоугольники
  tft.drawRect(50, 50, 60, 60, TFT_GREEN);
  tft.fillRect(55, 55, 50, 50, TFT_YELLOW);
  
  // Треугольники
  tft.drawTriangle(180, 50, 160, 90, 200, 90, TFT_CYAN);
  tft.fillTriangle(120, 180, 100, 220, 140, 220, TFT_MAGENTA);
}

void demoAnimation() {
  tft.fillScreen(TFT_BLACK);
  
  // Анимированный круг
  for(int r = 5; r < 100; r += 5) {
    tft.drawCircle(120, 120, r, TFT_WHITE);
    delay(50);
  }
  
  // Спираль
  for(float angle = 0; angle < 4*PI; angle += 0.1) {
    int x = 120 + (int)(80 * cos(angle));
    int y = 120 + (int)(80 * sin(angle));
    tft.drawPixel(x, y, TFT_GREEN);
  }
  
  delay(1000);
 
}