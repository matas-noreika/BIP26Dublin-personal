# BMP280 — Undergraduate Guide

## What Is It and What Does It Do?

The Bosch Sensortec **BMP280** is a small digital sensor that measures:

- **Air pressure (barometric pressure)**
- **Temperature**

It is commonly connected to microcontrollers such as Arduino, ESP32, Raspberry Pi Pico, STM32, and many others using either the **I²C** or **SPI** communication interface.

Although the BMP280 can measure temperature, its main purpose is **measuring air pressure accurately**. The temperature measurement is also used internally to improve the accuracy of the pressure reading.

### How does a piezo-resistive pressure sensor work?

Imagine stretching a rubber sheet.

When you press on the sheet, it bends slightly. Now imagine tiny electrical "strain gauges" attached to that sheet. As the sheet bends, the electrical resistance of those tiny elements changes.

That is essentially how the BMP280 works.

Inside the sensor is an incredibly thin silicon membrane. Air pressure pushes on this membrane, causing it to flex by an extremely small amount. Tiny **piezo-resistive** elements ("piezo" means pressure-related, and "resistive" means their electrical resistance changes) detect this bending. Electronics inside the chip convert that tiny resistance change into a digital pressure reading.

### Common beginner projects

The BMP280 is popular because one sensor enables several useful applications:

- **Weather stations** – measuring atmospheric pressure and temperature to observe weather changes.
- **Altitude measurement** – estimating height above sea level from air pressure.
- **Drones** – helping estimate altitude and vertical movement.
- **Indoor navigation** – detecting movement between building floors.
- **GPS enhancement** – improving height estimation when combined with GPS.

---

## Key Numbers to Know (Specifications)

These are the specifications that matter most when wiring and programming the BMP280 for the first time.

| Specification | Typical Value | Why it matters |
|---|---:|---|
| Supply voltage (VDD) | **1.71–3.6 V** | The sensor itself is **not** a 5 V device. |
| Logic voltage (VDDIO) | **1.2–3.6 V** | Communication pins also expect 3.3 V levels. |
| Communication | **I²C or SPI** | Most beginners use I²C because it needs fewer wires. |
| Pressure range | **300–1100 hPa** | Covers normal weather conditions and most altitude applications. |
| Operating temperature | **−40 °C to +85 °C** | Suitable for most indoor and outdoor projects. |
| Pressure accuracy | About **±1 hPa** (typical) | Roughly equivalent to around **±8 m** of altitude under ideal conditions. |
| Relative pressure accuracy | **±0.12 hPa** (typical) | Can detect altitude changes of about **1 metre** under stable conditions. |
| Temperature accuracy | About **±1 °C** (0–65 °C) | Good enough for general projects, but not a laboratory thermometer. |
| Typical current | Around **2.7–3.4 µA at 1 Hz** | Extremely low power, making it suitable for battery-powered devices. |
| Sleep current | About **0.1 µA** | Uses almost no power while sleeping. |

---

## What Are Its Limits? (Physical & Environmental)

### Operating outside its temperature or pressure range

Every sensor is designed to work within certain limits.

If the BMP280 becomes much hotter, colder, or experiences pressure outside its specified operating range:

- readings become less accurate
- measurements may drift
- the sensor may stop operating correctly
- extreme conditions could permanently damage it

For typical student projects indoors or outdoors, these limits are rarely reached.

### Water and condensation

The BMP280 is **not waterproof**.

It measures air pressure through a tiny opening. If water enters:

- pressure readings become incorrect
- moisture can damage the sensing membrane
- condensation (tiny water droplets) can temporarily block or distort measurements

If you're building an outdoor weather station, place the sensor inside a ventilated enclosure that keeps rain out while still allowing air to flow around it.

### PCB placement matters

Where you place the sensor on your circuit board can noticeably affect measurements.

Avoid placing it:

- beside voltage regulators
- next to power transistors
- near CPUs or microcontrollers that become warm
- close to motors

These components heat the surrounding air. The BMP280 may then measure the board's heat rather than the true air temperature.

Also avoid mounting it where the PCB bends or is under mechanical stress. Since the sensing element detects tiny deformations, stress in the circuit board can slightly affect pressure readings.

### Soldering considerations

The BMP280 is supplied in a tiny surface-mount package.

Most students use **breakout boards**, where the sensor has already been professionally soldered.

If you ever solder the bare chip:

- follow the manufacturer's recommended reflow soldering profile
- avoid overheating
- do not repeatedly rework the chip with a soldering iron

Excessive heat can affect calibration or permanently damage the device.

---

## How Do You Get the Best Out of It? (Optimisation Tips)

