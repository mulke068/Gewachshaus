#include <Wlan.h>

Wlan::Wlan() {
}

Wlan::~Wlan() {
    return;
}

void Wlan::connect() {
    try {
        WiFi.mode(WIFI_STA);
        WiFi.setHostname(WIFI_HOSTNAME);
        WiFi.config(WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET, WIFI_DNS1, WIFI_DNS2);
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
        Serial.print("Connecting to WiFi ");
        while(WiFi.status() != WL_CONNECTED) {
            delay(250);
            Serial.print(".");
            return;
        }
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        Serial.print("MAC address: ");
        Serial.println(WiFi.macAddress());
        Serial.print("Hostname: ");
        Serial.println(WiFi.getHostname());
        Serial.print("SSID: ");
        Serial.println(WiFi.SSID());
        Serial.print("Gateway: ");
        Serial.println(WiFi.gatewayIP());
        Serial.print("Subnet: ");
        Serial.println(WiFi.subnetMask());
        Serial.print("DNS: ");
        Serial.println(WiFi.dnsIP());
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

void Wlan::reconnect() {
    try {
        disconnect();
        connect();
    } catch (const std::exception& e) {
        Serial.println(e.what());
    }
}

wlan_status Wlan::status() {
    return static_cast<wlan_status>(WiFi.status());
}
