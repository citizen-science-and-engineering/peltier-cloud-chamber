#include <Arduino.h>
#include <max6675.h>
#include "main.h"

MAX6675 thermocouple1(SPI0_SCK, probe1_CS, SPI0_MISO);
MAX6675 thermocouple2(SPI0_SCK, probe2_CS, SPI0_MISO);
MAX6675 thermocouple3(SPI0_SCK, probe3_CS, SPI0_MISO);
MAX6675 thermocouple4(SPI0_SCK, probe4_CS, SPI0_MISO);


void setup()
{
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,HIGH);

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
  delay(50);
  float p2 = thermocouple2.readCelsius();
  delay(50);
  float p3 = thermocouple3.readCelsius();
  delay(50);
  float p4 = thermocouple4.readCelsius();
  delay(50);

  display.clearDisplay();

  display.setCursor(0, 0); // Start at top-left corner
  display.print(F("ThermProbe 1: "));
  display.println(p1);
  display.print(F("ThermProbe 2: "));
  display.println(p2);
  display.print(F("ThermProbe 3: "));
  display.println(p3);
  display.print(F("ThermProbe 4: "));
  display.println(p4);

  display.display();

  char s[250];
  sprintf(s, "{\"DataSets\":[{\"Tag\":\"ThermProbe1\",\"Value\":%.2f},{\"Tag\":\"ThermProbe2\",\"Value\":%.2f},{\"Tag\":\"ThermProbe3\",\"Value\":%.2f},{\"Tag\":\"ThermProbe4\",\"Value\":%.2f}]}\r\n", p1, p2, p3, p4);
  Serial.write(s);

  delay(1000-150);
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

