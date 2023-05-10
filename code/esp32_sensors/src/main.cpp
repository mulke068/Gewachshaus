#include <Arduino.h>
#include <Wlan.h>
#include <Request.h>
#include <config.h>

Wlan wlan;
Request api("http://192.168.178.38:8080/sensor");

void setup() {
  Serial.begin(115200);
  Serial.println("Starting up ...");
  wlan.connect();
}

void loop() {
  Serial.println("--------------------");
  // api.set("Temperature", "Pin1" , String(random(0, 100)), "Temperature Sensor");
  // api.set("Lüfter", "Pin3" , String(true), "Lüfter an aus");
  // api.set("Pumpe" , "Pin4" , String(false), "Pumpe an aus", true);
  // api.setTest();
  api.get();
  // api.test();
  Serial.println("Request Sensor ID:");
  Serial.println(api.pin(3));
  Serial.println("Request Sensor Name:");
  Serial.println(api.name(1));
  api.end();
  Serial.println("--------------------");
  delay(2000);
}