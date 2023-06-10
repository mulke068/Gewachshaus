/**
 * @file Request.cpp
 * @author mulke068 (kevbchef@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <Request.h>

/// @brief 
/// @param url
/// @param type
Request::Request(String url, uint8_t type) : get(*this), set(*this) {
    _url  = url;
    _type = type;
}

/// @brief In case of a Crash
Request::~Request() {
    return;
}

/**
 * @brief GET Request 
 * 
 * @return int 
 */
int Request::start() {
    int http_code = -1;
    HTTPClient http;
    http.addHeader("Content-Type", "application/json");
    switch (_type) {
    case DEF_SETTINGS:
        http.begin(_url + "/settings");
        http_code = http.GET();
        if (http_code >= 200 && http_code < 300) {
            _req = http.getString();
            storeSettings();
        }
        break;
    case DEF_SENSOR:
        http.begin(_url + "/sensor");
        http_code = http.GET();
        if (http_code >= 200 && http_code < 300) {
            _req = http.getString();
            storeSensor();
        };
        break;
    };
    http.end();
    return http_code;
}

/**
 * @brief POST Request 
 * 
 * @param response  true = print HTTP Response
 * @return int 
 */
int Request::post(bool response) {
    int     http_code = -1;
    String  req;
    HTTPClient http;
    switch (_type) {
    case DEF_SETTINGS:
        sendSettings();
        http.begin(_url + "/settings");
        http.addHeader("Content-Type", "application/json");
        http_code = http.sendRequest("PATCH", _res);
        req       = http.getString();
        break;
    case DEF_SENSOR:
        sendSensor();
        http.begin(_url + "/sensor");
        http.addHeader("Content-Type", "application/json");
        http_code = http.sendRequest("POST", _res);
        req       = http.getString();
        break;
    };
    if (http_code < 200 || http_code >= 300) {
        Serial.println("UPLOAD ERROR");
    };
    http.end();
    if(response) { Serial.println(req); };
    return http_code;
}

/**
 * @brief END Request // Clear all Data
 * 
 */
void Request::end() {
    _req = "";
    _res = "";
    _doc.clear();
}

void Request::storeSettings() {
    StaticJsonDocument<0> filter;
    filter.set(true);
    //StaticJsonDocument<192> _doc;
    DeserializationError error = deserializeJson(_doc, _req, DeserializationOption::Filter(filter));
    if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.c_str());
        return;
    }
    _settingsData.temperature_Min   = _doc["temperature_Min"];
    _settingsData.temperature_Avg   = _doc["temperature_Avg"];
    _settingsData.temperature_Max   = _doc["temperature_Max"];
    _settingsData.soilMoisture_Min  = _doc["soilMoisture_Min"];
    _settingsData.soilMoisture_Max  = _doc["soilMoisture_Max"];
    _settingsData.setBrightness     = _doc["setBrightness"];
    _settingsData.setLufter_1       = _doc["setLufter_1"];
    _settingsData.setLufter_2       = _doc["setLufter_2"];
    _settingsData.setPumpe          = _doc["setPumpe"];
    _settingsData.setLight          = _doc["setLight"];
    _settingsData.setRgbLed         = _doc["setRgbLed"];
    _settingsData.setMatrixLed      = _doc["setMatrixLed"];
}

void Request::storeSensor() {
    StaticJsonDocument<0> filter;
    filter.set(true);
    //StaticJsonDocument<192> _doc;
    DeserializationError error = deserializeJson(_doc, _req, DeserializationOption::Filter(filter));
    if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
    }
    _sensorData.temperature_1   = _doc["temperature_1"];
    _sensorData.humidity_1      = _doc["humidity_1"];
    _sensorData.temperature_2   = _doc["temperature_2"];
    _sensorData.humidity_2      = _doc["humidity_2"];
    _sensorData.soilMoisture_1  = _doc["soilMoisture_1"];
    _sensorData.soilMoisture_2  = _doc["soilMoisture_2"];
    _sensorData.statusPumpe     = _doc["statusPumpe"];
    _sensorData.statusLufter_1  = _doc["statusLufter_1"];
    _sensorData.statusLufter_2  = _doc["statusLufter_2"];
    _sensorData.statusLight     = _doc["statusLight"];
    _sensorData.getRgbLed       = _doc["getRgbLed"];
}

