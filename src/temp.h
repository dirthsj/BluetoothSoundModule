#pragma once

#include "Adafruit_NeoPixel.h"

#define LED_PIN 6
#define LED_COUNT 16

class Temp {
    public:
        Temp(Adafruit_NeoPixel& strip);
        void loop(int apitemp);
    private:
        Adafruit_NeoPixel& strip;
};
