void app_fc() {
    //Serial.println("Full Color");
    fill_solid(leds, NUM_LEDS, CRGB(fc_color[0], fc_color[1], fc_color[2]));
    FastLED.show();
}

void app_fc_setup(String parameters[]) {  //parameters: cmdType/AppID/r/g/b
    Serial.println("Setting up Full Color App...");
    fc_color[0] = parameters[2].toInt();
    fc_color[1] = parameters[3].toInt();
    fc_color[2] = parameters[4].toInt();
}