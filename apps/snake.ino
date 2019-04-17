void app_snake() {
    if (snake_lastMillis + snake_delay < millis()) {
        if (snake_ledIndex >= NUM_LEDS) {
            Serial.println("snake ledIndex rolled over");
            snake_ledIndex = 0;
            snake_colorIndex++;
        }
        if (snake_colorIndex >= snake_color_count) {
            snake_colorIndex = 0;
        }

        byte snake_color = snake_colors[snake_colorIndex];

        leds[snake_ledIndex] = CRGB(colors[snake_color][0], colors[snake_color][1], colors[snake_color][2]);
        FastLED.show();

        snake_ledIndex++;
        snake_lastMillis = millis();
    }
}

void app_snake_setup(String parameters[]) {  //parameters: cmdType/AppID/delay/number of colors/color1/color2/color3/ ...
    Serial.println("Setting up Color Snake App...");
    snake_delay = parameters[2].toInt();
    snake_color_count = parameters[3].toInt();
    for (int i = 0; i < snake_color_count; i++) {
        snake_colors[i] = parameters[i + 4].toInt();
    }

    snake_colorIndex = 0;
    snake_ledIndex = 0;
}