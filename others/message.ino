#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

int upbutton = 10;
int selectbutton = 11;
int downbutton = 12;
int backbutton =13;
int Potentiometer =A0;
int Temp = A1;
int menu = 1;

byte Temperatur[] = {
  B00100,
  B01010,
  B01010,
  B01010,
  B01010,
  B10001,
  B01110,
  B00000
};

byte Feuchtigkeit[] = {
  B00000,
  B00100,
  B00100,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110
};

byte Grad[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte Lichteinfall[] = {
  B11100,
  B11000,
  B10000,
  B00010,
  B00111,
  B00111,
  B00101,
  B00111
};

byte Dimmen[] = {
  B11111,
  B01111,
  B00111,
  B00011,
  B11001,
  B00010,
  B00111,
  B00010
};

void setup(){
  lcd_1.begin(16, 2);
  pinMode(upbutton, INPUT_PULLUP);
  pinMode(selectbutton, INPUT_PULLUP);
  pinMode(downbutton, INPUT_PULLUP);
  pinMode(backbutton, INPUT_PULLUP);
  pinMode(Potentiometer, INPUT_PULLUP);
  pinMode(Temp, INPUT);
  updatemenu();
  Serial.begin(9600);
  
  
  
}

void loop() {

  if(!digitalRead(downbutton))
  {
    menu++;
    updatemenu();
    delay(100);
    while(!digitalRead(downbutton));
  }

  if(!digitalRead(upbutton))
  {
    menu--;
    updatemenu();
    delay(100);
    while(!digitalRead(upbutton));
  }
  
  if(!digitalRead(selectbutton))
  {
    executeAction();
    updatemenu();
    delay(100);
    while(!digitalRead(selectbutton));
    
    
  }
}

void updatemenu(){
  switch(menu){
    case 0:
      menu = 1;
      break;
    case 1:
      lcd_1.createChar(0, Temperatur);
      lcd_1.createChar(1, Feuchtigkeit);
      lcd_1.createChar(2, Grad);
      lcd_1.clear();
    
      lcd_1.setCursor(0,0);
      lcd_1.print(">IN: ");
      lcd_1.setCursor(6,0);
      lcd_1.write(0); lcd_1.print("24"); lcd_1.write(2);
      lcd_1.setCursor(11, 0);
      lcd_1.write(1); lcd_1.print("69%");
    
      lcd_1.setCursor(0,1);
      lcd_1.print(" OUT:");
      lcd_1.setCursor(6, 1);
      lcd_1.write(0); lcd_1.print("24"); lcd_1.write(2);
      lcd_1.setCursor(11, 1);
      lcd_1.write(1); lcd_1.print("69%");

      break;
    
    case 2:
      lcd_1.createChar(0, Temperatur);
      lcd_1.createChar(1, Feuchtigkeit);
      lcd_1.createChar(2, Grad);
      lcd_1.clear();
    
      lcd_1.setCursor(0,0);
      lcd_1.print(" IN: ");
      lcd_1.setCursor(6,0);
      lcd_1.write(0); lcd_1.print("24"); lcd_1.write(2);
      lcd_1.setCursor(11, 0);
      lcd_1.write(1); lcd_1.print("69%");
    
      lcd_1.setCursor(0,1);
      lcd_1.print(">OUT:");
      lcd_1.setCursor(6, 1);
      lcd_1.write(0); lcd_1.print("24"); lcd_1.write(2);
      lcd_1.setCursor(11, 1);
      lcd_1.write(1); lcd_1.print("69%");

      break;
    
    case 3:
      lcd_1.createChar(3, Lichteinfall);
      lcd_1.createChar(4, Dimmen);
      lcd_1.clear();
      lcd_1.write(3);
      lcd_1.print(">Lichteinfall");
    
      lcd_1.setCursor(0,1);
      lcd_1.write(4);
      lcd_1.print(" LED dimmen");
    
      break;
    
    case 4:
      lcd_1.clear();
      lcd_1.print(" Lichteinfall");
      lcd_1.setCursor(0,1);
      lcd_1.print(">LED dimmen");
      break;
    case 5:
    menu = 4;
    break;
  }
}

void executeAction(){
  switch(menu){
    case 1:
    	action1();
    	break;
    case 2:
    	action2();
    	break;
    case 3:
    	action3();
    	break;
    case 4:
    	action4();
    	break;
  }
}
    
void action1(){
  lcd_1.clear();
  lcd_1.print("Temp:");
  lcd_1.setCursor(0,1); lcd_1.print("Exit");

}
void action2(){
  lcd_1.clear();
  lcd_1.print("Feuchtigkeit:");
  lcd_1.setCursor(0,1); lcd_1.print("Exit");
  delay(1500);
}
void action3(){
  lcd_1.clear();
  lcd_1.print("Lichteinfall beträgt:");
  lcd_1.setCursor(0,1); lcd_1.print("Exit");
  delay(1500);
}
void action4(){
  lcd_1.clear();
  lcd_1.print("Helligkeit:");
  lcd_1.setCursor(0,1); lcd_1.print("Exit");
  delay(1500);
}