/**
 * @file main.ino
 * @author Muller Kevin (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>

#include "ui.h"
#include "config.h"

// Screen
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST, TFT_MISO);
// Touch
Adafruit_FT6206 ctp = Adafruit_FT6206();

void UI_TempHum(int tmp1=0,int hum1=0,int tmp2=0,int hum2=0) {
  tft.fillScreen(BLACK);
  // Title
  DTP(2,WHITE,90,10,"Daten");
  tft.drawLine(0,30,240,30,WHITE);
  // Block 1
  DTP(2,WHITE,80,40,"Drinnen");
  tft.fillRoundRect(20,70,60,60,35,RED);
  tft.fillRoundRect(25,75,50,50,35,BLACK);
  DTP(2,RED,33,92,String(tmp1)+"C");
  tft.fillRoundRect(150,70,60,60,35,BLUE);
  tft.fillRoundRect(155,75,50,50,35,BLACK);
  DTP(2,BLUE,163,92,String(hum1)+"%");
  tft.drawLine(20,150,200,150,WHITE);
  // Block 2
  DTP(2,WHITE,71,160,"Draussen");
  tft.fillRoundRect(20,200,60,60,35,RED);
  tft.fillRoundRect(25,205,50,50,35,BLACK);
  DTP(2,RED,32,222,String(tmp2)+"C");
  tft.fillRoundRect(150,200,60,60,35,BLUE);
  tft.fillRoundRect(155,205,50,50,35,BLACK);
  DTP(2,BLUE,162,222,String(hum2)+"%");
  tft.drawLine(0,280,240,280,WHITE);
  // Bottom
  DTP(2,WHITE,0,290,"7.7V");
  // 
  tft.drawLine(110,290,110,320,WHITE);
  /**
   * @brief Home_Button
   * @param y[289-320]
   * @param x[141-221]
   */
  tft.fillRoundRect(140,290,80,30,35,WHITE);
  DTP(2,BLACK,160,297,"Home");
}

void UI_Home(){
  tft.fillScreen(BLACK);
  // Title
  DTP(1,LOGO_BLUE,100,1,"Lycee Prive Emile Metz");
  //
  DTP(2,WHITE,90,20,"Home");
  //
  tft.drawLine(0,40,240,40,WHITE);
  /**
   * @brief box1
   * @param y[49-70] 
   * @param x[20-221]
   */
  tft.fillRoundRect(20,50,200,20,50,HOME_BOX);
  DTP(1,WHITE,30,60,"Temperature / Luftfeuchtigkeit");
  // box2
  tft.fillRoundRect(20,80,200,20,50,HOME_BOX);
  DTP(1,WHITE,60,90,"Bewasserungs System");
  // box3
  tft.fillRoundRect(20,110,200,20,50,HOME_BOX);
  DTP(1,WHITE,70,120,"Lufter + LEDs");
  // box4
  tft.fillRoundRect(20,140,200,20,50,HOME_BOX);
  DTP(1,WHITE,60,150,"Akku / Energie Status");
  // box5
  tft.fillRoundRect(20,170,200,20,50,HOME_BOX);
  DTP(1,WHITE,80,180,"Einstellungen");
  // IMG
  // Bottom
  
  tft.drawLine(0,300,240,300,WHITE);
  DTP(2,WHITE,0,305,"7.7V");
  DTP(2,WHITE,170,305,"Datum");
}
/**
  * @name Display Text Print = DTP
*/
void DTP(int16_t size,int16_t color,int16_t x,int16_t y,String text){
  tft.setTextSize(size);
  tft.setTextColor(color);
  tft.setCursor(x,y);
  tft.print(text);
}

void setup(void) {
  Serial.begin(115200);
  Serial.println(F("Loading"));

  tft.begin();
  ctp.begin(40);

  //tft.fillScreen(ILI9341_BLACK);

  int u1=20,u2=35,u3=20,u4=25;
  //UI_TempHum(u1,u2,u3,u4);
  //UI_Home();
  Serial.println("Completed");
}

void Touch(void){

}

void loop(void) {
  Touch();
  if (!ctp.touched()) {
    return;
  }

  TS_Point p = ctp.getPoint();

  p.x = map(p.x,0,240,240,0);
  p.y = map(p.y,0,320,320,0);

  Serial.print("X"); Serial.print(p.x); Serial.print("Y"); Serial.println(p.y);

  switch (int menu){
    case home:
        Serial.println("Start Loading UI_Home");
        UI_Home();
        Serial.println("Finished Loading UI_Home");
        if(((p.y<70)and(p.y>49))and((p.x<221)and(p.x>20))){
          menu = temphum;
        }
      break;
    case temphum:
        Serial.println("Start Loading UI_TempHum");
        UI_TempHum(20,40,20,50);
        Serial.println("Finished Loading UI_TempHum");
    default:
        menu = home;
        Serial.println(menu);
      break;
  }
  Serial.println(menu);
  /*
  if(((p.y<320)and(p.y>289))and((p.x<221)and(p.x>141))){
    Serial.println("Start Loading UI_Home");
    UI_Home();
    Serial.println("Finished Loading UI_Home");
  }
  if(((p.y<70)and(p.y>49))and((p.x<221)and(p.x>20))){
    Serial.println("Start Loading UI_TempHum");
    UI_TempHum(20,40,20,50);
    Serial.println("Finished Loading UI_TempHum");
  }
  */

  tft.drawCircle(p.x,p.y,2,WHITE);

}