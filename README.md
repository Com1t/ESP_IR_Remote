# Web IR Remote

## Introduction

The **Web IR Remote** project allows you to control a KBro TV box using a web interface hosted on an ESP8266 microcontroller (such as a NodeMCU). The KBro TV box has a 3.5mm IR extender jack that can be utilized to pass the simulated IR signals for remote control. This project leverages the ESP8266 to generate the required IR signals and send them through the IR extender jack, enabling remote control functionality through a web browser.

## Features

- Control the KBro TV box from any web browser on the same network.
- Easily send IR signals using a web-based interface.
- Flexible button layout that can be customized to match the original remote.
- Supports multiple all functions from the original remote.

## Wiring

After some experimentation with the IR extender jack of the KBro TV box, I discovered the following wiring configuration:

![Photo of Experiment](./img/example_connection_2.HEIC)

### Stereo Jack Schematic

The 3.5mm stereo jack (TRS) typically has three connections: **Tip (T)**, **Ring (R)**, and **Sleeve (S)**. In the case of the KBro TV box IR extender jack, the pinout is as follows:

![Photo of Experiment](./img/stereo_cable.gif)

- **Right Channel (Signal):** This is connected to the GPIO pin of the ESP8266 that outputs the IR signal (via an IR LED or direct output).
- **Left Channel (VCC 5V):** This provides 5V power and can be used to power the ESP8266 or as a reference.
- **Ground:** The ground pin should be connected to the common ground of the ESP8266.
