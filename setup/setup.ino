void setup() {
    Serial.begin(115200);
    Serial.println("Setup starting...");
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(brightness);
    leds[0] = CRGB(2, 0, 0);

    Wire.begin();

    printTime();

    //FastLED.setDither(0); //Falls setBrigtness buggt

    pinMode(BTN_A_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BTN_A_PIN), btn_a_ISR, RISING);
    //attachInterrupt(digitalPinToInterrupt(BTN_B_PIN), btn_b_ISR, RISING);  //Isn't build in yet

    Serial.println("Setup done...");

    cmdArr[0] = "a/0/200/50/10";
    cmdArr[1] = "a/1/100/3/3/4/5";
}
