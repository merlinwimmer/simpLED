void parser(String cmd) {
    String parameters[MAX_PARAMETER] = "";
    Serial.println("Parser started for command: " + cmd);

    if (cmd.equals("__RESET__") || cmd.equals("RST")) {
        Serial.println("Resetting simpLED...");
        sysReset();
    }

    int parameterIndex = 0;

    uint8_t i = 0;
    for (; i < cmd.length() && parameterIndex < MAX_PARAMETER; i++)  //divide the incoming command s into parameters
    {
        if (cmd.charAt(i) == seperator) {
            parameterIndex++;
        } else {
            parameters[parameterIndex] += cmd.charAt(i);
        }
    }

    char cmdType = parameters[0].charAt(0);

    if (parameterIndex >= MAX_PARAMETER) {
        errorIndex = 2;
    }

    Serial.println("Following parameters were parsed: ");
    for (int i = 0; i <= parameterIndex; i++) {
        Serial.println("    " + parameters[i]);
    }

    Serial.print("parameterIndex is: ");
    Serial.print(parameterIndex);
    Serial.print(", cmType is: ");
    Serial.println(cmdType);

    switch (cmdType) {
        case 'a':  //App-Command    (cmdType/AppID/Parameter1/Parameter2/Parameter3/ ...)
            currentApp = parameters[1].toInt();
            app_setup[currentApp](parameters);
            break;
        case 'n':  //Next          (cmdType/optionally: steps forward)
            next(parameterIndex > 0 ? parameters[1].toInt() : 1);
            break;
        case 'p':  //Previous          (cmdType/optionally: steps backwards)
            previous(parameterIndex > 0 ? parameters[1].toInt() : 1);
            break;
        case 'b':  //Previous          (cmdType/brightness 0-255)
            FastLED.setBrightness(parameters[1].toInt());
            Serial.print("Brightness set to ");
            Serial.print(parameters[1].toInt() * 100 / 255);
            Serial.println("%");
            break;
        case 't':  //Previous          (cmdType/brightness 0-255)
            if (parameters[1] == "s") {
                setTime(parameters);
            } else if (parameters[1] == "p") {
                printTime();
            }
            break;
        default:
            break;
    }
}