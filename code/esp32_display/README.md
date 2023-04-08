# Dependencies

- [PlatformIO Core](https://docs.platformio.org/en/latest/installation.html)
- [PlatformIO IDE](https://platformio.org/install/ide?install=vscode) (optional)

- [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)
- [TFT_eWidgets](https://github.com/Bodmer/TFT_eWidget)
- [ArduinoJson](https://arduinojson.org/)

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