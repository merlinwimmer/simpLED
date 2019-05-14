FullColor::FullColor(byte r, byte g, byte b) {
    output("Setting up Full Color App...\n");
    this->color[0] = r;
    this->color[1] = g;
    this->color[2] = b;
}

void FullColor::refresh()  {
    draw::fill(this->color[0], this->color[1], this->color[2]);
    FastLED.show();
}

String FullColor::print()  {
}