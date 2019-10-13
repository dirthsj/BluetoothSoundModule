#pragma once

#include "Adafruit_NeoPixel.h"
#include "rain.h"

#define LED_PIN 6
#define LED_COUNT 16

class Lightning {
    public:
        Lightning(Adafruit_NeoPixel& strip, Rain& rain);
        void loop();
    private:
        const uint8_t RAIN_BRIGHTNESS = 64;
        const uint8_t LIGHTNING_BRIGHTNESS = 255;
        enum State {
            RAINING,
            LIGHTNING
        };
        Adafruit_NeoPixel& strip;
        uint8_t lightning[LED_COUNT] = {0};
        uint8_t dropLet = 10;
        State state = State::RAINING;
        Rain& rain;
};