# Documentation for the Wlan Library

## Description

This library is used to connect to a WLAN network. In a easy way that you don't have to worry about the connection.

## Config File

The config file is used to set the WLAN network credentials. The config file is located in the `lib/Wlan/config.h` file.

```cpp
#define WLAN_SSID "ssid"
#define WLAN_PASSWORD "password"
```

## Functions

### declaration

- **Description:** This method is used to declare the Wlan object.
- **Parameters:** None
- **Returns:** None
- **Example:**
    ```cpp
    Wlan object;
    ```

### connect

- **Description:** This method is used to connect to a WLAN network.
- **Parameters:** 
  - ssid     : String - The SSID of the WLAN network
  - password : String - The password of the WLAN network
- **Returns:** None
- **Example:**
    ```cpp
    object.connect("ssid", "password");
    ```
### disconnect

- **Description:** This method is used to disconnect from a WLAN network.
- **Parameters:** None
- **Returns:** None
- **Example:**
    ```cpp
    object.disconnect();
    ```

### reconnect

- **Description:** This method is used to reconnect to a WLAN network.
- **Parameters:** None
- **Returns:** None
- **Example:**
    ```cpp
    object.reconnect();
    ```