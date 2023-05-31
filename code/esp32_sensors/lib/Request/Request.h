/**
 * @file Request.h
 * @author mulke068 (kevbchef@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-05-28
 *
 * @copyright Copyright (c) 2023
 *
 */
// USED TO STOP LIBRARY FROM BEING INCLUDED MORE THAN ONCE
#ifndef Request_h
#define Request_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>

// TYPES DEIFNITION
static const uint8_t DEF_SETTINGS{0};
static const uint8_t DEF_SENSOR{1};
// STRUCTS
struct SensorData {
    float temperature_1;
    float temperature_2;
    float humanity_1;
    float humanity_2;
    float soilMoisture_1;
    float soilMoisture_2;
    bool statusPumpe;
    bool statusLufter_1;
    bool statusLufter_2;
    bool statusLight;
    const char *getRgbLed;
};
struct SettingsData {
    int temperature_Min;
    int temperature_Avg;
    int temperature_Max;
    int soilMoisture_Min;
    int soilMoisture_Max;
    bool setLufter_1;
    bool setLufter_2;
    bool setPumpe;
    bool setLight;
    const char *setRgbLed;
    const char *setMatrixLed;
};

class Request {
public:
    Request(String url, uint8_t type);
    virtual ~Request();
    int start();
    int post();
    // void set();
    void end();
    // TEST
    void setTest();
    void getTest();

    class GET {
    public:
        GET(Request& request);
        int temperature_Min();
        int temperature_Avg();
        int temperature_Max();
        int soilMoisture_Min();
        int soilMoisture_Max();
        bool setLufter_1();
        bool setLufter_2();
        bool setPumpe();
        bool setLight();
        const char* setRgbLed();
        const char* setMatrixLed();

    private:
        Request& _request;
        SettingsData& _settingsData;
    };
    class SET {
    public:
        SET(Request& request);
        float temperature_1(float value);
        float humanity_1(float value);
        float temperature_2(float value);
        float humanity_2(float value);
        float soilMoisture_1(float value);
        float soilMoisture_2(float value);
        bool statusPumpe(bool value);
        bool statusLufter_1(bool value);
        bool statusLufter_2(bool value);
        bool statusLight(bool value);
        const char* getRgbLed(const char *value);

    private:
        Request& _request;
        SensorData& _sensorData;
    };

    GET get;
    SET set;

    /*
    class USE {
    public:
        // SETTINGS
        int temperature_Min_GET();
        int temperature_Min_SET(int temperature_Min);
    private:
        // REFERENCE TO REQUEST CLASS
        Request& _request;
        SensorData& _sensorData;
        SettingsData& _settingsData;
        // DONT ASK ME WHY BUT IT WORKS
        USE(Request& request) : _request(request), _sensorData(request._sensorData), _settingsData(request._settingsData) {};
        // SHARE PRIVATE MEMBERS
        friend class Request;
    };
    // INITIALISE USE CLASS to Request use
    USE use;
    */
protected:
    // DOCUMENTS
    StaticJsonDocument<700> _doc;
    SensorData _sensorData;
    SettingsData _settingsData;

private:
    // DEFINED TYPES
    uint8_t _type;
    String _url, _req, _res;
    // STORED DATA
    void storeSettings();
    void storeSensor();
    void sendSettings();
    void sendSensor();
};

#endif