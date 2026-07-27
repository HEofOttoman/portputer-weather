#include <cmath>
// Obtained & modified from https://aa.usno.navy.mil/faq/sun_approx

const float jd = 2461245.366563;
const float d = jd - 2451545.0;  // Julian date offset

const float g = 357.529 + 0.98560028* d;
const float q = 280.459 + 0.98564736* d;
const float L = q + 1.915 * sin(g) + 0.020 * sin(2*g);

const float R = 1.00014 - 0.01671* cos(g) - 0.00014* cos(2*g);
const float e = 23.439 - 0.00000036* d;
const float RA = atan2(cos(e) * sin(L), cos(L)) / 15;

const float D = asin(sin(e) * sin(L));  // Declination of the Sun
const float EqT = q/15 - RA;  // Equation of Time

const float latitude = 1.92;
const float longitude = 1.92;
const int timeZone = 10; // Timezone? In UTC offset?

float getNoon() {
    return 12 + timeZone - longitude/15 - EqT;
}


void fetchAllTimes() {
    const float noonTime = getNoon();

    int t = 1; // PLACEHOLDER PLEASE
    float A = 1/5 * acos ( sin(atan2(t + tan(L - D), t)) - sin(L) * sin(D) / cos(L) * cos(D)); // Check if I translated this correctly

    float afterNoon = noonTime + A * 2;
}