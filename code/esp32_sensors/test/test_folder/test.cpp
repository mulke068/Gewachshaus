#include <Arduino.h>
#include <WiFi.h>
#include <config.h>

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  //WiFi.config(ip, gateway, subnet, dns1, dns2);
  WiFi.begin(ssid, password);
  Serial.print("Connecting ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println(" connected");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());
  Serial.println(WiFi.getHostname());
  Serial.println(WiFi.SSID());
  Serial.println(WiFi.RSSI());
  Serial.println(WiFi.gatewayIP());
  Serial.println(WiFi.dnsIP());
  Serial.println(WiFi.subnetMask());
}

void loop() {
  // do nothing
}