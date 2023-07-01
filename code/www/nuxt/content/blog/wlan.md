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

### status

- **Description:** This method is used to get the status of the WLAN connection.
- **Parameters:** None
- **Returns:**  

  - 255 - WL_NO_SHIELD: Arduino WiFi Shield 101 or MKR1000 board not present
  - 0 - WL_IDLE_STATUS: Wi-Fi is in process of changing between statuses
  - 1 - WL_NO_SSID_AVAIL: In case of connection failure due to incorrect credentials or no APs are found
  - 2 - WL_SCAN_COMPLETED: scanNetworks() has completed
  - 3 - WL_CONNECTED: Assigned when connected to a WiFi network
  - 4 - WL_CONNECT_FAILED: Assigned when failed to connect to a WiFi network
  - 5 - WL_CONNECTION_LOST: Assigned when disconnected from a WiFi network
  - 6 - WL_DISCONNECTED: Assigned when disconnected from a WiFi network
  - 7 - WL_AP_LISTENING: Assigned when the device is acting as an access point and is listening for connections (valid for WiFi101 / MKR1000 only)
  - 8 - WL_AP_CONNECTED: Assigned when a station is connected to the device acting as an access point (valid for WiFi101 / MKR1000 only)
  - 9 - WL_AP_FAILED: Assigned when the access point fails (valid for WiFi101 / MKR1000 only)
  - 10 - WL_PROVISIONING: Assigned when the device is provisioning Wi-Fi credentials (valid for WiFi101-ABGN / MKR1000 only)
  - 11 - WL_PROVISIONING_FAILED: Assigned when the device fails to provision Wi-Fi credentials (valid for WiFi101-ABGN / MKR1000 only)
  - 12 - WL_PROVISIONING_AP_NOT_FOUND: Assigned when the device fails to connect to the network created by the provisioner (valid for WiFi101-ABGN / MKR1000 only)
  - 13 - WL_PROVISIONING_CONNECTION_LOST: Assigned when the device loses connection to the network created by the provisioner (valid for WiFi101-ABGN / MKR1000 only)
  - 14 - WL_PROVISIONING_TIMEOUT: Assigned when the device times out while waiting for the provisioner to configure it (valid for WiFi101-ABGN / MKR1000 only)
  - 15 - WL_PROVISIONING_SUCCESS: Assigned when the device has been successfully provisioned (valid for WiFi101-ABGN / MKR1000 only)
  - 16 - WL_DISCONNECTING: Assigned when disconnect() is called to disconnect from the network
  - 17 - WL_GOT_IP: Assigned when connected and has a valid IP address
  - 18 - WL_NO_MODULE: Assigned when no WiFi module is present
  - 19 - WL_COULD_NOT_SET_MODE: Assigned when the specified mode (WiFi mode, network mode, etc.) could not be set
  - 20 - WL_WRONG_PASSWORD: Assigned when the password is invalid for the network
  - 21 - WL_DISCONNECTED: Assigned when disconnected from a network
  - 22 - WL_DHCP_TIMEOUT: Assigned when the DHCP timed out
  - 23 - WL_FAILED_DHCP: Assigned when the DHCP failed
  - 24 - WL_INVALID_MAC_ADDRESS: Assigned when the MAC address is invalid

- **Example:**

    ```cpp
    object.status();
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


