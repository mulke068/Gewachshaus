// @ts-ignore
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>


int TextPrint(int size=0,char color="",int cursor_x=0,int cursor_y=0,char text=""){
  tft.setTextSize(size);
  tft.setTextColor(color);
  tft.setCursor(cursor_x,cursor_y);
  tft.print(text);
}