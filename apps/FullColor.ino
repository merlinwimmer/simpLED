FullColor::FullColor() {
    this->setName("Full Color");
    outputln("Constructed new " + this->getName());
}

void FullColor::refresh() {
    draw::fill(this->color[0], this->color[1], this->color[2]);
    FastLED.show();
}

String FullColor::get() {
    String s = "0";  //AppID
    s += (String) "/" + this->color[0];
    s += (String) "/" + this->color[1];
    s += (String) "/" + this->color[2];
    return s;
}

void FullColor::set(String parameters[]) {
    byte i = 1;
    this->color[0] = parameters[i++].toInt();
    this->color[1] = parameters[i++].toInt();
    this->color[2] = parameters[i++].toInt();
}