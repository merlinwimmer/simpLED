void draw::pixel(short p, byte r, byte g, byte b) {
    leds[p] = CRGB(r,g,b);
    //Support for external slave simpLEDs to be added
}

void draw::fill(byte r, byte g, byte b) {
    fill_solid(leds, NUM_LEDS, CRGB(r,g,b));
    //Support for external slave simpLEDs to be added
}