/*
void Request::sendSettings() {
    String payload = "{\"temperature_Min\":" + String(_settingsData.temperature_Min) + ",\"temperature_Avg\":" + String(_settingsData.temperature_Avg) + ",\"temperature_Max\":" + String(_settingsData.temperature_Max) + ",\"soilMoisture_Min\":" + String(_settingsData.soilMoisture_Min) + ",\"soilMoisture_Max\":" + String(_settingsData.soilMoisture_Max) + ",\"setLufter_1\":" + String(_settingsData.setLufter_1) + ",\"setLufter_2\":" + String(_settingsData.setLufter_2) + ",\"setPumpe\":" + String(_settingsData.setPumpe) + ",\"setLight\":" + String(_settingsData.setLight) + ",\"setRgbLed\":" + String(_settingsData.setRgbLed) + ",\"setMatrixLed\":" + String(_settingsData.setMatrixLed) + "}";
    _res = payload;
}

void Request::sendSensor() {
    String payload = "{\"temperature_1\":" + String(_sensorData.temperature_1) + ",\"humanity_1\":" + String(_sensorData.humanity_1) + ",\"temperature_2\":" + String(_sensorData.temperature_2) + ",\"humanity_2\":" + String(_sensorData.humanity_2) + ",\"soilMoisture_1\":" + String(_sensorData.soilMoisture_1) + ",\"soilMoisture_2\":" + String(_sensorData.soilMoisture_2) + ",\"statusPumpe\":" + String(_sensorData.statusPumpe) + ",\"statusLufter_1\":" + String(_sensorData.statusLufter_1) + ",\"statusLufter_2\":" + String(_sensorData.statusLufter_2) + ",\"statusLight\":" + String(_sensorData.statusLight) + ",\"getRgbLed\":" + String(_sensorData.getRgbLed) + "}";
    _res = payload;
}
*/

void Request::sendSettings() {
    StaticJsonDocument<256> doc;

    doc["temperature_Min"]  = _settingsData.temperature_Min;
    doc["temperature_Avg"]  = _settingsData.temperature_Avg;
    doc["temperature_Max"]  = _settingsData.temperature_Max;
    doc["soilMoisture_Min"] = _settingsData.soilMoisture_Min;
    doc["soilMoisture_Max"] = _settingsData.soilMoisture_Max;
    doc["setBrightness"]    = _settingsData.setBrightness;
    doc["setLufter_1"]      = _settingsData.setLufter_1;
    doc["setLufter_2"]      = _settingsData.setLufter_2;
    doc["setPumpe"]         = _settingsData.setPumpe;
    doc["setLight"]         = _settingsData.setLight;
    doc["setRgbLed"]        = _settingsData.setRgbLed;
    doc["setMatrixLed"]     = _settingsData.setMatrixLed;

    String payload;
    serializeJson(doc, payload); 
    _res = payload;
}

void Request::sendSensor() {
    StaticJsonDocument<256> doc;

    doc["temperature_1"]    = _sensorData.temperature_1;
    doc["humidity_1"]       = _sensorData.humidity_1;
    doc["temperature_2"]    = _sensorData.temperature_2;
    doc["humidity_2"]       = _sensorData.humidity_2;
    doc["soilMoisture_1"]   = _sensorData.soilMoisture_1;
    doc["soilMoisture_2"]   = _sensorData.soilMoisture_2;
    doc["statusPumpe"]      = _sensorData.statusPumpe;
    doc["statusLufter_1"]   = _sensorData.statusLufter_1;
    doc["statusLufter_2"]   = _sensorData.statusLufter_2;
    doc["statusLight"]      = _sensorData.statusLight;
    doc["getRgbLed"]        = _sensorData.getRgbLed;

    String payload;
    serializeJson(doc, payload); 
    _res = payload;
}

