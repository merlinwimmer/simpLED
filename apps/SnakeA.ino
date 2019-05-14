SnakeA::SnakeA(int delay, byte colorCount, byte colors[]) {  //parameters: cmdType/AppID/delay/number of colors/color1/color2/color3/ ...
    Serial.println("Setting up Color Snake App...");
    this->delay = delay;
    this->colorCount = colorCount;
    for (int i = 0; i < colorCount; i++) {
        this->colors[i] = colors[i];
    }
    this->colorIndex = 0;
    this->position = 0;
}

void SnakeA::refresh() {
    if (this->lastMillis + this->delay < millis()) {
        if (this->position >= NUM_LEDS) {
            outputln("snake ledIndex rolled over");
            this->position = 0;
            this->colorIndex++;
        }
        if (this->colorIndex >= this->colorCount) {
            this->colorIndex = 0;
        }

        int snake_color = this->colors[this->colorIndex];

        byte r = colorLib[snake_color][0];
        byte g = colorLib[snake_color][1];
        byte b = colorLib[snake_color][2];
        draw::pixel(this->position, r, g, b);
        FastLED.show();

        this->position++;
        this->lastMillis = millis();
    }
}

String SnakeA::print() {
}