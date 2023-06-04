#include <Adafruit_NeoPixel.h>

#define LEDPIXEL_PIN 15
#define LEDPIXEL_NUMPIXELS 16
#define LEDPIXEL_DELAYVAL 500

Adafruit_NeoPixel LedPixel(LEDPIXEL_NUMPIXELS,LEDPIXEL_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
    LedPixel.begin();
    LedPixel.clear();
}

void loop() {
    LedPixel.setBrightness(100);
    for(int i=0;i<LEDPIXEL_NUMPIXELS;i++) {
        LedPixel.setPixelColor(i, LedPixel.Color(100,100,100));
    
        LedPixel.show();
    }
}