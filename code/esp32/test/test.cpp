/**
 * @file main.ino
 * @author Muller Kevin (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
**/
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

#include "config.h"
#include "ui.h"

TFT_eSPI tft = TFT_eSPI();

void touch_calibrate()
{
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  // Calibrate
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(20, 0);
  tft.setTextFont(2);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  tft.setTextFont(1);
  tft.println();
  tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.println("Calibration complete!");

  delay(3000);
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
  tft.fillRoundRect(140,290,80,30,Box_Radius,WHITE);
  DTP(2,BLACK,160,297,"Home");
}

void UI_Home(){
  tft.fillScreen(BLACK);
  // Title
  DTP(1,LOGO_BLUE,100,1,"Lycee Prive Emile Metz");
  //
  DTP(2,WHITE,95,20,"Home");
  //
  tft.drawLine(0,40,240,40,WHITE);
  // 
  /**
   * @brief box1
   * @param y[49-70] 
   * @param x[20-221]
  */
  String box_text[5] = {
    "Temperature / Luftfeuchtigkeit",
    "Bewasserungs System",
    "Lufter + LEDs",
    "Akku / Energie Status",
    "Einstellungen"};
  int cursor_x[5] = {30,60,80,60,80};
  for(int i=0,rect_y=54,cursor_y=60;i<5;i++){
    tft.fillRoundRect(20,rect_y,200,20,Box_Radius,HOME_BOX);
    DTP(1,WHITE,cursor_x[i],cursor_y,box_text[i]);
    rect_y=rect_y+30;
    cursor_y=cursor_y+30;
  }
  // IMG
  // Bottom
  
  tft.drawLine(0,300,240,300,WHITE);
  DTP(2,WHITE,0,305,"7.7V");
  DTP(2,WHITE,170,305,"Datum");
}

void setup(void){
  Serial.begin(9600);
  Serial.println("Terminal Started");

  tft.begin();
  tft.setRotation(0);

  //uint16_t calData[5] = { 438, 3390, 368, 3317, 7 };
  //tft.setTouch(calData);
  //touch_calibrate();

  tft.fillScreen(BLACK);
  UI_Home();
}

void loop(void){
  uint16_t x=0,y=0;

  bool pressed = tft.getTouch(&x,&y);

  if(pressed){
    tft.fillCircle(x,y,2,WHITE);
  }
}


