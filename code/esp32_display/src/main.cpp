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

// WiFi Extension
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "config.h"
#include "json.h"
#include "ui.h"
#include "icons.h"

// ================================================= HTTP Start ================================================================

void initWiFi(){
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.config(ipv4, gateway, subnet, DNS1, DNS2);
  WiFi.setHostname(hostname.c_str());
  WiFi.begin(ssid, password)
  int waitWifi = 0;
  Serial.println("--------------------------------");
  Serial.print("Connecting to WiFi ");
  while ((WiFi.status() != WL_CONNECTED)){
    if(waitWifi > 10) {
      Serial.println(" ");
      Serial.println("Error WiFi not connected");
      Serial.println("--------------------------------");
      return;
    } else {
      Serial.print(".");
      waitWifi++;
      sleep(min_delay);
    }
  }
  Serial.println(" ");
  Serial.print("Host IP : "); Serial.println(WiFi.localIP());
  Serial.print("SSID    : "); Serial.println(WiFi.SSID());
  Serial.print("Hostname: "); Serial.println(WiFi.getHostname());
  Serial.print("Subnet  : "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway : "); Serial.println(WiFi.gatewayIP());
  Serial.print("DNS     : "); Serial.println(WiFi.dnsIP());
  Serial.println("--------------------------------");
}

String httpGETRequest(const char* url,bool print){
  HTTPClient http;
  http.begin(url);
  int http_response = http.GET();

  String payload = "{}";

  if(print){
    Serial.println("----------------------------------------");
    if(http_response > 0){
      Serial.print("HTTP GET Response Code :");
      Serial.println(http_response);
      payload = http.getString();
      Serial.println("Data :");
      Serial.println(payload);
    }else{
      Serial.print("HTTP GET Error Code :");
      Serial.println(http_response);
    }
    Serial.println("----------------------------------------");
  }else{
    if (http_response != 200){
      Serial.println("Error Server not Online");
      Serial.print("Error Code : ");
      Serial.println(http_response);
    }else{payload = http.getString();}
    
  }


  http.end();
  return payload;
}

void httpPUTRequest(const char* url,char* req,bool print){
  HTTPClient http;
  http.begin(url);
  http.addHeader("Content-Type", "application/json");

  String httpResponseData = req;
  int http_response = http.PUT(httpResponseData);

  if (print){
    Serial.println("----------------------------------------");
    if(http_response > 0 ){
      Serial.print("HTTP PUT Response Code : ");
      Serial.println(http_response);
    }else{
      Serial.print("HTTP PUT Error Code :");
      Serial.println(http_response);
    }
    Serial.println("----------------------------------------");
  }else{
    if (http_response != 200){
      Serial.println("Error Server not Online");
      Serial.print("Error Code : ");
      Serial.println(http_response);
    }
  }
  

  http.end();
}

void get_data(bool print=true){
  if ((WiFi.status() == WL_CONNECTED)){
    StaticJsonDocument<0> filter;
    filter.set(true);

    StaticJsonDocument<1024> res;
    String json = httpGETRequest(api_url,print);
    DeserializationError error = deserializeJson(res, json, DeserializationOption::Filter(filter));

    if(error){
      Serial.print("deserialization error :");
      Serial.println(error.c_str());
    }

    // ----------------------------------------------------------------
    JsonArray root_main = res[0];

    JsonObject root_0 = root_main[0];
    root_0_id = root_0["id"];

    JsonObject root_0_devices = root_0["devices"];
    root_0_devices_esp32_1 = root_0_devices["esp32"]["connected"][0];
    root_0_devices_esp32_2 = root_0_devices["esp32"]["connected"][1];
    root_0_devices_raspberrypi = root_0_devices["raspberrypi"]["connected"];
    
    JsonObject root_1 = root_main[1];
    root_1_id = root_1["id"];

    JsonObject root_1_tempHum = root_1["tempHum"];
    root_1_tempHum_temperature_1 = root_1_tempHum["temperature_1"];
    root_1_tempHum_humidity_1 = root_1_tempHum["humidity_1"];
    root_1_tempHum_temperature_2 = root_1_tempHum["temperature_2"];
    root_1_tempHum_humidity_2 = root_1_tempHum["humidity_2"];

    JsonObject root_1_waterSystem = root_1["waterSystem"];
    root_1_waterSystem_sensor_1 = root_1_waterSystem["sensor_1"];
    root_1_waterSystem_sensor_2 = root_1_waterSystem["sensor_2"];
    root_1_waterSystem_pumpe = root_1_waterSystem["pumpe"];

    JsonObject root_1_lufterLeds = root_1["lufterLeds"];
    root_1_lufterLeds_getLufter_1 = root_1_lufterLeds["getLufter_1"];
    root_1_lufterLeds_setLufter_1 = root_1_lufterLeds["setLufter_1"];
    root_1_lufterLeds_getLufter_2 = root_1_lufterLeds["getLufter_2"];
    root_1_lufterLeds_setLufter_2 = root_1_lufterLeds["setLufter_2"];
    root_1_lufterLeds_getLed = root_1_lufterLeds["getLed"];
    root_1_lufterLeds_setLed = root_1_lufterLeds["setLed"];

    JsonObject root_1_energieStatus = root_1["energieStatus"];
    root_1_energieStatus_solar_1 = root_1_energieStatus["solar_1"];
    root_1_energieStatus_solar_2 = root_1_energieStatus["solar_2"];
    root_1_energieStatus_akku = root_1_energieStatus["akku"];
    root_1_energieStatus_strom = root_1_energieStatus["strom"];

    JsonObject root_1_settings = root_1["settings"];
    root_1_settings_brightness = root_1_settings["brightness"];
    root_1_settings_sound = root_1_settings["sound"];

    //sleep(min_delay);
  }
  //sleep(min_delay);
}

void put_data(bool print=true){
  if((WiFi.status() == WL_CONNECTED)){
    StaticJsonDocument<768> req;

    JsonObject doc_0 = req.createNestedObject();
    doc_0["id"] = 0;

    JsonObject doc_0_devices = doc_0.createNestedObject("devices");

    JsonArray doc_0_devices_esp32 = doc_0_devices.createNestedArray("esp32");
    doc_0_devices_esp32[0]["connected"] = root_0_devices_esp32_1;
    doc_0_devices_esp32[1]["connected"] = root_0_devices_esp32_2;
    doc_0_devices["raspberrypi"]["connected"] = root_0_devices_raspberrypi;

    JsonObject doc_1 = req.createNestedObject();
    doc_1["id"] = 1;

    JsonObject doc_1_tempHum = doc_1.createNestedObject("tempHum");
    doc_1_tempHum["temperature_1"] = root_1_tempHum_temperature_1;
    doc_1_tempHum["humidity_1"] = root_1_tempHum_humidity_1;
    doc_1_tempHum["temperature_2"] = root_1_tempHum_temperature_2;
    doc_1_tempHum["humidity_2"] = root_1_tempHum_humidity_2;

    JsonObject doc_1_waterSystem = doc_1.createNestedObject("waterSystem");
    doc_1_waterSystem["sensor_1"] = root_1_waterSystem_sensor_1;
    doc_1_waterSystem["sensor_2"] = root_1_waterSystem_sensor_2;
    doc_1_waterSystem["pumpe"] = root_1_waterSystem_pumpe;

    JsonObject doc_1_lufterLeds = doc_1.createNestedObject("lufterLeds");
    doc_1_lufterLeds["getLufter_1"] = root_1_lufterLeds_getLufter_1;
    doc_1_lufterLeds["setLufter_1"] = root_1_lufterLeds_setLufter_1;
    doc_1_lufterLeds["getLufter_2"] = root_1_lufterLeds_getLufter_2;
    doc_1_lufterLeds["setLufter_2"] = root_1_lufterLeds_setLufter_2;
    doc_1_lufterLeds["getLed"] = root_1_lufterLeds_getLed;
    doc_1_lufterLeds["setLed"] = root_1_lufterLeds_setLed;

    JsonObject doc_1_energieStatus = doc_1.createNestedObject("energieStatus");
    doc_1_energieStatus["solar_1"] = root_1_energieStatus_solar_1;
    doc_1_energieStatus["solar_2"] = root_1_energieStatus_solar_2;
    doc_1_energieStatus["akku"] = root_1_energieStatus_akku;
    doc_1_energieStatus["strom"] = root_1_energieStatus_strom;

    JsonObject doc_1_settings = doc_1.createNestedObject("settings");
    doc_1_settings["brightness"] = root_1_settings_brightness;
    doc_1_settings["sound"] = root_1_settings_sound;

    serializeJson(req, output);
    httpPUTRequest(api_url, output,print);
    
    sleep(min_delay);
  }
  sleep(min_delay);
}

// ================================================= HTTP END ==================================================================
// =============================================================================================================================
// ================================================= Display START =============================================================
TFT_eSPI tft = TFT_eSPI(); // Invoke library, pins defined in User_Setup.h
TFT_eSprite sprite = TFT_eSprite(&tft); // Sprite object for display buffer
TFT_eSprite header = TFT_eSprite(&tft); // Sprite object for display buffer
TFT_eSprite content = TFT_eSprite(&tft); // Sprite object for display buffer
TFT_eSprite footer = TFT_eSprite(&tft); // Sprite object for display buffer


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
void DTP(String object,int8_t size,int16_t color,int16_t x,int16_t y,String text){
  if (object == "header"){
    header.setTextSize(size);
    header.setTextColor(color);
    header.setCursor(x,y);
    header.print(text);
  }
  if (object == "content"){
    content.setTextSize(size);
    content.setTextColor(color);
    content.setCursor(x,y);
    content.print(text);
  }
  if (object == "footer"){
    footer.setTextSize(size);
    footer.setTextColor(color);
    footer.setCursor(x,y);
    footer.print(text);
  }
};

/**
 * @brief SPT = Standard Page Template
 * 
 * @param text
 */
void SPT(String text){
  // Top
  header.createSprite(240,45);
  header.fillSprite(BLACK);
  header.setTextSize(2);
  header.setTextColor(WHITE);
  DTP("header",2,WHITE,(header.width()-header.textWidth(text))/2,10,text);
  header.drawLine(0,30,240,30,WHITE);
  // Bottom
  footer.createSprite(240,45);
  footer.fillSprite(BLACK);
  footer.drawLine(0,1,240,1,WHITE);
  footer.drawLine(100,9,100,29,WHITE);
  DTP("footer",2,WHITE,10,18,"7.7V");
  footer.fillRoundRect(150,8,Box_Width,Box_Height,Box_Radius,BOX_COLOR);
  DTP("footer",2,BLACK,168,15,"Home");
  // Push
  header.pushSprite(0,0);
  footer.pushSprite(0,275);
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

  tft.setTextSize(1);
  tft.setTextColor(GREEN);
  tft.setCursor(0,0);
  tft.print("Calibration complete!");
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
void DrawCircleVarTemplate(int32_t x, int32_t y, int32_t var,String end,int32_t circleColor,int32_t bgColor, int32_t varColor){
  content.fillCircle(x,y,32,circleColor);
  content.fillCircle(x,y,24,bgColor);
  content.setTextSize(2);
  content.setTextColor(varColor);
  content.setCursor(x-16,y-8);
  content.print(String(var)+end);
}

/**
 * @brief Page Einstellungen
 * 
 * @param brightness 
 * @param sound 
 */
void UI_Settings(int16_t brightness,int16_t sound){
  page = 5;
  //tft.fillScreen(BLACK);
  SPT("Einstellungen");
  // INIT
  content.createSprite(240,230);
  content.fillScreen(BLACK);
  // BLOCK 1
  DTP("content",2,WHITE,60,0,"Helligkeit");
  DTP("content",2,WHITE,(content.width()-content.textWidth(String(brightness)+"%"))/2,35,String(brightness)+"%");
  // BLOCK 2
  content.drawLine(40,85,180,85,WHITE);
  DTP("content",2,WHITE,90,95,"Ton");
  DTP("content",2,WHITE,(content.width()-content.textWidth(String(sound)+"%"))/2,130,String(sound)+"%");
  // BLOCK 3
  content.drawLine(20,175,220,175,WHITE);
  DTP("content",2,WHITE,20,195,"Touch Calibrieren");
  // PUSH
  content.pushSprite(0,45);
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
  page = 4;
  //tft.fillScreen(BLACK);
  SPT("Energie Status");
  // INIT
  content.createSprite(240,230);
  content.fillScreen(BLACK);
  // BLOCK 1
  String text[4] = {"Solar Panel 1:","Solar Panel 2:","Akku Kap.:","Strom Verb.:"};
  String data[4] = {String(sp1)+"V",String(sp2)+"V",String(akku)+"%",String(strom)+"V"};
  for (int i=0,y=5; i < 4; i++,y+=30)
  {
    DTP("content",2,WHITE,0,y,text[i]);
    DTP("content",2,WHITE,180,y,data[i]);
  }
  // PUSH
  content.pushSprite(0,45);
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
  page = 3;
  //tft.fillScreen(BLACK);
  SPT("Lufter / LEDs");
  // INIT
  content.createSprite(240,230);
  content.fillScreen(BLACK);
  // BLOCK 1
  DTP("content",2,BLUE,10,0,"Lufter");
  DTP("content",1,WHITE,120,15,"2");
  DTP("content",1,WHITE,10,15,"1");
  /**
   * @note Search for Slider
   * @details var -> Slider ≠ Text 
  */
  DTP("content",2,WHITE,45,25,String(getLufter1)+"%");
  DTP("content",2,WHITE,160,25,String(getLufter2)+"%");
  // Buttons
  if(setLufter1){content.fillRoundRect(20,65,Box_Width,Box_Height,Box_Radius,GREEN);} 
  else {content.fillRoundRect(20,65,Box_Width,Box_Height,Box_Radius,RED);};
  if (setLufter2){content.fillRoundRect(140,65,Box_Width,Box_Height,Box_Radius,GREEN);}
  else {content.fillRoundRect(140,65,Box_Width,Box_Height,Box_Radius,RED);};
  // BLOCK 2
  DTP("content",2,BLUE,10,115,"LED");
  DTP("content",2,WHITE,20,145,"Dimmung");
  DTP("content",2,WHITE,20,185,"Status");
  /**
   * @note Search for Slider
   * @details var -> Slider ≠ Text 
  */
  DTP("content",2,WHITE,150,145,String(getLed)+"%");
  // Button
  if(setLed){content.fillRoundRect(130,185,Box_Width,Box_Height,Box_Radius,GREEN);}
  else {content.fillRoundRect(130,185,Box_Width,Box_Height,Box_Radius,RED);};
  // PUSH
  content.pushSprite(0,45);
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
  //tft.fillScreen(BLACK);
  SPT("Bewasserung");
  // INIT
  content.createSprite(240,230);
  content.fillScreen(BLACK);
  // BLOCK 1
  DTP("content",2,BLUE,20,0,"Bodenfeuchtigkeit");
  DTP("content",2,WHITE,0,25,"Sensor 1");
  DrawCircleVarTemplate(40,75,sensor_1,"%",BLUE,BLACK,WHITE);
  DTP("content",2,WHITE,140,25,"Sensor 2");
  DrawCircleVarTemplate(190,75,sensor_2,"%",BLUE,BLACK,WHITE);
  tft.drawLine(20,115,220,115,WHITE);
  // BLOCK 2
  DTP("content",2,WHITE,20,145,"Pumpe");
  DTP("content",2,WHITE,20,185,"Status");
  if(pumpe){
    DTP("content",2,WHITE,140,145,"-> Aus");
    DTP("content",2,WHITE,140,185,"An");
  }else {
    DTP("content",2,WHITE,140,145,"-> An");
    DTP("content",2,WHITE,140,185,"Aus");
  }
  // PUSH
  content.pushSprite(0,45);
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
  //tft.fillScreen(BLACK);
  // Title
  SPT("Daten");
  // INIT
  content.createSprite(240,230);
  content.fillScreen(BLACK);
  // Block 1
  DTP("content",2,WHITE,80,5,"Drinnen");
  DrawCircleVarTemplate(50,64,tmp1,"C",RED,BLACK,RED);
  DrawCircleVarTemplate(180,64,hum1,"%",BLUE,BLACK,BLUE);
  content.drawLine(20,114,200,114,WHITE);
  // Block 2
  DTP("content",2,WHITE,71,124,"Draussen");
  DrawCircleVarTemplate(50,184,tmp2,"C",RED,BLACK,RED);
  DrawCircleVarTemplate(180,184,hum2,"%",BLUE,BLACK,BLUE);
  // Push
  content.pushSprite(0,45);
}

/**
 * @brief Main Page
 * 
 * @param strom
 */
void UI_Home(void){
  page = 0;
  //tft.fillScreen(BLACK);
  header.createSprite(240,46);
  header.fillScreen(BLACK);
  DTP("header",1,LOGO_COLOR,100,1,"Lycee Prive Emile Metz");
  DTP("header",3,WHITE,85,20,"Home");
  header.drawBitmap(0,0,settings,iconSettingWidth,iconSettingHeight,WHITE);
  header.drawLine(0,45,240,45,WHITE);
  // ----
  content.createSprite(240,230);
  content.fillScreen(BLACK);
  content.drawBitmap(30,15,temperature_humidity,iconsHomeWidth,iconsHomeHeight,WHITE);
  content.drawBitmap(140,15,bewasserungs_system,iconsHomeWidth,iconsHomeHeight,WHITE);
  content.drawLine(20,86,220,83,WHITE);  
  content.drawLine(120,15,120,145,WHITE);
  content.drawBitmap(30,85,led_lufter,iconsHomeWidth,iconsHomeHeight,WHITE);
  content.drawBitmap(140,90,akku_energie,iconsHomeWidth,iconsHomeHeight,WHITE);
  // IMG
  content.drawBitmap((tft.width()-logoWidth)/2,145,logo,logoWidth,logoHeight,WHITE);
  // Bottom
  footer.createSprite(240,40);
  footer.fillScreen(BLACK);
  footer.drawLine(0,20,240,20,WHITE);
  DTP("footer",2,WHITE,0,25,"7.7V");
  DTP("footer",2,WHITE,170,25,"Datum");
  //---
  header.pushSprite(0,0);
  content.pushSprite(0,47); // 45
  footer.pushSprite(0,280); // 277
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
  if((WiFi.status() == WL_CONNECTED)){
    get_data();
  }else {
    fetch_data();
  }

  switch (ui)
  {
  case 1:
    UI_TempHum(root_1_tempHum_temperature_1,root_1_tempHum_humidity_1,root_1_tempHum_temperature_2,root_1_tempHum_humidity_2);
    break;
  case 2:
    UI_WaterSys(root_1_waterSystem_sensor_1,root_1_waterSystem_sensor_2,root_1_waterSystem_pumpe);
    break;
  case 3:
    UI_LufterLeds(root_1_lufterLeds_getLufter_1,root_1_lufterLeds_setLufter_1,root_1_lufterLeds_getLufter_2,root_1_lufterLeds_setLufter_2,root_1_lufterLeds_getLed,root_1_lufterLeds_setLed);
    break; 
  case 4:
    UI_EnergieStatus(root_1_energieStatus_solar_1,root_1_energieStatus_solar_2,root_1_energieStatus_akku,root_1_energieStatus_strom);
    break;
  case 5:
    UI_Settings(root_1_settings_brightness,root_1_settings_sound);
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
  initWiFi();
  get_data(false);
  //root_0_devices_esp32_1 = true;
  //put_data(false);
  Serial.println("Ended   : WiFi    Configuration");
  Serial.println("Start   : Display Configuration");
  tft.init();
  tft.setRotation(2);
  tft.fillScreen(BLACK);

  //uint16_t calData[5] = { 438, 3390, 368, 3317, 7 };
  //tft.setTouch(calData);
  Serial.println("Ended   : Display Configuration");
  Serial.println("Start   : Display Calibration");
  touch_calibrate();
  //tft.fillScreen(BLACK);
  Serial1.println("Ended  : Display Calibration");
  // TEST PAGE
  //menuIndex = 5;
}

void loop(void){
  //fetch_data();
  menu(menuIndex);

  uint16_t touch_x=0,touch_y=0;

  bool pressed = tft.getTouch(&touch_x,&touch_y);

  // if the button is pressed
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
  delay(100);
  sprite.deleteSprite();
  header.deleteSprite();
  content.deleteSprite();
  footer.deleteSprite();
}