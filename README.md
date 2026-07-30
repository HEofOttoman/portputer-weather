# Cardputer Weather
This project is a dashboard that pulls data from the OpenMeteo API and displays it on the OLED display of the Cardputer, or an OLED display connected to a cardputer.
Also, it displays certain ritually significant times of the day calculated by an included algorithm.

## What is this?
I have no clue! (YET!)

## Setup
You can test the project over at [Wokwi](https://wokwi.com/projects/470952053373991937)! Disclaimer that it might not build properly.

## Compiling manually
If you have the hardware for the ESP32 Devkit to run it, you can compile & upload it via PlatformIO. 
1. Create a header file called `secrets.h` and paste in the following code:
    ```
    // Use for WiFi
    #define SECRET_SSID ""
    #define SECRET_PASS ""
    ```
    This is used to define your WiFi connection, change it accordingly.
2. Clone the repository
3. Upload & compile with PlatformIO

~~Then you might want to flash it with the `partitions.bin`, `bootloader.bin`, & `firmware.bin` files.~~ *Actually nvm this only works with my specific network I compiled it with then*


### Suffering
I did some testing on [Wokwi.com](https://wokwi.com), their sims hate me very much.
ESP32 hates me apparently.
- Hold boot every time
- Wrong chip
- Serial was not declared in this scope
- I LOST MY ENTIRE CIRCUIT AAAAAAAAAAAAAAAAAA

Made for [portputer](https://portputer.hackclub.com)!