#pragma once

#include "Adafruit_NeoPixel.h"

#define LED_PIN 6
#define LED_COUNT 16

class Lightning {
    public:
        Lightning(Adafruit_NeoPixel& strip);
        void loop();
    private:
        Adafruit_NeoPixel& strip;
        uint8_t rain[LED_COUNT] = {0};
        uint8_t dropLet 10;
        enum State {
            RAINING,
            LIGHTNING
        };
        uint8_t RAIN_BRIGHTNESS = 64;
        uint8_t LIGHTNING_BRIGHTNESS = 255;
};