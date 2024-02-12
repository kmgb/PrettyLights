#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip;
uint16_t index;
bool dir; // The direction the index will change in

void setup()
{
  strip = Adafruit_NeoPixel(196, PIN, NEO_GRB + NEO_KHZ800);
  strip.begin();
  strip.show();

  index = 0;
  dir = false;
}

void loop()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    if (i == index)
      strip.setPixelColor(i, strip.Color(0xff, 0xff, 0xff));
    else
      strip.setPixelColor(i, strip.Color(20, 20, 20));
  }

  if (index == strip.numPixels() && !dir)
    dir = true;

  if (index == 0 && dir)
    dir = false;

  dir ? index-- : index++;

  strip.show();
}
