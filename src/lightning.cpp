#include "lightning.h"
#include "rain.h"
#include <Adafruit_NeoPixel.h>

State state = State::RAINING;

Lightning::Lightning(Adafruit_NeoPixel& strip) : strip{strip} {}

void Lightning::loop() {
    if (random(0, 255) == 0) {
        for(int i = 0; i < LED_COUNT; i++) {
            lightning[i] = 255;
        }
        state = State::LIGHTNING;
    }
    switch(state) {
        case RAINING:
            strip.setBrightness(RAIN_BRIGHTNESS);
            Rain rain(strip);
            break;
        case LIGHTNING:
            strip.setBrightness(LIGHTNING_BRIGHTNESS);
            for(int i = 0; i < LED_COUNT; i++) {
                if(lightning[i] > 0) {
                    lightning[i] -= 5;
                } else {
                    state = State::RAINING;
                }
            strip.setPixelColor(i, lightning[i], lightning[i], lightning[i]);
            }
      break;
    }

    strip.show();
    delay(10);
}