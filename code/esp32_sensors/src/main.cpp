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
  api.get();
  Serial.println("Starting loop ...");
  delay(2000);
}