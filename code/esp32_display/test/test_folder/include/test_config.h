// CONFIG

// ---- DATA
char output[768];
#define min_delay 1
// ---- PINS

#define RX 2
#define TX 1
#define D1 8
#define D0 7
#define CLK 6
#define CMD 11
#define D3 10
#define D2 9
#define VN 39
#define VP 36
#define EN EN

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

// ----- API & W-Lan
const char* ssid = "FRITZ!Box 7490";
const char* password = "05767844606687810343";
const char* api_url = /*"https://api.kevbchef.com";*/ "http://34.159.6.21:8080";


// Error when using api.kevbchef.com
/*
httpclient 
[ 4048][E][ssl_client.cpp:37] _handle_error(): [start_ssl_client():278]: (-30592) SSL - A fatal alert message was received from our peer
[ 4050][E][WiFiClientSecure.cpp:135] connect(): start_ssl_client: -30592
*/
/*
const char* client_cert = \
    "-----BEGIN CERTIFICATE-----\n" \
    "MIIEFTCCAv2gAwIBAgIUQsEuZ5CJxrxXE1Wa/y2NZbTognwwDQYJKoZIhvcNAQEL\n" \
    "BQAwgagxCzAJBgNVBAYTAlVTMRMwEQYDVQQIEwpDYWxpZm9ybmlhMRYwFAYDVQQH\n" \
    "Ew1TYW4gRnJhbmNpc2NvMRkwFwYDVQQKExBDbG91ZGZsYXJlLCBJbmMuMRswGQYD\n" \
    "VQQLExJ3d3cuY2xvdWRmbGFyZS5jb20xNDAyBgNVBAMTK01hbmFnZWQgQ0EgZGE2\n" \
    "YzNmMTA2NGViYTIxZTE0ZGM2MWRmNmUyMDBjZmUwHhcNMjMwNDA4MjI1MTAwWhcN\n" \
    "MzMwNDA1MjI1MTAwWjAiMQswCQYDVQQGEwJVUzETMBEGA1UEAxMKQ2xvdWRmbGFy\n" \
    "ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAOm2+hmVAzOBG8DRQebr\n" \
    "e3g8EK7N/Pi1ynR1/eKUOZF287kXhdvC9o7cFc2/66PM0dB+aaY7ABFKhhb5YpS5\n" \
    "ok1wZ7ikOKW5hMIn4U8WRTAy4JK97AN6gh3hBHG/2CXKpNFtoJ0sLW4hp8loXgFu\n" \
    "soTMZRS9T7tGVltVZ4nSgoJoU2S3Ycbf19+RLVYXSWRivjgEaTtbmFy8GD1PKyL3\n" \
    "U3Zu1SoJV2kXBjcblHGoccZQCGx2KQZ/ip+dWfezj9M8pOkywYQdC1eZuy7CHgNo\n" \
    "F6SGJkz1oa7WMDAhJwcIJuB/DbGofIzE5ldzLhCtXyEaHv/888hM3q6+4cxw8ZYh\n" \
    "qfMCAwEAAaOBuzCBuDATBgNVHSUEDDAKBggrBgEFBQcDAjAMBgNVHRMBAf8EAjAA\n" \
    "MB0GA1UdDgQWBBQbH+Gd5LlyS5dWOJ2ZGjsDkFvIcjAfBgNVHSMEGDAWgBTF1gPk\n" \
    "iwMoTwbTmAKZafFlgU1uPDBTBgNVHR8ETDBKMEigRqBEhkJodHRwOi8vY3JsLmNs\n" \
    "b3VkZmxhcmUuY29tLzc4ZjVjMDc3LTFmZDktNDljMy1iNzU3LTRjMDYzODcwZTU2\n" \
    "Mi5jcmwwDQYJKoZIhvcNAQELBQADggEBAH2FeZSAD6ndgn+4swMb2zlgbSZKCpY5\n" \
    "V8UkY5X1KcrXi0XTjAFKOyKbfhTtlthFfH+EVdaUnvx12XSNb/rTi73Um7LCvH+0\n" \
    "TYcE7AenURcBIIWBHmh+DY4AQ43DAWCgb03nBMXGG6ewR+vLhGC9IyFKgxFU8MY8\n" \
    "NxhJPYZ3OARt9Fnyv71dllkDhhRSQvyIZWF7hFKou2VvE18f5QM0iAPJXMRd0aDQ\n" \
    "grc9M7Qz6ZT2YhUsSFJXlg8FZHLhjDz6pA6OaxSDqar2nnSke/HcgTwckFDPk/T1\n" \
    "J3XGbzYix5xEZnzpk3AdyQVIXJszQ7PmROcc8rYbWoAMj2dcF03LVnY=\n" \
    "-----END CERTIFICATE-----\n";
*/