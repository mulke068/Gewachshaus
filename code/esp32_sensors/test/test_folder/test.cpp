#include <Arduino.h>
#include <config.h>
#include <Wlan.h>

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  Wlan wlan;
  wlan.connect();
  
}

void loop() {
  // do nothing
}