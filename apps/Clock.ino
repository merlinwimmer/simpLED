Clock::Clock() {
    this->setName("Clock");
    outputln("Constructed new " + this->getName());
}

void Clock::refresh() {
    byte r = colorLib[this->color[0]][0];
    byte g = colorLib[this->color[0]][1];
    byte b = colorLib[this->color[0]][2];
    draw::digit(rtc.getMinute() / 10, 2, 0, r, g, b);  // Durch 10 teilen -> linke Stelle
    draw::digit(rtc.getMinute() % 10, 6, 0, r, g, b);  //Mit Modulo rechte Stelle bestimmen
    r = colorLib[this->color[1]][0];
    g = colorLib[this->color[1]][1];
    b = colorLib[this->color[1]][2];
    draw::digit(rtc.getHour(h12, PM) / 10, 0, 5, r, g, b);  // Durch 10 teilen -> linke Stelle
    draw::digit(rtc.getHour(h12, PM) % 10, 4, 5, r, g, b);  //Mit Modulo rechte Stelle bestimmen
    FastLED.show();
}

String Clock::get() {
    String s = "2";  //AppID
    s += (String) "/" + this->color[0];
    s += (String) "/" + this->color[1];
    s += (String) "/" + this->color[2];
    return s;
}

void Clock::set(String parameters[]) {
    byte i = 1;
    this->color[0] = parameters[i++].toInt();
    this->color[1] = parameters[i++].toInt();
}