#include <Arduino.h>
#include <Wlan.h>
#include <Request.h>
#include <config.h>

#include "DHT.h"

#define apiSettings DEF_SETTINGS
#define apiSensor DEF_SENSOR
const char* uri = "http://192.168.178.38:3030";

Wlan wlan;
Request settings(uri, apiSettings);
Request sensor(uri, apiSensor);

// DHT help
// https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/
// VCC -> 3.3V or 5V
// GND -> GND
// DATA -> PIN (27 / 14) WITH 10K RESISTOR
#define DHTPIN_1 27     // Digital pin connected to the DHT sensor
#define DHTPIN_2 14     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht_1(DHTPIN_1, DHTTYPE);
DHT dht_2(DHTPIN_2, DHTTYPE);

void setup(void) {
  Serial.begin(115200);
  Serial.println("Starting up ...");
  wlan.connect();
  dht_1.begin();
  dht_2.begin();
}

void loop(void) {

  float humidity_1 = dht_1.readHumidity();
  float humidity_2 = dht_2.readHumidity();
  float temperature_1 = dht_1.readTemperature();
  float temperature_2 = dht_2.readTemperature();

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
  settings.getTest();
  Serial.println("--------------------");
  sensor.start();
  sensor.getTest();
  Serial.println("--------------------");
  settings.end();
  sensor.end();
  delay(2000);
}