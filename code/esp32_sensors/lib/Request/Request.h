#ifndef Request_h
#define Request_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>

#include <config.h>

static const uint8_t DEF_SETTINGS{0};
static const uint8_t DEF_SENSOR{1};

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
    char* getRgbLed;
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
    char* setRgbLed;
    char* setMatrixLed;
};
class Request {
    public:
        Request(String url, uint8_t type);
        virtual ~Request();
        int get();
        Request& use() {return *this; } // dummy function
        int post();
        void set(String name, String pin, String value, String description);
        void set(String name, String pin,String value, String description, boolean last);
        void end();
        void setTest();
        void getTest();
        //
    private:
        SensorData _sensorData;
        uint8_t _type;
        String _url;
        String _req, _res;
};

#endif