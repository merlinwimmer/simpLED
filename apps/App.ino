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

void addApp(byte appID, String parameters[]) {
    int n = appCount;
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
        outputln("No more storage for another app");
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

void getApp(int n) {
    if (n < appCount) {
        outputln(apps[n]->get());
    }
}

void printApps() {
    for (int i = 0; i < appCount; i++) {
        output(apps[i]->getName() + ": ");
        outputln((String)apps[i]->get());
    }
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
