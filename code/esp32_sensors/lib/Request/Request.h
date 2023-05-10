#ifndef Request_h
#define Request_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>

#include <config.h>

struct SensorData {
    static const size_t maxArray = 10;
    const char* id[maxArray];
    const char* name[maxArray];
    const char* pin[maxArray];
    const char* value[maxArray];
    const char* description[maxArray];

    // 
    const char* request_id; // @mulke068 @bug don't output the right value
    const char* request_unique_id;
    const char* request_created_at;
    const char* request_timestamp;
    const char* request_version; // @mulke068 @bug don't output the right value
};
class Request {
    public:
        Request(String url);
        ~Request();
        int get();
        Request& use() {return *this; } // dummy function
        int post();
        void set(String name, String pin, String value, String description);
        void set(String name, String pin,String value, String description, boolean last);
        void setTest();
        void end();
        void test();
        //
        String id(int index);
        String name(int index);
        String pin(int index);
        String value(int index);
        String description(int index);
    private:
        SensorData _sensorData;
        String _url = "";
        String _req = "";
        String _res = "";
        void storeData();
};

#endif