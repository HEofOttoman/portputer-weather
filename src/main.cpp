#include <Arduino.h>
// #include <M5Cardputer.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <time.h>
#include <Arduino_JSON.h>

// const char* ssid = "";
// const char* password = "";
#include "secrets.h" // Contains SECRET_SSID & SECRET_PASS

const long  gmtOffset_sec = 36000;
const int   daylightOffset_sec = 0;
const char* ntpServer = "au.pool.ntp.org";

// const char* openmeteo_url = "https://open-meteo.com/en/docs?hourly=temperature_2m,showers,snowfall,snow_depth,rain,precipitation,weather_code,uv_index&timezone=auto&latitude=40.7143,-35.2835,-6.2146,-1.2833&longitude=-74.006,149.1281,106.8451,36.8167&forecast_days=1&bounding_box=-90,-180,90,180&daily=temperature_2m_max,temperature_2m_min,sunrise,sunset,uv_index_max,rain_sum,precipitation_probability_max,temperature_2m_mean,weather_code&current=temperature_2m,precipitation,rain,showers,snowfall,is_day,apparent_temperature,weather_code,cloud_cover&timeformat=unixtime#current_weather";
const char* openmeteo_url = "https://api.open-meteo.com/v1/forecast?latitude=-35.2835&longitude=149.1281&daily=temperature_2m_max,temperature_2m_min,precipitation_probability_max&current=temperature_2m,is_day&timezone=Australia%2FSydney";
float latitude = 35.2835;
float longitude = 149.1281;

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// #include <U8g2lib.h>
// #include <U8x8lib.h>
// U8G2_SSD1306_128X64_NONAME_1_HW_I2C display(U8G2_R0, U8X8_PIN_NONE);
// U8X8_SH1106_128X64_NONAME_HW_I2C display(U8X8_PIN_NONE, U8X8_PIN_NONE);
Adafruit_SSD1306 display(128, 64, &Wire, -1);

const uint8_t buzzerPin = 2;

void setup() {
    // Serial.begin(115200);
    Serial.begin(115200);

    Wire.begin(); // Maybe this can work?

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("OLED failed to boot.");
    }
    Serial.println("OLED Initialised!");

    display.clearDisplay();
    display.display();
    display.print("Display reset.");
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.clearDisplay();
    display.setCursor(0,0);
    delay(100);
    display.print("Hello?");
    Serial.print("Over I2C!");
    
    // display.begin();
    // display.setFont(u8g2_font_ncenB08_tr);
    // display.drawString(0, 15, "Mode: SH1106");
    // display.drawString(0, 30, "Check border alignment:"); // This is for U8G2 SH1106
    // display.drawStr(0, 15, "Mode: SH1106");
    // display.drawStr(0, 30, "Check border alignment:"); // This is for U8G2 SSD1306
    // Draw a box along the absolute edges (0,0 to 127,63)
    // display.drawFrame(0, 0, 128, 64);

    // Serial.println("OLED SH1106 Initialised!");

    // Uncomment when cardputer porting 
    // M5Cardputer.begin();

    pinMode(buzzerPin, OUTPUT);
    tone(buzzerPin, 100, 100);

    WiFi.mode(WIFI_STA);
    WiFi.begin(SECRET_SSID, SECRET_PASS);
    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Success!");

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

long startTime ;
long elapsedTime ;

unsigned long interval = 0;
unsigned long previousMilis = 0;


void fetchWeather() {
    tone(buzzerPin, 200, 100);

    HTTPClient http;

    http.begin(openmeteo_url);

    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
        String response = http.getString();
        Serial.println(httpResponseCode);
        // Serial.println(response);

        JSONVar obj = JSON.parse(response);

        if (JSON.typeof_(obj) == "undefined") {
            Serial.println("ERROR: JSON PARSING FAILED");
            return;
        }

        // const char* city = obj[""];
        float temp = (double)obj["current"]["temperature"];
        // float rainChance = (doubleobj["current"]["precipitation_probability_max"];
        float minTemp = (double)obj["current"]["temperature_2m_min"]; 
        float maxTemp = (double)obj["current"]["temperature_2m_max"];

        // Serial.println((double)obj["current_weather"]["temperature"]);
        Serial.printf("Weather for %.4f lat %.4f long, for today: \n", latitude, longitude);
        Serial.printf("%.1f°C, with min of %.1f°C and max of %.1f°C \n", temp, minTemp, maxTemp);

    } else {
        Serial.print("ERROR SENDING REQUEST");
        Serial.println(httpResponseCode);
    }

    http.end();
}

void loop() {
    unsigned long currentMilis = millis();

    if (!WiFi.status() == WL_CONNECTED) {
        Serial.print("Disconnected, reconnecting..");
        return;
    }

    if (currentMilis - previousMilis >= interval) {
        previousMilis = currentMilis;
        // code here..?
        fetchWeather();

    }

    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)){
        Serial.println("Failed to obtain time");
        return;
    }

    
    Serial.println(&timeinfo, "%Y-%m-%d %H:%M:%S");
    delay(1000); // TO DO: Rework to use millis()

}
