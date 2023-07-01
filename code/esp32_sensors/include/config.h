const char* uri = "http://192.168.178.38:8080";//"http://192.0.0.20:8080";//"http://192.0.0.21:8080";
// STANDARD SETTINGS
#define MINDelay 3000

// DHT help
// https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/
// VCC  -> 3.3V 
// GND  -> GND
// DATA -> PIN (21 / 22) 
#define DHTPIN_1  	21 // Digital pin connected to the DHT sensor
#define DHTPIN_2  	22 // Digital pin connected to the DHT sensor
#define DHTTYPE_1	DHT22 // DHT 22  (AM2302), AM2321
#define DHTTYPE_2	DHT11

// Capacitive Soil Moisture Sensor help
// https://media.digikey.com/pdf/data%20sheets/dfrobot%20pdfs/sen0193_web.pdf
// VCC    -> 5V
// GND    -> GND
// DATA   -> Pin (25 / 26) 
// 2006.0 = 100%
// 4095.0 = 0%
const int soilMoisturePin_1 = 32;// 25
const int soilMoisturePin_2 = 33;// 26
const int soilMoisture_Map_Min = 2006;
const int soilMoisture_Map_Max = 4095;
const int soilMoisture_Map_From = 0;
const int soilMoisture_Map_To = 100;

// Adafruit Neo Pixel Ring help
// https://www.adafruit.com/product/1463
// VCC    -> 3.3V  	- WHITE 
// GND    -> GND 	- BROWN
// DIN    -> 14		- BLUE
// DOUT   -> NONE
#define NeoPixel_NUM 16
#define NeoPixel_PIN 14

// LED Matrix help
// https://lastminuteengineers.com/max7219-dot-matrix-arduino-tutorial/
// VCC -> 3.3V 	- RED
// GND -> GND	- BLUE
// DIN -> 19	- YELLOW
// CS  -> 5	- GRAY
// CLK -> 18	- VIOLET
#define MATRIX_HARDWARE_TYPE 	MD_MAX72XX::FC16_HW
#define MATRIX_MAX_DEVICES 	4
#define MATRIX_DIN_PIN 		19
#define MATRIX_CS_PIN		5
#define MATRIX_CLK_PIN		18


// Lüfter Relais 
// VCC -> 3.3V
// GND -> GND
const int Lufter_Low_Pin 	= 17; // 5V  GREEN
const int Lufter_High_Pin 	= 16; // 12V VIOLET

// Pumpe Relais
// VCC -> 3.3V
// GND -> GND
const int Pumpe_Pin = 4; // 12V GRAY

// Buzzer VCC
// VCC -> 27
// GND -> GND
const int Buzzer_Pin = 27; // YELLOW

// SYSTEM USE
const int SIDO 		= 5;  //SDIO
const int BOOT 		= 0;  //BOOT
const int LOG  		= 15; //LOG
const int VDD_FLASH	= 12; //VDD_FLASH
