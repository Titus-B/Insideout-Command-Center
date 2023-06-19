/// Working LEDs 
///Testing Sound

// Setup
    #include <FastLED.h>
    #define NUM_LEDS 512
    #define DATA_PIN A0
    #include "SD.h"
    #define SD_ChipSelectPin 10
    #include "TMRpcm.h"
    #include "SPI.h"
    TMRpcm sound;
    CRGB leds[NUM_LEDS];
    // SCREENS 
//        const int default1[] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,47,46,45,44,43,36,35,34,33,32,48,49,50,51,60,61,62,63,79,78,77,74,73,72,71,70,69,66,65,64,80,81,82,85,86,87,88,89,90,93,94,95,111,110,109,106,105,104,103,102,101,98,97,96,112,113,114,117,118,119,120,121,122,125,126,127,143,142,141,138,137,136,135,134,133,130,129,128,144,145,146,149,150,151,152,153,154,157,158,159,175,174,173,170,169,168,167,166,165,162,161,160,176,177,178,181,182,183,184,185,186,189,190,191,207,206,205,204,201,200,199,198,195,194,193,192,208,209,210,211,212,219,220,221,222,223,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,271,270,269,268,267,266,265,264,263,262,261,260,259,258,257,256,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,303,302,301,300,297,296,295,294,291,290,289,288,304,305,306,307,310,311,312,316,317,318,319,335,334,333,332,329,328,324,323,322,321,320,336,337,338,339,342,346,347,348,349,350,351,367,366,365,364,361,358,357,356,355,354,353,352,368,369,370,371,376,377,378,379,380,381,382,383,399,398,397,396,390,389,388,387,386,385,384,400,401,402,403,406,410,411,412,413,414,415,431,430,429,428,425,424,420,419,418,417,416,432,433,434,435,438,439,440,444,445,446,447,463,462,461,460,457,456,455,454,450,449,448,464,465,466,467,470,471,472,473,474,477,478,479,495,494,493,492,491,490,489,488,487,486,485,484,483,482,481,480,496,497,498,499,500,501,502,503,504,505,506,507,508,509,510,511};
        const int default2[] = {42,41,40,39,38,37,52,53,54,55,56,57,58,59,76,75,68,67,83,84,91,92,108,107,100,99,115,116,123,124,140,139,132,131,147,148,155,156,172,171,164,163,179,180,187,188,203,202,201,200,199,198,197,196,213,214,215,216,217,218,299,298,293,292,308,309,313,314,315,331,330,327,326,325,340,341,343,344,345,363,362,360,359,372,373,374,375,395,394,393,392,391,404,405,407,408,409,427,426,423,422,421,436,437,441,442,443,459,458,453,452,451,468,469,475,476};
        const int j1y[] = {17,18,19,20,21,22,23,24,25,26,46,45,44,43,42,41,40,39,38,37,53,54,74,73,65,64,85,86,93,94,95,106,105,99,98,117,118,124,125,138,137,131,130,149,150,156,157,170,169,163,162,181,182,188,189,206,202,201,195,194,209,213,214,220,221,238,237,236,235,234,233,226,225,224,241,242,243,244,245,246,254,255,297,296,291,290,310,311,316,317,334,329,328,323,322,335,336,337,338,342,343,348,349,365,364,361,360,355,354,370,371,374,375,380,381,397,396,392,391,390,389,388,387,402,403,407,408,409,410,411,412,429,428,422,421,434,435,441,442,461,460,454,453,466,467,473,474,495,496,494,493,486,485,497,505,506};
        const int j2y[] = {8,18,19,23,27,28,45,44,43,37,36,35,51,54,55,56,59,74,73,72,71,70,84,85,86,87,88,89,90,107,106,104,102,101,113,114,116,117,119,121,122,124,125,142,141,139,138,137,136,135,134,133,131,130,148,149,150,151,152,153,154,171,169,168,167,165,180,181,185,186,202,201,200,199,198,211,214,215,216,219,237,236,235,229,228,227,242,243,247,251,252,264,275,279,283,284,301,300,299,293,292,291,307,310,311,312,315,330,329,328,327,326,340,341,342,343,344,345,346,363,362,360,358,357,369,370,372,373,375,377,378,380,381,398,397,395,394,393,392,391,390,389,387,386,404,405,406,407,408,409,410,427,425,424,423,421,436,437,441,442,458,457,456,455,454,467,470,471,472,475,493,492,491,485,484,483,498,499,503,507,508};
        const int j2p[] = {105,103,118,120,170,182,183,184,166,361,359,374,376,426,438,439,440,422};
