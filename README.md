# Bluetooth-Macropad

## Description
A customizable Bluetooth macropad built with ESP32, featuring programmable keys and RGB lighting. This project allows users to configure the macropad's layout and lighting effects through an intuitive interface.

## Introduction
This repository contains the firmware and configuration files for a customizable Bluetooth macropad based on the ESP32 microcontroller. The macropad features RGB lighting and programmable keys, allowing for personalized setups and dynamic lighting effects.

## Features
- Bluetooth Connectivity: Easily pair with your computer or device.
- Customizable Macros: Program custom key functions and shortcuts.
- RGB Lighting: Dynamic and customizable RGB lighting effects.
- User-Friendly Configuration: Simple interface for adjusting key mappings and lighting.

## Hardware Requirements
- ESP32 development board (e.g., ESP32 DevKit v1)
- Mechanical switches (e.g., Gateron, Cherry MX)
- RGB LEDs (e.g., WS2812B)
- Keycaps

## Software Requirements
- Arduino IDE
- ESP32 Board Support Package
- Adafruit NeoPixel Library
- ESP32 BLE Keyboard Library

## Installation
1. Clone the Repository:
```
git clone https://github.com/pinilDissanayaka/Bluetooth-Macropad.git
```
2. Open Arduino IDE:
- Install the ESP32 board support if you haven’t already.
- Add the Adafruit NeoPixel library and ESP32 BLE Keyboard library to your Arduino IDE.

4. Upload Firmware:
- Open the HIDBleKeboard.ino file in the Arduino IDE.
- Select the appropriate ESP32 board and port.
- Click "Upload" to flash the firmware onto your ESP32.

5. Configuration
- Key Mapping: Edit the config.h file to customize key mappings.
- RGB Lighting: Adjust lighting effects in the lighting.h file.

## Usage
- Pairing: Follow the pairing instructions included in the README.md to connect your macropad to your computer.
- Programming Macros: Use the configuration interface to set up macros and shortcuts.

## License
This project is licensed under the MIT License.

## Contributing
Contributions are welcome! 

## Credits
[ESP32 BLE Keyboard Library](https://github.com/T-vK/ESP32-BLE-Keyboard): Developed by T-vK, available at ESP32 BLE Keyboard Library.
[Adafruit NeoPixel Library](https://github.com/adafruit/Adafruit_NeoPixel): Developed by Adafruit Industries, available at Adafruit NeoPixel Library.
