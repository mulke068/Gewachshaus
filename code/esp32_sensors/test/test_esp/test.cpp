#include <Arduino.h>
#include <config.h>
#include <Wlan.h>
#include <Request.h>

#define apiSettings DEF_SETTINGS
#define apiSensor DEF_SENSOR
Wlan wlan;
Request settings("http://192.168.178.38:3030", apiSettings);
Request sensor("http://192.168.178.38:3030", apiSensor);

void setup()
{
  Serial.begin(115200);

  wlan.connect();
}

void loop()
{
  Serial.println("loop");
  Serial.println("Request-Code: " + String(settings.start()));
  settings.getTest();
  // Serial.println("GET temperature_Min: " + String(settings.use.temperature_Min_GET()));
  // Serial.println("SET temperature_Avg: " + String(settings.use.temperature_Min_SET(20)));
  Serial.println(String(settings.get.temperature_Min()));
  Serial.println(String(settings.set.temperature_1(30.2)));
  settings.end();
  delay(5000);
}