### Oversampling

Think of oversampling like asking five people the same question instead of one.

A single measurement might contain random noise.

Taking several measurements and combining them produces a smoother, more reliable answer.

Higher oversampling:

- reduces noise
- improves altitude estimation
- increases measurement time
- uses slightly more power

For weather stations, higher oversampling is usually worthwhile.

For fast-moving drones, lower oversampling often provides quicker updates.

### IIR filter

The built-in **IIR (Infinite Impulse Response) filter** smooths sudden jumps.

Imagine averaging your last few measurements instead of trusting every single reading immediately.

Higher filter settings:

- smoother graphs
- fewer spikes
- slower response to rapid pressure changes

Use stronger filtering for:

- weather stations
- indoor monitoring

Use lighter filtering or disable it for:

- drones
- fast altitude changes
- experiments requiring quick response

### Choosing the right power mode

The BMP280 offers different operating modes.

#### Sleep mode

- Uses almost no power.
- Best when no measurements are needed.

#### Forced mode

- Takes one measurement when requested.
- Excellent for battery-powered projects that only measure every few seconds or minutes.

#### Normal mode

- Continuously measures.
- Best for applications needing regular updates, such as drones or continuously running weather stations.

### Why altitude readings can be wrong

The BMP280 does **not** directly measure height.

Instead, it estimates altitude by comparing the measured air pressure with a reference pressure (often sea-level pressure).

The problem is that atmospheric pressure changes naturally with the weather. A storm can change the pressure enough to make the calculated altitude appear tens of metres different, even if the sensor has not moved.

To improve altitude estimates:

- update the local sea-level pressure regularly
- calibrate the sensor before use
- use GPS or another reference if high accuracy is needed

### Tips for stable readings

- Power the sensor from a clean, stable **3.3 V** supply.
- Keep wires short on a breadboard.
- Allow the sensor a few seconds to stabilise after power-up.
- Avoid touching the sensor while measuring.
- Keep it away from warm components.
- Use oversampling and filtering when high precision is more important than speed.
- Mount the sensor where air can circulate freely.

---

## Common Beginner Mistakes

### Using the wrong I²C address

The BMP280 usually appears at either:

- **0x76**
- **0x77**

Many beginners assume only one address exists.

If your program cannot find the sensor, run an I²C scanner first and verify which address your module uses.

### Assuming it is 5 V tolerant

The sensor chip itself is **not 5 V tolerant**.

Many breakout boards include voltage regulators or level shifters that make them safe with 5 V microcontrollers, but **not all modules do**.

Always check the specifications of the specific breakout board before connecting it to a 5 V system.

### Buying fake or incorrectly labelled modules

Some inexpensive modules are:

- clones with poorer quality
- incorrectly labelled
- actually a different sensor

A common source of confusion is mixing up the **BMP280** and the **BME280**.

- **BMP280:** Pressure + Temperature
- **BME280:** Pressure + Temperature + Humidity

Always check the chip marking or the supplier's documentation before buying.

### Ignoring self-heating

Like any electronic device, the BMP280 warms up slightly while operating.

Continuous measurements or nearby warm components can make the reported temperature a little higher than the surrounding air.

To minimise this effect:

- measure less frequently
- keep the sensor away from heat sources
- mount it where air flows freely

### Misconfigured power modes

A common programming mistake is leaving the sensor in **sleep mode** or selecting an unsuitable operating mode.

The result may be:

- readings that never update
- stale values
- no measurements at all

Using a well-tested software library and checking the power mode during setup can save a lot of debugging time.

---

## References

[1] Bosch Sensortec, *BMP280 Digital Pressure Sensor: Datasheet*, Rev. 1.19, Bosch Sensortec GmbH, 2024. [Online]. Available: <https://www.bosch-sensortec.com/products/environmental-sensors/pressure-sensors/bmp280/>

[2] Bosch Sensortec, *BMP280 Product Page*. [Online]. Available: <https://www.bosch-sensortec.com/products/environmental-sensors/pressure-sensors/bmp280/>

[3] DigiKey, *BMP280 Digital Pressure Sensor Datasheet (Bosch Sensortec)*. [Online]. Available: <https://www.digikey.com/>

[4] Arduino, "BMP280 Library Documentation." [Online]. Available: <https://docs.arduino.cc/libraries/adafruit-bmp280-library/>

[5] Adafruit Industries, "Adafruit BMP280 Barometric Pressure + Temperature Sensor Guide." [Online]. Available: <https://learn.adafruit.com/adafruit-bmp280-barometric-pressure-plus-temperature-sensor-breakout>
