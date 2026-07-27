
// Obtained & modified from https://aa.usno.navy.mil/faq/sun_approx

const d = jd - 2451545.0;  // Julian date offset

const g = 357.529 + 0.98560028* d;
const q = 280.459 + 0.98564736* d;
const L = q + 1.915 * sin(g) + 0.020 * sin(2*g);

const R = 1.00014 - 0.01671* cos(g) - 0.00014* cos(2*g);
const e = 23.439 - 0.00000036* d;
const RA = arctan2(cos(e) * sin(L), cos(L)) / 15;

const D = arcsin(sin(e) * sin(L));  // Declination of the Sun
const EqT = q/15 - RA;  // Equation of Time