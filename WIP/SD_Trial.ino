/// File:       SD_Trial
/// Version:    Draft Version 0.1
/// Resourses:  https://docs.arduino.cc/learn/programming/sd-guide#file-management (Public Domain)

// Include Files
#include <SPI.h>        //Serial Periperal Interface
#include <SD.h>         //SD Library
#include <TMRpcm.h>     //include speaker control library

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
File root;
const int chipSelect = 10;  //define CS pin

//const char *wav_files[10] = { "1.wav", "2.wav", "3.wav", "4.wav", "5.wav", "6.wav", "7.wav", "8.wav", "9.wav", "10.wav" };

TMRpcm sound;                            //crete an object for speaker library


void setup() {

 // Open serial communications and wait for port to open:
    Serial.begin(9600);
    // wait for Serial Monitor to connect. Needed for native USB port boards only:
    while (!Serial);
    Serial.print("1 of 4 Initializing SD card via Begin...");
    if (!SD.begin(chipSelect)) {
        Serial.println("initialization failed. Things to check:");
        Serial.println("1. is a card inserted?");
        Serial.println("2. is your wiring correct?");
        Serial.println("3. did you change the chipSelect pin to match your shield or module?");
        Serial.println("Note: press reset or reopen this serial monitor after fixing your issue!");
    }
    Serial.println("initialization done.");

    Serial.print("2 of 4 Initializing SD card...");
    if (!card.init(SPI_HALF_SPEED, chipSelect)) {
        Serial.println("initialization failed. Things to check:");
        Serial.println("* is a card inserted?");
        Serial.println("* is your wiring correct?");
        Serial.println("* did you change the chipSelect pin to match your shield or module?");
        while (1);
    } else {
        Serial.print("Wiring is correct and a card is present...");
    }
    // print the type of card
        Serial.print("Card type: ");
        Serial.print(card.type());
        Serial.print("... OR ");
        switch (card.type()) {
            case SD_CARD_TYPE_SD1:
            Serial.print("SD1");
            break;
            case SD_CARD_TYPE_SD2:
            Serial.print("SD2");
            break;
            case SD_CARD_TYPE_SDHC:
            Serial.print("SDHC");
            break;
            default:
            Serial.print("Unknown");
        }

    Serial.println("...initialization done.");

    // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
    Serial.print("3 of 5 Explore Volume Formatting...");
    if (!volume.init(card)) {
        Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
        while (1);
    }
    uint32_t volumesize;
    Serial.print("...Volume type is:    FAT");
    Serial.print(volume.fatType(), DEC);
    volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
    volumesize *= volume.clusterCount();       // we'll have a lot of clusters
    volumesize /= 2;                           // SD card blocks are always 512 bytes (2 blocks are 1KB)
    Serial.print("... Volume size (Kb):  ");
    Serial.print(volumesize);

    Serial.print("4 of 5 Select root directory...");
    //root = SD.open("/");
    root.openRoot(volume);
    Serial.println("done!");
    
    Serial.print("5 of 5 Print Root Directory...");
    //printDirectory(root, 0);
    // list all files in the card with date and size
    root.ls(LS_R | LS_DATE | LS_SIZE);
    root.close();
    Serial.println("done!");
}

void loop() {
  // nothing happens after setup finishes.
}

void printDirectory(File dir, int numTabs) {

  while (true) {
    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}