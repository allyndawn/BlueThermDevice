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

## Sample Output (Tools > Serial Monitor)

### Not connected to a cental

```
Not connected
4F 1 4B 46 7F FF C 10 46 
Temperature: 69.688
BLE:2D 8
Not connected
4F 1 4B 46 7F FF C 10 46 
Temperature: 69.688
BLE:2D 8
Not connected
4F 1 4B 46 7F FF C 10 46 
Temperature: 69.688
BLE:2D 8
Not connected
4F 1 4B 46 7F FF C 10 46 
Temperature: 69.688
BLE:2D 8
```

### Connected to a central

```
Connected, sending notification
58 1 4B 46 7F FF C 10 E8 
Temperature: 70.700
BLE:66 8
Connected, sending notification
50 1 4B 46 7F FF C 10 E8 
Temperature: 69.800
BLE:34 8
Connected, sending notification
50 1 4B 46 7F FF C 14 E8 
Temperature: 69.800
BLE:34 8
Connected, sending notification
50 1 4B 46 7F FF C 10 E8 
Temperature: 69.800
BLE:34 8
```

## How It Appears to a Central (e.g. LightBlue by PunchThrough)

![In the peripherals list](/media/LightBlue-0.png)

![On connecting](/media/LightBlue-1.png)

![On listening to notifications](/media/LightBlue-2.png)