//        const int f1p[] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,47,46,45,39,38,32,48,49,50,56,57,63,79,78,77,75,74,73,72,71,70,68,67,66,65,64,80,81,82,84,85,86,87,88,89,91,92,93,94,95,111,110,109,105,104,103,102,98,97,96,112,113,114,118,119,120,121,125,126,127,143,142,141,139,138,137,136,135,134,132,131,130,129,128,144,145,146,148,149,150,151,152,153,155,156,157,158,159,175,174,173,171,170,169,168,167,166,164,163,162,161,160,176,177,178,180,181,182,183,184,185,187,188,189,190,191,207,206,205,203,202,201,200,199,198,192,208,209,210,212,213,214,215,216,217,223,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,271,270,269,268,267,266,265,264,263,262,261,260,259,258,257,256,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,303,302,298,297,296,291,290,289,288,304,310,311,317,318,319,335,333,332,331,329,328,326,325,324,322,321,320,336,338,339,340,342,343,345,346,347,349,350,351,367,361,360,354,353,352,368,374,375,380,381,382,383,399,397,396,395,393,392,390,388,387,386,385,384,400,402,403,404,406,407,409,412,413,414,415,431,429,428,427,425,424,422,421,419,418,417,416,432,434,435,436,438,439,441,442,445,446,447,463,461,460,459,457,456,454,453,452,450,449,448,464,466,467,468,470,471,473,474,475,477,478,479,495,494,493,492,491,490,489,488,487,486,485,484,483,482,481,480,496,497,498,499,500,501,502,503,504,505,506,507,508,509,510,511};
        const int f2p[] = {1,2,3,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,25,26,27,28,29,30,38,39,46,47,48,49,56,57,70,71,74,75,76,77,78,79,80,81,82,83,84,85,88,89,98,99,100,101,102,103,110,111,112,113,120,121,122,123,124,125,134,135,142,143,144,145,152,153,166,167,174,175,176,177,184,185,198,199,206,207,208,209,216,217,225,226,227,228,229,230,231,238,239,240,241,248,249,250,251,252,253,254,257,258,259,260,261,262,266,267,268,269,274,275,276,277,281,282,283,284,285,286,289,290,293,294,296,297,302,303,304,305,310,311,313,314,317,318,321,322,325,326,328,329,334,335,336,337,338,339,340,341,342,343,345,346,347,348,349,350,353,354,355,356,357,358,360,361,362,363,364,365,366,367,368,369,374,375,377,378,379,386,387,388,389,390,392,393,398,399,400,401,406,407,409,410,412,413,417,418,421,422,424,425,430,431,432,433,438,439,441,442,445,446,449,450,453,454,456,457,462,463,464,465,470,471,473,474,478,479,480,481,485,486,488,489,494,495,496,497,502,503,505,506,510,511};
        const int f3p[] = {54,55,56,68,70,71,72,73,74,76,82,84,85,86,87,88,89,90,92,98,101,102,103,104,105,106,107,110,116,117,118,119,120,121,122,132,133,134,135,136,137,138,139,140,146,148,149,150,151,152,153,154,156,162,165,166,167,168,169,170,171,174,179,181,182,183,184,185,187,195,199,200,201,205,209,221,294,295,296,297,309,314,315,324,331,340,343,345,347,356,358,360,363,372,379,388,395,404,411,420,427,436,443,452,453,457,459,469,471,472,473};
        const int f3r[] = {214,216};
        const int s1b[] = {21,22,23,24,25,26,30,31,43,42,41,40,39,38,37,33,32,52,53,60,61,75,74,73,67,66,85,86,92,93,106,105,104,99,98,97,96,118,119,124,125,126,127,137,136,131,130,150,151,156,157,169,168,163,162,181,182,188,189,202,201,195,194,209,210,211,212,213,214,220,221,238,237,236,235,234,233,227,226,272,273,278,279,280,281,282,283,303,302,297,296,295,294,293,292,291,306,307,310,316,333,332,329,323,338,339,342,348,367,366,365,364,361,355,368,369,370,371,374,380,397,396,393,387,402,403,406,412,429,428,425,419,434,435,438,444,461,460,457,451,466,467,470,471,472,473,474,475,476,493,492,489,488,487,486,485,484};
        const int s2b[] = {21,42,52,53,54,63,75,74,73,64,83,84,85,86,87,94,95,108,107,106,105,104,97,96,114,115,116,117,118,119,120,125,126,127,141,140,139,138,137,136,135,130,129,128,146,147,148,149,150,151,152,157,158,159,173,172,171,170,169,168,167,162,161,160,178,179,180,181,182,183,184,189,190,191,204,203,202,201,200,193,192,211,212,213,214,215,222,223,235,234,233,224,272,283,303,292,304,305,314,315,316,335,334,325,324,323,336,337,338,345,346,347,348,349,367,366,365,358,357,356,355,354,368,369,370,371,376,377,378,379,380,381,382,399,398,397,396,391,390,389,388,387,386,385,400,401,402,403,408,409,410,411,412,413,414,431,430,429,428,423,422,421,420,419,418,417,432,433,434,435,440,441,442,443,444,445,446,463,462,461,454,453,452,451,450,464,465,466,473,474,475,476,477,495,494,485,484,483};
