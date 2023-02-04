#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>

//#define TFT_SCK 18
#define TFT_SCK 18
#define TFT_MOSI 23
#define TFT_MISO 19
#define TFT_CS 15
#define TFT_DC 4
#define TFT_RST 2

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC,TFT_MOSI,TFT_SCK,TFT_RST,TFT_MISO);

Adafruit_FT6206 ctp = Adafruit_FT6206();

void setup(void) {
  Serial.begin(115200);
  Serial.println(F("Started"));

  tft.begin();
  ctp.begin(40);

  //tft.fillScreen(ILI9341_BLACK);
}

void loop() {
  if(!ctp.touched()){
    return;
  }

  TS_Point p = ctp.getPoint();

  Serial.print("X");Serial.print(p.x);Serial.print("Y");Serial.println(p.y);
  
  tft.fillCircle(p.x,p.y,2, ILI9341_RED);
}