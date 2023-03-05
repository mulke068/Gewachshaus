/**
 * @file main.cpp
 * @author Muller Kevin (www.kevbchef.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
**/
#include <Arduino.h>
#include <SPI.h>
#include <FS.h>
#include <TFT_eSPI.h>

#include "include/test_config.h"
#include "include/test_ui.h"
#include "include/test_icons.h"


// =============================================================================================================================
// ================================================= Display START =============================================================
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

int page=0;

/**
 * @brief DTP = Display Text Print
 * 
 * @param size Size from Text
 * @param color Color from Text
 * @param x Cords
 * @param y Cords
 * @param text Displayed Text
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
  // Bottom
  tft.drawLine(0,280,240,280,WHITE);
  tft.drawLine(100,290,100,310,WHITE);
  DTP(2,WHITE,10,293,"7.7V");
  tft.fillRoundRect(150,285,Box_Width,Box_Height,Box_Radius,BOX_COLOR);
  DTP(2,BLACK,168,293,"Home");
}

void touch_calibrate()
{
  tft.fillScreen(WHITE);
  delay(250);

  uint16_t calData[5];
  uint8_t calDataOK = 0;
  
  String calibText = "Calibrate Touch";
  // Calibrate
  tft.fillScreen(BLACK);
  //tft.setCursor(20, 0);
  
  tft.setTextFont(2);
  tft.setTextSize(2);
  tft.setCursor((tft.width()-tft.textWidth(calibText))/2,tft.height()/2);
  tft.setTextColor(WHITE, BLACK);
  tft.print(calibText);

  tft.setTextFont(1);
  tft.println();
  tft.calibrateTouch(calData, RED, BLACK, 30);

  DTP(1,GREEN,0,0,"Calibration complete!");
  delay(1000);
}

/**
 * @brief DrawCircleVarTemplate = Template for Draw a Circle with a Value
 * 
 * @param x 
 * @param y 
 * @param var 
 * @param end 
 * @param circleColor 
 * @param bgColor 
 * @param varColor 
 */
void DrawCircleVarTemplate(int16_t x, int16_t y, int16_t var,String end,int16_t circleColor,int16_t bgColor, int16_t varColor){
  tft.fillCircle(x,y,32,circleColor);
  tft.fillCircle(x,y,24,bgColor);
  DTP(2,varColor,x-16,y-8,String(var)+end);
}

/**
 * @brief Page Einstellungen
 * 
 * @param brightness 
 * @param sound 
 */
void UI_Settings(int16_t brightness,int16_t sound){
  page = 5;
  tft.fillScreen(BLACK);
  SPT("Einstellungen");
  DTP(2,WHITE,60,40,"Helligkeit");
  //
  DTP(2,WHITE,(tft.width()-tft.textWidth(String(brightness)+"%"))/2,80,String(brightness)+"%");
  //
  tft.drawLine(40,130,180,130,WHITE);
  DTP(2,WHITE,90,140,"Ton");
  //
  DTP(2,WHITE,(tft.width()-tft.textWidth(String(sound)+"%"))/2,175,String(sound)+"%");
  //
  tft.drawLine(20,220,220,220,WHITE);
  DTP(2,WHITE,20,240,"Touch Calibrieren");
}

/**
 * @brief Page EnergieStatus
 * 
 * @param sp1 solar_1
 * @param sp2 solar_2
 * @param akku 
 * @param strom 
 */
void UI_EnergieStatus(int16_t sp1,int16_t sp2,int16_t akku,int16_t strom){
  page = 3;
  tft.fillScreen(BLACK);
  SPT("Energie Status");
  String text[4] = {"Solar Panel 1:","Solar Panel 2:","Akku Kap.:","Strom Verb.:"};
  String data[4] = {String(sp1)+"V",String(sp2)+"V",String(akku)+"%",String(strom)+"V"};
  for (int i=0,y=50; i < 4; i++,y+=30)
  {
    DTP(2,WHITE,0,y,text[i]);
    DTP(2,WHITE,180,y,data[i]);
  }
}

/**
 * @brief Page Lüfter und LEDs
 * 
 * @param getLufter1 
 * @param setLufter1 
 * @param getLufter2 
 * @param setLufter2 
 * @param getLed 
 * @param setLed 
 */
