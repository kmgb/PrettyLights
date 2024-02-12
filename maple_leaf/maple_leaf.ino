#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip;

// I could do it in a 1D array but that would require me
// to flip the order every other line, this way is more
// coder friendly.
// Pretty maple leaf:
bool lights[14][14] =
  {
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}
  };

// Set the color of a particular LED in a series (zig-zag form) LED strand
void setColor(uint16_t x, uint16_t y, uint32_t color)
{
  if (y % 2 == 0)
    strip.setPixelColor(y * 14 + x, color);
  else
    strip.setPixelColor(y * 14 + (13 - x), color);
}

void setup()
{
  // put your setup code here, to run once:
  strip = Adafruit_NeoPixel(196, PIN, NEO_GRB + NEO_KHZ800);
  strip.begin();

  // Only needs to run once
  for (uint16_t x = 0; x < 14; x++)
  {
    for (uint16_t y = 0; y < 14; y++)
    {
      if (lights[y][x])
        setColor(x, y, Adafruit_NeoPixel::Color(0xFF, 0, 0));
      else
        setColor(x, y, Adafruit_NeoPixel::Color(0xdd, 0xdd, 0xdd));
    }
  }
  
  strip.show();
}

void loop()
{
  // Nothing needs to be updated, it's displaying a static image
}
