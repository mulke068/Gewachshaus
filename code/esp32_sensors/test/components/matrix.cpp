#include <Arduino.h>
#include <config.h>

#include <SPI.h>
#include <MD_MAX72xx.h>
// #include <MD_Parola.h>

// LED Matrix help
// https://lastminuteengineers.com/max7219-dot-matrix-arduino-tutorial/
// VCC  ->  5V
// GND  ->  GND
// DIN  ->  Pin 23
// CS   ->  Pin 5
// CLK  ->  Pin 18

#define PRINT(s, x) { Serial.print(F(s)); Serial.print(x); }
#define PRINTS(x) Serial.print(F(x))
#define PRINTD(x) Serial.println(x, DEC)
#define PRINT(s, x)
#define PRINTS(x)
#define PRINTD(x)

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

#define MAX_DEVICES 4
#define DIN_PIN     2
#define CS_PIN      4
#define CLK_PIN     14

// MD_Parola matrix = MD_Parola(HARDWARE_TYPE, DIN_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
MD_MAX72XX matrix = MD_MAX72XX(HARDWARE_TYPE, DIN_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  matrix.begin();
  // matrix.setIntensity(0);
  // matrix.displayClear();
  // matrix.displayScroll("Hello World!", PA_CENTER, PA_SCROLL_LEFT, 100);
  matrix.control(MD_MAX72XX::INTENSITY, 2);
}

void scrollText(const char *p)
{
  uint8_t charWidth;
  uint8_t cBuf[8];  
 
  PRINTS("\nScrolling text");
  matrix.clear();
 
  while (*p != '\0')
  {
    charWidth = matrix.getChar(*p++, sizeof(cBuf) / sizeof(cBuf[0]), cBuf);
 
    for (uint8_t i=0; i<=charWidth; i++)  // allow space between characters
    {
      matrix.transform(MD_MAX72XX::TSL);
      if (i < charWidth)
        matrix.setColumn(0, cBuf[i]);
      delay(50);
    }
  }
}

void loop() {
  // if(matrix.displayAnimate()) {
    // matrix.displayReset();
  // }
  // delay(1000);
  scrollText("Test");
}