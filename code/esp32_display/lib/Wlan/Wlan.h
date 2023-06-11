#ifndef Wlan_h
#define Wlan_h

#include <WiFi.h>
#include <config.h>

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
};

#endif