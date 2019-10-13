#include "temp.h"
#include <Adafruit_NeoPixel.h>


Temp::Temp(Adafruit_NeoPixel& strip) : strip{strip} {}

void Temp::loop(int apitemp) {
    strip.clear();
    int celsius = apitemp - 273;
    if (celsius >= 0) {
        for (uint8_t i = 0; i < LED_COUNT; i++) {
            if (3*i <= celsius) {
                strip.setPixelColor(i, 255, 0, 0);
            }
        }
    } else {
        for (uint8_t i = 0; i < LED_COUNT; i++) {
            if (3*(LED_COUNT-i) <= 0-celsius) {
                strip.setPixelColor(i, 0, 0, 255);
            }
        }
    }
    strip.show();
    delay(10);
}
