//#include <Arduino.h>

// EEPROM
#include <EEPROM.h>

// Wifi
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiUdp.h>
ESP8266WiFiMulti wifi;

//Artnet
#include <ArtnetWifi.h>

//FastLED
#include <FastLED.h>

//DS3231 RTC
#include <Wire.h>
#include "DS3231.h"
DS3231 rtc;
bool h12;
bool PM;
bool Century = false;

/*
//DS18b20

#include <DallasTemperature.h>
#define ONE_WIRE_PIN 10
OneWire oneWire(ONE_WIRE_PIN);
DallasTemperature sensors(&oneWire);
*/
