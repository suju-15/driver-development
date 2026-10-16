# MPU6050 ESP-IDF Driver for ESP32-C3

A lightweight, professional, and efficient I2C driver for the MPU6050 accelerometer and gyroscope, specifically designed for **ESP-IDF (Espressif IoT Development Framework)**.

## Features
*   **Bare-metal implementation:** Uses the modern ESP-IDF `i2c_master` driver API.
*   **Modular Design:** Encapsulated as a standalone component for easy integration into any ESP-IDF project.
*   **Efficient:** Implements burst-reading for high-speed data acquisition.
*   **Clean API:** Intuitive functions to initialize and read sensor data without exposing I2C register-level complexity.

## Getting Started

### Prerequisites
*   [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) installed and configured.
*   Hardware: ESP32-C3 and an MPU6050 sensor.

### Installation
1. Copy the `components/mpu6050` folder into your project's `components` directory.
2. Ensure your `main/CMakeLists.txt` includes the dependency:
   ```cmake
   idf_component_register(SRCS "main.c"
                          INCLUDE_DIRS "."
                          REQUIRES mpu6050)
