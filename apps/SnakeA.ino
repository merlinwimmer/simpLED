SnakeA::SnakeA(int delay, char bounce, byte colorCount, byte colors[]) {  //parameters: cmdType/AppID/delay/number of colors/color1/color2/color3/ ...
    Serial.println("Setting up Color Snake App...");
    this->delay = delay;
    this->colorCount = colorCount;
    for (int i = 0; i < colorCount; i++) {
        this->colors[i] = colors[i];
    }
    this->colorIndex = 0;
    this->xPos = 0;
    this->yPos = 0;
    this->up = true;
    this->right = true;
    this->bounce = bounce == '1' ? true : false;
}

void SnakeA::refresh() {
    if (this->lastMillis + this->delay < millis()) {
        int snake_color = this->colors[this->colorIndex];

        byte r = colorLib[snake_color][0];
        byte g = colorLib[snake_color][1];
        byte b = colorLib[snake_color][2];
        draw::xy(this->xPos, this->yPos, r, g, b);
        FastLED.show();

        if (this->up ? (this->yPos < LEDS_Y - 1) : (this->yPos > 0)) {
            this->yPos = this->up ? this->yPos + 1 : this->yPos - 1;
        } else {  //Edge at top or bottom
            if (this->right ? (this->xPos < LEDS_X - 1) : (this->xPos > 0)) {
                this->xPos = this->right ? this->xPos + 1 : this->xPos - 1;
            } else {  //left or right edge
                this->colorIndex = this->colorIndex + 1 < this->colorCount ? this->colorIndex + 1 : 0;
                if (bounce) {
                    this->right = !this->right;
                } else {
                    this->xPos = this->right ? 0 : LEDS_X - 1;
                }
            }
            this->up = !this->up;  //Flip direction
        }

        this->lastMillis = millis();
    }
}


String SnakeA::print() {
}