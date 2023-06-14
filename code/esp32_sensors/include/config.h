const char* uri = "http://192.0.0.23:8080"; // http://192.168.178.38:3030
// STANDARD SETTINGS
#define MINDelay 3000

// DHT help
// https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/
// VCC  -> 3.3V or 5V
// GND  -> GND
// DATA -> PIN (27 / 14) WITH 10K RESISTOR
#define DHTPIN_1  	27    // Digital pin connected to the DHT sensor
#define DHTPIN_2  	14    // Digital pin connected to the DHT sensor
#define DHTTYPE22   	DHT22 // DHT 22  (AM2302), AM2321
#define DHTTYPE11	DHT11

// Capacitive Soil Moisture Sensor help
// https://media.digikey.com/pdf/data%20sheets/dfrobot%20pdfs/sen0193_web.pdf
// VCC    -> 5V
// GND    -> GND
// DATA   -> Pin 23 
// 2006.0 = 100%
// 4095.0 = 0%
const int soilMoisturePin_1 = 25;//12 // 25
const int soilMoisturePin_2 = 26;//13 // 26
const int soilMoisture_Map_Min = 2006;
const int soilMoisture_Map_Max = 4095;
const int soilMoisture_Map_From = 0;
const int soilMoisture_Map_To = 100;

// Adafruit Neo Pixel Ring help
// https://www.adafruit.com/product/1463
// VCC    -> 5V
// GND    -> GND
// DIN    -> 15
// DOUT   -> NONE
#define NeoPixel_NUM 16
#define NeoPixel_PIN 15
