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

void setup(void) {
  Serial.begin(115200);
  Serial.println("Starting up ...");
//  wlan.connect();
  dht_1.begin();
  dht_2.begin();
  neoPixel.begin();
  neoPixel.clear();
  matrix.begin();
  pinMode(Lufter_Low_Pin ,OUTPUT);
  pinMode(Lufter_High_Pin ,OUTPUT);	
  pinMode(Pumpe_Pin ,OUTPUT); 
  pinMode(Buzzer_Pin ,OUTPUT); 
  pinMode(soilMoisturePin_1, INPUT);
  pinMode(soilMoisturePin_2, INPUT);
  digitalWrite(Lufter_Low_Pin, 1);
  digitalWrite(Lufter_High_Pin, 1);
  digitalWrite(Pumpe_Pin, 1);
  digitalWrite(Buzzer_Pin, 0);
};

int POST_Sensor() {
  sensor.set.temperature_1(temperature_1);
  sensor.set.temperature_2(temperature_2);
  sensor.set.humidity_1(humidity_1);
  sensor.set.humidity_2(humidity_2);
  sensor.set.soilMoisture_1(soilMoisture_1);
  sensor.set.soilMoisture_2(soilMoisture_2);
  sensor.set.statusPumpe(statusPumpe);
  sensor.set.statusLufter_Low(statusLufter_Low);
  sensor.set.statusLufter_High(statusLufter_High);
  sensor.set.statusLight(statusLight);
  int http_code = sensor.post(false);
  if(http_code < 200 || http_code >= 300) {
    Serial.println("UpdateValues -> Error Code: " + String(http_code));
  };
  return http_code;
};

