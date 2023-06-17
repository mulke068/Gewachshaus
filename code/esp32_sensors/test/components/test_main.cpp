#include <Arduino.h>
#include <Wlan.h>
#include <Request.h>
#include <config.h>
#include <variables.h>

#include <SPI.h>

#include "DHT.h"
#include "Adafruit_NeoPixel.h"
#include "MD_MAX72XX.h"

#define apiSettings DEF_SETTINGS
#define apiSensor   DEF_SENSOR

Wlan    wlan;
Request settings(uri, apiSettings);
Request sensor(uri, apiSensor);


DHT dht_1(DHTPIN_1, DHTTYPE_1);
DHT dht_2(DHTPIN_2, DHTTYPE_2);

Adafruit_NeoPixel neoPixel(NeoPixel_NUM,NeoPixel_PIN,NEO_GBR + NEO_KHZ800);

MD_MAX72XX matrix = MD_MAX72XX(MATRIX_HARDWARE_TYPE,MATRIX_DIN_PIN,MATRIX_CLK_PIN,MATRIX_CS_PIN,MATRIX_MAX_DEVICES);

bool setBuzzer = false;

void setup(void) {
  Serial.begin(115200);
  Serial.println("Starting up ...");
  // wlan.connect();
  dht_1.begin();
  dht_2.begin();
  neoPixel.begin();
  neoPixel.clear();
  matrix.begin();
  matrix.control(MD_MAX72XX::INTENSITY, 2);
  pinMode(Lufter_Low_Pin ,OUTPUT);
  pinMode(Lufter_High_Pin ,OUTPUT);	
  pinMode(Pumpe_Pin ,OUTPUT); 
  pinMode(Buzzer_Pin ,OUTPUT); 
  pinMode(soilMoisturePin_1, INPUT);
  pinMode(soilMoisturePin_2, INPUT);
}

void TEST_GET_Settings() {
  setBrightness     = 100;
  setLufter_Low     = false;
  setLufter_High    = true;
  setLight          = true;
  setPumpe          = false;
  setRgbLed         = "rgb(255,255,255)"; 
  setMatrixLed      = "Test Text";
}


int *rgb_String_To_Int(String rgb) {
  int startPos  = rgb.indexOf("(");
  int lastPos   = rgb.indexOf(")");
  
  String rgbValues = rgb.substring(startPos + 1, lastPos);
  
  int commaPos1 = rgbValues.indexOf(",");
  int commaPos2 = rgbValues.lastIndexOf(",");
  
  String r_String = rgbValues.substring(0 , commaPos1);
  String g_String = rgbValues.substring(commaPos1 + 1, commaPos2);
  String b_String = rgbValues.substring(commaPos2 + 1);

  static int rgbArray[3];
  rgbArray[0] = r_String.toInt();
  rgbArray[1] = g_String.toInt();
  rgbArray[2] = b_String.toInt();

  return rgbArray;
}

void scrollText(const char *p)
{
  uint8_t charWidth;
  uint8_t cBuf[8];  
 
  Serial.println("\nScrolling text");
  matrix.clear();
 
  while (*p != '\0')
  {
    charWidth = matrix.getChar(*p++, sizeof(cBuf) / sizeof(cBuf[0]), cBuf);
 
    for (uint8_t i=0; i<=charWidth; i++)  // allow space between characters
    {
      matrix.transform(MD_MAX72XX::TSL);
      if (i < charWidth)
        matrix.setColumn(0, cBuf[i]);
      delay(50);
    }
  }
}

void LufterSetOn(int lufter, bool state) {
	if(lufter == 0) {
		state ? digitalWrite(Lufter_Low_Pin, 0)/* ON */ : digitalWrite(Lufter_Low_Pin, 1); /* OFF */
	};
	if(lufter == 1) {
		state ? digitalWrite(Lufter_High_Pin, 0)/* ON */ : digitalWrite(Lufter_High_Pin, 1); /* OFF */
	};
};
	

void TemperatureSettings() {
	setLufter_High ? setLufter_Low = false : setLufter_High = false;
	setLufter_Low ? setLufter_High = false : setLufter_Low = false;
	setLufter_High ? LufterSetOn(1,true) : LufterSetOn(1,false);
	setLufter_Low ? LufterSetOn(0,true) : LufterSetOn(0,false);
}

void LightSettings() {
  int *rgbValues = rgb_String_To_Int(setRgbLed);
  if(setLight) {
    neoPixel.setBrightness(setBrightness);
    for(int i=0;i<NeoPixel_NUM;i++) {
      neoPixel.setPixelColor(i, rgbValues[0],rgbValues[1],rgbValues[2]);
      neoPixel.show();
    }
  } else {
    neoPixel.clear();
    neoPixel.show();
  };
}

void SoilMoistureSettings() {
	if(setPumpe) {
		digitalWrite(Pumpe_Pin, 0);
  	} else {
		digitalWrite(Pumpe_Pin, 1);
	};
}

void BuzzerON(int time) {
	if(setBuzzer) {
		digitalWrite(Buzzer_Pin, 1);
		delay(time);
		digitalWrite(Buzzer_Pin, 0);
	};
};

void MatrixLedSettings() {
  scrollText(setMatrixLed);
}

void loop(void) {
	Serial.println("----SETTINGS----");
 	TEST_GET_Settings();
  	Serial.println("----------------");
	// temperature_1 = dht_1.readTemperature();
	// humidity_1 = dht_1.readHumidity();
	if (isnan(temperature_1) || isnan(humidity_1)) {
		Serial.println("No DHT22 sensor connected");
	 };
	temperature_2 = dht_2.readTemperature();
	humidity_2 = dht_2.readHumidity();
	if (isnan(temperature_2) || isnan(humidity_2)) {
		Serial.println("No DHT11 sensor connected");
	 };
	soilMoisture_1 = analogRead(soilMoisturePin_1);
	soilMoisture_2 = analogRead(soilMoisturePin_2);
	// soilMoisture_1 = map(analogRead(soilMoisturePin_1), soilMoisture_Map_Min, soilMoisture_Map_Max, soilMoisture_Map_From, soilMoisture_Map_To);
	// soilMoisture_2 = map(analogRead(soilMoisturePin_2), soilMoisture_Map_Min, soilMoisture_Map_Max, soilMoisture_Map_From, soilMoisture_Map_To);
	Serial.print("1 | temperature : ");Serial.print(temperature_1);Serial.print(" humidity : ");Serial.println(humidity_1);
	Serial.print("2 | temperature : ");Serial.print(temperature_2);Serial.print(" humidity : ");Serial.println(humidity_2);
	Serial.print("1 | soil Moisture : ");Serial.println(soilMoisture_1);
	Serial.print("2 | soil Moisture : ");Serial.println(soilMoisture_2);

  	TemperatureSettings();
	SoilMoistureSettings();
  	LightSettings();
  	MatrixLedSettings();
	// BuzzerON(2000);
  
  	Serial.println("-----SENSOR----");
  	Serial.println("----------------");
  	delay(MINDelay);
}
