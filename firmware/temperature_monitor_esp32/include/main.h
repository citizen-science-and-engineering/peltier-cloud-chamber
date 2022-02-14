
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int probe1_DO = 19;
int probe1_CLK = 5;
int probe1_CS = 14;

int probe2_DO = 19;
int probe2_CLK = 5;
int probe2_CS = 9;


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void Display(String line1);
void Display(String line1, String line2);
void Display(String line1, String line2, String line3);
void Display(String line1, String line2, String line3, String line4);

