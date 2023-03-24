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
#include <TFT_eWidget.h>

#include "config.h"
#include "ui.h"

TFT_eSPI tft = TFT_eSPI();

/**
 * @brief DTP = Display Text Print
 * 
 * @param size 
 * @param color 
 * @param x 
 * @param y 
 * @param text 
 */
void DTP(int16_t size,int16_t color,int16_t x,int16_t y,String text){
  tft.setTextSize(size);
  tft.setTextColor(color);
  tft.setCursor(x,y);
  tft.print(text);
}

/**
 * @brief SPT = Standard Page Template
 * 
 * @param text
 */
void SPT(String text){
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  DTP(2,WHITE,(tft.width()-tft.textWidth(text))/2,10,text);
  tft.drawLine(0,30,240,30,WHITE);
  tft.drawLine(0,280,240,280,WHITE);
  tft.drawLine(100,290,100,310,WHITE);
  DTP(2,WHITE,10,293,"7.7V");
  tft.fillRoundRect(150,285,80,30,Box_Radius,BOX_COLOR);
  DTP(2,BLACK,168,293,"Home");
}


void setup(void){
  Serial.begin(115200);
  Serial.println("Terminal Started");

  tft.begin();
  tft.setRotation(0);

  //uint16_t calData[5] = { 438, 3390, 368, 3317, 7 };
  //tft.setTouch(calData);
  //touch_calibrate();

  tft.fillScreen(BLACK);
  
  SPT("Lufter / LEDs");
  DTP(2,BLUE,10,40,"Lufter");
  DTP(1,WHITE,10,60,"1");
  DTP(1,WHITE,120,60,"2");

  DTP(2,BLUE,10,160,"LED");
  DTP(2,WHITE,20,190,"Dimmung");
  DTP(2,WHITE,20,230,"Status");
} 

void loop(void){

}


