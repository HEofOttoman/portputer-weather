# Cardputer Weather
This project is a dashboard that pulls data from the OpenMeteo API and displays it on the OLED display of the Cardputer, or an OLED display connected to a cardputer.
Also, it displays certain ritually significant times of the day calculated by an included algorithm.

## What is this?
I have no clue! (YET!)

### Setup
For ESP32 - Create a header file called `secrets.h` and paste in the following code:
```
// Use for WiFi
#define SECRET_SSID ""
#define SECRET_PASS ""
```
This is used to define your WiFi connection, change it accordingly.

### Suffering
I did some testing on [Wokwi.com](https://wokwi.com), their sims hate me very much
ESP32 hates me apparently .
- Hold boot every time
- Wrong chip
- Serial was not declared in this scope
- I LOST MY ENTIRE CIRCUIT AAAAAAAAAAAAAAAAAA

Made for [portputer](https://portputer.hackclub.com)!