#include "SD.h"
#define SD_ChipSelectPin 53 // 10 for Uno and 53 for Mega
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm sound;

void setup()
{
sound.speakerPin=11; // 9 for Uno and 11 for Mega
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
} 
//Serial.println("SD connected");
sound.setVolume(7);
sound.quality(0);
//Serial.print("TESTATM/Anger.wav");
//            // Check to see if the file exists:
//            if (SD.exists("TESTATM/Anger.wav")) {
//                Serial.println(" exists.");
//            } else {
//                Serial.println(" doesn't exist.");
//            }
sound.play("TESTATM/Disgust.wav");
delay(10000);
sound.play("TESTATM/Anger.wav");
delay(10000);
sound.play("TESTATM/Fear.wav");
delay(10000);
sound.play("TESTATM/Joy.wav");
delay(10000);
sound.play("TESTATM/Sadness.wav");
delay(10000);

//Serial.print("audio is done");
}

void loop() {
  // put your main code here, to run repeatedly:

}
