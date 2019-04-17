void setup()
{
    Serial.begin(115200);
    Serial.println("Setup starting...");
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(brightness);
    //FastLED.setDither(0); //Falls setBrigtness buggt

    pinMode(BTN_A_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BTN_A_PIN), btn_a_ISR, RISING);
    //attachInterrupt(digitalPinToInterrupt(BTN_B_PIN), btn_b_ISR, RISING);  //Isn't build in yet

    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB(2, 0, 0);
    }
    FastLED.show();
    delay(100);
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB(0, 2, 0);
    }
    FastLED.show();
    delay(100);
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB(0, 0, 2);
    }
    FastLED.show();
    delay(100);
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB(0, 0, 0);
    }
    FastLED.show();

    Serial.println("Setup done...");
}
