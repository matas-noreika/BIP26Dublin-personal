# LC29H

## Overview

The LC29H is a series of dual-band, multi-constellation GNSS modules manufactured by Quectel that support concurrent reception of GPS, BDS, Galileo, NavIC, and GLONASS. Compared to GNSS modules that track only L1 signals, the LC29H series can receive and track a higher number of visible satellites across multiple bands, significantly mitigating the multipath effect in deep urban canyons and improving positioning accuracy. An internal LNA and SAW filter provide better sensitivity and anti-interference capability. The module delivers CEP accuracy of 1 m in autonomous mode and centimetre-level accuracy in RTK-capable variants, with an optional dead reckoning function for superior positioning in weak-signal or GNSS-denied areas.

## Specifications

The LC29H-BA variant measures 12.2 × 16.0 × 2.5 mm and weighs approximately 0.9 g. Supply voltage range is 3.1–3.6 V (typical 3.3 V). Operating temperature range is −40 °C to +85 °C. Dead reckoning position error for ADR is less than 2% of distance travelled (4-wheel) and less than 4% (2-wheel) without GNSS. The module supports UART, I²C, and SPI interfaces. It includes an integrated 6-axis IMU (on BA and CA variants), TCXO, and GNSS IC with PMU. A 1PPS output pin provides a time pulse signal synchronised to GNSS time. The series covers five main variants: AA (standard), BA (RTK + DR), CA (DR only), DA (RTK only), and BS (base station).

## Known Issues

DR calibration requirement: The LC29H BA and CA modules must be firmly fixed to the vehicle body with no relative movement allowed. Manually holding the device is not acceptable, and failure to mount properly will result in inaccurate dead reckoning.
Timestamp anomalies without RTC: Since there is no external RTC connected, the module's timestamp may experience inaccuracies or anomalies — potentially reverting to an earlier time — when it encounters an environment devoid of GNSS signal coverage.
Temperature sensitivity of IMU: The integrated IMU is a temperature-sensitive sensor; performance degrades when the operating environment deviates significantly from calibration temperature.
Mounting angle tolerance: When mounting the LC29H on a carrier, yaw, pitch, and roll angles must be kept within ±5 degrees; exceeding this introduces errors into navigation calculations.
Firmware bugs: Quectel releases firmware updates containing bug fixes and performance optimisations, and it is highly important to implement a firmware upgrade mechanism in the host system.

## Solutions

Firmly screw the device to the vehicle frame to prevent any relative movement. Ensure the GNSS antenna, module, and any supported sensors are all mounted on the same rigid body.
Enable temperature compensation when the operating environment deviates more than 25 °C from normal temperature. Maintain the installation position throughout testing after initial setup to accumulate temperature-effect data.
Timestamp anomalies resolve automatically once the module exits GNSS-denied environments. After the vehicle comes to a complete stop, wait 10 seconds before cutting power to allow DR calibration data to be saved properly.
When implementing RTK or DR, ensure careful calibration of external sensors and reliable delivery of RTK correction data for optimal high-precision results.
Keep module firmware up to date via Quectel's official firmware upgrade process to benefit from ongoing bug fixes and positioning improvements.
