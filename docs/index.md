---
title: Home
summary: Home page of personal STMP documentation
authors:
  - Matas Noreika
date: 2026-06-26 16:18:26
---

This repository is made to hold content and material in relation to
the Blended Intensive Programme SENSATE-X 2.0 in Dublin 2026. More information
on the program can be accessed at [BIP26Dublin](https://github.com/gstockiltud/BIP26Dublin/tree/main)

## Hardware

The following hardware is required for the programme and sourced code:

* [Tenstar ESP32 S3](https://www.aliexpress.com/item/1005006454900498.html#nav-description)
* [Waveshare LC29H(AA) GNSS module](https://www.aliexpress.com/item/1005006000498473.html)

## development environment

Due to the limited time span of the programme the use of Arduino IDE
simplifies the complexity enabling participants to rapidly produce operational
prototypes. The project is not constraint to the IDE although it is advised.

### Dependencies

The following Arduino libraries are required at minimum for the hardware
specified above:

* Adafruit BMP280 - Interface library for the BMX280 family of pressure and
temperature sensors [embedded on the development board].
* Adafruit ST7735 and ST7789 - Interface library for the 1.14" TFT display
[embedded in the development board].
* SensorLib - Interface library for the QMI8685 Inertial Measurement Unit
[embedded in the development board].
* TinyGPSPlus - NMEA message parsing library [Waveshare LC29H GNSS module].

### Directory structure

```Shell
*TBD*
```
