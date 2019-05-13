void App::setName(String name) {
    this->name = name;
}

String App::getName() {
    return this->name;
}


String App::print() {
    return "no print function defined for " + this->getName() + "\n";
}
void App::refresh() {
    output("no refresh function defined for " + this->getName() + "\n");
}


void addApp(String parameters[]) {
    if (appCount < MAX_APPS) {
        byte i = 2;
        switch (parameters[i++].toInt())  //AppID
        {
            case 0: {  //Full Screen Color
                byte r = parameters[i++].toInt();
                byte g = parameters[i++].toInt();
                byte b = parameters[i++].toInt();
                apps[appCount] = new FullColor(r, g, b);
                break;
            }
            case 1: {  //SnakeAnimation
                int d = parameters[i++].toInt();
                int colorCount = parameters[i++].toInt();
                byte temp_colors[colorCount];
                for (int j = 0; j < colorCount; j++) {
                    temp_colors[j] = parameters[i++].toInt();
                }
                apps[appCount] = new SnakeA(d, colorCount, temp_colors);
                break;
            }
            default:
                errorIndex = 4;  //No valid AppID
                return;
        }
        appCount++;
    }
}

void delApp(int n) {
    if (appCount > 1) {
        output("Deleting cmd " + n);
        appCount--;
        delete apps[n];
        for (int i = n; i < appCount; i++) {
            apps[i] = apps[i + 1];
        }
        delete apps[appCount];
    } else {
        output("Only one cmd left");
    }
}

void printApps() {
    output("Apps: {");
    for (int i = 0; i < appCount; i++) {
        output(apps[i]->print());
    }
    output("}");
}

void switchApps(int a, int b) {
    App* temp = apps[a];
    apps[a] = apps[b];
    apps[b] = temp;
}