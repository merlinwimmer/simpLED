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
        if (cmdIndex + 1 < command_count) {
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
                cmdIndex = command_count - 1;
            }
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

void addCMD(String newCMD) {
    if (command_count < MAX_CMDS) {
        command_count++;
        newCMD.replace(",", "/");
        cmdArr[command_count - 1] = newCMD;
    }
    printCMDs();
}

void delCMD(int n) {
    if (command_count > 1) {
        Serial.print("Deleting cmd ");
        Serial.println(n);
        command_count--;
        for (int i = n; i < command_count; i++) {
            cmdArr[i] = cmdArr[i + 1];
        }
        cmdArr[command_count] = "";
    } else {
        output("Only one cmd left");
    }
}

void printCMDs() {
    Serial.println("List of CMDs:");
    for (int i = 0; i < command_count; i++) {
        Serial.println("  " + cmdArr[i]);
    }
}

void switchCMDs(int a, int b) {
    String temp = cmdArr[a];
    cmdArr[a] = cmdArr[b];
    cmdArr[b] = temp;
}