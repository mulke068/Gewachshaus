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

#include "include/test_config.h"
#include "include/test_json.h"

// ================================================= HTTP Start ================================================================

void initWiFi(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("--------------------------------");
  Serial.print("Connecting to WiFi ");
  while ((WiFi.status() != WL_CONNECTED)){
    Serial.print(".");
    sleep(min_delay);
  }
  Serial.println(" ");
  Serial.print("Host IP : ");
  Serial.println(WiFi.localIP());
  Serial.println("SSID    : " + WiFi.SSID());
  Serial.println("--------------------------------");
}

String httpGETRequest(const char* url,bool print){
  HTTPClient http;
  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Access-Control-Allow-Origin", "*"); // access-control-allow-credentials : true
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

    //StaticJsonDocument<1024> res;
    StaticJsonDocument<1050> res;
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

    sleep(min_delay);
  }
  sleep(min_delay);
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

}

#define LOOP_DELAY 200
uint32_t currentTime = 0;
uint32_t upTime = 0;
// that the 1s delay is not affected by the loop time
int currentTime_delay = 1000 - LOOP_DELAY;
int ss,mm;


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

  //uint16_t calData[5] = { 438, 3390, 368, 3317, 7 };
  //tft.setTouch(calData);
  Serial.println("Ended   : Display Configuration");

  // TEST PAGE
  //menuIndex = 5;
  currentTime = millis() + currentTime_delay;
}

void loop(void){

  //fetch_data();
  /*
  WiFiClientSecure *client = new WiFiClientSecure;
  if(client){
    client -> setCACert(client_cert);
    {
      HTTPClient http;
      Serial.println("Starting connection to server...");
      menu(menuIndex);
    }
    delete client;
  } else {
    Serial.println("Unable to create client");
  }
  */
  //menu(menuIndex);
  //Serial.print("response: ");
  //Serial.println(root_1_energieStatus_akku);
  //delay(10000);

  if(currentTime < millis()){
    currentTime = millis() + currentTime_delay;
    ss++;
    if(ss == 60){
      ss = 0;
      mm++;
    }
    Serial.println(String(mm)+"m"+String(ss)+"s");
    Serial.println("Current Uptime: " + String(upTime = millis()) + "s"); 
  }
  delay(LOOP_DELAY);
}