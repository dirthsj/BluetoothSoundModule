#pragma once

#include "Adafruit_NeoPixel.h"

#define LED_PIN 6
#define LED_COUNT 16

class Sunny {
    public:
        Sunny(Adafruit_NeoPixel& strip);
        void loop();
    private:
        Adafruit_NeoPixel& strip;
        uint8_t sunny[LED_COUNT] = {0};
        uint8_t dropLet = 10;
};