/**
 * @brief GET Test
 * 
 */
void Request::getTest() {
    Serial.println("GET Test");
    Serial.println(_req);
}

/**
 * @brief POST Test
 * 
 */
void Request::setTest() {
    Serial.println("POST Test: ");
    switch(_type) {
    case DEF_SETTINGS:
        sendSettings();
        Serial.println(_res);
        break;
        // [[fallthrough]]; // fällt eine case runter  
    case DEF_SENSOR:
        sendSensor();
        Serial.println(_res);
        break;
    };
}

// GET
/**
 * @brief Construct a new Request:: GET :: GET object
 * 
 * @param request 
 */
Request::GET::GET(Request& request)
    : _request(request), _settingsData(request._settingsData), _sensorData(request._sensorData) {};

// -------- SETTINGS --------

// @brief Get the temperature_Min object @return int 
int     Request::GET::temperature_Min()     { return _settingsData.temperature_Min; };
// @brief Get the temperature_Avg object @return int
int     Request::GET::temperature_Avg()     { return _settingsData.temperature_Avg; };
// @brief Get the temperature_Max object @return int
int     Request::GET::temperature_Max()     { return _settingsData.temperature_Max; };
// @brief Get the soilMoisture_Min object @return int
int     Request::GET::soilMoisture_Min()    { return _settingsData.soilMoisture_Min; };
// @brief Get the soilMoisture_Max object @return int
int     Request::GET::soilMoisture_Max()    { return _settingsData.soilMoisture_Max; };
// @brief Get the setBrightness object @return int
int     Request::GET::setBrightness()       { return _settingsData.setBrightness;   };
// @brief Get the setLufter_1 object @return bool
bool    Request::GET::setLufter_1()         { return _settingsData.setLufter_1; };
// @brief Get the setLufter_2 object @return bool
bool    Request::GET::setLufter_2()         { return _settingsData.setLufter_2; };
// @brief Get the setPumpe object @return bool
bool    Request::GET::setPumpe()            { return _settingsData.setPumpe; };
// @brief Get the setLight object @return bool
bool    Request::GET::setLight()            { return _settingsData.setLight; };
// @brief Get the setRgbLed object @return char
const char* Request::GET::setRgbLed()       { return _settingsData.setRgbLed; };
// @brief Get the setMatrixLed object @return char
const char* Request::GET::setMatrixLed()    { return _settingsData.setMatrixLed; };

// --------- SENSOR ---------

// @brief Get the temperature_1 object @return float
float   Request::GET::temperature_1()   { return _sensorData.temperature_1; };
// @brief Get the humanity_1 object @return float
float   Request::GET::humidity_1()      { return _sensorData.humidity_1; };
// @brief Get the temperature_2 object @return float
float   Request::GET::temperature_2()   { return _sensorData.temperature_2; };
// @brief Get the humanity_2 object @return float
float   Request::GET::humidity_2()      { return _sensorData.humidity_2; };
// @brief Get the soilMoisture_1 object @return float
float   Request::GET::soilMoisture_1()  { return _sensorData.soilMoisture_1; };
// @brief Get the soilMoisture_2 object @return float
float   Request::GET::soilMoisture_2()  { return _sensorData.soilMoisture_2; };
// @brief Get the statusPumpe object @return bool
bool    Request::GET::statusPumpe()     { return _sensorData.statusPumpe; };
// @brief Get the statusLufter_1 object @return bool
bool    Request::GET::statusLufter_1()  { return _sensorData.statusLufter_1; };
// @brief Get the statusLufter_2 object @return bool
bool    Request::GET::statusLufter_2()  { return _sensorData.statusLufter_2; };
// @brief Get the statusLight object @return bool
bool    Request::GET::statusLight()     { return _sensorData.statusLight; };
// @brief Get the getRgbLed object @return char
const char* Request::GET::getRgbLed()   { return _sensorData.getRgbLed; };

