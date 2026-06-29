---
date:
  created: 2026-06-29 
  updated: 2026-06-29 
draft: false 
authors:
  - Dovydas Klisys
readtime: 5 
pin: false 
---


# ESP32-S3 Tenstar Board Guide

Here is some important notes on the pinouts for the microcontroller board and understanding how to connect the board to its internal sensors or externally connected sensors.
In arduino you can create macros using #define before specifiyng the name of the pin.
then you can state the number of the gpio pin

example: #define TFT_CS 7

## ESP32-S3 to LC29H
- A0: on arduino is GPIO 18 and acts as the receive line (RX)
- A1: on arduino is GPIO 17 and acts as the transmit line (TX)

## ESP32-S3 to internal tft screen
- TFT_I2C_Power: on arduino connects to GPIO 21
- TFT_CS: on arduino connects to GPIO 7
- TFT_DC: on arduino connects to GPIO 39
- TFT_RESET: on arduino connects to GPIO 40
- TFT_BACKLIGHT: on arduino connects to GPIO 45

## ESP32-S3 to internal BMP280 sensor
- SCL: on arduino connects to GPIO 41
- SDA: on arduino connects to GPIO 42
- VDD: on board power supply (not included in code)
- GND: internal ground (not included in code)
