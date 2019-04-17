//FastLED
#define LEDS_X 10
#define LEDS_Y 10
#define NUM_LEDS 100
#define DATA_PIN 4  //D4
CRGB leds[NUM_LEDS];

//Controls
const byte BTN_A_PIN = 5;  //D1
unsigned long lastInterrupt = 0;
#define INTERRUPT_DEBOUNCE_TIME 50

//Parser
const char seperator = '/';
#define MAX_PARAMETER 8

//System

String serialString = "";     // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

byte errorIndex = 0;  //-1 means no error   syntax (is analyzed by errorOut() ): errortype errormessage
const String errorStore[] = {
    /*0*/ "0 No Error",
    /*1*/ "0 ",
    /*2*/ "4 Too many parameters in command",
    /*3*/ "4 Not enough parameters, using prior/default",
    /*4*/ "5 No valid AppID",
    /*5*/ "5 No valid Command"};

const String errorComment[] = {
    /*0*/ "Minor System Error",
    /*1*/ "Major System Error",
    /*2*/ "idk",
    /*3*/ "idk",
    /*4*/ "minor parsing error",
    /*5*/ "major parsing error"};

// Error Types
// 0 minor system error
// 1 major system error
// 2
// 3
// 4 minor parsing error
// 5 major parsing error

//Settings
bool wifiMode = false;
byte brightness = 255;

//Apps

void (*app[2])(){
    app_fc,
    app_snake};

void (*app_setup[2])(String parameters[]){
    app_fc_setup,
    app_snake_setup};

bool cmdChanged = true;
byte currentApp = 0;
byte cmdIndex = 0;

#define COMMAND_COUNT 2
String cmdArr[COMMAND_COUNT] = {
    "a/0/200/50/10",
    "a/1/100/3/3/4/5"};

//Standart Colors
byte colors[16][3] = {
    {0, 0, 0},        //black
    {255, 255, 255},  //white
    {255, 0, 0},      //red
    {255, 106, 0},    //orange
    {255, 216, 0},    //yellow
    {182, 255, 0},    //neon green
    {76, 255, 0},     //green
    {0, 255, 33},     //green
    {0, 255, 144},    //blue green
    {0, 255, 255},    //light blue
    {0, 148, 255},    //blue
    {0, 38, 255},     //dark blue
    {72, 0, 255},     //slight purple
    {178, 0, 255},    //purple
    {255, 0, 220},    //pink
    {255, 0, 110}     //magenta
};
