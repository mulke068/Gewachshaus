#include <WiFi.h>
#include <config.h>

#include <Wlan.h>

void Wlan::connect() {
    try {
        Wlan::disconnect();
        WiFi.mode(WIFI_STA);
        WiFi.config(WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET, WIFI_DNS1, WIFI_DNS2);
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
        Serial.print("Connecting to WiFi");
        while(WiFi.status() != WL_CONNECTED) {
            delay(250);
            Serial.print(".");
        }
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.print(WiFi.localIP());
        Serial.println("MAC address: ");
        Serial.print(WiFi.macAddress());
        Serial.println("Hostname: ");
        Serial.print(WiFi.getHostname());
        Serial.println("SSID: ");
        Serial.print(WiFi.SSID());
        Serial.println("Gateway: ");
        Serial.print(WiFi.gatewayIP());
        Serial.println("Subnet: ");
        Serial.print(WiFi.subnetMask());
        Serial.println("DNS: ");
        Serial.print(WiFi.dnsIP());
    } catch (const std::exception& e){
        Serial.println("Could not connect to WiFi");
        Serial.println(e.what());
    }
}

void Wlan::disconnect() {
    try {
        WiFi.disconnect();
        Serial.println("WiFi disconnected");
    } catch (const std::exception& e) {
        Serial.println(e.what());
    }
}