void UI_LufterLeds(int16_t getLufter1,bool setLufter1,int16_t getLufter2,bool setLufter2,int16_t getLed,bool setLed){
  page = 4;
  tft.fillScreen(BLACK);
  SPT("Lufter / LEDs");
  DTP(2,BLUE,10,40,"Lufter");
  DTP(1,WHITE,10,60,"1");
  DTP(1,WHITE,120,60,"2");
  /**
   * @note Search for Slider
   * @details var -> Slider ≠ Text 
  */
  DTP(2,WHITE,45,70,String(getLufter1)+"%");
  DTP(2,WHITE,160,70,String(getLufter2)+"%");
  // Buttons
  if(setLufter1){tft.fillRoundRect(20,110,Box_Width,Box_Height,Box_Radius,GREEN);} 
  else {tft.fillRoundRect(20,110,Box_Width,Box_Height,Box_Radius,RED);};
  if (setLufter2){tft.fillRoundRect(140,110,Box_Width,Box_Height,Box_Radius,GREEN);}
  else {tft.fillRoundRect(140,110,Box_Width,Box_Height,Box_Radius,RED);};
  // ---
  DTP(2,BLUE,10,160,"LED");
  DTP(2,WHITE,20,190,"Dimmung");
  DTP(2,WHITE,20,230,"Status");
  /**
   * @note Search for Slider
   * @details var -> Slider ≠ Text 
  */
  DTP(2,WHITE,150,190,String(getLed)+"%");
  // Button
  if(setLed){tft.fillRoundRect(130,230,Box_Width,Box_Height,Box_Radius,GREEN);}
  else {tft.fillRoundRect(130,230,Box_Width,Box_Height,Box_Radius,RED);};
}

/**
 * @brief Page Wasser System
 * 
 * @param sensor_1 
 * @param sensor_2 
 * @param pumpe 
 */
void UI_WaterSys(int16_t sensor_1,int16_t sensor_2,bool pumpe){
  page = 2;
  tft.fillScreen(BLACK);
  SPT("Bewasserung");
  //
  DTP(2,BLUE,20,40,"Bodenfeuchtigkeit");
  DTP(2,WHITE,0,70,"Sensor 1");
  DrawCircleVarTemplate(40,120,sensor_1,"%",BLUE,BLACK,WHITE);
  DTP(2,WHITE,140,70,"Sensor 2");
  DrawCircleVarTemplate(190,120,sensor_2,"%",BLUE,BLACK,WHITE);
  tft.drawLine(20,160,220,160,WHITE);
  //
  DTP(2,WHITE,20,190,"Pumpe");
  DTP(2,WHITE,20,230,"Status");
  if(pumpe){
    DTP(2,WHITE,140,190,"-> Aus");
    DTP(2,WHITE,140,230,"An");
  }else {
    DTP(2,WHITE,140,190,"-> An");
    DTP(2,WHITE,140,230,"Aus");
  }
}

/**
 * @brief Page Temperatur und Feuchtigkeit
 * 
 * @param tmp1 
 * @param hum1 
 * @param tmp2 
 * @param hum2 
 */
void UI_TempHum(int16_t tmp1=0,int16_t hum1=0,int16_t tmp2=0,int16_t hum2=0) {
  page = 1;
  tft.fillScreen(BLACK);
  // Title
  SPT("Daten");
  // Block 1
  DTP(2,WHITE,80,40,"Drinnen");
  DrawCircleVarTemplate(50,100,tmp1,"C",RED,BLACK,RED);
  DrawCircleVarTemplate(180,100,hum1,"%",BLUE,BLACK,BLUE);
  tft.drawLine(20,150,200,150,WHITE);
  // Block 2
  DTP(2,WHITE,71,160,"Draussen");
  DrawCircleVarTemplate(50,220,tmp2,"C",RED,BLACK,RED);
  DrawCircleVarTemplate(180,220,hum2,"%",BLUE,BLACK,BLUE);
}

/**
 * @brief Main Page
 * 
 * @param strom
 */
void UI_Home(void){
  page = 0;
  sprite.fillScreen(BLACK);
  DTP(1,LOGO_COLOR,100,1,"Lycee Prive Emile Metz");
  DTP(3,WHITE,85,20,"Home");
  sprite.drawLine(0,45,240,45,WHITE);
  // ----
  sprite.drawBitmap(0,0,settings,iconSettingWidth,iconSettingHeight,WHITE);
  sprite.drawBitmap(30,60,temperature_humidity,iconsHomeWidth,iconsHomeHeight,WHITE);
  sprite.drawBitmap(140,60,bewasserungs_system,iconsHomeWidth,iconsHomeHeight,WHITE);
  sprite.drawLine(20,128,220,128,WHITE);
  sprite.drawLine(120,60,120,190,WHITE);  
  sprite.drawBitmap(30,130,led_lufter,iconsHomeWidth,iconsHomeHeight,WHITE);
  sprite.drawBitmap(140,135,akku_energie,iconsHomeWidth,iconsHomeHeight,WHITE);
  // IMG
  sprite.drawBitmap((tft.width()-logoWidth)/2,190,logo,logoWidth,logoHeight,WHITE);
  // Bottom
  sprite.drawLine(0,300,240,300,WHITE);
  DTP(2,WHITE,0,305,"7.7V");
  DTP(2,WHITE,170,305,"Datum");
}

