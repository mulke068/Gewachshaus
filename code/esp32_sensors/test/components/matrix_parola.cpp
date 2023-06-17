#include <Arduino.h>

#include <SPI.h>
#include <MD_MAX72xx.h>
#include <MD_Parola.h>

// LED Matrix help
// https://lastminuteengineers.com/max7219-dot-matrix-arduino-tutorial/
// VCC  ->  5V
// GND  ->  GND
// DIN  ->  Pin 23 / 19
// CS   ->  Pin 5
// CLK  ->  Pin 18

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define DIN_PIN     23
#define CS_PIN      5
#define CLK_PIN     18

MD_Parola matrix = MD_Parola(HARDWARE_TYPE, DIN_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
    //Initialize serial and wait for port to open:
    Serial.begin(115200);
    matrix.begin();
    // matrix.displayScroll("Hello World!", PA_CENTER, PA_SCROLL_LEFT, 100);
    matrix.displayText("Hello, World!", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
}

void loop() {
    // Update the display
    if (matrix.displayAnimate()) {
    // If animation is completed, reset and display the text again
        matrix.displayReset();
        matrix.displayText("Hello, World!", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
    }

    delay(1000);
}