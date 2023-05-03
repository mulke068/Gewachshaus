#ifndef Request_h
#define Request_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>

#include <config.h>

class Request {
    public:
        Request(String url);
        ~Request();
        void get();
        void post();
    private:
        String _url;
        String _payload;
};

#endif