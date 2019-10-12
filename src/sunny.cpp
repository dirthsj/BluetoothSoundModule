#include "sunny.h"
#include <Adafruit_NeoPixel.h>

Sunny::Sunny(Adafruit_NeoPixel& strip) : strip{strip} {}

void Sunny::loop() {
    strip.clear();
    for (uint8_t i = 0; i <= 255; i++) {
        color = strip.Color(i,0.5*i, 0);
        for (uint8_t j = 0; j < 15; j++) {
            strip.setPixelColor(j,color);
        }
        strip.show()
        delay(10);
    }

    delay(100);
}