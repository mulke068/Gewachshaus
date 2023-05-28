#include <Arduino.h>
#include <config.h>
#include <Wlan.h>
#include <Request.h>

#define apiSettings DEF_SETTINGS
#define apiSensor DEF_SENSOR
Wlan wlan;
Request settings("http://192.168.178.38:3030", apiSettings);
Request sensor("http://192.168.178.38:3030", apiSensor);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  wlan.connect();
}

void loop() {
  Serial.println("loop");
  Serial.println("Request-Code: " + String(settings.get()));
  settings.getTest();
  settings.end();
  Serial.println("Request-Code: " + String(sensor.get()));
  sensor.getTest();

  


  sensor.end();
  delay(5000);
}