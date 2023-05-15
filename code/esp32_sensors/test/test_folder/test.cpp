#include <Arduino.h>
#include <config.h>

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
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  pinMode(soilMoisturePin_1, INPUT);
  
}

void loop() {
  // do nothing
  float soilMoisture_Value_1 = (analogRead(soilMoisturePin_1)/1023.0)*3.3;
  Serial.println(soilMoisture_Value_1);
  delay(1000);
}