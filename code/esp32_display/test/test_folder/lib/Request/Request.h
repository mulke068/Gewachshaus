#ifndef Request_h
#define Request_h

#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>

class Request {
    public:
        Request(String url,bool print);
        void get();
        //void put();
        void set();
        String data = "hello World";
        String data2;
    private:
        String _url;
        bool _print;
};

#endif