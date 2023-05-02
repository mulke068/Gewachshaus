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
//#include <WiFiClientSecure.h>
//#include <WiFiClient.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "lib/Request/Request.h"

#include "include/test_config.h"
#include "include/test_json.h"

// ================================================= HTTP Start ================================================================

/**
* Initializes WiFi and connects to it's SSID and IP address. This is called from init
*/
void initWiFi(){
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.config(ipv4, gateway, subnet, DNS1, DNS2);
  WiFi.setHostname(hostname.c_str());
  WiFi.begin(ssid, password);
  Serial.println("--------------------------------");
  Serial.print("Connecting to WiFi ");
  while ((WiFi.status() != WL_CONNECTED)){
    Serial.print(".");
    sleep(min_delay);
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

/*
void httpGETRequest(String url) {
  HTTPClient https;
  http.begin("https://api.kevbchef.com/display" , root_ca);
  int httpCode = https.GET();
  if (httpCode > 0) {
    String payload = https.getString();
    Serial.println(payload);
  } else {
    Serial.println("HTTP request failed");
  }
  http.end();
}
*/
/*
// dont work
void httpGETRequest(const char* url){
    Serial.println("Initialize   : HTTP    Client");
    WiFiClient http;
    Serial.println("Initialize   : HTTP    Client");
    WiFiClientSecure https;
    Serial.println("Start   : HTTP    Connection");
    if (https.connect(url, 443)){
      Serial.println("Ended   : HTTP    ERROR");
      Serial.println("Start   : HTTPS   Connection");
      https.setCertificate(root_ca);
      //https.loadCertificate();
      int https_response = https.read();
      if(https > 0){
        String payload = https.readString();
        Serial.println("----------------------------------------");
        Serial.println(payload);
        Serial.println("----------------------------------------");
      }
      Serial.println("Ended   : HTTPS   Connection");
    } else {
      Serial.println("Ended   : HTTP/HTTPS    ERROR");
    }
    http.stop();
};
*/

/*
// dont work
void httpGETRequest(const char* url){
  WiFiClient http;
  IPAddress ip = IPAddress(192,168,178,38);
  if(http.connect(ip, uint16_t(8080))){
    http.println("GET http://192.168.178.38:8080/display HTTP/1.1");
    http.println("Connection: close");

    while (http.connected()){
      String line = http.readStringUntil('\n');
      if (line == "\r"){
        Serial.println("Header recived");
        break;
      }
    }

    while (http.available()) {
      char c = http.read();
      Serial.write(c);
    }

    http.stop();
  }

}
*/

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