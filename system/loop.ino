void loop() {
    delay(10);
    //Serial.println("loop");
    if (cmdChanged) {
        Serial.print("cmd has Changed: cmdIndex = ");
        Serial.println(cmdIndex, DEC);
        parser(cmdArr[cmdIndex]);
        cmdChanged = false;
    }

    app[currentApp]();
    checkSerial();
    errorOut();
}
