void errorOut() {
    if (errorIndex == 0) {
        return;
    }

    //output(errorStore[errorIndex] + '(' + errorComment[errorStore[errorIndex].charAt(0)] + ')');
    //output(errorStore[errorIndex] + ' (' + errorComment[(int) errorStore[errorIndex].charAt(0)] + ')');
    output(errorStore[errorIndex] + " (" + errorComment[errorStore[errorIndex].charAt(0) - '0'] + ")");

    errorIndex = -1;
}

void output(String msg) {
    Serial.println(msg);

    //output via Wifi or other channels to be added
}

void btn_a_ISR() {
    if (lastInterrupt + INTERRUPT_DEBOUNCE_TIME < millis()) {
        next(1);
        lastInterrupt = millis();
    }
}

void next(int steps) {
    cmdChanged = true;
    for (uint8_t i = 0; i < steps; i++) {
        if (cmdIndex + 1 < COMMAND_COUNT) {
            cmdIndex++;
        } else {
            cmdIndex = 0;
        }
    }
}

void previous(int steps) {
    if (lastInterrupt + INTERRUPT_DEBOUNCE_TIME < millis()) {
        cmdChanged = true;
        for (uint8_t i = 0; i < steps; i++) {
            if (cmdIndex > 0) {
                cmdIndex--;
            } else {
                cmdIndex = COMMAND_COUNT - 1;
            }
        }
        lastInterrupt = millis();
    }
}