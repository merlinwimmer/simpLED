SnakeA::SnakeA() {  //parameters: cmdType/bounce/AppID/delay/number of colors/color1/color2/color3/ ...
    this->setName("Snake Animation");
    outputln("Constructed new " + this->getName());
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

String SnakeA::get() {
    String s = "1";  //AppID
    s += (String) "/" + (this->bounce ? "1" : "0");
    s += (String) "/" + this->delay;
    s += (String) "/" + this->colorCount;
    for (short i = 0; i < this->colorCount; i++) {
        s += "/";
        s += (String)this->colors[i];
    }
    return s;
}

void SnakeA::set(String parameters[]) {
    short i = 1;
    this->bounce = parameters[i++] == "1" ? true : false;
    this->delay = parameters[i++].toInt();
    this->colorCount = parameters[i++].toInt();
    for (int j = 0; j < this->colorCount; j++) {
        this->colors[j] = parameters[i++].toInt();
    }
}
