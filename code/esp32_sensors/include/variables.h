// SENSOR

float   temperature_1 		= 0.00;
float   humidity_1 		= 0.00;
float   temperature_2 		= 0.00;
float   humidity_2 		= 0.00;
float   soilMoisture_1 		= 0.00;
float   soilMoisture_2 		= 0.00;
bool    statusPumpe		= false;
bool    statusLufter_Low	= false;
bool    statusLufter_High	= false;
bool    statusLight		= true;
const char* getRgbLed		= "rgb(255,255,255)";

// SETTINGS

int 	temperature_Min 	= 15;
int 	temperature_Avg 	= 20;
int 	temperature_Max 	= 25;
int 	soilMoisture_Min 	= 40;
int 	soilMoisture_Max 	= 80;
int 	setBrightness 		= 100;
bool 	setBuzzer 		= true;
bool 	setLufter_Low 		= true;
bool 	setLufter_High 		= true;
bool 	setPumpe 		= false;
bool 	setLight 		= true;
const char* setRgbLed 		= "rgb(255,255,255)";
const char* setMatrixLed 	= "Lycee Prive Emile Metz";
