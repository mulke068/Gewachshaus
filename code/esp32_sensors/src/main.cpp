#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Starting up ...");
}

void loop() {
  Serial.println("Starting loop ...");
}