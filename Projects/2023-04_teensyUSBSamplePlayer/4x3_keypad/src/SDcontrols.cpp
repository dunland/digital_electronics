#include <Arduino.h>
#include <SD.h>
#include <Wire.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <vector>
#include <SDcontrols.h>
#include <iostream>

// ---------------------------- SD CARD ------------------------------

// Use these with the Teensy Audio Shield
// #define SDCARD_CS_PIN 10
// #define SDCARD_MOSI_PIN 7
// #define SDCARD_SCK_PIN 14

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// Teensy audio board: pin 10
// Teensy 3.5 & 3.6 on-board: BUILTIN_SDCARD
// Wiz820+SD board: pin 4
// Teensy 2.0: pin 0
// Teensy++ 2.0: pin 20
const int chipSelect = BUILTIN_SDCARD;

void SD_info()
{
  //UNCOMMENT THESE TWO LINES FOR TEENSY AUDIO BOARD:
  //SPI.setMOSI(7);  // Audio shield has MOSI on pin 7
  //SPI.setSCK(14);  // Audio shield has SCK on pin 14

  Serial.print("\nInitializing SD card...");

  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!card.init(SPI_HALF_SPEED, chipSelect))
  {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    return;
  }
  else
  {
    Serial.println("Wiring is correct and a card is present.");
  }

  // print the type of card
  Serial.print("\nCard type: ");
  switch (card.type())
  {
  case SD_CARD_TYPE_SD1:
    Serial.println("SD1");
    break;
  case SD_CARD_TYPE_SD2:
    Serial.println("SD2");
    break;
  case SD_CARD_TYPE_SDHC:
    Serial.println("SDHC");
    break;
  default:
    Serial.println("Unknown");
  }

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card))
  {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    return;
  }

  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  Serial.print("\nVolume type is FAT");
  Serial.println(volume.fatType(), DEC);
  Serial.println();

  volumesize = volume.blocksPerCluster(); // clusters are collections of blocks
  volumesize *= volume.clusterCount();    // we'll have a lot of clusters
  if (volumesize < 8388608ul)
  {
    Serial.print("Volume size (bytes): ");
    Serial.println(volumesize * 512); // SD card blocks are always 512 bytes
  }
  Serial.print("Volume size (Kbytes): ");
  volumesize /= 2;
  Serial.println(volumesize);
  Serial.print("Volume size (Mbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);

  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
  root.openRoot(volume);

  // list all files in the card with date and size
  root.ls(LS_R | LS_DATE | LS_SIZE);
}

void SD_save_file_list(std::vector<char *> file_list)
{

  const int listItemsTotal = 12;
  const int listItemMaxChar = 12;
  char *listItems[listItemsTotal];
  char tempString[listItemMaxChar]; //temporary string of the max number of characters per file name
  byte listLength = 0;

  Sd2Card sd;
  File dir;
  File file;

  Serial.println("\n\nSortSDfiles algorithm:");
  if (!(SD.begin(BUILTIN_SDCARD)))
  {
    while (1)
    {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }

  File root = SD.open("/");
  while (true)
  {
    File entry = root.openNextFile();
    if (!entry)
    {
      break;
    } // no more files
    else
    {
      Serial.println((String)entry);
      //      listItems[listLength][0] = entry.name(); //add file name to list array
      //      listItems[listLength] = (char[128]) malloc(128);
      sprintf(tempString, "%s", entry.name());                 //save file name to temporary string with null terminator at the end
      listItems[listLength] = (char *)malloc(listItemMaxChar); //assign enough memory for 100 chars to current list item pointer
      sprintf(listItems[listLength], "%s", tempString);
      listLength++; //increment counter of files
      entry.close();
    }
  }
  /* print pointers array */
  for (int i = 0; i < listLength; i++)
  {
    Serial.println(listItems[i]);
    // file_list.push_back(listItems[i]);
  }
}

/* ---------------------------- method 3 --------------------------- */

File root_;

void readSD()
{

  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect))
  {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  root_ = SD.open("/");

  printDirectory(root_, 0);

  Serial.println("done!");
}

void printDirectory(File dir, int numTabs)
{
  while (true)
  {

    File entry = dir.openNextFile();
    if (!entry)
    {
      // no more files
      //Serial.println("**nomorefiles**");
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++)
    {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    Serial.print("\t\t");
    Serial.println(String(entry.name()).endsWith("wav") || String(entry.name()).endsWith("WAV"));


    if (entry.isDirectory())
    {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    }
    else
    {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.print(entry.size(), DEC);
    }
    entry.close();
  }
}