//        const int s3b[] = {13,12,11,10,9,17,18,19,20,21,22,23,30,31,46,45,44,43,42,41,40,34,33,32,49,50,51,52,53,54,55,60,61,62,63,77,76,75,74,73,67,66,65,64,83,84,85,92,93,94,95,98,97,96,116,119,125,126,127,141,139,136,129,128,146,156,170,163,179,181,183,190,206,204,200,193,209,220,223,234,227,224,245,279,280,281,282,303,297,296,295,294,293,292,304,305,309,310,311,312,313,314,315,316,335,334,330,329,328,327,326,325,324,323,336,337,341,342,343,344,345,346,347,348,367,362,361,360,359,358,357,356,355,368,374,375,376,377,378,379,392,391,390,389,401,430,425,421,419,438,442,444,463,458,455,464,469,472,484,503,505,507};
        const int d1g[] = {47,46,45,44,41,38,37,36,34,33,32,48,52,54,57,61,79,75,73,70,66,80,84,86,89,93,111,107,105,101,100,98,112,116,118,123,125,143,139,137,132,130,144,148,150,155,157,175,171,169,164,162,160,176,180,182,187,189,207,203,201,196,194,208,209,210,211,214,216,217,218,219,221,222,223,303,301,298,295,294,293,291,290,289,288,306,309,312,318,333,330,327,321,338,341,345,350,365,362,357,353,370,373,378,382,397,394,389,385,402,405,410,414,431,429,426,421,417,432,434,437,442,446,463,461,458,453,449,464,466,467,468,469,471,472,473,474,478};
        const int d2g[] = {35,34,59,60,61,62,75,74,69,68,67,66,65,64,83,84,85,86,90,91,92,93,94,95,109,108,107,106,105,104,100,99,98,97,114,115,116,117,118,119,124,125,140,139,138,137,131,130,148,149,156,157,171,170,163,162,180,181,188,189,203,202,195,194,212,213,235,234,292,291,314,315,316,317,326,325,324,323,322,321,339,345,346,347,348,349,350,365,364,363,357,356,355,354,369,370,371,372,373,379,380,398,397,396,395,394,393,388,387,401,402,403,404,405,406,411,412,429,428,427,426,420,419,435,436,443,444,460,459,452,451,467,468,475,476,492,491,499,500};
        //const int d3g[] = {17,18,19,20,21,46,45,44,43,42,49,53,78,81,110,113,121,125,142,141,140,139,134,133,130,145,153,154,157,174,166,164,162,177,185,187,189,206,202,198,195,194,209,210,211,212,213,217,220,221,238,237,236,235,234,230,226,281,285,294,290,313,317,326,322,346,348,357,355,369,373,378,380,398,394,389,387,401,405,411,429,427,420,434,436,443,461,459,452,467,475,492,484};
        const int a1r[] = {16,17,18,19,20,21,22,41,42,43,44,45,46,47,48,49,53,54,58,59,60,67,68,69,73,74,78,79,80,81,85,86,88,89,93,94,97,98,102,103,105,106,107,108,109,110,111,112,113,114,115,116,117,118,120,121,125,126,129,130,131,132,133,134,135,140,141,142,143,144,145,146,147,152,153,154,155,156,157,158,161,152,166,167,171,172,174,175,176,177,179,180,184,185,189,190,193,194,198,199,202,203,206,207,208,209,212,213,216,217,221,222,225,226,230,231,233,234,238,239,240,241,245,246,248,249,253,254,306,307,308,309,310,313,314,315,316,317,318,319,320,321,322,323,324,325,326,329,330,331,332,333,334,336,337,345,346,357,358,366,367,368,369,377,378,384,385,386,387,388,389,390,398,399,400,401,409,410,411,412,413,414,415,421,422,424,425,426,427,430,431,432,433,436,437,438,439,441,442,453,454,456,457,462,463,464,465,470471,473,474,480,481,482,483,484,485,486,488,489,490,491,492,493,494,498,499,500,501,502,503,505,506,507,508,509,510,511};
        const int a2r[] = {17,18,19,20,23,24,28,30,31,33,35,39,40,42,47,48,53,55,57,60,62,65,67,70,72,74,79,80,85,87,89,92,94,97,99,101,102,104,406,107,108,109,110,111,112,117,119,122,124,126,129,131,132,133,136,138,143,144,149,151,155,156,158,161,163,168,170,175,176,181,183,188,190,193,195,200,202,207,208,213,215,220,222,224,225,227,232,234,239,272,273,276,277,278,279,280,281,283,284,285,286,287,288,292,299,308,315,319,320,324,33,340,347,351,353,354,355,356,363,372,373,374,375,376,377,379,380,386,388,395,397,398,399,402,404,411,413,417,420,427,429,434,436,443,446,449,452,459,461,466,468,475,479,480,484,486,487,488,489,490,491,193,494,495};
        const int a3r[] = {52,74,75,83,84,85,105,106,108,109,114,115,118,119,136,137,141,142,145,146,151,167,168,173,174,176,177,183,184,199,200,206,207,208,209,215,216,231,232,238,239,240,241,247,248,64,95,94,97,96,367,369,368,126,125,130,398,401,157,156,163,188,195,220,227,252,430,429,433,434,462,461,465,466,494,493,497,498,315,326,325,324,345,347,359,358,356,355,375,376,380,387,412,419,444,451,476,483,508,392,407,425,424,438,439,457,456,470,471,489,488,502,503};
        const int a3o[] = {107,116,117,140,139,138,147,149,150,172,169,182,201,214,233,246,178,179,205,237,242,253,226,221,194,189,190,162,161,160,158,159,129,128,127,399,400,431,432,463,464,495,496,504,487,472,455,440,423,408,409,391,390,377,378,379,357,346,388,411,420,443,452,475,484,507};
        const int a3y[] = {148,171,170,181,180,204,203,202,211,212,213,236,235,234,243,244,245,191,193,192,222,223,225,224,254,255,389,410,422,421,441,442,454,453,473,474,486,485,505,506};
    // Size of Array
        const int sizeofint = sizeof(int);
