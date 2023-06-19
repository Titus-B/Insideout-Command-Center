#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm sound;

void setup()
{
sound.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
} Serial.println("SD connected");
sound.setVolume(7);
sound.quality(0);
Serial.print("TESTATM/Anger.wav");
            // Check to see if the file exists:
            if (SD.exists("TESTATM/Anger.wav")) {
                Serial.println(" exists.");
            } else {
                Serial.println(" doesn't exist.");
            }
sound.play("TESTATM/Anger.wav");

}

void loop() {
  // put your main code here, to run repeatedly:

}
