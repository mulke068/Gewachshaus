# Docuementation for the Request class


## Request Class

The Request class is used to handle the request from the client. It is used to get the request method, the request URI, the request body and the request headers.

### Methods

- [Request](#request)
- [get()](#get)
- [use()](#use)
- [post()](#post)
- [set()](#set)
- [end()](#end)

### Testing
- [setTest()](#setTest)
- [test()](#test)

## SensorData

- id[index]
- name[index]
- pin[index]
- value[index]
- description[index]


# Example

```cpp
#include <Request.h>

Request Object("http://localhost:80");

int index = 0;

Object.get();

String id = Object.id[index];
String name = Object.name[index];

Object.set("name", "pin", "value", "description", false);
Object.set("name", "pin", "value", "description", true);
Object.post();

Object.end();

```

# Expiation of Methods

## Request

- **Description:** This is the constructor for the Request class. It is used to create a new Request object.

- **Parameters:**
  
  - url : String - The url of the request

- **Example:**
    ```cpp
    Request object("http://localhost:80");
    ```

## get

- **Description:** This method is used to get the data from the request body.

- **Parameters:** None

- **Returns:** 

  - status : int - The HTTP status code

- **Example:**
    ```cpp
    object.get();
    ```


## post

- **Description:** This method is used to send the data from the request body.
 
- **Parameters:** None

- **Returns:**
  
  - status : int - The HTTP status code

- **Example:**
    ```cpp
    object.post();
    ```

## set

- **Description:** This method is used to set the data for the request body.

- **Parameters:** 
  
  - name        : String    - The name of the data
  - pin         : String    - The pin of the data
  - value       : String    - The value of the data
  - description : String    - The description of the data
  - last        : bool      - If the data is the last data

- **Returns:** None

- **Example:**
    ```cpp
    object.set("name", "pin", "value", "description", false);
    ```

## end

- **Description:** Is used to end the request and reset the request object.
- **Parameters:** None
- **Returns:** None
- **Example:**
    ```cpp
    object.end();
    ```