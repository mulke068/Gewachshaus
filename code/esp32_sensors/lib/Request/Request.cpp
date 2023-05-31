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
    _url = url;
    _type = type;
}

/// @brief In case of a Crash
Request::~Request() {
    return;
}

int Request::start() {
    int http_code;
    HTTPClient http;
    http.addHeader("Content-Type", "application/json");
    switch (_type) {
    case DEF_SETTINGS:
        http.begin(_url + "/settings");
        http_code = http.GET();
        if (http_code <= 200) {
            _req = http.getString();
            // Serial.println("HTTP response : " + _req);
            storeSettings();
        };
        break;
    case DEF_SENSOR:
        http.begin(_url + "/sensor");
        http_code = http.GET();
        if (http_code <= 200) {
            _req = http.getString();
            // Serial.println("HTTP response : " + _req);
            storeSensor();
        };
        break;
    };
    return http_code;
    http.end();
}

int Request::post() {
    int http_code;
    HTTPClient http;
    http.addHeader("Content-Type", "application/json");
    switch (_type) {
    case DEF_SETTINGS:
        sendSettings();
        http.begin(_url + "/settings");
        http_code = http.PATCH(_res);
        if (http_code >= 202) {
            Serial.println("PATCH ERROR");
        };
        break;
    case DEF_SENSOR:
        sendSensor();
        http.begin(_url + "/sensor");
        http_code = http.POST(_res);
        if (http_code >= 201) {
            Serial.println("POST ERROR");
        };
        break;
    };
    return http_code;
    http.end();
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
    _settingsData.temperature_Min = _doc["temperature_Min"];
    _settingsData.temperature_Avg = _doc["temperature_Avg"];
    _settingsData.temperature_Max = _doc["temperature_Max"];
    _settingsData.soilMoisture_Min = _doc["soilMoisture_Min"];
    _settingsData.soilMoisture_Max = _doc["soilMoisture_Max"];
    _settingsData.setLufter_1 = _doc["setLufter_1"];
    _settingsData.setLufter_2 = _doc["setLufter_2"];
    _settingsData.setPumpe = _doc["setPumpe"];
    _settingsData.setLight = _doc["setLight"];
    _settingsData.setRgbLed = _doc["setRgbLed"];
    _settingsData.setMatrixLed = _doc["setMatrixLed"];
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
    _sensorData.temperature_1 = _doc["temperature_1"];
    _sensorData.humanity_1 = _doc["humanity_1"];
    _sensorData.temperature_2 = _doc["temperature_2"];
    _sensorData.humanity_2 = _doc["humanity_2"];
    _sensorData.soilMoisture_1 = _doc["soilMoisture_1"];
    _sensorData.soilMoisture_2 = _doc["soilMoisture_2"];
    _sensorData.statusPumpe = _doc["statusPumpe"];
    _sensorData.statusLufter_1 = _doc["statusLufter_1"];
    _sensorData.statusLufter_2 = _doc["statusLufter_2"];
    _sensorData.statusLight = _doc["statusLight"];
    _sensorData.getRgbLed = _doc["getRgbLed"];
}

void Request::sendSettings() {
    String payload = "{\"temperature_Min\":" + String(_settingsData.temperature_Min) + ",\"temperature_Avg\":" + String(_settingsData.temperature_Avg) + ",\"temperature_Max\":" + String(_settingsData.temperature_Max) + ",\"soilMoisture_Min\":" + String(_settingsData.soilMoisture_Min) + ",\"soilMoisture_Max\":" + String(_settingsData.soilMoisture_Max) + ",\"setLufter_1\":" + String(_settingsData.setLufter_1) + ",\"setLufter_2\":" + String(_settingsData.setLufter_2) + ",\"setPumpe\":" + String(_settingsData.setPumpe) + ",\"setLight\":" + String(_settingsData.setLight) + ",\"setRgbLed\":" + String(_settingsData.setRgbLed) + ",\"setMatrixLed\":" + String(_settingsData.setMatrixLed) + "}";
    _res = payload;
}

