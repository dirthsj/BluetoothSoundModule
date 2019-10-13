#include "sunny.h"
#include <Adafruit_NeoPixel.h>

Sunny::Sunny(Adafruit_NeoPixel& strip) : strip{strip} {}

void Sunny::loop() {
    i = i + state;
    if (i == 255) {
        state = State::DECREMENT;
    } else if (i == 0) {
        state = State::INCREMENT;
    }
    uint32_t color = strip.Color(i, 0.5*i, 0);
    for (uint8_t j = 0; j < 16; j++) {
        strip.setPixelColor(j, color);
    }
    strip.show();
    delay(10);
}
