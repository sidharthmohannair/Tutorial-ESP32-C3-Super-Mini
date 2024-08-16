# Tutorial: ESP32-C3 Super Mini

Welcome to the comprehensive guide for the ESP32-C3 Super Mini board. This repository includes everything you need to get started and work with the ESP32-C3 Super Mini.

## Table of Contents
1. [Introduction](#introduction)
2. [Board Specifications](#board-specifications)
3. [Pinout Diagram](#pinout-diagram)
4. [Getting Started](#getting-started)
   - [Arduino IDE Setup](#arduino-ide-setup)
5. [Example Projects](#example-projects)
6. [Troubleshooting](#troubleshooting)
7. [Contributing](#contributing)
8. [License](#license)

## Introduction
The ESP32-C3 Super Mini is a compact development board based on the ESP32-C3 microcontroller, providing WiFi and Bluetooth connectivity. This guide covers the board's specifications, pinouts, and instructions for setting up and programming with the Arduino IDE.

## Board Specifications
- **Microcontroller**: ESP32-C3
- **Connectivity**: WiFi, Bluetooth
- **GPIO Pins**: 10 digital I/O, 2 analog inputs
- **Power Supply**: 5V via USB, 3.3V via onboard regulator
- **Flash Memory**: 4MB
- **Operating Voltage**: 3.3V

## Pinout Diagram
![Pinout Diagram Top](/images/esp32_c3_supermini_pinout_top.jpg)
![Pinout Diagram Bottom](/images/esp32_c3_supermini_pinout_bot.jpg)

## Getting Started

### Arduino IDE Setup
1. **Install the Arduino IDE** from [Arduino's official website](https://www.arduino.cc/en/software).
2. **Add ESP32 board support** to the Arduino IDE:
   - Open the Arduino IDE, go to File > Preferences.
   - In the "Additional Board Manager URLs" field, add: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
   - Go to Tools > Board > Board Manager, search for "ESP32", and install the latest version by Espressif Systems.
3. **Select the ESP32-C3 Super Mini** board from Tools > Board > ESP32 Arduino > ESP32C3 Dev Module.
4. **Connect the board** to your computer via USB.

## Example Projects
- **Blink LED**: A basic example to blink an LED.
  - Code: [blink.ino](examples/blink/blink.ino)
- **WiFi Scanner**: Scans and displays available WiFi networks.
  - Code: [wifi_scanner.ino](examples/wifi_scanner/wifi_scanner.ino)
- **Bluetooth Beacon**: Sets up the board as a Bluetooth beacon.
  - Code: [bluetooth_beacon.ino](examples/bluetooth_beacon/bluetooth_beacon.ino)

## Troubleshooting
- **Common Issues**:
  - Ensure the correct board and port are selected in the Arduino IDE.
  - Check the USB connection and try different cables if necessary.
  - Install the latest drivers for your operating system.
- **Further Resources**:
  - [ESP32 Troubleshooting Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/troubleshooting.html)

## Contributing
Contributions are welcome! Please fork this repository and submit a pull request with your improvements. Follow the [contributing guidelines](CONTRIBUTING.md).

## References

- [ESP32 C3 Super Mini Deatailed Board Summery](https://www.sudo.is/docs/esphome/boards/esp32c3supermini/#enter-bootloader-mode-to-program-over-usb)

- [Espressif datasheets](https://www.espressif.com/en/support/documents/technical-documents)

- [platformio/espressif32 boards](https://registry.platformio.org/platforms/platformio/espressif32/boards)

- [ESPHome: ESP32 Platform](https://esphome.io/components/esp32)

- [ESPHome: (ESP32 platform): ESP-IDF Framework](https://esphome.io/components/esp32.html#esp-idf-framework)

- [esp32_c3_datasheet.pdf](https://www.sudo.is/docs/esphome/boards/esp32c3/esp32_c3_datasheet.pdf)



## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