void Request::sendSensor() {
    String payload = "{\"temperature_1\":" + String(_sensorData.temperature_1) + ",\"humanity_1\":" + String(_sensorData.humanity_1) + ",\"temperature_2\":" + String(_sensorData.temperature_2) + ",\"humanity_2\":" + String(_sensorData.humanity_2) + ",\"soilMoisture_1\":" + String(_sensorData.soilMoisture_1) + ",\"soilMoisture_2\":" + String(_sensorData.soilMoisture_2) + ",\"statusPumpe\":" + String(_sensorData.statusPumpe) + ",\"statusLufter_1\":" + String(_sensorData.statusLufter_1) + ",\"statusLufter_2\":" + String(_sensorData.statusLufter_2) + ",\"statusLight\":" + String(_sensorData.statusLight) + ",\"getRgbLed\":" + String(_sensorData.getRgbLed) + "}";
    _res = payload;
}

void Request::end() {
    _req = "";
    _res = "";
    _doc.clear();
}

void Request::getTest() {
    Serial.println("GET Test");
    Serial.println(_req);
}

void Request::setTest() {
    switch(_type) {
        case DEF_SETTINGS:
            sendSettings();
            Serial.println("POST Test");
            Serial.println(_res);
        case DEF_SENSOR:
            sendSensor();
            Serial.println("POST Test");
            Serial.println(_res);
    };
}

// GET
Request::GET::GET(Request& request) : _request(request), _settingsData(request._settingsData) {};

int Request::GET::temperature_Min() {
    return _settingsData.temperature_Min;
};

int Request::GET::temperature_Avg() {
    return _settingsData.temperature_Avg;
};

int Request::GET::temperature_Max() {
    return _settingsData.temperature_Max;
};

int Request::GET::soilMoisture_Min() {
    return _settingsData.soilMoisture_Min;
};

int Request::GET::soilMoisture_Max() {
    return _settingsData.soilMoisture_Max;
};

bool Request::GET::setLufter_1() {
    return _settingsData.setLufter_1;
};

bool Request::GET::setLufter_2() {
    return _settingsData.setLufter_2;
};

bool Request::GET::setPumpe() {
    return _settingsData.setPumpe;
};

bool Request::GET::setLight() {
    return _settingsData.setLight;
};

const char* Request::GET::setRgbLed() {
    return _settingsData.setRgbLed;
};

const char* Request::GET::setMatrixLed() {
    return _settingsData.setMatrixLed;
};

// SET 
Request::SET::SET(Request& request) : _request(request), _sensorData(request._sensorData) {};

float Request::SET::temperature_1(float value) {
    _sensorData.temperature_1 = value;
    return _sensorData.temperature_1;
};

float Request::SET::humanity_1(float value) {
    _sensorData.humanity_2 = value;
    return _sensorData.humanity_2;
};

float Request::SET::temperature_2(float value) {
    _sensorData.temperature_2 = value;
    return _sensorData.temperature_2;
};

float Request::SET::humanity_2(float value) {
    _sensorData.humanity_2 = value;
    return _sensorData.humanity_2;
};

float Request::SET::soilMoisture_1(float value) {
    _sensorData.soilMoisture_1 = value;
    return _sensorData.soilMoisture_1;
};

float Request::SET::soilMoisture_2(float value) {
    _sensorData.soilMoisture_2 = value;
    return _sensorData.soilMoisture_2;
};

bool Request::SET::statusPumpe(bool value) {
    _sensorData.statusPumpe = value;
    return _sensorData.statusPumpe;
};

bool Request::SET::statusLufter_1(bool value) {
    _sensorData.statusLufter_1 = value;
    return _sensorData.statusLufter_1;
};

bool Request::SET::statusLufter_2(bool value) {
    _sensorData.statusLufter_2 = value;
    return _sensorData.statusLufter_2;
};

bool Request::SET::statusLight(bool value) {
    _sensorData.statusLight = value;
    return _sensorData.statusLight;
};

const char* Request::SET::getRgbLed(const char* value) {
    _sensorData.getRgbLed = value;
    return _sensorData.getRgbLed;
};
