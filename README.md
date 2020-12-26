# BlueThermDevice

A Bluetooth Low Energy (BLE) thermometer that implements
- the Environmental Sensing Service (ESS, UUID 0x181A)
- the Temperature characteristic (UUID 0x2A6E)

## Hardware

- Maxim Integrated DS18B20 Programmable Resolution 1-Wire Digital Thermometer - https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf
- Adafruit Feather nRF52840 Express - https://www.adafruit.com/product/4062
- Pull up resistor, 4.7K

## Software

- Board Support Package for the nRF52840 - https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather/arduino-bsp-setup
- Arduino IDE 1.8 or newer - https://www.arduino.cc/en/Main/Software
