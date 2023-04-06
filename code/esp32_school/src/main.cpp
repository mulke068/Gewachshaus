#include <Arduino.h>

#define solidWed 500
#define solidDry 750

#define waterPin 4
#define waterPower 5

void setup() {
  Serial.begin(115200);
  pinMode(waterPower, OUTPUT);
  

  digitalWrite(waterPower, LOW);

  Serial.println("Connected");
}

float waterVar(){
  digitalWrite(waterPower, HIGH);
  delay(10);
  int var = analogRead(waterPin);
  digitalWrite(waterPower, LOW);
  return var;
}

void loop() {
  float waterfuil = waterVar();
  Serial.print("Water % :");
  Serial1.println(waterfuil);
  delay(20);
}