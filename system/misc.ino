void errorOut() {
    if (errorIndex == -1) {
        return;
    } else {
        //output(errorStore[errorIndex] + '(' + errorComment[errorStore[errorIndex].charAt(0)] + ')');
        //output(errorStore[errorIndex] + ' (' + errorComment[(int) errorStore[errorIndex].charAt(0)] + ')');
        output(errorStore[errorIndex]);
        output(" (");
        output(errorComment[errorStore[errorIndex].charAt(0) - '0']);
        outputln(")");

        errorIndex = -1;
    }
}

void output(String msg) {
    Serial.print(msg);
    //output via Wifi or other channels to be added
}
void outputln(String msg) {
    Serial.print(msg);
    Serial.println();
    //output via Wifi or other channels to be added
}

void btn_a_ISR() {
    if (lastInterrupt + INTERRUPT_DEBOUNCE_TIME < millis()) {
        next(1);
        lastInterrupt = millis();
    }
}

void next(int steps) {
    for (uint8_t i = 0; i < steps; i++) {
        if (currentApp + 1 < appCount) {
            currentApp++;
        } else {
            currentApp = 0;
        }
        output("Next App: " + apps[currentApp]->getName() + "\n");
    }
}

void previous(int steps) {
    if (lastInterrupt + INTERRUPT_DEBOUNCE_TIME < millis()) {
        for (uint8_t i = 0; i < steps; i++) {
            if (currentApp > 0) {
                currentApp--;
            } else {
                currentApp = appCount - 1;
            }
            output("Previous App: " + apps[currentApp]->getName() + "\n");
        }
        lastInterrupt = millis();
    }
}

void sysReset() {
    //asm volatile("  jmp 0");
    ESP.restart();
}

void setTime(String parameters[]) {  //   t/s/Y/M/D/w/H/M/S
    rtc.setYear(parameters[2].toInt());
    rtc.setMonth(parameters[3].toInt());
    rtc.setDate(parameters[4].toInt());
    rtc.setDoW(parameters[5].toInt());
    rtc.setHour(parameters[6].toInt());
    rtc.setMinute(parameters[7].toInt());
    rtc.setSecond(parameters[8].toInt());

    printTime();
}

void printTime() {
    Serial.print(dow[rtc.getDoW() - 1]);
    Serial.print(", ");
    Serial.print(rtc.getDate(), DEC);
    Serial.print(".");
    Serial.print(rtc.getMonth(Century), DEC);
    Serial.print(".");
    Serial.print(rtc.getYear(), DEC);
    Serial.print(" ");

    Serial.print(rtc.getHour(h12, PM), DEC);
    Serial.print(":");
    Serial.print(rtc.getMinute(), DEC);
    Serial.print(":");
    Serial.print(rtc.getSecond(), DEC);
    Serial.print("\n");
}
