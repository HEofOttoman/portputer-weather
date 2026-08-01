# Cardputer Weather
![Static oled](<portputer weather.jpg>)

## What is this?
This project is a dashboard that pulls data from the OpenMeteo API (configured for Canberra) and displays it on the OLED display of the Cardputer, or an OLED display connected to a cardputer.
Also, it displays certain 'ritually significant' times of the day calculated by an algorithm within the code I attempted to translate into C++ from some documentation.

## Setup
You can test the project over at [Wokwi](https://wokwi.com/projects/470952053373991937)! Disclaimer that this might not build under Wokwi server limits however.

### Compiling manually
If you have the hardware for the ESP32 Devkit to run it, you can compile & upload it via PlatformIO. 
1. Clone the repository
2. Create a header file called `secrets.h` and paste in the following code:
    ```
    // Use for WiFi
    #define SECRET_SSID ""
    #define SECRET_PASS ""
    ```
    This is used to define your WiFi connection, change it accordingly.
3. Upload & compile with PlatformIO (making sure that the circuit is connected to port COM3 or manually specified in `platformio.ini`)

~~Then you might want to flash it with the `partitions.bin`, `bootloader.bin`, & `firmware.bin` files.~~ *Actually nvm this only works with my specific network I compiled it with then*

## Suffering
This is a small section that journals my issues in making this project. 
- I tried to do some testing on [Wokwi.com](https://wokwi.com), their sims do not like compiling this ESP32 project
- I need to hold boot button every time I upload
- Wrong chip error (fixed by changing ESP32-S3 to ESP32-Devkit)
- `Serial was not declared in this scope`
- I LOST MY ENTIRE CIRCUIT AAAAAAAAAAAAAAAAAA
- OLED circuit inexplicably does not work with my PlatformIO/computer setup (works on other computers & with Arduino IDE)

I spent 11 hours on this barely functioning project somehow hardware debugging is no joke

### Future Features(?)
- [ ] Port to the Cardputer (speaker functionality)
- [ ] Add ability to call/calculate from inputted coordinates (Cardputer keyboard integration)
- [ ] Add better algorithm

---
*Made for [portputer](https://portputer.hackclub.com)!*