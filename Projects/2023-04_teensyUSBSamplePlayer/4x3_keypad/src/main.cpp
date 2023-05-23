#include <Arduino.h>
#include <Audio.h>
#include <Keypad.h>
#include <vector>

#include "SDcontrols.h"
#include "Globals.h"
// ------------------------------ KEYPAD ------------------------------

const int ROW_NUM = 4;    // four rows
const int COLUMN_NUM = 3; // three columns

char keys[ROW_NUM][COLUMN_NUM] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

byte pin_rows[ROW_NUM] = {26, 31, 30, 28};  // connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {27, 25, 29}; // connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

// -------------------------------- SD --------------------------------

// --------------------------- AUDIO SHIELD ---------------------------

AudioPlaySdWav playWav;
// Use one of these 3 output types: Digital I2S, Digital S/PDIF, or Analog DAC
AudioOutputI2S audioOutput;
// AudioOutputAnalog dac; // play to both I2S audio board and on-chip DAC

// AudioOutputSPDIF       audioOutput;
// AudioOutputAnalog      audioOutput;
AudioControlSGTL5000 sgtl5000_1;

AudioConnection patchCord1(playWav, 0, audioOutput, 0);
AudioConnection patchCord2(playWav, 1, audioOutput, 1);

// Create the Audio components.  These should be created in the
// order data flows, inputs/sources -> processing -> outputs
//
// AudioPlayMemory sound0;
// AudioPlayMemory sound1; // six memory players, so we can play
// AudioPlayMemory sound2; // all six sounds simultaneously
// AudioPlayMemory sound3;
// AudioPlayMemory sound4;
// AudioPlayMemory sound5;
// AudioPlayMemory sound6;
// AudioPlayMemory sound7;
// AudioPlayMemory sound8;
// AudioPlayMemory sound9;

// AudioMixer4 mix1; // two 4-channel mixers are needed in
// AudioMixer4 mix2; // tandem to combine 6 audio sources
// AudioOutputI2S headphones;
// AudioOutputAnalog dac; // play to both I2S audio board and on-chip DAC

// Create Audio connections between the components

// AudioConnection c1(sound0, 0, mix1, 0);
// AudioConnection c2(sound1, 0, mix1, 1);
// AudioConnection c3(sound2, 0, mix1, 2);
// AudioConnection c4(sound3, 0, mix1, 3);
// AudioConnection c5(mix1, 0, mix2, 0); // output of mix1 into 1st input on mix2
// AudioConnection c6(sound4, 0, mix2, 1);
// AudioConnection c7(sound5, 0, mix2, 2);
// AudioConnection c8(mix2, 0, headphones, 0);
// AudioConnection c9(mix2, 0, headphones, 1);
// AudioConnection c10(mix2, 0, dac, 0);

// Create an object to control the audio shield.
//
// AudioControlSGTL5000 audioShield;

void setup()
{

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect.
  }

  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(8);

  // turn on the output
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);

  SD_info();

  readSD();

  for (uint8_t i = 0; i < Globals::dynamicFileList.size(); i++)
  {
    Serial.println(Globals::dynamicFileList.at(i));
  }

  // if (!(SD.begin(BUILTIN_SDCARD)))
  // {
  //   // stop here, but print a message repetitively
  //   while (1)
  //   {
  //     Serial.println("Unable to access the SD card");
  //     delay(500);
  //   }
  // }

  // by default the Teensy 3.1 DAC uses 3.3Vp-p output
  // if your 3.3V power has noise, switching to the
  // internal 1.2V reference can give you a clean signal
  // dac.analogReference(INTERNAL);

  // reduce the gain on mixer channels, so more than 1
  // sound can play simultaneously without clipping
  // mix1.gain(0, 0.4);
  // mix1.gain(1, 0.4);
  // mix1.gain(2, 0.4);
  // mix1.gain(3, 0.4);
  // mix2.gain(1, 0.4);
  // mix2.gain(2, 0.4);
}

void playFile(char fileNumChar)
{
  int fileNum = (int)fileNumChar - 48;
  // When the buttons are pressed, just start a sound playing.
  // The audio library will play each sound through the mixers
  // so any combination can play simultaneously.
  //
  String nameString;

  if (fileNum == -6) // corresponds to *
    fileNum = 10;
  else if (fileNum == -13) // corresponds to #
    fileNum = 11;

  // escape if file list too small:
  if (fileNum > Globals::dynamicFileList.size() - 1)
  {
    Serial.print("no file mapped to key ");
    Serial.println(fileNum);
    return;
  }

  nameString = Globals::dynamicFileList.at(fileNum);
  playWav.play(nameString.c_str());

  Serial.print("playing file ");
  Serial.println(nameString);

  // A brief delay for the library read WAV info
  delay(5);

  // Simply wait for the file to finish playing.
  // while (playWav.isPlaying()) {
  // uncomment these lines if you audio shield
  // has the optional volume pot soldered
  // float vol = analogRead(15);
  // vol = vol / 1024;
  // sgtl5000_1.volume(vol);
  // }
}

void loop()
{
  char key = keypad.getKey();

  if (key)
  {
    Serial.print("key: ");
    Serial.println(key);
    playFile(key);
  }
}
