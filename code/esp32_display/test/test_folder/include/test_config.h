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

// Set your Static IP address
IPAddress ipv4(192, 168, 178, 55);
// Set your Gateway IP address
IPAddress gateway(192, 168, 178, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress DNS1(8, 8, 8, 8);
IPAddress DNS2(192, 168, 178, 1);

const byte mac[] = {0x78,0x21,0x84,0xE6,0x32,0x78};
const String hostname = "Display-ESP32";

const char* ssid = "FRITZ!Box 7490";
const char* password = "05767844606687810343";
const String api_url = "http://192.168.178.38:8080/display";

/*
PROGMEM const static char* root_ca = \
    "-----BEGIN CERTIFICATE-----\n" \
    "MIIFODCCBN6gAwIBAgIQDpPYv5WQwsfpP/P0gVWBgzAKBggqhkjOPQQDAjBKMQsw\n" \
    "CQYDVQQGEwJVUzEZMBcGA1UEChMQQ2xvdWRmbGFyZSwgSW5jLjEgMB4GA1UEAxMX\n" \
    "Q2xvdWRmbGFyZSBJbmMgRUNDIENBLTMwHhcNMjIwOTIxMDAwMDAwWhcNMjMwOTIx\n" \
    "MjM1OTU5WjB1MQswCQYDVQQGEwJVUzETMBEGA1UECBMKQ2FsaWZvcm5pYTEWMBQG\n" \
    "A1UEBxMNU2FuIEZyYW5jaXNjbzEZMBcGA1UEChMQQ2xvdWRmbGFyZSwgSW5jLjEe\n" \
    "MBwGA1UEAxMVc25pLmNsb3VkZmxhcmVzc2wuY29tMFkwEwYHKoZIzj0CAQYIKoZI\n" \
    "zj0DAQcDQgAEqbHA+RkgZssePl4hTgJWlKUbc6fGjKFQPVSUhpV1TYVAZ8ZiB95q\n" \
    "Cb3TR8nC/Fd04JHyz0GGAhH5iuTFywXDMaOCA3kwggN1MB8GA1UdIwQYMBaAFKXO\n" \
    "N+rrsHUOlGeItEX62SQQh5YfMB0GA1UdDgQWBBTMsoLVdW/mSSieOaHQSEFkz2bs\n" \
    "DjA+BgNVHREENzA1gg4qLmtldmJjaGVmLmNvbYIVc25pLmNsb3VkZmxhcmVzc2wu\n" \
    "Y29tggxrZXZiY2hlZi5jb20wDgYDVR0PAQH/BAQDAgeAMB0GA1UdJQQWMBQGCCsG\n" \
    "AQUFBwMBBggrBgEFBQcDAjB7BgNVHR8EdDByMDegNaAzhjFodHRwOi8vY3JsMy5k\n" \
    "aWdpY2VydC5jb20vQ2xvdWRmbGFyZUluY0VDQ0NBLTMuY3JsMDegNaAzhjFodHRw\n" \
    "Oi8vY3JsNC5kaWdpY2VydC5jb20vQ2xvdWRmbGFyZUluY0VDQ0NBLTMuY3JsMD4G\n" \
    "A1UdIAQ3MDUwMwYGZ4EMAQICMCkwJwYIKwYBBQUHAgEWG2h0dHA6Ly93d3cuZGln\n" \
    "aWNlcnQuY29tL0NQUzB2BggrBgEFBQcBAQRqMGgwJAYIKwYBBQUHMAGGGGh0dHA6\n" \
    "Ly9vY3NwLmRpZ2ljZXJ0LmNvbTBABggrBgEFBQcwAoY0aHR0cDovL2NhY2VydHMu\n" \
    "ZGlnaWNlcnQuY29tL0Nsb3VkZmxhcmVJbmNFQ0NDQS0zLmNydDAMBgNVHRMBAf8E\n" \
    "AjAAMIIBfwYKKwYBBAHWeQIEAgSCAW8EggFrAWkAdQDoPtDaPvUGNTLnVyi8iWvJ\n" \
    "A9PL0RFr7Otp4Xd9bQa9bgAAAYNdhTkhAAAEAwBGMEQCICGY+olYmcTEWzcCi5Qh\n" \
    "npmjTobzMo1Aq2VrfjQLgu2jAiAeEuiws/0ZqqqRDFuqwYdWvXmyMkRpwNvGEgBC\n" \
    "zfKp1wB3ADXPGRu/sWxXvw+tTG1Cy7u2JyAmUeo/4SrvqAPDO9ZMAAABg12FOWAA\n" \
    "AAQDAEgwRgIhALrLlU/w84i+UiocEBq2jHXJujOfjG9Lu1HGcvMxoup0AiEAj15w\n" \
    "3xHFVwVrNdslEiTUVdcz0c0k4TdA1NpJPTUKRD8AdwC3Pvsk35xNunXyOcW6WPRs\n" \
    "XfxCz3qfNcSeHQmBJe20mQAAAYNdhTlZAAAEAwBIMEYCIQDpYIz/BhLJc9WNGzQT\n" \
    "h2LnJB8F1pywJwGc4AQoCXsivQIhAMDIT/3dNuXULop4TBxx7+0lRp//E3Oy6/sP\n" \
    "xGKlxKQNMAoGCCqGSM49BAMCA0gAMEUCIQDexFllXbcUhCw2CJD9GytQUvKdqDQ9\n" \
    "WsIojKzOZBFL9gIgBnh09trDDtG/uYp20jbLHwVyMD4vaTnWI4SUgdKpTKk=\n" \
    "-----END CERTIFICATE-----\n";
*/

/*
const char* root_cert PROGMEM = \
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