#include "lightning.h"

Lightning::Lightning(Adafruit_NeoPixel& strip, Rain& rain) : strip{strip}, rain{rain} {}

void Lightning::loop() {
    if (random(0, 255) == 0) {
        for (int i = 0; i < LED_COUNT; i++) {
            lightning[i] = 255;
        }
        state = State::LIGHTNING;
    }
    switch (state) {
        case RAINING:
            strip.setBrightness(RAIN_BRIGHTNESS);
            rain.loop();
            break;
        case LIGHTNING:
            strip.setBrightness(LIGHTNING_BRIGHTNESS);
            for (int i = 0; i < LED_COUNT; i++) {
                if (lightning[i] > 0) {
                    lightning[i] -= 15;
                } else {
                    state = State::RAINING;
                }
            strip.setPixelColor(i, lightning[i], lightning[i], lightning[i]);
            }
            strip.show();
            delay(10);
      break;
    }
}
