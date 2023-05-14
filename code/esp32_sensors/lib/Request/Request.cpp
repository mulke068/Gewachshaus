#include <Request.h>

/// @brief 
/// @param url 
Request::Request(String url) {
    _url = url;
}

/// @brief In case of a Crash
Request::~Request() {
    return;
}

/// @brief 
/// @return 
int Request::get() {
    HTTPClient http;
    http.begin(_url);
    http.addHeader("Content-Type", "application/json");
    int http_code = http.GET();
    if (http_code >= 200) {
        _req = http.getString();
        // Serial.println("HTTP response : " + _req);
        storeData();
        return http_code;
    } else {
        return http_code;
    }
    http.end();
}

/// @brief 
/// @return 
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

/// @brief 
void Request::end() {
    _req = "";
    _res = "";
    //
}


/// @brief 
void Request::storeData() {
    StaticJsonDocument<2048> _doc;
    DeserializationError error = deserializeJson(_doc, _req);
    if (error) {
        Serial.print("deserialize failed: ");
        Serial.println(error.c_str());
        return;
    }
    JsonObject root = _doc[0];
    _sensorData.request_id = root["id"];
    _sensorData.request_unique_id = root["_id"];
    _sensorData.request_created_at = root["created_at"];
    _sensorData.request_timestamp = root["timestamp"];
    _sensorData.request_version = root["__v"];

    JsonArray sensorArray = root["sensor"].as<JsonArray>();
    const size_t numSensor = sensorArray.size();
    // const char* sensorId[numSensor];
    // const char* sensorName[numSensor];
    // const char* sensorPin[numSensor];
    // const char* sensorValue[numSensor];
    // const char* sensorDescription[numSensor];
    
    for (size_t i = 0; i < numSensor; i++) {
        JsonObject sensorObj = sensorArray[i];
        const char* id = sensorObj["_id"];
        const char* name = sensorObj["name"];
        const char* pin = sensorObj["pin"];
        const char* value = sensorObj["value"];
        const char* description = sensorObj["description"]; 
        // strcpy(sensorId[i+1], id);
        _sensorData.id[i+1] = id;
        _sensorData.name[i+1] = name;
        _sensorData.pin[i+1] = pin;
        _sensorData.value[i+1] = value;
        _sensorData.description[i+1] = description;
    }
}


/// @brief 
/// @param index 
/// @return 
int IndexCheck(int index) {
    index == NAN ? index = 0 : index = index;
    return index;
}

/// @brief 
/// @param index 
/// @return 
String Request::id(int index) {
    int i = IndexCheck(index);
    return _sensorData.id[i];
}

/// @brief 
/// @param index 
/// @return 
String Request::name(int index) {
    int i = IndexCheck(index);
    return _sensorData.name[i];
}

/// @brief 
/// @param index 
/// @return 
String Request::pin(int index) {
    int i = IndexCheck(index);
    return _sensorData.pin[i];
}

/// @brief 
/// @param index 
/// @return 
String Request::value(int index) {
    int i = IndexCheck(index);
    return _sensorData.value[i];
}

/// @brief 
/// @param index 
/// @return 
String Request::description(int index) {
    int i = IndexCheck(index);
    return _sensorData.description[i];
}

/// @brief 
void Request::test() {
    Serial.println(_req);
}

/// @brief 
void Request::setTest() {
    String payload = "{\"Sensor\":[" + _res + "]}";
    Serial.println("Test");
    Serial.println(payload);
}