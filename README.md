# **Tutorial: ESP32-C3 Super Mini**

![cover image](/images/main.png)

Welcome to the comprehensive guide for the ESP32-C3 Super Mini board. This repository includes everything you need to get started and work with the ESP32-C3 Super Mini.

---

## **Table of Contents**
1. [Introduction](#introduction)
2. [Board Specifications](#board-specifications)
3. [Pinout Diagram and Details](#pinout-diagram-and-details)
4. [Getting Started](#getting-started)
   - [Hardware Requirements](#hardware-requirements)
   - [Setting Up the Arduino IDE](#setting-up-the-arduino-ide)
5. [Supported Interfaces](#supported-interfaces)
6. [Example Projects](#example-projects)
7. [Troubleshooting](#troubleshooting)
8. [References](#references)
9. [License](#license)

---

## **Introduction**
![ESP32 Super Mini](/images/ESP32_supermini_intro.png)

The **ESP32-C3 Super Mini** is a compact and versatile development board powered by the **ESP32-C3** microcontroller. It offers robust Wi-Fi and Bluetooth Low Energy (BLE) connectivity, making it ideal for IoT, smart devices, and wireless sensor networks.

Key features include:
- Compact form factor with excellent GPIO access.
- **RISC-V single-core processor** for efficient performance.
- Comprehensive Wi-Fi and BLE 5.0 capabilities.

This guide will walk you through its setup, pinout, and how to create projects using the **Arduino IDE**.

---

## **Board Specifications**

| **Feature**           | **Details**                                               |
|------------------------|-----------------------------------------------------------|
| **Microcontroller**    | ESP32-C3 FN4 (RISC-V single-core processor @160 MHz)      |
| **Connectivity**       | Wi-Fi (2.4 GHz 802.11 b/g/n), BLE 5.0                     |
| **GPIO Pins**          | 10 Digital I/O, 2 Analog inputs                           |
| **ADC**                | 6 channels of 12-bit SAR ADC                              |
| **Flash Memory**       | 4MB                                                      |
| **Power Supply**       | 5V via USB-C, onboard 3.3V regulator                      |
| **Operating Voltage**  | 3.3V                                                     |
| **Dimensions**         | Ultra-compact, ideal for space-constrained applications   |

---

## **Pinout Diagram and Details**
![ESP32-C3 Super Mini Pinout](/images/pinout%20ESP32_supermini.jpg "ESP32 C3 Super Mini Pinout")


### **Pin Mappings**

| **Pin Name** | **GPIO** | **Function**                           |
|--------------|----------|----------------------------------------|
| 0            | GPIO0    | ADC1, PWM                             |
| 1            | GPIO1    | ADC1, PWM                             |
| 2            | GPIO2    | ADC1, Strapping Pin (Boot Mode)        |
| 3            | GPIO3    | ADC1, PWM                             |
| 4            | GPIO4    | JTAG, ADC1                            |
| 5            | GPIO5    | JTAG                                  |
| 8            | GPIO8    | Status LED (inverted), Strapping Pin  |
| 9            | GPIO9    | BOOT Button, Strapping Pin            |
| 10           | GPIO10   | PWM                                   |
| 20           | GPIO20   | General-purpose I/O                   |
| 21           | GPIO21   | General-purpose I/O                   |

### **Key Notes**:
- **GPIO8**: Connected to an inverted blue status LED.
- **GPIO9**: Connected to the BOOT button.
- **JTAG Support**: GPIO4–GPIO7 pins are reserved for debugging.

---

## **Getting Started**

### **Hardware Requirements**
To get started with the ESP32-C3 Super Mini, you’ll need:
- **ESP32-C3 Super Mini board**
- **Computer** (Windows, macOS, or Linux)
- **USB Type-C data cable** (ensure it supports data transfer, not just power)

### **Setting Up the Arduino IDE**

#### **1. Install the Arduino IDE**

1. Download the latest Arduino IDE from the [official website](https://www.arduino.cc/en/software).
    ![Arduino IDE](https://www.nologo.tech/assets/img/arduino/other/ArduinoIDE.png)
2. Follow the installation instructions for your operating system.

#### **2. Install USB Drivers (Windows Only)**
- For boards with CP210x or CH340 USB-to-UART bridge chips, install the respective drivers:
  - [CP210x Drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)
  - [CH340 Drivers](http://www.wch.cn/download/CH341SER_EXE.html)

#### **3. Add ESP32 Board Support**
1. Open the Arduino IDE and go to **File > Preferences**.
2. In the "Additional Board Manager URLs" field, add:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
    ![ESP32 super mini add board URL](/images/add_board.jpeg)
3. Click **OK** to save your preferences.
4. Go to **Tools > Board > Boards Manager**, search for "ESP32," and install the **ESP32 by Espressif Systems** package.
    ![ESP32 super mini add ESP32](/images/add_esp32c3.jpeg)

#### **4. Select the Board and Port**
1. Connect your ESP32-C3 Super Mini to the computer.

    ![ESP32 super mini USB connect](/images/usbconnect.jpeg)

2. Go to **Tools > Port** and select the corresponding serial port for your device. This will usually be **COM3** or higher on Windows, and `/dev/ttyUSBx` or `/dev/ttyACMx` on Linux/macOS. 

    ![ESP32 C3 Super Mini COM port](/images/com_port.png)

    **Optional: Enable USB CDC on Boot**
    If you are experiencing issues with serial communication or your device is not being recognized correctly after a reset, you can enable the "USB CDC on Boot" option:

    1. Go to Tools > USB CDC on Boot.
    2. Select Enabled.

   > **Note:** Enabling "USB CDC on Boot" allows the USB connection to remain active during boot, which can help resolve issues where the serial port is not detected after the ESP32-C3 restarts.

#### **5. Upload a Test Sketch**
1. Open a new sketch in the Arduino IDE.
2. Add a simple example like the Blink sketch ([Blink Project](/docs/examples/Blink/README.md)).
3. Click **Upload** to send the sketch to your ESP32-C3.

If everything is set up correctly, the LED on the ESP32-C3 should start blinking, indicating that the upload was successful.

---

## **Supported Interfaces**
The ESP32-C3 Super Mini supports a wide range of peripherals:

| **Interface**   | **Description**                                |
|------------------|-----------------------------------------------|
| **Wi-Fi**       | 2.4 GHz b/g/n, WPA3                           |
| **Bluetooth**   | BLE 5.0, long range                           |
| **UART**        | 2 interfaces                                  |
| **SPI**         | 3 interfaces (SPI0, SPI1 reserved)            |
| **I²C**         | Configurable on GPIO pins                     |
| **I²S**         | 1 interface (Full-duplex audio support)       |
| **PWM**         | Up to 6 channels                              |
| **ADC**         | 6 channels, 12-bit resolution                 |
| **JTAG**        | Debugging via GPIO4–GPIO7                     |

---

## **Example Projects**
 ### **1. Blink LED**: 

  **A basic example to blink an LED.**
  - Guide: [Blink Project](/docs/examples/Blink/README.md)
  - Code: [blink.ino](/docs/examples/Blink/Blink.ino)

### **2. ESP32 C3 Super Mini with DHT11/DHT22**: 

  **Read temperature and humidity using DHT11/DHT22.**
  - Guide: [ESP32 C3 Super Mini with DHT11](/docs/examples/ESP32_C3_Super_Mini_with_DHT11/README.md)
  - Code: [ESP32_C3_Super_Mini_with_DHT11.ino](/docs/examples/ESP32_C3_Super_Mini_with_DHT11/ESP32_C3_Super_Mini_with_DHT11.ino)

### **3. ESP32-C3 Super Mini with DHT11/DHT22 - Display values using web server**: 

  **To read temperature and humidity data from a DHT11/DHT22 sensor and display these values on a web server.**
  - Guide: [Read DHT11/DHT22 - Display Values Using Web Server](/docs/examples/ESP32_C3_Super_Mini_with_DHT11_webServer/README.md)
  - Code: [ESP32_C3_Super_Mini_with_DHT11_webServer.ino](/docs/examples/ESP32_C3_Super_Mini_with_DHT11_webServer/ESP32_C3_Super_Mini_with_DHT11_webServer.ino)

---

## Troubleshooting
### **Common Issues**:

1. **Serial Port Not Detected**:
   - Ensure you’re using a data-capable USB cable.
   - Reconnect the board and restart the Arduino IDE.
2. **Sketch Upload Fails**:
   - Press and hold the BOOT button during upload.
   - Verify correct board and port settings.
3. **LED Not Blinking**:
   - Double-check the GPIO pin definitions in your sketch.
4. **Use Serial Monitor**:
    - After uploading a sketch, open the Serial Monitor (`Tools > Serial Monitor`) to view any output. Make sure the baud rate is set to 115200 to match the `Serial.begin(115200);` statement in your code.

    >**Further Resources**: [ESP32 Troubleshooting Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/troubleshooting.html)

---

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

