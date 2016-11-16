
#ifndef PIXELS_H
#define PIXELS_H

#define FASTLED_FORCE_SOFTWARE_SPI
#define FASTLED_ALLOW_INTERRUPTS 0
//#define FASTLED_ESP8266_RAW_PIN_ORDER
#include <EEPROM.h>
#include "FastLED.h"

FASTLED_USING_NAMESPACE


#define DATA_PIN      2     // for Huzzah: Pins w/o special function:  #4, #5, #12, #13, #14; // #16 does not work :(
  #define LED_TYPE      WS2811
  #define COLOR_ORDER   GRB
  #define NUM_LEDS      64

  #define MILLI_AMPS         2000     // IMPORTANT: set here the max milli-Amps of your power supply 5V 2A = 2000
  //#define FRAMES_PER_SECOND  speed // here you can control the speed. With the Access Point / Web Server the animations run a bit slower.

  #define MILLI_AMPS         2000     // IMPORTANT: set here the max milli-Amps of your power supply 5V 2A = 2000
  //#define FRAMES_PER_SECOND  speed // here you can control the speed. With the Access Point / Web Server the animations run a bit slower.

  #define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))


  class ESPLedDriver
  {
  public:
    ESPLedDriver();
    void setup();
    uint8_t getPower();
    void setPower(uint8_t power);
    uint8_t getBrightness();
    void adjustBrightness(bool up);
    void setBrightness(uint8_t value);
    void adjustSpeed(bool up);
    void setSpeed(uint8_t value);
    void adjustPattern(bool up);
    void setPattern(int value);
    void setSolidColor(CRGB color);
    void setSolidColor(uint8_t r, uint8_t g, uint8_t b);
    CRGB getSolidColor();
    String getStatus();
    void run();
  private:
    CRGB _leds[NUM_LEDS];

    uint8_t _power;
    uint8_t _r;
    uint8_t _g;
    uint8_t _b;
    uint8_t _h;
    uint8_t _s;
    uint8_t _l;

    uint8_t _patternIndex;

    static const uint8_t _brightnessCount = 5;
    uint8_t _brightnessMap[_brightnessCount] = { 16, 32, 64, 128, 255 };
    int _brightnessIndex;
    uint8_t _brightness = _brightnessMap[_brightnessIndex];

    static const uint8_t _speedCount = 5;
    uint8_t _speedMap[_speedCount] = { 16, 32, 64, 128, 255 };
    int _speedIndex = 0;
    uint8_t _speed = _speedMap[_speedCount];

    int _framesPerSecond = 100;
    int _secondsPerPalette = 120;
    ///////////////////////////////////////////////////////////////////////
    // Forward declarations of an array of cpt-city gradient palettes, and
    // a count of how many there are.  The actual color palette definitions
    // are at the bottom of this file.
    // extern const TProgmemRGBGradientPalettePtr gGradientPalettes[];
    // extern const uint8_t gGradientPaletteCount;
    //
    // // Current palette number from the 'playlist' of color palettes
    uint8_t _gCurrentPaletteNumber = 0;
    //
    CRGBPalette16 _gCurrentPalette;
    CRGBPalette16 _gTargetPalette;

    uint8_t _currentPatternIndex = 0; // Index number of which pattern is current
    bool _autoplayEnabled = false;

    uint8_t _autoPlayDurationSeconds = 10;
    unsigned int _autoPlayTimeout = 0;

    uint8_t _gHue = 0; // rotating "base color" used by many of the patterns

    CRGB _solidColor = CRGB::Blue;

    uint8_t _patternCount = 4;
    void loadSettings();

    /* Animations */
    void showSolidColor();
    void rainbow();
    void rainbowWithGlitter();
    void addGlitter(fract8 chanceOfGlitter);
    void confetti();
    void sinelon();
    void bpm();
    void juggle();
    void pride();
    void colorwaves();
    void palettetest();

    typedef void (*Pattern)();
    typedef Pattern PatternList[];
    typedef struct {
      Pattern pattern;
      String name;
    } PatternAndName;
    typedef PatternAndName PatternAndNameList[];

    // List of patterns to cycle through.  Each is defined as a separate function below.
    // PatternAndNameList patterns = {
    //   { colorwaves, "Color Waves" },
    //   { palettetest, "Palette Test" },
    //   { pride, "Pride" },
    //   { rainbow, "Rainbow" },
    //   { rainbowWithGlitter, "Rainbow With Glitter" },
    //   { confetti, "Confetti" },
    //   { sinelon, "Sinelon" },
    //   { juggle, "Juggle" },
    //   { bpm, "BPM" },
    //   { showSolidColor, "Solid Color" },
    // };

    // const uint8_t patternCount = ARRAY_SIZE(patterns);


  };

  #endif
