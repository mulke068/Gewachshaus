// CONFIG

// ---- PINS

// DISPLAY Pins
/*
    Vcc 3.3V
    LED 3.3V
    GND GND
    T_DO 19  // DataOUT Use Same Pin as MISO By Chip enable
    T_DIN 23 // DataInterScreen Is Connected Whit MOSI
    T_CLK 18 // CLOCK always chared whit the clock pin

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCK 18
#define TFT_CS   15 
#define TFT_DC    2  
#define TFT_RST   4
#define TOUCH_CS 21     // Chip select pin (T_CS) of touch screen
*/

// ---- COLORS
#define BLACK 0x0000
#define WHITE 0xFFFF
#define RED 0xF904
#define BLUE 0x211F
#define GREEN 0x1F80
#define LOGO_COLOR 0x29D1
#define BOX_COLOR 0x9CD3