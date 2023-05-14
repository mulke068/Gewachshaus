#include <Arduino.h>
#include <config.h>
#include <lib/Wlan.h>

Wlan wlan;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  wlan.connect();
  
}

void loop() {
  // do nothing
}