//        const int sizeofdefault1 = sizeof(default1)/sizeofint;
        const int sizeofdefault2 = sizeof(default2)/sizeofint;
        const int sizeofj1y = sizeof(j1y)/sizeofint;
        const int sizeofj2y = sizeof(j2y)/sizeofint;
        const int sizeofj2p = sizeof(j2p)/sizeofint;
//        const int sizeoff1p = sizeof(f1p)/sizeofint;
        const int sizeoff2p = sizeof(f2p)/sizeofint;
        const int sizeoff3p = sizeof(f3p)/sizeofint;
        const int sizeoff3r = sizeof(f3r)/sizeofint;
        const int sizeofs1b = sizeof(s1b)/sizeofint;
        const int sizeofs2b = sizeof(s2b)/sizeofint;
//        const int sizeofs3b = sizeof(s3b)/sizeofint;
        const int sizeofd1g = sizeof(d1g)/sizeofint;
        const int sizeofd2g = sizeof(d2g)/sizeofint;
        //const int sizeofd3g = sizeof(d3g)/sizeofint;
        const int sizeofa1r = sizeof(a1r)/sizeofint;
        const int sizeofa2r = sizeof(a2r)/sizeofint;
        const int sizeofa3r = sizeof(a3r)/sizeofint;
        const int sizeofa3o = sizeof(a3o)/sizeofint;
        const int sizeofa3y = sizeof(a3y)/sizeofint;

        
    // Color
        const CRGB cPurple = CRGB::Purple;
        const CRGB cYellow = CRGB::Yellow;
        const CRGB cGreen = CRGB::Green;
        const CRGB cBlue = CRGB::Blue;
        const CRGB cRed = CRGB::Red;
        const CRGB cOrange = CRGB::Orange;

    // INPUT PINS
        int pinLW = 22; // Leg White
        int pinLY = 23; // Leg Yellow
        int pinLR = 24; // Leg Red
        int pinLB = 25; // Leg Blue
        int pinLG = 26; // Leg Green //
        int pinPW = 27; // Pentagon White
        int pinPY = 28; // Pentagontagon Yellow
        int pinPR = 29; // Pentagon Red
        int pinPB = 30; // Pentagon Blue
        int pinPG = 31; // Pentagon Green //
        int pinBW = 32; // Brain White
        int pinBY = 33; // Brain Yellow
        int pinBR = 34; // Brain Red
        int pinBB = 35; // Brain Blue
        int pinBG = 36; // Brain Green //
        int pinHW = 37; // Heart White
        int pinHY = 38; // Heart Yellow
        int pinHR = 39; // Heart Red
        int pinHB = 40; // Heart Blue
        int pinHG = 41; // Heart Green //
        int pinSW = 42; // Stomach White
        int pinSY = 43; // Stomach Yellow
        int pinSR = 44; // Stomach Red
        int pinSB = 45; // Stomach Blue
        int pinSG = 46; // Stomach Green //
    // TRIGGERS 
        int conditionCode = 0; // Zero is Default
    // VARIABLES
        long randomNumber;

