#ifndef ASTRONOMICALPOSITIONS_H
#define ASTRONOMICALPOSITIONS_H

#include <Arduino.h>
// #include "equationoftime.cpp"
// #include "astronomicalpositions.cpp"

class astronomicalPositions {
    private:
        /* data */
        float longitude;
        float latitude;

    public:
        astronomicalPositions();
        ~astronomicalPositions();
        
        void calculateTimes(float longt, float lat);
};

#endif