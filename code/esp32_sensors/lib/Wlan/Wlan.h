#ifndef Wlan_h
#define Wlan_h

#include <WiFi.h>
#include <config.h>

class Wlan {
    public:
        Wlan(string Hostname);
        ~Wlan();
        void connect();
        void disconnect();
    private:
        string _Hostname;
};

#endif