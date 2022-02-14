#include <Arduino.h>
#include <WiFi.h>
#include <max6675.h>
#include "main.h"

MAX6675 thermocouple1(probe1_CLK, probe1_CS, probe1_DO);
MAX6675 thermocouple2(probe2_CLK, probe2_CS, probe2_DO);

void setup()
{
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    for (;;)
    {
      delay(2000);
    } 
  }
  display.clearDisplay();

  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);             // Start at top-left corner
  display.cp437(true);                 // Use full 256 char 'Code Page 437' font

  display.println(F("Starting..."));
  display.display();
}

void loop()
{

  float p1 = thermocouple1.readCelsius();
  delay(100);
  float p2 = thermocouple2.readCelsius();
  delay(100);

  display.clearDisplay();

  display.setCursor(0, 0); // Start at top-left corner
  display.println(F("Probe 1"));
  display.println(p1);
  display.println(F("Probe 2"));
  display.println(p2);

  display.display();

  char s[120];
  sprintf(s, "{\"DataSets\":[{\"Tag\":\"probe1\",\"Value\":%.2f},{\"Tag\":\"probe2\",\"Value\":%.2f}]}\r\n", p1, p2);
  Serial.write(s);

  delay(1000);
}

void Display(String line1)
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(line1);
  display.display();
}
void Display(String line1, String line2)
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(line1);
  display.println(line2);
  display.display();
}
void Display(String line1, String line2, String line3)
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(line1);
  display.println(line2);
  display.println(line3);
  display.display();
}
void Display(String line1, String line2, String line3, String line4)
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(line1);
  display.println(line2);
  display.println(line3);
  display.println(line4);
  display.display();
}

