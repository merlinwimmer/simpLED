void loop() {
    delay(1);

    apps[currentApp]->refresh();
    checkSerial();
    errorOut();
}