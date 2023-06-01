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
static const uint8_t DEF_SETTINGS{0}; // 0 = SETTINGS
static const uint8_t DEF_SENSOR{1};  // 1 = SENSOR
/**
 * @brief Struct for storing sensor data 
 * 
 */
struct SensorData {
    float temperature_1;
    float temperature_2;
    float humidity_1;
    float humidity_2;
    float soilMoisture_1;
    float soilMoisture_2;
    bool statusPumpe;
    bool statusLufter_1;
    bool statusLufter_2;
    bool statusLight;
    const char *getRgbLed;
};
/**
 * @brief Struct for storing settings data 
 * 
 */
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
    int post(bool response);
    void end();
    void setTest();
    void getTest();

    class GET {
    public:
        GET(Request& request);
        // SETTINGS
        
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
        // SENSOR

        float temperature_1();
        float humidity_1();
        float temperature_2();
        float humidity_2();
        float soilMoisture_1();
        float soilMoisture_2();
        bool statusPumpe();
        bool statusLufter_1();
        bool statusLufter_2();
        bool statusLight();
        const char* getRgbLed();
    private:
        Request& _request;
        SettingsData& _settingsData;
        SensorData& _sensorData;
    };
    class SET {
    public:
        SET(Request& request);
        // SETTINGS

        int temperature_Min(int value);
        int temperature_Avg(int value);
        int temperature_Max(int value);
        int soilMoisture_Min(int value);
        int soilMoisture_Max(int value);
        bool setLufter_1(bool value);
        bool setLufter_2(bool value);
        bool setPumpe(bool value);
        bool setLight(bool value);
        const char* setRgbLed(const char *value);
        const char* setMatrixLed(const char *value);
        // SENSOR

        float temperature_1(float value);
        float humidity_1(float value);
        float temperature_2(float value);
        float humidity_2(float value);
        float soilMoisture_1(float value);
        float soilMoisture_2(float value);
        bool statusPumpe(bool value);
        bool statusLufter_1(bool value);
        bool statusLufter_2(bool value);
        bool statusLight(bool value);
        const char* getRgbLed(const char *value);
    private:
        Request& _request;
        SettingsData& _settingsData;
        SensorData& _sensorData;
    };
    GET get;
    SET set;
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