#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip;
uint16_t offs;

void setup()
{
  // put your setup code here, to run once:
  strip = Adafruit_NeoPixel(196, PIN, NEO_GRB + NEO_KHZ800);
  strip.begin();
  strip.show();
  
  // green data
  // red pwr
  // white gnd

  offs = 0;
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    // `offs' lighting logic:
    // 0: 1 0 0 1 0 0 1
    // 1: 0 0 1 0 0 1 0
    // 2: 0 1 0 0 1 0 0
    // We reverse the order (2, 1, 0) so that the lights go forwards instead
    // of backwards as seen above
    if (((i + offs) % 3) == 0)
    {
      strip.setPixelColor(i, strip.Color(0xFF, 0xFF, 0x0));
    }
    else
    {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
  }

  if (offs == 0)
    offs = 3;

  offs--;

  strip.show();

  delay(300);
}
