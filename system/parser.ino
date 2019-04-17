void parser(String cmd) {
    String parameters[MAX_PARAMETER] = "";
    Serial.println("Parser started for command: " + cmd);

    int parameterIndex = 0;

    char cmdType = cmd.charAt(0);

    uint8_t i = 1;
    for (; i < cmd.length() && parameterIndex < MAX_PARAMETER; i++)  //divide the incoming command s into parameters
    {
        if (cmd.charAt(i) == seperator) {
            parameterIndex++;
        } else {
            parameters[parameterIndex] += cmd.charAt(i);
        }
    }

    if (parameterIndex >= MAX_PARAMETER) {
        errorIndex = 2;
    }

    Serial.println("Following parameters were parsed: ");
    for (int i = 0; i <= parameterIndex; i++) {
        Serial.println("    " + parameters[i]);
    }

    switch (cmdType) {
        case 'a':  //App-Command    (AppID/Parameter1/Parameter2/Parameter3/ ...)
            currentApp = parameters[0].toInt();
            app_setup[currentApp](parameters);
            break;
        case 'n':  //Next          (optionally: steps forward)
            next(parameterIndex == 1 ? parameters[0].toInt() : 1);
        case 'p':  //Previous          (optionally: steps backwards)
            previous(parameterIndex == 1 ? parameters[0].toInt() : 1);
        case 'b':  //Previous          (brightness 0-255)
            FastLED.setBrightness(parameters[0].toInt());
            Serial.print("Brightness set to ");
            Serial.print((parameters[0].toInt() / 255) * 100);
            Serial.println("%");
        default:
            break;
    }
}