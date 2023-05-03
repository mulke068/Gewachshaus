#ifndef Wlan_h
#define Wlan_h

#include <WiFi.h>
#include <config.h>

class Wlan {
    public:
        void connect();
        void disconnect();
};

#endif