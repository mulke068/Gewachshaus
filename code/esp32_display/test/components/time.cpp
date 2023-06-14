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


// ================================================= HTTP Start ================================================================

// ================================================= HTTP END ==================================================================


// ================================================= SETUP ==================================================================

#define LOOP_DELAY 200
uint32_t currentTime = 0;
uint32_t upTime = 0;
// that the 1s delay is not affected by the loop time
int currentTime_delay = 1000 - LOOP_DELAY;
int ss,mm;


void setup(void){
  Serial.begin(115200);
  Serial.println("Terminal Started");
  Serial.println("Start   : WiFi      Configuration");
  initWiFi();
  Serial.println("Started : WiFi      Configuration");
  // TEST PAGE
  //menuIndex = 5;
  currentTime = millis() + currentTime_delay;
}

void loop(void){
  if(currentTime < millis()){
    currentTime = millis() + currentTime_delay;
    ss++;
    if(ss == 60){
      ss = 0;
      mm++;
    }
    Serial.println(String(mm)+"m"+String(ss)+"s");
    if(ss % 10 == 0){
      Serial.println("Start   : HTTP    Configuration");
      Request api(api_url,true);
      api.get();
      Serial.println(api.data);
      api.data = "No Hello World";
      api.set();
      Serial.println(api.data2);
      Serial.println("Ended   : HTTP    Configuration");
    }
  }
  delay(LOOP_DELAY);
}