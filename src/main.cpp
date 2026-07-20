#include <Arduino.h>
#include <M5Cardputer.h>
#include <Wifi.h>
#include <HTTPClient.h>
#include <time.h>
#include <Arduino_JSON.h>

const char* ssid = "";
const char* password = "";

const long  gmtOffset_sec = 36000;
const int   daylightOffset_sec = 0;
const char* ntpServer = "au.pool.ntp.org";

const char* openmeteo_url = "https://open-meteo.com/en/docs?hourly=temperature_2m,showers,snowfall,snow_depth,rain,precipitation,weather_code,uv_index&timezone=auto&latitude=40.7143,-35.2835,-6.2146,-1.2833&longitude=-74.006,149.1281,106.8451,36.8167&forecast_days=1&bounding_box=-90,-180,90,180&daily=temperature_2m_max,temperature_2m_min,sunrise,sunset,uv_index_max,rain_sum,precipitation_probability_max,temperature_2m_mean,weather_code&current=temperature_2m,precipitation,rain,showers,snowfall,is_day,apparent_temperature,weather_code,cloud_cover&timeformat=unixtime#current_weather";

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
    Serial.begin(115200);
    
    display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
    display.setTextColor(WHITE);
    display.setTextSize(2);
    
    M5Cardputer.begin();
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

long startTime ;
long elapsedTime ;

unsigned long interval = 0;
unsigned long previousMilis = 0;

void loop() {
    unsigned long currentMilis = millis();

    if (currentMilis - previousMilis >= interval) {
        previousMilis = currentMilis;
        // code here..?

    }

    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)){
        Serial.println("Failed to obtain time");
        return;
    }

    
    Serial.println(&timeinfo, "%Y-%m-%d %H:%M:%S");
    delay(1000);

    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;

        http.begin(openmeteo_url);

        int httpResponseCode = http.GET();

        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println(httpResponseCode);
            Serial.println(response);
        } else {
            Serial.print("ERROR SENDING REQUEST");
            Serial.println(httpResponseCode);
        }

        JSONVar obj = JSON.parse(http.getString());
        Serial.println((double)obj["current_weather"]["temperature"]);

        http.end();
    }

}
