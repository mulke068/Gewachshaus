const char* uri = "http://192.0.0.23:8080"; // http://192.168.178.38:3030
// STANDARD SETTINGS
#define MINDelay 3000

// DHT help
// https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/
// VCC  -> 3.3V or 5V
// GND  -> GND
// DATA -> PIN (27 / 14) WITH 10K RESISTOR
#define DHTPIN_1  	32    // Digital pin connected to the DHT sensor
#define DHTPIN_2  	33    // Digital pin connected to the DHT sensor
#define DHTTYPE22   	DHT22 // DHT 22  (AM2302), AM2321
#define DHTTYPE11	DHT11

// Capacitive Soil Moisture Sensor help
// https://media.digikey.com/pdf/data%20sheets/dfrobot%20pdfs/sen0193_web.pdf
// VCC    -> 5V
// GND    -> GND
// DATA   -> Pin (25 / 26) 
// 2006.0 = 100%
// 4095.0 = 0%
const int soilMoisturePin_1 = 25;// 25
const int soilMoisturePin_2 = 26;// 26
const int soilMoisture_Map_Min = 2006;
const int soilMoisture_Map_Max = 4095;
const int soilMoisture_Map_From = 0;
const int soilMoisture_Map_To = 100;

// Adafruit Neo Pixel Ring help
// https://www.adafruit.com/product/1463
// VCC    -> 5V
// GND    -> GND
// DIN    -> 16 
// DOUT   -> NONE
#define NeoPixel_NUM 16
#define NeoPixel_PIN 14

// LED Matrix help
// https://lastminuteengineers.com/max7219-dot-matrix-arduino-tutorial/
// VCC -> 5V
// GND -> GND
// DIN -> 19
// CS  -> 5
// CLK -> 18
#define MATRIX_HARDWARE_TYPE 	MD_MAX72XX::FC16_HW
#define MATRIX_MAX_DEVICES 	4
#define MATRIX_DIN_PIN 		19
#define MATRIX_CS_PIN		5
#define MATRIX_CLK_PIN		18


// Lüfter Relais 
const int Lufter_Low_Pin 	= 17; // 5V 
const int Lufter_High_Pin 	= 16; // 12V

// Pumpe Relais
const int Pumpe_Pin = 4; // 12V

// Buzzer VCC
const int Buzzer_Pin = 27;

// SYSTEM USE
const int SIDO 		= 5;  //SDIO
const int BOOT 		= 0;  //BOOT
const int LOG  		= 15; //LOG
const int VDD_FLASH	= 12; //VDD_FLASH
