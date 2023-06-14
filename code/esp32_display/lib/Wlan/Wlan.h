#ifndef Wlan_h
#define Wlan_h

#include <WiFi.h>

const IPAddress WIFI_IP(192,0,0,27); // 192,168,178,55
const IPAddress WIFI_GATEWAY(192,0,0,1); // 192,168,178,1
const IPAddress WIFI_SUBNET(255,255,255,0);
const IPAddress WIFI_DNS1(1,1,1,1);
const IPAddress WIFI_DNS2(8,8,8,8);

typedef enum {
    NO_SHIELD        = 255,
    IDLE_STATUS      = 0,
    NO_SSID_AVAIL    = 1,
    SCAN_COMPLETED   = 2,
    CONNECTED        = 3,
    CONNECT_FAILED   = 4,
    CONNECTION_LOST  = 5,
    DISCONNECTED     = 6
} wlan_status;

class Wlan {
public:
        Wlan();
        ~Wlan();
        void connect();
        void disconnect();
        void reconnect();
        static wlan_status status();
private:
	const char* WIFI_SSID     = "FRITZ!Box 4020 YD"; // FRITZ!Box 7490  // your network SSID (name of wifi network)
	const char* WIFI_PASSWORD = ""; // 05767844606687810343 // your network password
	const char* WIFI_HOSTNAME = "ESP32_Display"; // your hostname (will be visible in router)
};

#endif
