#include <Arduino.h>
#include <Wlan.h>
#include <Request.h>
#include <config.h>
#include <variables.h>

#include <SPI.h>

#include "DHT.h"
#include "Adafruit_NeoPixel.h"

#define apiSettings DEF_SETTINGS
#define apiSensor   DEF_SENSOR
const char* uri = "http://192.168.178.38:3030";

Wlan    wlan;
Request settings(uri, apiSettings);
Request sensor(uri, apiSensor);

// DHT help
// https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/
// VCC  -> 3.3V or 5V
// GND  -> GND
// DATA -> PIN (27 / 14) WITH 10K RESISTOR
#define DHTPIN_1  27    // Digital pin connected to the DHT sensor
#define DHTPIN_2  14    // Digital pin connected to the DHT sensor
#define DHTTYPE   DHT22 // DHT 22  (AM2302), AM2321
DHT dht_1(DHTPIN_1, DHTTYPE);
DHT dht_2(DHTPIN_2, DHTTYPE);

// Capacitive Soil Moisture Sensor help
// https://media.digikey.com/pdf/data%20sheets/dfrobot%20pdfs/sen0193_web.pdf
// VCC    -> 5V
// GND    -> GND
// DATA   -> Pin 23 
// 2006.0 = 100%
// 4095.0 = 0%
const int soilMoisturePin_1 = 25;
const int soilMoisturePin_2 = 26;

// Adafruit Neo Pixel Ring help
// https://www.adafruit.com/product/1463
// VCC    -> 5V
// GND    -> GND
// DIN    -> 15
// DOUT   -> NONE
#define NeoPixel_NUM 16
#define NeoPixel_PIN 15
Adafruit_NeoPixel neoPixel(NeoPixel_NUM,NeoPixel_PIN,NEO_GBR + NEO_KHZ800);

void setup(void) {
  Serial.begin(115200);
  Serial.println("Starting up ...");
  wlan.connect();
  dht_1.begin();
  dht_2.begin();
  neoPixel.begin();
  neoPixel.clear();
}

int *rgb_String_To_Int(String rgb) {
  int startPos  = rgb.indexOf("(");
  int lastPos   = rgb.indexOf(")");
  
  String rgbValues = rgb.substring(startPos + 1, lastPos);
  
  int commaPos1 = rgbValues.indexOf(",");
  int commaPos2 = rgbValues.lastIndexOf(",");
  
  String r_String = rgbValues.substring(0 , commaPos1);
  String g_String = rgbValues.substring(commaPos1 + 1, commaPos2);
  String b_String = rgbValues.substring(commaPos2 + 1);

  static int rgbArray[3];
  rgbArray[0] = r_String.toInt();
  rgbArray[1] = g_String.toInt();
  rgbArray[2] = b_String.toInt();

  return rgbArray;
}

void TemperatureSettings() {
  if(settings.get.setLufter_1()) {
    if(temperature_1 <= settings.get.temperature_Min()) {} // lüfter on 100 %
    if(temperature_1 <= settings.get.temperature_Avg()) {} // lüfter on 50 %
    if(temperature_1 >= settings.get.temperature_Max()) {} // läfter off 0 %
  };
  if(settings.get.setLufter_2()) {
    if(temperature_2 <= settings.get.temperature_Min()) {} // lüfter on 100 %
    if(temperature_2 <= settings.get.temperature_Avg()) {} // lüfter on 50 %
    if(temperature_2 >= settings.get.temperature_Max()) {} // läfter off 0 %
  };
}

void LightSettings() {
  int *rgbValues = rgb_String_To_Int(settings.get.setRgbLed());
  if(settings.get.setLight()) {
    neoPixel.setBrightness(100);
    for(int i=0;i<NeoPixel_NUM;i++) {
      neoPixel.setPixelColor(i, rgbValues[0],rgbValues[1],rgbValues[2]);
      neoPixel.show();
    }
  } else {
    neoPixel.clear();
    neoPixel.show();
  };
}

void SoilMoistureSettings() {
  if(settings.get.setPumpe()) {
    if((soilMoisture_1 || soilMoisture_2) <= settings.get.soilMoisture_Min()) {} // Pumepe ON
    if((soilMoisture_1 && soilMoisture_2) >= settings.get.soilMoisture_Max()) {} // Pumpe OFF
  };
}

void MatrixLedSettings() {
  String text_displayed = settings.get.setMatrixLed();
}

int UpdateValues() {
  sensor.set.temperature_1(temperature_1);
  sensor.set.temperature_2(temperature_2);
  sensor.set.humidity_1(humidity_1);
  sensor.set.humidity_2(humidity_2);
  sensor.set.soilMoisture_1(soilMoisture_1);
  sensor.set.soilMoisture_2(soilMoisture_2);
  sensor.set.statusPumpe(statusPumpe);
  sensor.set.statusLufter_1(statusLufter_1);
  sensor.set.statusLufter_2(statusLufter_2);
  sensor.set.statusLight(statusLight);
  int http_code = sensor.post(true);
  if(http_code <= 200 || http_code >= 300) {
    Serial.println("UpdateValues -> Error Code: " + String(http_code));
  };
  return http_code;
};

void loop(void) {

  humidity_1      = dht_1.readHumidity();
  humidity_2      = dht_2.readHumidity();
  temperature_1   = dht_1.readTemperature();
  temperature_2   = dht_2.readTemperature();
  soilMoisture_1  = analogRead(soilMoisturePin_1);
  soilMoisture_2  = analogRead(soilMoisturePin_2);

  if (isnan(humidity_1) || isnan(temperature_1)) {
    Serial.println("Failed to read from DHT 1 sensor!");
    return;
  }
  if (isnan(humidity_2) || isnan(temperature_2)) {
    Serial.println("Failed to read from DHT 2 sensor!");
    return;
  }

  Serial.println("--------------------");
  settings.start();
  Serial.println("--------------------");
  sensor.start();
  Serial.println("--------------------");
  settings.end();
  sensor.end();
  delay(2000);
}