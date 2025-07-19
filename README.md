# wiiu_unstable_power
The boot0 of the Wii U has the option to boot from a SD card for recovery purposes. Boot 0 will check the UNSTBL_PWR flag in the RTC to decide if it boots of NAND or SD card. To cause the RTC to set the UNSTBL_PWR a specific signal needs to be present on TP73 (next to the Battery connector).

This code generates this signal on micro controller.

Keep in mind boot0 only supports SDSC cards, so SD cards with more than 2GB won't work. Also the SD card needs to contain the special SD boot1.

## Compatible Hardware

- Raspberry Pico 1

## How to use

1. Connect one or more of Pico GPIOs 14, 15, 16 and 17 to TP73. Connect GND from the Pico to the Wii U.
2. Put in a SD card prepared with the SD boot1 and a payload.
3. Put the Pico into bootsel mode and drag and drop the UF2 onto it. The LED should start blinking
4. Power on the Wii U

## Troubleshooting

When running on a Raspberry Pi Pico, then the LED on the Pico should flicker, since the signal is also mirrored there (GPIO25). 

If the console boots normally, then it didn't work. Make sure both GND and one of the outputting GPIOs (by default 14, 15, 16 and 17) is connected to TP73 properly. Consoles with bottom side RTCs seem less compatible for the time being

If the console doesn't turn on but stays on the red LED, then UNSTBL_PWR worked, but the SD card isn't bootable. Either it is incompatible (>2GB) or it doesn't have the correct boot1 flashed or it makes bad contact. Even if it looks like it is off, it is running and you should unplug the power to reset and make sure it doesn't overheat.
