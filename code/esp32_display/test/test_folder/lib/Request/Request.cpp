#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>

#include "Request.h"

/**
 * @brief Construct a new Request:: Request object
 * 
 * @param url 
 * @param print 
 */
Request::Request(String url, bool print) {
    _url = url;
    _print = print;
}

// String Request::data = "Hello World";

void Request::set() {
    Serial.println(data);
    data2 = "test";
}

void Request::get() {
    HTTPClient http;
    http.begin(_url);
    http.addHeader("Content-Type", "application/json");
    int http_response = http.GET();
    String payload = "{}";
    // Print the payload to the console.
    if(http_response < 0){
        Serial.println(payload);
    } else {
        payload = http.getString();
        Serial.println(payload);
    }
    http.end();
};