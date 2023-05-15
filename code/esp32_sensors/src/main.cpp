#include <Arduino.h>
#include <Wlan.h>
#include <Request.h>
#include <config.h>

#include "DHT.h"

Wlan wlan;
Request api("http://192.168.178.38:8080/sensor");

// DHT help
// https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/
// VCC -> 5V
// GND -> GND
// DATA -> PIN (27 / 14) -> 10K RESISTOR -> 5V
#define DHTPIN_1 27     // Digital pin connected to the DHT sensor
#define DHTPIN_2 14     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht_1(DHTPIN_1, DHTTYPE);
DHT dht_2(DHTPIN_2, DHTTYPE);

// Capacitive Soil Moisture Sensor help
// https://media.digikey.com/pdf/data%20sheets/dfrobot%20pdfs/sen0193_web.pdf
// VCC -> 5V
// GND -> GND
// DATA -> Pin 23
// 2006.0 = 100%
// 4095.0 = 0%
const int soilMoisturePin_1 = 32;
const int soilMoisturePin_2 = 33;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting up ...");
  wlan.connect();
  dht_1.begin();
  dht_2.begin();
  pinMode(soilMoisturePin_1, INPUT);
}

void loop() {
  Serial.println("--------------------");
  // api.get();

  float humidity_1 = dht_1.readHumidity();
  float humidity_2 = dht_2.readHumidity();
  float temperature_1 = dht_1.readTemperature();
  float temperature_2 = dht_2.readTemperature();
  float soilMoisture_1 = analogRead(soilMoisturePin_1);
  float soilMoisture_2 = analogRead(soilMoisturePin_2);

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity_1) || isnan(temperature_1)) {
    Serial.println(F("Failed to read from DHT 1 sensor!"));
    return;
  }
  if (isnan(humidity_2) || isnan(temperature_2)) {
    Serial.println(F("Failed to read from DHT 2 sensor!"));
    return;
  }

  api.set("Test", "Pin First", "true", "Testing");
  api.set("Temperature", "Pin"+String(DHTPIN_1) , String(temperature_1), "Temperature Sensor 1");
  api.set("Humidity", "Pin"+String(DHTPIN_1) , String(humidity_1), "Humidity Sensor 1");
  api.set("Temperature", "Pin"+String(DHTPIN_2) , String(temperature_2), "Temperature Sensor 2");
  api.set("Humidity", "Pin"+String(DHTPIN_2) , String(humidity_2), "Humidity Sensor 2");
  api.set("Soil Moisture", "Pin"+String(soilMoisturePin_1) , String(soilMoisture_1), "Soil Moisture Sensor 1");
  api.set("Soil Moisture", "Pin"+String(soilMoisturePin_2) , String(soilMoisture_2), "Soil Moisture Sensor 2");
  api.set("Test", "Pin Last", "false", "Testing", true);
  api.setTest();
  int res_code = api.post();
  Serial.println("Response: " + String(res_code));
  Serial.println("--------------------");

  Serial.println("--------------------");
  api.get();

  Serial.println("--------------------");
  api.end();
  delay(2000);
}