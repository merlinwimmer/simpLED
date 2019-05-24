void setup() {
    Serial.begin(115200);
    Serial.println("\n\n\n");
    Serial.println("                                                                                                    \n                                                                                                    \n                                                                                                    \n                                                .:++++++++++/:.                                     \n                                             ./oo/-.       .-/oo/                                   \n                                            /s/.               ./s/                                 \n                                          .s+.                   .+s.                               \n                                          s+                       /s.                              \n                                         /s                         o+                              \n                                         y/                         -h                              \n                                         y:                         .d                              \n                                         y:                         .d                              \n                                         y:      /++++++/:.         .d                              \n                                         y:      .......-:oo-       .d.                             \n                                         y:                :y.      .d.                             \n          -:/:-     .:   .:.            .h:    -/////:-     o+      .d::::::::-  .:::--.            \n        .o+---/o.   -y   :hs.          .sd:    +o----:+o:   +o      .d:-------.  :y:://++:.         \n        /s     .    -y   :y/s-        -s:y:    +o      .s+  +o       d.          :y     -+s-        \n        .s/.        -y   :y :s-      :s- y:    +o       -h  +o       d.          :y       -y-       \n         ./++/:.    -y   :y  -s:    /s-  y:    +o       +s  +o       d-.......   :y        /s       \n            .-/o+.  -y   :y   .s/  +s.   y:    +o    .-+o.  +o       d++++++++:  :y        -h       \n                /s  -y   :y    .o+oo.    y:    +y+++++/-    +o       d-          :y        /s       \n       -         h. -y   :y      ++    .+s-    +o           +o       +o+         :y       :y-       \n       o+.     ./s  -y   :y            /s      +o           +o        .h.        :y    .-+o-        \n       ./o/:-:/o+.  -y   :s            -y/:::::ss::::::.    +o  .:::::oy::::::.  :y://+o+-          \n          -:::-.    .-   .-             .::::::os::::::.    +s  .:::::::::::::.  .:---.             \n                                               +o           /s                                      \n                                               +o           /s                                      \n                                               +o           /y///////////-                          \n                                               +o                                                   \n                                               +o                                                   \n                                               +o                                                   \n                                               --                                                   \n                                                                                                    \n                                                                                                    ");
    Serial.println("\n\n\n");
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

    parser("a/a/0/200/50/10");
    apps[0]->setName("Vollbild Farbe");
    parser("a/a/1/1/60/3/3/4/6");
    apps[1]->setName("Schlangen-Animation");

    configManager::load();

    outputln("### Setup done");
}
