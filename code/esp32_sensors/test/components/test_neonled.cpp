#include <Request.h>
#include <Wlan.h>

#include <Adafruit_NeoPixel.h>


#define LEDPIXEL_PIN 15
#define LEDPIXEL_NUMPIXELS 16
#define LEDPIXEL_DELAYVAL 500

Adafruit_NeoPixel LedPixel(LEDPIXEL_NUMPIXELS,LEDPIXEL_PIN, NEO_GRB + NEO_KHZ800);

Wlan wlan;

Request settings("http://192.168.178.38:3030", DEF_SETTINGS);
void setup() {
    Serial.begin(115200);
    wlan.connect();
    LedPixel.begin();
    LedPixel.clear();
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

void LightSettings() {
    int *rgbValues = rgb_String_To_Int(settings.get.setRgbLed());
    if(settings.get.setLight()) {
        LedPixel.setBrightness(settings.get.setBrightness());
        for(int i=0;i<LEDPIXEL_NUMPIXELS;i++) {
            LedPixel.setPixelColor(i, rgbValues[0],rgbValues[1],rgbValues[2]);
            LedPixel.show();
        }
    } else {
        LedPixel.clear();
        LedPixel.show();
    };
}

void loop() {
    settings.start();
    LightSettings();
    settings.end();
    delay(1000);
}