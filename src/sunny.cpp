#include "sunny.h"
#include <Adafruit_NeoPixel.h>

Sunny::Sunny(Adafruit_NeoPixel& strip) : strip{strip} {}

void Sunny::loop() {
    for (uint8_t i = 0; i < 255; i++) {
        uint32_t color = strip.Color(i, 0.5*i, 0);
        for (uint8_t j = 0; j < 16; j++) {
            strip.setPixelColor(j, color);
        }
        strip.show();
        delay(10);
    }

    for (uint8_t i = 255; i > 0; i--) {
        uint32_t color = strip.Color(i, 0.5*i, 0);
        for (uint8_t j = 0; j < 16; j++) {
            strip.setPixelColor(j, color);
        }
        strip.show();
        delay(10);
    }
}