void setup() {
    // Setup LEDS 
    Serial.begin(9600);
    Serial.print("1 of 2 Setting up FastLED... ");
    FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(10);
    FastLED.clear(true);
    Serial.println("done.");
    sound.speakerPin=9;
    Serial.begin(9600);
    if(!SD.begin(SD_ChipSelectPin))
    {
      Serial.println("SD fail");
      return;
    } 
    sound.setVolume(7);
    sound.quality(0);

    // Setup Inputs 
    Serial.print("2 of 2 Setting up Pins as INPUTS... ");
    pinMode(pinLW, INPUT);
    pinMode(pinLY, INPUT);
    pinMode(pinLR, INPUT);  
    pinMode(pinLB, INPUT);
    pinMode(pinLG, INPUT);
    pinMode(pinPW, INPUT);
    pinMode(pinPY, INPUT);
    pinMode(pinPR, INPUT);
    pinMode(pinPB, INPUT);
    pinMode(pinPG, INPUT);
    pinMode(pinBW, INPUT);
    pinMode(pinBY, INPUT);
    pinMode(pinBR, INPUT);
    pinMode(pinBB, INPUT);
    pinMode(pinBG, INPUT);
    pinMode(pinHW, INPUT);
    pinMode(pinHY, INPUT);
    pinMode(pinHR, INPUT);
    pinMode(pinHB, INPUT);
    pinMode(pinHG, INPUT);
    pinMode(pinSW, INPUT);
    pinMode(pinSY, INPUT);
    pinMode(pinSR, INPUT);
    pinMode(pinSB, INPUT);
    pinMode(pinSG, INPUT);
    Serial.println("done.");
}

void display() {
    Serial.print("Starting display... ");
    FastLED.show();
    delay(5000);
    FastLED.clear(true);
    Serial.println("done.");
}

void addDisplay(const int vScreenArray[], const int sizeofvScreenArray, const CRGB vColor) {
    // See https://forum.arduino.cc/t/crgb-color-as-a-function-argument/620376 for sample calls
    Serial.print("Starting addDisplay...     ");
    int i =0;
    Serial.print("Size = ");
    Serial.print(sizeofvScreenArray);
    for(i = 0; i < sizeofvScreenArray; i++){
        leds[vScreenArray[i]] = vColor; //vColor;
    }
    Serial.println(" done.");
}


void clearLEDs() {
    Serial.print("Starting addDisplay...     ");
    int i =0;
    for(i=0; i < NUM_LEDS + 1; i++){
        leds[i] = CRGB::Black;
    }
    Serial.println("done.");
}

