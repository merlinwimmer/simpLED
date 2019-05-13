void parser(String cmd) {
    String parameters[MAX_PARAMETER] = "";
    output("Parser started for command: " + cmd + "\n");

    if (cmd.equals("__RESET__") || cmd.equals("RST")) {
        output("Resetting simpLED...\n");
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

    output("Following parameters were parsed: \n");
    for (int i = 0; i <= parameterIndex; i++) {
        Serial.println("    " + parameters[i]);
    }

    output("parameterIndex is: ");
    output((String) parameterIndex);
    output(", cmType is: ");
    output((String) cmdType + "\n");

    switch (cmdType) {
        case 'a':                        //App-Command    (cmdType/action/AppID/Parameter1/Parameter2/Parameter3/ ...)
            if (parameters[1] == "a") {  //add app
                addApp(parameters);
            } else if (parameters[1] == "d") {  //delete App
                delApp(parameters[2].toInt());
            } else if (parameters[1] == "p") {  //print all Apps with parameters
                printApps();
            } else if (parameters[1] == "s") {  //switch two Apps
                switchApps(parameters[2].toInt(), parameters[3].toInt());
            }
            break;
        case 'n':  //Next          (cmdType/optionally: steps forward)
            next(parameterIndex > 0 ? parameters[1].toInt() : 1);
            break;
        case 'p':  //Previous          (cmdType/optionally: steps backwards)
            previous(parameterIndex > 0 ? parameters[1].toInt() : 1);
            break;
        case 'b':  //Brightness          (cmdType/brightness 0-255)
            FastLED.setBrightness(parameters[1].toInt());
            output("Brightness set to ");
            output((String) (parameters[1].toInt() * 100 / 255));
            output("%\n");
            break;
        case 't':                        //time          (cmdType/s)
            if (parameters[1] == "s") {  //set
                setTime(parameters);
            } else if (parameters[1] == "p") {  //print
                printTime();
            }
            break;
        default:
            break;
    }
}