#include "temp.h"
#include <Adafruit_NeoPixel.h>


Temp::Temp(Adafruit_NeoPixel& strip) : strip{strip} {}

void Temp::loop(apitemp) {
  // put your main code here, to run repeatedly:
  uint8_t celsius = apitemp - 273;
  if (celsius >= 0) {
    for (uint8_t i = 0; i < LED_COUNT; i++) {
        if (3*temp[i] >= celsius) {
            strip.setPixelColor(255,0,0, temp[i]);
        }
    }
 } else {
     for (uint8_t i = 15; i >= 0; i--) {
        if (3*temp[i] >= celsius) {
            strip.setPixelColor(126,126,255, temp[i]);
        }
    }
 }
  strip.show();
  delay(10);
}