void loop() {
    FastLED.clear(true);

    // Read Signals
       // Leg
        int sigLW = digitalRead(pinLW);
        int sigLY = digitalRead(pinLY);
        int sigLR = digitalRead(pinLR);
        int sigLB = digitalRead(pinLB);
        int sigLG = digitalRead(pinLG);
       // Pentagon
        int sigPW = digitalRead(pinPW);
        int sigPY = digitalRead(pinPY);
        int sigPR = digitalRead(pinPR);
        int sigPB = digitalRead(pinPB);
        int sigPG = digitalRead(pinPG);
       // Brain
        int sigBW = digitalRead(pinBW);
        int sigBY = digitalRead(pinBY);
        int sigBR = digitalRead(pinBR);
        int sigBB = digitalRead(pinBB);
        int sigBG = digitalRead(pinBG);
       // Heart
        int sigHW = digitalRead(pinHW);
        int sigHY = digitalRead(pinHY);
        int sigHR = digitalRead(pinHR);
        int sigHB = digitalRead(pinHB);
        int sigHG = digitalRead(pinHG);
       // Stomach
        int sigSW = digitalRead(pinSW);
        int sigSY = digitalRead(pinSY);
        int sigSR = digitalRead(pinSR);
        int sigSB = digitalRead(pinSB);
        int sigSG = digitalRead(pinSG);
    // Calculate Triggers
        if(sigLW == HIGH && sigPW == HIGH && sigBW == HIGH && sigHW == HIGH && sigSW == HIGH) {
            conditionCode = 1; // Fear
        }
        if(sigLY == HIGH && sigPY == HIGH && sigBY == HIGH && sigHY == HIGH && sigSY == HIGH) {
            conditionCode = 2; // Joy
        }
        if(sigLB == HIGH && sigPB == HIGH && sigBB == HIGH && sigHB == HIGH && sigSB == HIGH) {
            conditionCode = 3; // Sad
        }
        if(sigLG == HIGH && sigPG == HIGH && sigBG == HIGH && sigHG == HIGH && sigSG == HIGH) {
            conditionCode = 4; // Disgust
        }
        if(sigLR == HIGH && sigPR == HIGH && sigBR == HIGH && sigHR == HIGH && sigSR == HIGH) {
            conditionCode = 5; // Anger
        }

    // 
//    conditionCode = 4;
    switch (conditionCode) {
        case 1:
            // FEAR
                addDisplay(f2p, sizeoff2p, cPurple);
                display();
                sound.play("TESTATM/Fear.wav");
                addDisplay(f3p, sizeoff3p, cPurple);
                addDisplay(f3r, sizeoff3r, cRed);
                display();
                
            break;
        case 2:
            /// Joy
                addDisplay(j1y, sizeofj1y, cYellow);
                display();
                sound.play("TESTATM/Joy.wav");
                addDisplay(j2y, sizeofj2y, cYellow);
                addDisplay(j2p, sizeofj2p, cPurple);
                display();
      
            break;
        case 3:
            /// Sadness
                addDisplay(s1b, sizeofs1b, cBlue);
                display();
                sound.play("TESTATM/Sadness.wav");
                addDisplay(s2b, sizeofs2b, cBlue);
                display();
                
            break;
        case 4:
            /// Disgust
                addDisplay(d1g, sizeofd1g, cGreen);
                display();
                sound.play("TESTATM/Disgust.wav");
                addDisplay(d2g, sizeofd2g, cGreen);
                display();
                
            break;
        case 5: 
            /// Angry 1 - Rage Red Words
                addDisplay(a1r, sizeofa1r, cRed);
                display();
                sound.play("TESTATM/Anger.wav");
                addDisplay(a3r, sizeofa3r, cRed);
                addDisplay(a3o, sizeofa3o, cOrange);
                addDisplay(a3y, sizeofa3y, cYellow);
                display();

            break;
        default:
            // Default OK Words
            randomNumber = random(0,4);
            switch (randomNumber) {
                case 0:    
                    addDisplay(default2, sizeofdefault2, cGreen);
                    break;
                case 1:
                    addDisplay(default2, sizeofdefault2, cYellow);
                    break;
                case 2:
                    addDisplay(default2, sizeofdefault2, cPurple);
                    break;
                case 3:
                    addDisplay(default2, sizeofdefault2, cBlue);
                    break;
                case 4:
                    addDisplay(default2, sizeofdefault2, cRed);
                    break;
                default:
                    addDisplay(default2, sizeofdefault2, cGreen);
                    break;
            }
            display();
            break;
    }
    clearLEDs();
    conditionCode = 0;     
}
