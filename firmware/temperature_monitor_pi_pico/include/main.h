#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SPI0_MISO       16
#define SPI0_SCK        18

#define probe1_DO SPI0_MISO
#define probe1_CLK SPI0_SCK
#define probe1_CS       20

#define probe2_DO SPI0_MISO
#define probe2_CLK SPI0_SCK
#define probe2_CS       21

#define probe3_DO SPI0_MISO
#define probe3_CLK SPI0_SCK
#define probe3_CS       22


#define SCREEN_WIDTH    128 // OLED display width, in pixels
#define SCREEN_HEIGHT    32 // OLED display height, in pixels
#define OLED_RESET       -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void Display(String line1);
void Display(String line1, String line2);
void Display(String line1, String line2, String line3);
void Display(String line1, String line2, String line3, String line4);

