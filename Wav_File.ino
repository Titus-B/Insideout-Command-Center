// Needs work

#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup(){
tmrpcm.speakerPin = 9;
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}

char fname = "ANGER_1.wav";
Serial.println(fname);

// Check to see if the file exists:

  if (SD.exists(fname)) {

    Serial.println(" exists.");

  } else {

    Serial.println(" doesn't exist.");

  }

tmrpcm.setVolume(20);
tmrpcm.play(fname);
Serial.println("finish audio setup");

}

void loop(){  }
