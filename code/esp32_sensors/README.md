
# ESP32 - Sensor


## Libraries

- [Wlan](/lib/Wlan/README.md)
- [Request](/lib/Request/README.md)


## PINS - Layout - ESP32_Sensor

|  Pin | Module         | Name  |
|------|----------------|-------|
|  32  | DHT1           | DATA  |
|  33  | DHT2           | DATA  |
|  25  | SoilMoisture1  | DATA  |
|  26  | SoilMoisture2  | DATA  |
|  23  | LedMatrix      | DIN   |
|  05  | LedMatrix      | CS    |
|  18  | LedMatrix      | CLK   |
|  17  | Buzzer         | VCC   |
2x lüfter
pwm -> ?


## Data Structure

| Sensors           | Values    | Description         |
|-------------------|-----------|---------------------|
| temperature_1     | float     | DHT 1               |
| humanity_1        | float     | Cell                |
| temperature_2     | float     | Cell                |
| humanity_2        | float     | Cell                |
| soilMoisture_1    | float     | Bodenfeuchtigkeit   |
| soilMoisture_2    | float     | Cell                |
| statusPumpe       | boolean   | Status der Pumpe    |
| statusLufter_1    | boolean   | Status der Lüfter 1 |
| statusLufter_2    | boolean   | Status der Lüfter 2 |
| statusRgbLed      | boolean   | Status der RGB LED  |

## Settings

| Name              | Values    | Description                                           |
|-------------------|-----------|-------------------------------------------------------|
| soilMoisture_Min  | int       | Min - Value for map                                   |
| soilMoisture_Max  | int       | Max - Value for map                                   |
| bewasserung_Min   | int       | ab vie viel prozent bodenfeuctigkeit es muss haben    |
| ledMatrix         | string    | Text anzeige für led matrix                           |
| lufterSet_1       | boolean   | lufter 1 an oder aus                                  |
| lufterSet_2       | boolean   | lufter 2 an oder aus                                  |
| pumpeSet          | boolean   | pumpe an oder aus                                     |
| rgbLed            | string    | rgb led farbe                                         |
