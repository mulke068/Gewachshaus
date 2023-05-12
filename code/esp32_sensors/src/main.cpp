#include <Arduino.h>
#include <Wlan.h>
#include <Request.h>
#include <config.h>

#include "DHT.h"

Wlan wlan;
Request api("http://192.168.178.38:8080/sensor");

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

void setup() {
  Serial.begin(115200);
  Serial.println("Starting up ...");
  wlan.connect();
  dht_1.begin();
  dht_2.begin();
}

void loop() {
  Serial.println("--------------------");
  // api.set("Temperature", "Pin1" , String(random(0, 100)), "Temperature Sensor");
  // api.set("Lüfter", "Pin3" , String(true), "Lüfter an aus");
  // api.set("Pumpe" , "Pin4" , String(false), "Pumpe an aus", true);
  // api.setTest();
  // api.get();

  float humidity_1 = dht_1.readHumidity();
  float humidity_2 = dht_2.readHumidity();
  float temperature_1 = dht_1.readTemperature();
  float temperature_2 = dht_2.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity_1) || isnan(temperature_1)) {
    Serial.println(F("Failed to read from DHT 1 sensor!"));
    return;
  }
  if (isnan(humidity_2) || isnan(temperature_2)) {
    Serial.println(F("Failed to read from DHT 2 sensor!"));
    return;
  }

  api.set("Temperature", "Pin"+String(DHTPIN_1) , String(temperature_1), "Temperature Sensor 1");
  api.set("Humidity", "Pin"+String(DHTPIN_1) , String(humidity_1), "Humidity Sensor 1");
  api.set("Temperature", "Pin"+String(DHTPIN_2) , String(temperature_2), "Temperature Sensor 2");
  api.set("Humidity", "Pin"+String(DHTPIN_2) , String(humidity_2), "Humidity Sensor 2",true);
  api.setTest();
  int res_code = api.post();
  Serial.println("Response: " + String(res_code));
  Serial.println("--------------------");

  Serial.println("--------------------");
  api.get();
  Serial.print("Sensor: 1 - Temperature: ");
  Serial.print(api.use().value(1));
  Serial.print(" Humidity: ");
  Serial.println(api.use().value(2));
  Serial.print("Sensor: 2 - Temperature: ");
  Serial.print(api.use().value(3));
  Serial.print(" Humidity: ");
  Serial.println(api.use().value(4));

  Serial.println("--------------------");
  api.end();
  delay(2000);
}