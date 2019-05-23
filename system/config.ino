void configManager::load() {
    EEPROM.begin(sizeof(config));
    outputln("EEPROM.begin(" + String(sizeof(config)) + ");");
    Serial.println("EEPROM.get(EEPROM_BEGIN, config);");
    EEPROM.get(EEPROM_BEGIN, config);
    brightness = config.brightness;
    currentApp = config.currentApp;
    appCount = config.appCount;
    String appString = "";
    for (int i = 0; i < APP_MAX_LENGTH; i++) {
        appString += config.appCharArr[i];
    }
    outputln("Loaded appString: " + String(appString));

    appCount = 0;
    int j = 0;

    for (int i = 0; i < config.appCount; i++) {
        String appName = "";
        String appCmd = "";
        while (config.appCharArr[j] != '{') {
            appName += config.appCharArr[j];
            j++;
        }
        outputln("appName number " + String(i) + " is done, " + appName);
        j++;
        while (config.appCharArr[j] != '}') {
            appCmd += config.appCharArr[j];
            j++;
        }
        outputln("appCmd number " + String(i) + " is done, " + appCmd);
        j++;
        parser("a/a/" + appCmd);
        apps[i]->setName(appName);
        if (config.appCharArr[j] == APP_TERMINATOR) {
            break;
        } else {
            j++;
        }
    }
    EEPROM.end();
    outputln("#### Load done");
}

void configManager::store() {
    config.brightness = brightness;
    config.currentApp = currentApp;
    config.appCount = appCount;

    String appString = getApps();
    for (unsigned int i = 0; i < appString.length(); i++) {
        config.appCharArr[i] = appString.charAt(i);
    }
    output("Stored appCharArr: ");
    for (int i = 0; i < APP_MAX_LENGTH; i++) {
        output(String(config.appCharArr[i]));
    }
    outputln("");

    EEPROM.begin(sizeof(config));
    EEPROM.put(EEPROM_BEGIN, config);
    EEPROM.end();  // Free RAM copy of structure
}