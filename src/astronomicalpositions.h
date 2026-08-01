#ifndef ASTRONOMICALPOSITIONS_H
#define ASTRONOMICALPOSITIONS_H

#include <Arduino.h>
// #include "equationoftime.cpp"
// #include "astronomicalpositions.cpp"

class astronomicalPositions {
    private:
        

    
        /* data */
        float _latitude;
        float _longitude;

    public:
        astronomicalPositions(float lat, float longt);
        // ~astronomicalPositions();
        
        float getNoon(float longitude);
        void calculateTimes(float lat, float longt);
};

#endif