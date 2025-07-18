# wiiu_unstable_power
The boot0 of the Wii U has the option to boot from a SD card for recovery purposes. Boot 0 will check the UNSTBL_PWR flag in the RTC to decide if it boots of NAND or SD card. To cause the RTC to set the UNSTBL_PWR a specific signal needs to be present on TP73 (next to the Battery connector).

This code generates this signal on micro controller.

Keep in mind boot0 only supports SDSC cards, so SD cards with more than 2GB won't work. Also the SD card needs to contain the special SD boot1.

## Compatible Hardware

In theory this should work with any micro controller running MicroPython. But even if your Micro controller doesn't have Micropython, the code should be straight forward to port.

You might have adjust the GPIO

So far it was tested with:

- Raspberry Pico V1

## How to use

1. Connect GND and TP73 to the micro controller. Make sure to have the right pin configured in the script (the one you connected TP73 to, by default 13,14,15).
2. Put in a SD card prepared with the SD boot1 and a payload.
3. Run the main.py on the micro controller. Either by pasting the code in the serial terminal or by uploading it with rshell.
4. Try turning on the console

## Troubleshooting

When running on a Raspberry Pi Pico, then the LED on the Pico should flicker, since the signal is also mirrored there (GPIO25). If it doesn't, make sure the code is running. If you just pasted it into the terminal, you might need to press enter again. While running it will also print 0 to the terminal.

If the console boots normally, then it didn't work. Make sure both GND and one of the outputting GPIOs (by default 13,14,15) is connected to TP73 properly. If it is still not working then you can try to adjust the parameter of the `run_timings` up.

If the console doesn't turn on but stays on the red LED, then UNSTBL_PWR worked, but the SD card isn't bootable. Either it is incompatible (>2GB) or it doesn't have the correct boot1 flashed or it makes bad contact. Even if it looks like it is off, it is running and you should unplug the power to reset and make sure it doesn't overheat.
