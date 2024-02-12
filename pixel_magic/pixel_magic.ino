#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip;
uint16_t indexboi;
bool meme;

void setup()
{
  // put your setup code here, to run once:
  strip = Adafruit_NeoPixel(196, PIN, NEO_GRB + NEO_KHZ800);
  strip.begin();
  strip.show();
  
  // green data
  // red pwr
  // white gnd

  indexboi = 0;
  meme = false;
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    /*if (i == indexboi)
      strip.setPixelColor(i, strip.Color(0xff, 0xff, 0xff));
    else
      strip.setPixelColor(i, strip.Color(20, 20, 20));
    */
    strip.setPixelColor(i, strip.Color(100, 100, 50));
    //strip.show();
  }

  if (indexboi == strip.numPixels() && !meme)
    meme = true;

  if (indexboi == 0 && meme)
    meme = false;

  meme ? indexboi-- : indexboi++;

  strip.show();
}
