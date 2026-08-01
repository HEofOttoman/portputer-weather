// #include <Arduino.h>
#include <cmath>
#include "astronomicalpositions.h"

static const float jd = 2461245.366563;
static const float d = jd - 2451545.0;  // Julian date offset

static const float g = 357.529 + 0.98560028* d;
static const float q = 280.459 + 0.98564736* d;
static const float L = q + 1.915 * sin(g) + 0.020 * sin(2*g);

static const float R = 1.00014 - 0.01671* cos(g) - 0.00014* cos(2*g);
static const float e = 23.439 - 0.00000036* d;
static const float RA = atan2(cos(e) * sin(L), cos(L)) / 15;

static const float D = asin(sin(e) * sin(L));  // Declination of the Sun
static const float EqT = q/15 - RA;  // Equation of Time
static const int timeZone = 10; // Timezone? In UTC offset?

astronomicalPositions::astronomicalPositions(float lat, float longt) {
    _latitude = lat;
    _longitude = longt;
};

// astronomicalPositions::~astronomicalPositions() {    };

float astronomicalPositions::getNoon(float longitude) {
    return 12 + timeZone - longitude/15 - EqT;
}

void astronomicalPositions::calculateTimes(float lat, float longt) {
    
    // Serial.printf("Initialised calculations for %.4f lat %.4f long", _latitude, _longitude);
    const float latitude = lat;
    const float longitude = longt;

    Serial.printf("True noon at: %.1f", getNoon(longitude));

};