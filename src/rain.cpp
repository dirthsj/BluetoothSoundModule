#include "rain.h"
#include <Adafruit_NeoPixel.h>


Rain::Rain(Adafruit_NeoPixel& strip) : strip{strip} {}

void Rain::loop() {
  // put your main code here, to run repeatedly:
  for (uint8_t i = 0; i < LED_COUNT; i++) {
    if (rain[i] > 0) {
      rain[i] -= 5;
      strip.setPixelColor(i, 0, 0, rain[i]);
    }
  }
  if (dropLet-- == 0) {
      uint8_t i = random(0, LED_COUNT);
      rain[i] = 255;
      strip.setPixelColor(i, 0, 0, rain[i]);
      dropLet = 10;
  }
  strip.show();
  delay(10);
}
