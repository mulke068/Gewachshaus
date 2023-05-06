#ifndef Request_h
#define Request_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>

#include <config.h>

class Request {
    public:
        Request(String url);
        ~Request();
        void get();
        void post();
        void set(String name, String pin, String value, String description);
        void set(String name, String pin,String value, String description, boolean last);
        void end();
        void test();
        // 
        const char* request_id;
        const char* request_unique_id;
        const char* request_created_at;
        const char* request_timestamp;
        const char* request_unique_id;
        //
        const char* request_sensor_id;
        const char* request_sensor_name;
        const char* request_sensor_pin;
        const char* request_sensor_value;
        const char* request_sensor_description;
    private:
        String _url = "";
        String _req = "";
        String _res = "";
        void deserializeData();
};

#endif