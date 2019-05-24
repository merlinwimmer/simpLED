void draw::pixel(short p, byte r, byte g, byte b) {
    leds[p] = CRGB(r, g, b);
    //Support for external slave simpLEDs to be added
}

void draw::fill(byte r, byte g, byte b) {
    fill_solid(leds, NUM_LEDS, CRGB(r, g, b));
    //Support for external slave simpLEDs to be added
}

void draw::xy(short x, short y, byte r, byte g, byte b) {
    leds[(x * LEDS_Y) + y] = CRGB(r, g, b);
}

void draw::digit(byte digit, byte xOffs, byte yOffs, byte r, byte g, byte b) {
    byte totalOffs = (xOffs * LEDS_Y) + yOffs;
    int p = totalOffs;  //Pixel position
    for (int i = 0; i < DIGIT_WIDTH * DIGIT_HEIGHT; i++) {
        if (i % DIGIT_HEIGHT == 0 && i != 0) {
            p += LEDS_Y - DIGIT_HEIGHT;
        }
        if (digits[digit][i] == 1) {
            draw::pixel(p, r, g, b);
        }
        p++;
    }
    FastLED.show();
}