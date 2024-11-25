# Tutorial: ESP32-C3 Super Mini

![cover image](/images/main.png)

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
8. [References](#references)
9. [License](#license)

## Introduction

![ESP32 supermini](/images/ESP32_supermini_intro.png)

The ESP32-C3 Super Mini is a compact development board based on the ESP32-C3 microcontroller, providing WiFi and Bluetooth connectivity. This guide covers the board's specifications, pinouts, and instructions for setting up and programming with the Arduino IDE.

## Board Specifications
- **Microcontroller**: ESP32-C3 FN4 (172023 P3L7730)
- **Connectivity**: WiFi (2.4 GHz b/g/n), Bluetooth (BLE 5)
- **Processor**:	32-bit RISC-V single-core
- **GPIO Pins**: 10 digital I/O, 2 analog inputs
- **Power Supply**: 5V via USB, 3.3V via onboard regulator
- **Flash Memory**: 4MB
- **Operating Voltage**: 3.3V

## Pinout Diagram
![ESP32 C3 super mini pinout](/images/pinout%20ESP32_supermini.jpg "ESP32 C3 super mini pinout")


## Interfaces

The ESP32-C3 series supports the following interfaces:

- **2x ADCs**: ADC1 (GPIO0-GPIO4), ADC2 (GPIO5, not usable with Wi-Fi enabled).
- **6x PWM channels**: Configurable on any GPIO pins.
- **2x UART**: Configurable on any GPIO pins.
- **1x I²C**: Configurable on any GPIO pins.
- **3x SPI**: SPI0 and SPI1 are reserved, SPI2 configurable on any GPIO pins.

## Pin Mappings

| Silkscreen Pin | Internal Pin | Notes                                   |
|----------------|--------------|-----------------------------------------|
| 0              | GPIO0        | ADC1                                    |
| 1              | GPIO1        | ADC1                                    |
| 2              | GPIO2        | ADC1, boot mode / strapping pin         |
| 3              | GPIO3        | ADC1                                    |
| 4              | GPIO4        | ADC1, JTAG                              |
| 5              | GPIO5        | JTAG                                    |
| 6              | GPIO6        | JTAG                                    |
| 7              | GPIO7        | JTAG                                    |
| 8              | GPIO8        | Blue status_led (inverted), boot mode / strapping pin   |
| 9              | GPIO9        | Boot mode / strapping pin, boot button                             |
| 10             | GPIO10       |                                         |
| 20             | GPIO20       |                                         |
| 21             | GPIO21       |                                         |

### Pin Notes

- GPIO8 has an inverted blue status LED.
- The BOOT button is wired to GPIO9.
- JTAG is available on GPIO4 to GPIO7.

# Getting Started

### Hardware Requirements

Before getting started, ensure you have the following components:

- **ESP32-C3 Super Mini**
- **Computer** (Windows, macOS, or Linux)
- **USB Type-C data cable**

> **Tip:** Some USB cables only provide power without data transfer capabilities. If you're unsure whether your cable supports data transfer, consider purchasing a Type-C cable specifically designed for this purpose.


### Arduino IDE Setup

### Step 1: Install the Arduino IDE

1. Download the latest version of the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).
    ![Arduino IDE](https://www.nologo.tech/assets/img/arduino/other/ArduinoIDE.png)

    > **Note:** If you're experiencing slow download speeds, consider using alternative download links provided by local Arduino communities.
2. Install the Arduino IDE following the instructions for your operating system.

### Optional Step: Install USB Drivers (Windows Only)
1. **Windows Users Only:** Before connecting your ESP32-C3 Super Mini, ensure that the necessary USB-to-serial drivers are installed. This is especially important for Windows users.

- You can download the CP210x or CH340 drivers from the official websites if your board uses one of these USB-to-UART bridge chips.
- **Note:** Most modern versions of Windows will install the drivers automatically when you first connect the device.

### Step 2: Configure the Arduino IDE for ESP32-C3 Super Mini

### I. Adding ESP32 Board Support

1. Open the Arduino IDE.
2. Navigate to **File > Preferences**.
3. In the "Additional Board Manager URLs" field, paste the following URL:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
      ![ESP32 super mini add board URL](/images/add_board.jpeg)
4. Click **OK** to save your preferences.

### II. Installing the ESP32 Board Package

1. Go to **Tools > Board > Board Manager**.
2. In the search bar, type "ESP32".

    ![ESP32 super mini add ESP32](/images/add_esp32c3.jpeg)

3. Locate **"ESP32 by Espressif Systems"** and click **Install** to add the board package.

### III. Selecting the ESP32-C3 Super Mini Board

1. After installation, navigate to **Tools > Board > ESP32 Arduino**.
2. Scroll down and select **ESP32C3 Dev Module**.

    ![ESP32 super mini add ESP32](/images/supermini_setup.png)

### Step 3: Set Up the Serial Port

1. Connect your ESP32-C3 Super Mini to the computer.

    ![ESP32 super mini USB connect](/images/usbconnect.jpeg)

2. Go to **Tools > Port** and select the corresponding serial port for your device. This will usually be **COM3** or higher on Windows, and `/dev/ttyUSBx` or `/dev/ttyACMx` on Linux/macOS. 

    ![ESP32 C3 Super Mini COM port](/images/com_port.png)

    **Optional: Enable USB CDC on Boot**
    If you are experiencing issues with serial communication or your device is not being recognized correctly after a reset, you can enable the "USB CDC on Boot" option:

    1. Go to Tools > USB CDC on Boot.
    2. Select Enabled.

   > **Note:** Enabling "USB CDC on Boot" allows the USB connection to remain active during boot, which can help resolve issues where the serial port is not detected after the ESP32-C3 restarts.

### Step 4: Verify the Setup

1. Open a new sketch in the Arduino IDE.
2. Add a simple example like the Blink sketch ([Blink Project](/docs/examples/Blink/README.md)).
3. Click **Upload** to send the sketch to your ESP32-C3.

If everything is set up correctly, the LED on the ESP32-C3 should start blinking, indicating that the upload was successful.

# Example Projects
- ## **Blink LED**: 
  **A basic example to blink an LED.**

  - Guide: [Blink Project](/docs/examples/Blink/README.md)
  - Code: [blink.ino](/docs/examples/Blink/Blink.ino)
- ## **ESP32 C3 Super Mini with DHT11**: 
  **Read DHT11 sensor to measure temperature and humidity.**

  - Guide: [ESP32 C3 Super Mini with DHT11](/docs/examples/ESP32_C3_Super_Mini_with_DHT11/README.md)
  - Code: [ESP32_C3_Super_Mini_with_DHT11.ino](/docs/examples/ESP32_C3_Super_Mini_with_DHT11/ESP32_C3_Super_Mini_with_DHT11.ino)
- ## **ESP32-C3 Super Mini with DHT11/DHT22 - Display Values Using Web Server**: 
  **To read temperature and humidity data from a DHT11/DHT22 sensor and display these values on a web server.**

  - Guide: [Read DHT11/DHT22 - Display Values Using Web Server](/docs/examples/ESP32_C3_Super_Mini_with_DHT11_webServer/README.md)
  - Code: [ESP32_C3_Super_Mini_with_DHT11_webServer.ino](/docs/examples/ESP32_C3_Super_Mini_with_DHT11_webServer/ESP32_C3_Super_Mini_with_DHT11_webServer.ino)

## Troubleshooting
- **Common Issues**:
  - If the port does not appear, try disconnecting and reconnecting the USB cable or using a different USB port.
  - Ensure that you are using a data-capable USB cable (some cables are power-only).
- **Reset the Board**:
  - If your ESP32-C3 does not respond after uploading a sketch, try manually resetting the board by pressing the reset button.
- **Use Serial Monitor**:
  - After uploading a sketch, open the Serial Monitor (`Tools > Serial Monitor`) to view any output. Make sure the baud rate is set to 115200 to match the `Serial.begin(115200);` statement in your code.
- **Further Resources**:
  - [ESP32 Troubleshooting Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/troubleshooting.html)

## Contributing
Contributions are welcome! Please fork this repository and submit a pull request with your improvements. Follow the [contributing guidelines](CONTRIBUTING.md).

## References

- [ESP32 C3 Super Mini Deatailed Board Summery](https://www.sudo.is/docs/esphome/boards/esp32c3supermini/#enter-bootloader-mode-to-program-over-usb)

- [wiki.icbbuy.com for setup](https://wiki.icbbuy.com/doku.php?id=developmentboard:esp32-c3mini#schematic)

- [Espressif datasheets](https://www.espressif.com/en/support/documents/technical-documents)

- [platformio/espressif32 boards](https://registry.platformio.org/platforms/platformio/espressif32/boards)

- [ESPHome: ESP32 Platform](https://esphome.io/components/esp32)

- [ESPHome: (ESP32 platform): ESP-IDF Framework](https://esphome.io/components/esp32.html#esp-idf-framework)

- [esp32_c3_datasheet.pdf](https://www.sudo.is/docs/esphome/boards/esp32c3/esp32_c3_datasheet.pdf)



## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

