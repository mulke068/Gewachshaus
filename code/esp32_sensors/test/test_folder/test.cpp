#include <Arduino.h>
#include <config.h>
#include <Wlan.h>
#include <Request.h>

#define API_SETTINGS DEF_SETTINGS
#define API_SENSOR DEF_SENSOR
Wlan wlan;
Request settings("http://192.0.0.23:8080", API_SETTINGS);
Request sensor("http://192.0.0.23:8080", API_SENSOR);

void setup()
{
  Serial.begin(115200);

  wlan.connect();
  Serial.println(wlan.status());
}

void loop()
{
  int int_rand = random(0, 100);
  int r,g,b = random(0, 255);
  String RGB_String = "rgb(" + String(r) + "," + String(g) + "," + String(b) + ")";
  const char* RGB = RGB_String.c_str();
  float float_rand = random(0.99, 99.99);
  bool bool_rand;
  if (int_rand % 2 == 0)
  {
    bool_rand = true;
  }
  else
  {
    bool_rand = false;
  };
  String TEXT_String = "Final";
  const char* TEXT = TEXT_String.c_str();
  Serial.println("--------------------");
  Serial.println("Request-Code: " + String(settings.start()));
  settings.getTest();
  settings.set.temperature_Min(int_rand);
  settings.set.temperature_Avg(int_rand);
  settings.set.temperature_Max(int_rand);
  settings.set.soilMoisture_Min(int_rand);
  settings.set.soilMoisture_Max(int_rand);
  settings.set.setPumpe(bool_rand);
  settings.set.setLufter_1(bool_rand);
  settings.set.setLufter_2(bool_rand);
  settings.set.setLight(bool_rand);
  settings.set.setRgbLed(RGB);
  settings.set.setMatrixLed(TEXT);
  settings.setTest();
  Serial.println("Response-Code: " + String(settings.post(true)));
  settings.end();
  Serial.println("--------------------");
  Serial.println("Request-Code: " + String(sensor.start()));
  sensor.getTest();
  sensor.set.temperature_1(float_rand);
  sensor.set.humidity_1(float_rand);
  sensor.set.temperature_2(float_rand);
  sensor.set.humidity_2(float_rand);
  sensor.set.soilMoisture_1(float_rand);
  sensor.set.soilMoisture_2(float_rand);
  sensor.set.statusPumpe(bool_rand);
  sensor.set.statusLufter_1(bool_rand);
  sensor.set.statusLufter_2(bool_rand);
  sensor.set.statusLight(bool_rand);
  sensor.set.getRgbLed(RGB);
  sensor.setTest();
  Serial.println("Response-Code: " + String(sensor.post(false)));
  sensor.end();
  Serial.println("--------------------");
  delay(5000);
}