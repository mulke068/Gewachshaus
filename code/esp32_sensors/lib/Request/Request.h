#ifndef Request_h
#define Request_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>

#include <config.h>

class Request {
    public:
        Request(string url);
        void post();
    private:
        string _url;
};

#endif