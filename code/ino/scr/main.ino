#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>

#include "ui.h"
#include "config.h"

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST, TFT_MISO);

Adafruit_FT6206 ctp = Adafruit_FT6206();


void UI_TempHum(int tmp1=0,int hum1=0,int tmp2=0,int hum2=0) {
  tft.fillScreen(ILI9341_BLACK);
  // Oben
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE); 
  tft.setCursor(90,10);
  tft.print("Daten");
  tft.drawLine(0,30,240,30,ILI9341_WHITE);
  // Block 1
  tft.setTextColor(ILI9341_WHITE); 
  tft.setCursor(90,40);
  tft.print("Innen");
  tft.fillRoundRect(20,70,60,60,35,RED);
  tft.fillRoundRect(25,75,50,50,35,ILI9341_BLACK);
  tft.setTextColor(RED); 
  tft.setCursor(33,92);
  tft.print(String(tmp1)+"C");
  tft.fillRoundRect(150,70,60,60,35,BLUE);
  tft.fillRoundRect(155,75,50,50,35,ILI9341_BLACK);
  tft.setTextColor(BLUE);
  tft.setCursor(163,92);
  tft.print(String(hum1)+"%");
  tft.drawLine(20,150,200,150,ILI9341_WHITE);
  // Block 2
  tft.setCursor(71,160);
  tft.setTextColor(ILI9341_WHITE); 
  tft.print("Draussen");
  tft.fillRoundRect(20,200,60,60,35,RED);
  tft.fillRoundRect(25,205,50,50,35,ILI9341_BLACK);
  tft.setTextColor(RED);
  tft.setCursor(32,222);
  tft.print(String(tmp2)+"C");
  tft.fillRoundRect(150,200,60,60,35,BLUE);
  tft.fillRoundRect(155,205,50,50,35,ILI9341_BLACK);
  tft.setTextColor(BLUE);
  tft.setCursor(162,222);
  tft.print(String(hum2)+"%");
  tft.drawLine(0,280,240,280,ILI9341_WHITE);
  // Unten
}

void setup(void) {
  Serial.begin(115200);
  Serial.println(F("Loading"));

  tft.begin();
  ctp.begin(40);

  //tft.fillScreen(ILI9341_BLACK);

  int u1=20,u2=35,u3=20,u4=25;
  UI_TempHum(u1,u2,u3,u4);
  Serial.println("Compleded");
}

void loop() {
  if (!ctp.touched()) {
    return;
  }

  TS_Point p = ctp.getPoint();

  p.x = map(p.x,0,240,240,0);
  p.y = map(p.y,0,320,320,0);

  Serial.print("X"); Serial.print(p.x); Serial.print("Y"); Serial.println(p.y);

  if((p.y<130)and(p.y>71)){
    if((p.x<80)and(p.x>20)){
      Serial.println("Box1");
      UI_TempHum(p.x,p.y,p.x+10,p.y+10);
    }
  }
  tft.drawCircle(p.x,p.y,2,ILI9341_WHITE);

}