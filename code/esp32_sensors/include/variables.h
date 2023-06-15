// SENSOR

float   temperature_1;
float   humidity_1;
float   temperature_2;
float   humidity_2;
float   soilMoisture_1;
float   soilMoisture_2;
bool    statusPumpe;
bool    statusLufter_Low;
bool    statusLufter_High;
bool    statusLight;
const char* getRgbLed;

// SETTINGS

int temperature_Min = 20;
int temperature_Avg = 25;
int temperature_Max = 30;
int soilMoisture_Min = 40;
int soilMoisture_Max = 80;
int setBrightness = 100;
bool setLufter_Low = true;
bool setLufter_High = true;
bool setPumpe = true;
bool setLight = true;
const char* setRgbLed = "rgb(255,255,255)";
const char* setMatrixLed = "LPEM | NO WIFI Connection";
