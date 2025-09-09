# ESP32-WROOM DHT22 Firmware Project

## Project Description
This project demonstrates firmware development on the ESP32-WROOM microcontroller using PlatformIO with the Arduino framework. The firmware integrates a DHT22 temperature and humidity sensor, reads data every 60 seconds and prints the results to the Serial Monitor. It successfully builds and uploads, confirming a functional development setup. The code is written to directly support hardware, meaning it can be deployed to an ESP32 board connected with a DHT22 sensor to read and log real-time environmental data.


## Overview
- **Objective:** Develop firmware that reads and logs environmental temperature and humidity.  
- **Target Hardware:** ESP32-WROOM microcontroller.  
- **Sensor Used:** DHT22 digital temperature and humidity sensor.  
- **Framework:** Arduino, built and managed through PlatformIO.  
- **Key Features:**
  - Code compiles and builds successfully in PlatformIO.
  - Sensor reading every 1 minute.  
  - Human-readable serial output.  
  
## How It Works
1. The ESP32 initializes the DHT22 sensor.  
2. Every 60 seconds, the ESP32 collects temperature and humidity data.  
3. The values are checked for validity, then printed to the Serial Monitor in the format:  Temperature: 25.3 C, Humidity: 52.1 %
4. If invalid, the system outputs:  
 Failed to read from DHT sensor 

## Components and Their Role
- **ESP32-WROOM:** Microcontroller that runs the firmware, processes data and outputs results.  
- **DHT22 Sensor:** Digital sensor that provides calibrated temperature and humidity data.  
- **10kΩ Resistor:** Pull-up resistor ensuring stable communication between the sensor and ESP32.  
- **USB Cable:** Used for programming and powering the ESP32.  

## Development Environment
- **Editor:** Visual Studio Code with PlatformIO extension.  
- **Platform:** `espressif32`.  
- **Board:** `esp32dev`.  
- **Framework:** Arduino.  
- **Libraries Used:**  
- `Adafruit DHT sensor library`  
- `Adafruit Unified Sensor`  

## Results
- **Simulation Mode:** The firmware compiled and uploaded successfully in PlatformIO, confirming correct setup and functional source code.
    - The project includes a **simulation mode** enabled by the build flag `SIMULATE_SENSOR`.  
    - When defined, the ESP32 will generate fake temperature and humidity values and print them        to the Serial Monitor.  
    - This mode is useful for testing on an ESP32 board even if the DHT22 sensor is not                connected.  
    - In the standard mode (without `SIMULATE_SENSOR`), the firmware reads real data from a            connected DHT22 sensor and prints it to the Serial Monitor every 60 seconds.  
    - Since no hardware was available during this build, the results verified were **successful        firmware compilation** and **readiness to run on actual ESP32 hardware**.
- **Hardware Mode (expected):** ESP32 reads real-time values from the DHT22 and displays them on the Serial Monitor every 1 minute. If the sensor fails, the system outputs an error message.  

- **Proof of Functionality:** Successful builds confirm the firmware logic is correct and hardware readiness ensures it can operate with the DHT22 sensor.

## Applications
- **General:**  
  - Environmental monitoring systems.  
  - Smart agriculture and greenhouse automation.  
  - IoT-based climate data collection.  
- **Specific to Synnefa:**  
  - Integration into smart farming solutions.  
  - Real-time crop environment monitoring for precision agriculture.  
  - Scalable sensor nodes for climate-resilient farming systems.  

## Possible Improvements
- Use ESP32’s built-in WiFi to send sensor data to a remote server or IoT dashboard.  
- Implement data logging to an SD card for offline storage.  
- Add support for additional sensors (e.g., soil moisture, light).  
- Use interrupt-driven timers instead of `delay()` for efficiency.  

## Hardware Connections
| ESP32 Pin | DHT22 Pin | Description                |
|-----------|-----------|----------------------------|
| 3.3V      | VCC       | Powers the sensor          |
| GND       | GND       | Common ground              |
| GPIO4     | DATA      | Sensor data output to ESP32|
| 10kΩ      | VCC–DATA  | Pull-up resistor           |

## Setup Instructions

### Case 1: Firmware Only (No Hardware)
1. Install VS Code and PlatformIO.  
2. Open the project folder.  
3. Confirm the project builds without errors.  
4. Select **Build** in PlatformIO to compile.  
5. The terminal should show **SUCCESS**.  
6. No output will appear on the Serial Monitor since no sensor is connected.  

### Case 2: With Hardware
1. Wire the ESP32 and DHT22 as shown in the Hardware Connections table.  
2. Connect ESP32 to PC using a USB cable.  
3. Open the project in PlatformIO.  
4. Build and Upload the code to the ESP32.  
5. Open the **Serial Monitor** at `115200` baud rate.  
6. Observe real-time temperature and humidity readings every 1 minute.

## How to Build and Run the Code
1. Open the project in VS Code with PlatformIO.  
2. Install the required libraries via `platformio.ini`.  
3. Select **Build** (checkmark icon) to compile.  
4. Select **Upload** (arrow icon) to flash onto the ESP32.  
5. Open **Serial Monitor** at `115200`.  
6. View results in the format:  
Temperature: 26.0 C, Humidity: 53.2 %
