# ESP32 - Sensor

# Libraries

- [Wlan](lib/Wlan/README.md)
- [Request](lib/Request/README.md)

## PINS - Layout - ESP32_Sensor

|  Pin | Module                 | Name  |
|------|------------------------|-------|
|  32  | DHT22-1                | DATA  |
|  33  | DHT11-2                | DATA  |
|  25  | SoilMoisture-1         | DATA  |
|  26  | SoilMoisture-2         | DATA  |
|  23  | LedMatrix-1            | DIN   |
|  05  | LedMatrix-1            | CS    |
|  18  | LedMatrix-1            | CLK   |
|  27  | Buzzer                 | VCC   |
|  14  | RGBLed (NeoPixel)      | DIN   |
|  17  | Lüfter Relais (5V)     | IN    |
|  16  | Lüfter Relais (12V)    | IN    |
|  22  | Pumpe  Relais (12V)    | IN    |

## Data Structure

| Sensors           | Values    | Description               |
|-------------------|-----------|---------------------------|
| temperature_1     | float     | DHT 1                     |
| humanity_1        | float     | Cell                      |
| temperature_2     | float     | Cell                      |
| humanity_2        | float     | Cell                      |
| soilMoisture_1    | float     | Bodenfeuchtigkeit 1       |
| soilMoisture_2    | float     | Bodenfeuchtigkeit 2       |
| statusPumpe       | boolean   | Status der Pumpe          |
| statusLufter_Low  | boolean   | Status der Lüfter Low     |
| statusLufter_High | boolean   | Status der Lüfter High    |
| statusLight       | boolean   | Status of Light           |
| getRgbLed         | string    | Status der RGB LED        |

## Settings

| Name              | Values    | Description                                           |
|-------------------|-----------|-------------------------------------------------------|
| temperature_Min   | int       | Min - value for map                                   |
| temperature_Max   | int       | Max - Value for map                                   |
| soilMoisture_Min  | int       | Min - Value for map                                   |
| soilMoisture_Max  | int       | Max - Value for map                                   |
| setLufter_Low     | boolean   | lufter Low an oder aus                                |
| setLufter_High    | boolean   | lufter High an oder aus                               |
| setPumpe          | boolean   | pumpe an oder aus                                     |
| setLight          | boolean   | set Light on or off                                   |
| setBrightness     | int       | set brightness of led matrix(0-100)                   |
| setRgbLed         | string    | rgb led farbe                                         |
| setMatrixLed      | string    | Text anzeige für led matrix                           |

# Dependencies

- [PlatformIO Core](https://docs.platformio.org/en/latest/installation.html)
- [PlatformIO IDE](https://platformio.org/install/ide?install=vscode) (optional)

- [ArduinoJson](https://arduinojson.org/)
- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library)
- [Adafruit Unified Sensor](https://github.com/adafruit/Adafruit_Sensor)

# Usage

## Run build

```bash
pio run
```

## Upload firmware

```bash
pio run --target upload
```

## Run tests

```bash
pio test -e native
```

## Run tests with coverage and HTML report

```bash
pio test -e native --coverage --coverage-html
```

# Use Github Actions
<https://piolabs.com/blog/insights/unit-testing-part-3.html>


# License

       Copyright 2023 the original author or authors.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.


