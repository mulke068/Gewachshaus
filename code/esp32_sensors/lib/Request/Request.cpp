#include <Request.h>

Request::Request(String url) {
    Serial.println("Request created");
    _url = url;
}

Request::~Request() {
    Serial.println("Request destroyed");
}

void Request::get() {
    HTTPClient http;
    http.begin(_url);
    http.addHeader("Content-Type", "application/json");
    int http_code = http.GET();
    if (http_code >= 200) {
        Serial.println("HTTP response code: " + http_code);
        _payload = http.getString();
        Serial.println("HTTP response : " + _payload);
    } else {
        Serial.println("HTTP GET request failed");
    }
    http.end();
}

void Request::post() {
    HTTPClient http;
    http.begin(_url);
    http.addHeader("Content-Type", "application/json");
    int http_code = http.POST(_payload);
    if(http_code >= 200) {
        Serial.print("HTTP response code: " + http_code);  
    } else {
        Serial.print("HTTP POST request failed");
    }
    http.end();
}