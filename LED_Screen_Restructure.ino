// Setup
#include <FastLED.h>
#define NUM_LEDS 512
#define DATA_PIN A0
CRGB leds[NUM_LEDS];
const int f2p[] = {1,2,3,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,25,26,27,28,29,30,38,39,46,47,48,49,56,57,70,71,74,75,76,77,78,79,80,81,82,83,84,85,88,89,98,99,100,101,102,103,110,111,112,113,120,121,122,123,124,125,134,135,142,143,144,145,152,153,166,167,174,175,176,177,184,185,198,199,206,207,208,209,216,217,225,226,227,228,229,230,231,238,239,240,241,248,249,250,251,252,253,254,257,258,259,260,261,262,266,267,268,269,274,275,276,277,281,282,283,284,285,286,289,290,293,294,296,297,302,303,304,305,310,311,313,314,317,318,321,322,325,326,328,329,334,335,336,337,338,339,340,341,342,343,345,346,347,348,349,350,353,354,355,356,357,358,360,361,362,363,364,365,366,367,368,369,374,375,377,378,379,386,387,388,389,390,392,393,398,399,400,401,406,407,409,410,412,413,417,418,421,422,424,425,430,431,432,433,438,439,441,442,445,446,449,450,453,454,456,457,462,463,464,465,470,471,473,474,478,479,480,481,485,486,488,489,494,495,496,497,502,503,505,506,510,511};
const int f3p[] = {54,55,56,68,70,71,72,73,74,76,82,84,85,86,87,88,89,90,92,98,101,102,103,104,105,106,107,110,116,117,118,119,120,121,122,132,133,134,135,136,137,138,139,140,146,148,149,150,151,152,153,154,156,162,165,166,167,168,169,170,171,174,179,181,182,183,184,185,187,195,199,200,201,205,209,221,294,295,296,297,309,314,315,324,331,340,343,345,347,356,358,360,363,372,379,388,395,404,411,420,427,436,443,452,453,457,459,469,471,472,473};
const int f3r[] = {214,216};


void setup() {
    Serial.begin(9600);
    FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(10);
    FastLED.clear(true);
}

void display() {
    FastLED.show();
    Serial.print("display     ");
    delay(15000);
    FastLED.clear(true);
}

void addDisplay(int vScreenArray[], CRGB vColor) {
    // See https://forum.arduino.cc/t/crgb-color-as-a-function-argument/620376 for sample calls
    int i =0;
    Serial.print("addDisplay     ");
    int arraySize = sizeof(vScreenArray);
    for(i = 0; i < arraySize; i++){
        leds[vScreenArray[i]] = CRGB::Purple; //vColor;
    }
}

void loop() {
    FastLED.clear(true);

    // FEAR - Words in Purple
        int screenArray = f2p;
        CRGB color = "Purple";
        Serial.print("f2p     ");
        addDisplay(screenArray, color);
        display();

    // FEAR - Spider and Ghost
        screenArray = f3p;
        color = "Purple";
        Serial.print("f3p     ");
        addDisplay(screenArray, color);
        screenArray = f3r;
        color = "Red";
        Serial.print("f3r     ");
        addDisplay(screenArray, color);
        display();
        
}
