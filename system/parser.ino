void parser(String cmd) {
    String parameters[MAX_PARAMETER] = "";
    output("### parser started for command: " + cmd + "\n");

    if (cmd.equals("__RESET__") || cmd.equals("RST")) {
        output("Resetting simpLED...\n");
        sysReset();
    }

    unsigned short parameterIndex = 0;

    for (unsigned short i = 0; i < cmd.length() && parameterIndex < MAX_PARAMETER; i++)  //divide the incoming command s into parameters
    {
        if (cmd.charAt(i) == seperator) {
            parameterIndex++;
        } else {
            parameters[parameterIndex] += cmd.charAt(i);
        }
    }

    char cmdType = parameters[0].charAt(0);

    String shortParam[MAX_PARAMETER] = "";  //Parameters without the first 3 parameters, so cmdType, operation and appType/appPosition
    byte j = 0;
    for (byte i = 2; i <= parameterIndex; i++) {
        shortParam[j] = parameters[i];
        j++;
    }

    if (parameterIndex >= MAX_PARAMETER) {
        errorIndex = 2;
    }

    outputln("Following parameters were parsed:");
    for (int i = 0; i <= parameterIndex; i++) {
        outputln("    " + parameters[i]);
    }
    if (parameterIndex >= 3) {
        outputln("Following shortParam's were parsed:");
        for (int i = 0; i <= parameterIndex - 3; i++) {
            outputln("    " + shortParam[i]);
        }
    }

    output("parameterIndex is: ");
    output((String)parameterIndex);
    output(", cmdType is: ");
    output((String)cmdType + "\n");

    switch (cmdType) {
        case 'a':                        //App-Command    (cmdType/action/AppID/Parameter1/Parameter2/Parameter3/ ...)
            if (parameters[1] == "a") {  //add app

                addApp(shortParam);
            } else if (parameters[1] == "d") {  //delete App
                delApp(parameters[2].toInt());
            } else if (parameters[1] == "g") {  //get App cmd
                if (parameters[2] == "c") {     //get current App
                    outputln(getApp(currentApp));
                } else {
                    outputln(getApp(parameters[2].toInt()));
                }
            } else if (parameters[1] == "p") {  //print all Apps with parameters
                outputln(getApps());
            } else if (parameters[1] == "s") {  //set all Apps with parameters
                setApp(shortParam);
            } else if (parameters[1] == "w") {  //sWap two Apps
                swapApps(parameters[2].toInt(), parameters[3].toInt());
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
            output((String)(parameters[1].toInt() * 100 / 255));
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
            errorIndex = 5;  //No valid Command
            break;
    }
    outputln("### parser done");
}