// SET
/**
 * @brief Construct a new Request:: SET :: SET object
 * 
 * @param request 
 */
Request::SET::SET(Request& request) 
    : _request(request), _settingsData(request._settingsData),_sensorData(request._sensorData) {};

// -------- SETTINGS --------

// @brief Set the temperature_Min object @param value @return int
int     Request::SET::temperature_Min(int value)            { return _settingsData.temperature_Min = value; };
// @brief Set the temperature_Avg object @param value @return int
int     Request::SET::temperature_Avg(int value)            { return _settingsData.temperature_Avg = value; };
// @brief Set the temperature_Max object @param value @return int
int     Request::SET::temperature_Max(int value)            { return _settingsData.temperature_Max = value; };
// @brief Set the soilMoisture_Min object @param value @return int
int     Request::SET::soilMoisture_Min(int value)           { return _settingsData.soilMoisture_Min = value; };
// @brief Set the soilMoisture_Max object @param value @return int
int     Request::SET::soilMoisture_Max(int value)           { return _settingsData.soilMoisture_Max = value; };
// @brief Set the setBrightness object @param value  @return int
int     Request::SET::setBrightness(int value)              { return _settingsData.setBrightness = value;   };
// @brief Set the setLufter_1 object @param value @return bool
bool    Request::SET::setLufter_1(bool value)               { return _settingsData.setLufter_1 = value; };
// @brief Set the setLufter_2 object @param value @return bool
bool    Request::SET::setLufter_2(bool value)               { return _settingsData.setLufter_2 = value; };
// @brief Set the setPumpe object @param value @return bool
bool    Request::SET::setPumpe(bool value)                  { return _settingsData.setPumpe = value; };
// @brief Set the setLight object @param value @return bool
bool    Request::SET::setLight(bool value)                  { return _settingsData.setLight = value; };
// @brief Set the setRgbLed object @param value @return char
const char* Request::SET::setRgbLed(const char* value)      { return _settingsData.setRgbLed = value; };
// @brief Set the setMatrixLed object @param value @return char
const char* Request::SET::setMatrixLed(const char* value)   { return _settingsData.setMatrixLed = value; };

// ---------- SENSOR ----------

// @brief Set the temperature_1 object @param value @return float
float   Request::SET::temperature_1(float value)        { return _sensorData.temperature_1 = value; };
// @brief Set the humanity_1 object @param value @return float
float   Request::SET::humidity_1(float value)           { return _sensorData.humidity_1 = value; };
// @brief Set the temperature_2 object @param value @return float
float   Request::SET::temperature_2(float value)        { return _sensorData.temperature_2 = value; };
// @brief Set the humanity_2 object @param value @return float
float   Request::SET::humidity_2(float value)           { return _sensorData.humidity_2 = value; };
// @brief Set the soilMoisture_1 object @param value @return float 
float   Request::SET::soilMoisture_1(float value)       { return _sensorData.soilMoisture_1 = value; };
// @brief Set the soilMoisture_2 object @param value @return float
float   Request::SET::soilMoisture_2(float value)       { return _sensorData.soilMoisture_2 = value; };
// @brief Set the statusPumpe object @param value @return bool
bool    Request::SET::statusPumpe(bool value)           { return _sensorData.statusPumpe = value; };
// @brief Set the statusLufter_1 object @param value @return bool
bool    Request::SET::statusLufter_1(bool value)        { return _sensorData.statusLufter_1 = value; };
// @brief Set the statusLufter_2 object @param value @return bool
bool    Request::SET::statusLufter_2(bool value)        { return _sensorData.statusLufter_2 = value; };
// @brief Set the statusLight object @param value @return bool
bool    Request::SET::statusLight(bool value)           { return _sensorData.statusLight = value; };
// @brief Set the getRgbLed object @param value @return char
const char* Request::SET::getRgbLed(const char* value)  { return _sensorData.getRgbLed = value; };
// inline const char* Request::SET::getRgbLed(const char* value) { return _sensorData.getRgbLed = value; } 