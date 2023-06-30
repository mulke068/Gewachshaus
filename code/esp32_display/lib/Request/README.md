# Docuementation for the Request class

## Request Class

The Request class is used to handle the request from the client. It is used to get the request method, the request URI, the request body and the request headers.

### Methods

- [Request](#request)
- [get()](#get)
- [set()](#set)
- [post()](#post)
- [start()](#start)
- [end()](#end)

### Testing

- [getTest()](#gettest)
- [setTest()](#settest)

## SensorData

| Name | Type |
|------|------|
|temperature_1 | float|
|temperature_2 | float|
|humidity_1 | float|
|humidity_2 | float|
|soilMoisture_1 | float|
|soilMoisture_2 | float|
|statusPumpe | bool |
|statusLufter_Low | bool |
|statusLufter_High | bool |
|statusLight  | bool |
|getRgbLed | char |

## SettingsData

| Name | Type |
|------|------|
|temperature_Min | int |
|temperature_Avg | int |
|temperature_Max | int |
|soilMoisture_Min | int |
|soilMoisture_Max | int |
|setBrightness | int |
|setLufter_Low| bool |
|setLufter_High | bool |
|setPumpe | bool |
|setLight | bool |
|setRgbLed | char |
|setMatrixLed | char |

# Example

```cpp
#include <Request.h>
#define TYPE DEF_SENSOR

Request Object("http://localhost:80", TYPE);

Object.start();

Object.get.temperature_1();
Object.set.temperature_1(20.0);

Object.post(false);

Object.end();

```

# Expiation of Methods

## Request

- **Description:** This is the constructor for the Request class. It is used to create a new Request object.
- **Parameters:**
  
  - url : String - The url of the request
  - type : Define - The type of the request
    - DEF_SETTINGS || DEF_SENSOR

- **Returns:** None
- **Example:**

    ```cpp
    Request object("http://localhost:80", DEF_SETTINGS);
    ```

## start

- **Description:** This method is used to start the request.
- **Parameters:** None
- **Returns:**

  - status : int - The HTTP status code

- **Example:**

    ```cpp
    object.start();
    ```

## post

- **Description:** This method is used to send data to the server.
- **Parameters:**

  - response : bool - The response from the server

- **Returns:**

  - status : int - The HTTP status code

- **Example:**

    ```cpp
    object.post(false);
    // or
    object.post(true); // used for testing the response from the server
    ```

## end

- **Description:** Is used to end the request and reset the request object.
- **Parameters:** None
- **Returns:** None
- **Example:**

    ```cpp
    object.end();
    ```

## get

- **Description:** This method is used to get the data from the request body.
- **Parameters:** None
- **Returns:** None
- **Example:**

    ```cpp
    object.get();
    ```

### SensorData

- [SensorData](#sensordata)
- **Description:** This method is used to get the data from the request body.
- **Parameters:** None
- **Returns:**

  - value: int|bool|char|String - Variables from the SensorData struct

- **Example:**

    ```cpp
    object.get.temperature_1();
    ```

### SettingsData

- [SettingsData](#settingsdata)
- **Description:** This method is used to get the data from the request body.
- **Parameters:** None
- **Returns:**

  - value : int|bool|char|String - Variables from the SettingsData struct

- **Example:**

    ```cpp
    object.get.temperature_Min();
    ```

## set

- **Description:** This method is used to set the data for the request body.
- **Parameters:** None
- **Returns:** None
- **Example:**

    ```cpp
    object.set();
    ```

### SensorData

- [SensorData](#sensordata)
- **Description:** This method is used to set the data for the request body.
- **Parameters:**

  - value : int|bool|char|String - Set the variables from the SensorData struct

- **Returns:**

  - value : int|bool|char|String - Get the variables from the SensorData struct

- **Example:**

    ```cpp
    object.set.temperature_1(20.0);
    ```

### SettingsData

- [SettingsData](#settingsdata)
- **Description:** This method is used to set the data for the request body.
- **Parameters:**

  - value : int|bool|char|String - Set the variables from the SettingsData struct
- **Returns:**
  - value : int|bool|char|String - Get the variables from the SettingsData struct
- **Example:**

    ```cpp
    object.set.temperature_Min(20);
    ```

## getTest

- **Description:** This method is used to get the data from the request body.
- **Parameters:** None
- **Returns:** None
- **Example:**

    ```cpp
    object.getTest();
    ```

## setTest

- **Description:** This method is used to set the data for the request body.
- **Parameters:** None
- **Returns:** None
- **Example:**

    ```cpp
    object.setTest();
    ```


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

