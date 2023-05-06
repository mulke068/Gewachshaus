#include <Request.h>

/// @brief 
/// @param url 
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
        _req = http.getString();
        // Serial.println("HTTP response : " + _req);
        deserializeData();
    } else {
        Serial.println("HTTP GET request failed");
    }
    http.end();
}

void Request::post() {
    HTTPClient http;
    http.begin(_url);
    http.addHeader("Content-Type", "application/json");
    String payload = "{\"Sensor\":[" + _res + "]}";
    int http_code = http.POST(payload);
    if(http_code >= 200) {
        Serial.print("HTTP response code: " + http_code);  
    } else {
        Serial.print("HTTP POST request failed");
    }
    http.end();
}

/// @brief 
/// @param name 
/// @param pin 
/// @param value 
/// @param description 
void Request::set(String name,String pin, String value, String description) {
    String payload = "{\"name\":\"" + name + "\",\"pin\":" + pin + ",\"value\":" + value + ",\"description\":\"" + description + "\"},";
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
    last ? payload = "{\"name\":\"" + name + "\",\"pin\":" + pin + ",\"value\":" + value + ",\"description\":\"" + description + "\"}" : payload = "{\"name\":\"" + name + "\",\"pin\":" + pin + ",\"value\":" + value + ",\"description\":\"" + description + "\"},";
    _res += payload;
}

void Request::end() {
    _req = "";
    _res = "";
    request_sensor_id = "";
    request_sensor_name = "";
    request_sensor_pin = "";
    request_sensor_value = "";
    request_sensor_description = "";
}

/// @brief 
/// @param data 
void Request::deserializeData() {
    // const int capacity = JSON_OBJECT_SIZE(3) + 2 * JSON_OBJECT_SIZE(1);
    DynamicJsonDocument doc(6144); // 6144
    DeserializationError error = deserializeJson(doc, _req);
    if (error) {
        Serial.println("deserialize failed: "+ String(error.c_str()));
        return;
    }
    JsonObject root_0 = doc[0];
    request_unique_id = root_0["_id"];
    for (JsonObject root_0_sensor_item : root_0["sensor"].as<JsonArray>()) {
        request_sensor_id = root_0_sensor_item["_id"];
        request_sensor_name = root_0_sensor_item["name"];
        request_sensor_pin = root_0_sensor_item["pin"];
        request_sensor_value = root_0_sensor_item["value"];
        request_sensor_description = root_0_sensor_item["description"];
    }
    request_id = root_0["id"];
    request_timestamp = root_0["timestamp"];
    request_created_at = root_0["created_at"];
}

void Request::test() {
    String payload = "{\"Sensor\":[" + _res + "]}";
    Serial.println("Test");
    Serial.println(payload);
}