void GET_Settings() {
    temperature_Min   = settings.get.temperature_Min();
    temperature_Avg   = settings.get.temperature_Avg();
    temperature_Max   = settings.get.temperature_Max();
    soilMoisture_Min  = settings.get.soilMoisture_Min();
    soilMoisture_Max  = settings.get.soilMoisture_Max();
    setLufter_Low     = settings.get.setLufter_Low();
    setLufter_High    = settings.get.setLufter_High();
    setLight          = settings.get.setLight();
    setPumpe          = settings.get.setPumpe();
    setRgbLed         = settings.get.setRgbLed();
    setMatrixLed      = settings.get.setMatrixLed();
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

void scrollText(const char *p) {
  uint8_t charWidth;
  uint8_t cBuf[8];  
 
  Serial.println("\nScrolling text");
  matrix.clear();
 
  while (*p != '\0') {
    charWidth = matrix.getChar(*p++, sizeof(cBuf) / sizeof(cBuf[0]), cBuf);
 
    for (uint8_t i=0; i<=charWidth; i++) { // allow space between characters
      	matrix.transform(MD_MAX72XX::TSL);
      	if (i < charWidth) { 
        	matrix.setColumn(0, cBuf[i]);
        	delay(50);
	};
    };
  };
};

void BuzzerON(int time) {
	if(setBuzzer) {
		digitalWrite(Buzzer_Pin, 1);
		delay(time);
		digitalWrite(Buzzer_Pin, 0);
	};
};

void LufterSet(int lufter, bool state) {
	if(lufter == 0) {
		if (setLufter_Low) {
			state ? digitalWrite(Lufter_Low_Pin, 0)/* ON */ : digitalWrite(Lufter_Low_Pin, 1); /* OFF */
			BuzzerON(200);
		} else {
			digitalWrite(Lufter_Low_Pin, 1);
		};
	};
	if(lufter == 1) {
		if (setLufter_High) {
			state ? digitalWrite(Lufter_High_Pin, 0)/* ON */ : digitalWrite(Lufter_High_Pin, 1); /* OFF */
			BuzzerON(200);
		} else {
			digitalWrite(Lufter_High_Pin, 1);
		};
	};
};

void TemperatureSettings() {
	temperature_1 = dht_1.readTemperature();
	humidity_1 = dht_1.readHumidity();
	if (isnan(temperature_1) || isnan(humidity_1)) {
		Serial.println("No DHT22 sensor connected");
	 };
	temperature_2 = dht_2.readTemperature();
	humidity_2 = dht_2.readHumidity();
	if (isnan(temperature_2) || isnan(humidity_2)) {
		Serial.println("No DHT11 sensor connected");
	 };
	Serial.println(" | Temperature | Humidity ");
	Serial.println("1| " + String(temperature_1) + "°C | " + String(humidity_1) + "%");
	Serial.println("2| " + String(temperature_2) + "°C | " + String(humidity_2) + "%");
	Serial.println("-------------------------");
	Serial.println(" | Name 	   | Var ");
	temperature_Min = 26;
	temperature_Avg = 26;
	temperature_Max = 27;
	Serial.println(" | temperature_Min |" + String(temperature_Min)); 
	Serial.println(" | temperature_Avg |" + String(temperature_Avg)); 
	Serial.println(" | temperature_Max |" + String(temperature_Max)); 
	Serial.println("-------------------------");
	if(temperature_1 >= temperature_Max || temperature_2 >= temperature_Max) {	// lüfter on 100 %
		Serial.println("Set Lufter 100%");
		LufterSet(0,false);
		delay(250);
		LufterSet(1,true);
	}
	else if (temperature_1 >= temperature_Avg || temperature_2 >= temperature_Avg) {	// lüfter on 50 %
		Serial.println("Set Lufter 50%");
		LufterSet(1,false);
		delay(250);
		LufterSet(0,true);
	}
	else if(temperature_1 <= temperature_Min || temperature_2 <= temperature_Min) {	// läfter off 0 %
		Serial.println("Set Lufter 0%");
		LufterSet(0,false);
		LufterSet(1,false);
	}
	else {
		Serial.println("TemperaturSettings | ERROR");
		LufterSet(0,false);
		LufterSet(1,false);
	};
};

void LightSettings() {
  int *rgbValues = rgb_String_To_Int(setRgbLed);
  if(setLight) {
    neoPixel.setBrightness(setBrightness);
    for(int i=0;i<NeoPixel_NUM;i++) {
      neoPixel.setPixelColor(i, rgbValues[0],rgbValues[1],rgbValues[2]);
      neoPixel.show();
    };
  } else {
    neoPixel.clear();
    neoPixel.show();
  };
};

void PumpeSet(bool value) {
	value ? digitalWrite(Pumpe_Pin,0) : digitalWrite(Pumpe_Pin,1);
};

void SoilMoistureSettings() {
	soilMoisture_1 = map(analogRead(soilMoisturePin_1), soilMoisture_Map_Min, soilMoisture_Map_Max, soilMoisture_Map_To, soilMoisture_Map_From);
	soilMoisture_2 = map(analogRead(soilMoisturePin_2), soilMoisture_Map_Min, soilMoisture_Map_Max, soilMoisture_Map_To, soilMoisture_Map_From);
	if(setPumpe) {
		if((soilMoisture_1 || soilMoisture_2) <= soilMoisture_Min) {PumpeSet(true);}; // Pumepe ON
    		if((soilMoisture_1 && soilMoisture_2) >= soilMoisture_Max) {PumpeSet(false);}; // Pumpe OFF
  	} else {
		PumpeSet(false);
	};
};

void MatrixLedSettings() {
  matrix.control(MD_MAX72XX::INTENSITY, setBrightness);
  scrollText(setMatrixLed);
};

void loop(void) {
 // if (wlan.status() == DISCONNECTED ) {
 //   wlan.reconnect();
 // }
  Serial.println("----SETTINGS----");
 // int settings_http_code = settings.start();
  Serial.println("HTTP Code: ");
  // Serial.println(settings_http_code);
  // if(settings_http_code < 200 || settings_http_code >= 300) {
    //Serial.println("GET_Settings -> Error Code: " + String(settings_http_code));
  // } else {
    //GET_Settings();
  //};
  //settings.end();
  Serial.println("----------------");

  Serial.println("TemperatureSettings | Start");
  TemperatureSettings();
  Serial.println("----------------");
  Serial.println("SoilMoistueSettings | Start");
  SoilMoistureSettings();
  Serial.println("----------------");
  Serial.println("LightSettings | Start");
  LightSettings();
  Serial.println("----------------");
  Serial.println("MatrixSettings | Start");
  MatrixLedSettings();
  Serial.println("----------------");
  
  Serial.println("-----SENSOR----");
  // int sensor_http_code = sensor.start();
  Serial.println("HTTP Code: ");
  // Serial.println(sensor_http_code);
  // if(sensor_http_code < 200 || sensor_http_code >= 300) {
    // Serial.println("POST_Sensor -> Error Code: " + String(sensor_http_code));
  // } else {
    Serial.println("POST Code: ");
   // Serial.println(POST_Sensor());
  //};
  //sensor.end();
  Serial.println("----------------");
  delay(MINDelay);
}
