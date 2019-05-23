void App::setName(String name) {
    this->name = name;
}

String App::getName() {
    return this->name;
}

void App::refresh() {
    output("no refresh function defined for " + this->getName() + "\n");
}

String App::get() {
    return ("no get function defined for " + this->getName() + "\n");
}

void App::set(String parameters[]) {
    output("no set function defined for " + this->getName() + "\n");
}

void addApp(String parameters[]) {
    int n = appCount;
    short appID = parameters[0].toInt();
    if (appCount < MAX_APPS) {
        outputln("Adding new App...");
        switch (appID) {
            case 0:
                apps[n] = new FullColor();
                break;
            case 1:
                apps[n] = new SnakeA();
                break;
        }
        appCount++;
        setApp(n, parameters);
    } else {
        outputln("No more storage for another app, already " + String(appCount + 1) + " Apps saved");
    }
}

void delApp(int n) {
    if (appCount > 1) {
        outputln("Deleting App no. " + String(n));
        appCount--;
        for (int i = n; i < appCount; i++) {
            apps[i] = apps[i + 1];
        }
        if (n == currentApp) {
            next(1);
        }
    } else {
        outputln("Can't delete, only one App left");
    }
}

String getApp(int n) {
    if (n < appCount) {
        return apps[n]->get();
    }
    return "No " + String(n) + ". found.";
}

String getApps() {
    String appString = "";
    for (int i = 0; i < appCount; i++) {
        appString += apps[i]->getName();
        appString += "{";
        appString += apps[i]->get();
        appString += "}";
        if (i + 1 < appCount) {     // ',' between two apps
            appString += APP_SEPERATOR;
        } else {                    // ';' after last app
            appString += APP_TERMINATOR;
        }
    }
    return appString;
}

void setApp(int n, String parameters[]) {
    if (n < appCount) {
        outputln("Setting " + String(n) + "th app to given parameters...");
        apps[n]->set(parameters);
    } else {
        outputln("There is no " + String(n) + "th app!");
    }
}

void swapApps(int a, int b) {
    App* temp = apps[a];
    apps[a] = apps[b];
    apps[b] = temp;
}
