#include <Arduino.h>
#include <Wlan.h>
#include <Request.h>
#include <config.h>
#include <variables.h>

#include <SPI.h>

#include "DHT.h"
#include "Adafruit_NeoPixel.h"

#define apiSettings DEF_SETTINGS
#define apiSensor   DEF_SENSOR

Wlan    wlan;
Request settings(uri, apiSettings);
Request sensor(uri, apiSensor);


DHT dht_1(DHTPIN_1, DHTTYPE22);
DHT dht_2(DHTPIN_2, DHTTYPE11);

Adafruit_NeoPixel neoPixel(NeoPixel_NUM,NeoPixel_PIN,NEO_GBR + NEO_KHZ800);

void setup(void) {
  Serial.begin(115200);
  Serial.println("Starting up ...");
  // wlan.connect();
  dht_1.begin();
  dht_2.begin();
  neoPixel.begin();
  neoPixel.clear();
}

void TEST_GET_Settings() {
	int randint   = random(1,100);
  temperature_Min   = randint;
  temperature_Avg   = randint; 
  temperature_Max   = randint; 
  soilMoisture_Min  = randint;
  soilMoisture_Max  = randint; 
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

void TemperatureSettings() {
  humidity_1      = dht_1.readHumidity();
  humidity_2      = dht_2.readHumidity();
  temperature_1   = dht_1.readTemperature();
  temperature_2   = dht_2.readTemperature();
  if (isnan(humidity_1) || isnan(temperature_1)) {
    Serial.println("Failed to read from DHT 1 sensor!");
    return;
  }
  if (isnan(humidity_2) || isnan(temperature_2)) {
    Serial.println("Failed to read from DHT 2 sensor!");
    return;
  }
  if(setLufter_Low) {
  	if(setLufter_High) {
    		if(temperature_2 <= temperature_Min) {} // läfter off 0 %
    		if(temperature_2 <= temperature_Avg) {} // lüfter on 50 %
	    	if(temperature_2 >= temperature_Max) {} // lüfter on 100 %
  	} else {
    		if(temperature_1 <= temperature_Min) {} // läfter off 0 %
    		if(temperature_1 <= temperature_Avg) {} // lüfter on 50 %
    		if(temperature_1 >= temperature_Max) {} // lüfter on 100 %
	};
  };
}

void LightSettings() {
  int *rgbValues = rgb_String_To_Int(setRgbLed);
  if(setLight) {
    neoPixel.setBrightness(100);
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
    int soilMoisture_1_value  = analogRead(soilMoisturePin_1);
    int soilMoisture_2_value  = analogRead(soilMoisturePin_2);
    soilMoisture_1 = map(soilMoisture_1_value, soilMoisture_Map_Min, soilMoisture_Map_Max, soilMoisture_Map_From, soilMoisture_Map_To);
    soilMoisture_2 = map(soilMoisture_2_value, soilMoisture_Map_Min, soilMoisture_Map_Max, soilMoisture_Map_From, soilMoisture_Map_To);
    if((soilMoisture_1 || soilMoisture_2) <= soilMoisture_Min) {} // Pumepe ON
    if((soilMoisture_1 && soilMoisture_2) >= soilMoisture_Max) {} // Pumpe OFF
  };
}

void MatrixLedSettings() {
  String text_displayed = setMatrixLed;
}


void loop(void) {
  Serial.println("----SETTINGS----");
 	TEST_GET_Settings();
  Serial.println("----------------");

  //TemperatureSettings();
  SoilMoistureSettings();
  LightSettings();
  // MatrixLedSettings();
  
  Serial.println("-----SENSOR----");
  Serial.println("----------------");
  delay(MINDelay);
}
