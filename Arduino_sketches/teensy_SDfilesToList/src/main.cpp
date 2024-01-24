#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <vector>

// GUItool: begin automatically generated code
AudioInputI2S i2s1;                 // xy=530,578
AudioAnalyzeNoteFrequency notefreq; // xy=995,569
AudioConnection patchCord1(i2s1, 0, notefreq, 0);
AudioControlSGTL5000 sgtl5000_1; // xy=769,647
// GUItool: end automatically generated code

#define SDCARD_CS_PIN BUILTIN_SDCARD

File file;

int fileNum = 0;
int everyFileNum = 0;
std::vector<String> dynamicFileList;

void reloadFileList()
{
  while (true)
  {
    // Check the number of files
    File entry = file.openNextFile();
    if (!entry)
    {
      Serial.print("Detected files: ");
      Serial.println(fileNum);
      break;
    }
    if (!entry.isDirectory())
    {
      fileNum++;
    }
    everyFileNum++;
    entry.close();
  }

  // reiterate file list and store files:

  String fileList[fileNum];

  file.close();
  file = SD.open("/");
  int i = 0;
  while (i < fileNum)
  {
    File entry = file.openNextFile();
    Serial.println(i);
    if (!entry.isDirectory())
    {
      fileList[i] = (String)entry.name();
      dynamicFileList.push_back((String)entry.name());
    }
    entry.close();
    Serial.println(fileList[i]);
    i++;
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  while (!Serial);

  delay(250);
  if (!(SD.begin(SDCARD_CS_PIN)))
  {
    // stop here if no SD card, but print a message
    while (1)
    {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  file = SD.open("/");
  reloadFileList();
}
void loop()
{
  // put your main code here, to run repeatedly:

  delay(1000);

  for (uint8_t i = 0; i<dynamicFileList.size(); i++)
  {
    Serial.println(dynamicFileList.at(i));
  }
}
