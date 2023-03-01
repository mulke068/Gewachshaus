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

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "include/test_config.h"
#include "include/test_json.h"

void initWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to wifi ");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    sleep(min_delay);
  }
  Serial.println(" ");
  Serial.print("Connected to Network whit IP: ");
  Serial.println(WiFi.localIP());
}

String httpGETRequest(const char* url)
{
  HTTPClient http;
  http.begin(url);
  int http_response = http.GET();

  String payload = "{}";

  if (http_response > 0)
  {
    Serial.println("----------------------------------------------------------------");
    Serial.print("HTTP Response code: ");
    Serial.println(http_response);
    payload = http.getString();
    Serial.println(payload);
    Serial.println("----------------------------------------------------------------");
  }
  else
  {
    Serial.print("Error Code");
    Serial.println(http_response);
  }

  http.end();
  return payload;
}

void get_data()
{
  if ((WiFi.status() == WL_CONNECTED))
  {
    StaticJsonDocument<0> filter;
    filter.set(true);

    StaticJsonDocument<1024> doc;
    String json =  httpGETRequest(api_url);
    DeserializationError error = deserializeJson(doc, json, DeserializationOption::Filter(filter));

    if (error ){
      Serial.print("deserialization error: ");
      Serial.println(error.c_str());
      return;
    }

    JsonObject root_0 = doc[0];
    root_0_id = root_0["id"];

    JsonObject root_0_devices = root_0["devices"];
    root_0_devices_esp32_1 = root_0_devices["esp32"]["connected"][0];
    root_0_devices_esp32_2 = root_0_devices["esp32"]["connected"][1];
    root_0_devices_raspberrypi = root_0_devices["raspberrypi"]["connected"];

    // ----------------------------------------------------------------
    JsonObject root_1 = doc[1];
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

    Serial.print("root_1_energieStatus_akku : ");
    Serial.println(root_1_energieStatus_akku);

    sleep(min_delay);
  }
  sleep(min_delay);
}

void setup(void)
{
  Serial.begin(115200);
  //Serial2.begin(9600, SERIAL_8N1,RX,TX);
  Serial.println("Terminal Started");

  initWiFi();
  Serial.println("RRSI: " + WiFi.RSSI());
}

void loop(void)
{
  get_data();

  Serial.print("root_1_settings_sound : ");
  Serial.println(root_1_settings_sound);

  sleep(15);
}