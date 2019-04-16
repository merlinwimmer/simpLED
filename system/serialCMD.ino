void checkSerial() {    
    String serialString = "";
    while (Serial.available()) {
        delay(2);  //delay to allow byte to arrive in input buffer
        char c = Serial.read();
        serialString += c;
    }
    if (serialString.length() > 0) {
        Serial.println("Received via Serial: " + serialString);
        parser(serialString);
    }
}