// ================================================= Display END ================================================================
int var1;
float var2;
bool var3;
int menuIndex = 0;
void fetch_data(){
  var1 = random(0,100);
  var2 = random(1.25 , 50.25);
  var3 = (var1 >= 50 ? true : false);
}

void menu(int16_t ui){

  Serial.println("Loading ... ");

  switch (ui)
  {
  case 1:
    UI_TempHum(var1,var2,var1,var2);
    break;
  case 2:
    UI_WaterSys(var1,var1,var3);
    break;
  case 3:
    UI_LufterLeds(var1,var3,var1,var3,var1,var3);
    break; 
  case 4:
    UI_EnergieStatus(var2,var1,var1,var2);
    break;
  case 5:
    UI_Settings(var1,var1);
    break;
  default:
    UI_Home();
    break;
  }
}

void setup(void){
  Serial.begin(115200);
  Serial.println("Terminal Started");
  Serial.println("Start   : WiFi    Configuration");
  Serial.println("Ended   : WiFi    Configuration");
  Serial.println("Start   : Display Configuration");
  tft.begin();
  tft.setRotation(0);

  sprite.createSprite(240,320);
  //uint16_t calData[5] = { 438, 3390, 368, 3317, 7 };
  //tft.setTouch(calData);
  Serial.println("Ended   : Display Configuration");
  Serial.println("Start   : Display Calibration");
  //touch_calibrate();
  tft.fillScreen(BLACK);
  Serial1.println("Ended  : Display Calibration");
  UI_Home();

}

void loop(void){
  fetch_data();
  menu(menuIndex);

  uint16_t touch_x=0,touch_y=0;

  bool pressed = tft.getTouch(&touch_x,&touch_y);

  if(pressed){

    Serial.println("x"+String(touch_x)+"y"+String(touch_y));
    tft.fillCircle(touch_x,touch_y,2,RED);
    // Home btn
    // x 150 - 230 | y 284 - 314
    // Setings calibrate btn
    // x 20 - 230 | y 240 - 230
    if(page==0){
      // Settings x=0 - 40 y=0 - 40
      // Temp_Humidity x= 30 - 80 y= 60 - 130
      // water_system x= 140 - 210 y = 60 - 130
      // led_lüfter x= 30 - 100 y= 130 - 200
      // akku_energy x= 140 - 210 y = 135 - 205
      if(((touch_x<40)and(touch_x>0))and((touch_y<40)and(touch_y>0))){Serial.println("Start   : UI_Settings");menuIndex = 5;};
      if(((touch_x<80)and(touch_x>30))and((touch_y<130)and(touch_y>60))){Serial.println("Start   : UI_TempHum");menuIndex = 1;};
      if(((touch_x<210)and(touch_x>140))and((touch_y<130)and(touch_y>60))){Serial.println("Start   : UI_WaterSys");menuIndex = 2;};
      if(((touch_x<100)and(touch_x>30))and((touch_y<200)and(touch_y>130))){Serial.println("Start   : UI_LufterLeds");menuIndex = 3;};
      if(((touch_x<210)and(touch_x>140))and((touch_y<205)and(touch_y>135))){Serial.println("Start   : UI_EnergieStatus");menuIndex = 4;};
    }else if ((page==1)or(page==2)or(page==3)or(page==4)){
      if(((touch_x<230)and(touch_x>150))and((touch_y<314)and(touch_y>284))){
        Serial.println("Start   : UI_Home");
        menuIndex = 0;
      }
    }else if (page==5){
      if(((touch_x<230)and(touch_x>150))and((touch_y<314)and(touch_y>284))){
        Serial.println("Start   : UI_Home");
        menuIndex = 0;
      }
      if(((touch_x<240)and(touch_x>0))and((touch_y<272)and(touch_y>220))){
        Serial.println("Start   : Display Calibration");
        touch_calibrate();
        Serial1.println("Ended  : Display Calibration");
        Serial.println("Start   : UI_Home");
        menuIndex = 0;
      }
    }else{
      return;
    }
  }
  sprite.pushSprite(0,0);
  delay(100);
}