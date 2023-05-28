#include <Request.h>

/// @brief 
/// @param url 
Request::Request(String url, uint8_t type) {
    _url = url;
    _type = type;
}

/// @brief In case of a Crash
Request::~Request() {
    return;
}

int Request::get() {
	HTTPClient http;
	http.addHeader("Content-Type", "application/json");
    int http_code;
    switch (_type) {
    case DEF_SETTINGS:
        http.begin(_url + "/settings");
        http_code = http.GET();
        if (http_code >= 200) {
            _req = http.getString();
            // Serial.println("HTTP response : " + _req);

            return http_code;
        };
        break;
    case DEF_SENSOR:
        http.begin(_url + "/sensor");
        http_code = http.GET();
        if (http_code >= 200) {
            _req = http.getString();
            // Serial.println("HTTP response : " + _req);
    
            return http_code;
        };
        break;
    };
    return http_code;
	http.end();
}

int Request::post() {
    HTTPClient http;
    http.begin(_url);
    http.addHeader("Content-Type", "application/json");
    String payload = "{\"sensor\":[" + _res + "]}";
    int http_code = http.POST(payload);
    if(http_code >= 200) {
        return http_code;
    } else {
        return http_code;
    }
    http.end();
}

/// @brief 
/// @param name 
/// @param pin 
/// @param value 
/// @param description 
void Request::set(String name,String pin, String value, String description) {
    String payload = "{\"name\":\"" + name + "\",\"pin\":\"" + pin + "\",\"value\":\"" + value + "\",\"description\":\"" + description + "\"},";
    _res += payload;
}

/// @brief 
/// @param name 
/// @param pin 
/// @param value 
/// @param description 
/// @param last 
void Request::set(String name,String pin, String value, String description, boolean last = false) {
    String payload;
    last ? payload = "{\"name\":\"" + name + "\",\"pin\":\"" + pin + "\",\"value\":\"" + value + "\",\"description\":\"" + description + "\"}" : payload = "{\"name\":\"" + name + "\",\"pin\":\"" + pin + "\",\"value\":\"" + value + "\",\"description\":\"" + description + "\"},";
    _res += payload;
}

void Request::end() {
    _req = "";
    _res = "";
    //
}

void Request::getTest() {
    Serial.println("GET Test");
    Serial.println(_req);
}

void Request::setTest() {
    String payload = "{\"Sensor\":[" + _res + "]}";
    Serial.println("Test");
    Serial.println(payload);
}
