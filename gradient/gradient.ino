// Uses `rand` to choose a starting color and a target color.
// Uses integer linear interpolation on the RGB values to transition between colors.
// Sets all pixels to the same interpolated color.
// Once it reaches the target color it chooses a new target ad infinitum.

#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_PINS 196
#define MAX_BRIGHTNESS 96
#define MAX_STEPS 255
#define SLEEP_MS 25

Adafruit_NeoPixel strip(NUM_PINS, PIN, NEO_GRB + NEO_KHZ800);
uint32_t start_color = 0;
uint32_t end_color = 0;
int interpolation_index = 0;

uint32_t make_random_color() {
  return Adafruit_NeoPixel::Color(random(MAX_BRIGHTNESS), random(MAX_BRIGHTNESS), random(MAX_BRIGHTNESS));
}

uint8_t lerp(uint8_t a, uint8_t b, uint8_t amt) {
  return (((uint16_t)b * amt) >> 8) + (((uint16_t)a * (256 - amt)) >> 8);
}

// amt is in range [0, 255]
// Not appropriate for RGBW because it might overflow from the multiplies
uint32_t lerp_colors(uint32_t col1, uint32_t col2, uint8_t amt) {
  uint8_t b1 = col1 & 0xFF;
  uint8_t b2 = col2 & 0xFF;
  uint8_t g1 = (col1 & 0xFF00) >> 8;
  uint8_t g2 = (col2 & 0xFF00) >> 8;
  uint8_t r1 = (col1 & 0xFF0000) >> 16;
  uint8_t r2 = (col2 & 0xFF0000) >> 16;

  return Adafruit_NeoPixel::Color(lerp(r1, r2, amt), lerp(g1, g2, amt), lerp(b1, b2, amt));
}

void setup() {
  strip.begin();
  strip.show();

  end_color = make_random_color();
}

void loop() {
  uint32_t current_color = lerp_colors(start_color, end_color, interpolation_index);
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, current_color);
  }

  interpolation_index++;

  if (interpolation_index >= MAX_STEPS) {
    interpolation_index = 0;
    start_color = end_color;
    end_color = make_random_color();
  }

  strip.show();
  delay(SLEEP_MS);
}
