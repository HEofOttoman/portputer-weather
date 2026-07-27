# Cardputer Weather
Weather?? On a cardputer??
This project pulls data from the OpenMeteo API and displays it on the Cardputer.

## What is this?
I have no clue! (YET!)
I did some testing on [Wokwi.com](https://wokwi.com), their sims hate me very much
ESP32 hates me apparently .

### Setup
For ESP32 - Create a header file called `secrets.h` and paste in the following code:
```
// Use for WiFi
#define SECRET_SSID ""
#define SECRET_PASS ""
```
This is used to define your WiFi connection, change it accordingly.

### Suffering
- Hold boot every time
- Wrong chip
- Serial was not declared in this scope

Made for [portputer](https://portputer.hackclub.com)!