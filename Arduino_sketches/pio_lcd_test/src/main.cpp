#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Encoder.h>

/*
   THIS SKETCH SEEMS TO BE SOMEWHAT BROKEN!
   THE teensyDrums_master SKETCH WORKED BETTER FOR SOME REASON!

   Use an Arduino with an operating voltage of 3.3V, *** NOT 5V ***!
   Connect 3 wires from the Arduino to the Tsunami's serial connector:

       Arduino       Tsunami
       =======       =======
       GND  <------> GND
       TXn  <------> RX
       RXn  <------> TX
*/


#include <Tsunami.h>

Tsunami tsunami;

char gTsunamiVersion[VERSION_STRING_LEN];    // Tsunami version string


void setup() {

  pinMode(2, INPUT_PULLUP);

  Serial.begin(9600);
  // Serial3.begin(57600); // will be executed in tsunami.start() anyways
  while (!Serial);

  delay(2000);     // wait for Tsunami to finish reset // redundant?
  tsunami.start(); // Tsunami startup at 57600. ATTENTION: Serial Channel is selected in Tsunami.h !!!
  while (!Serial3)
  {
    Serial.println("waiting for Serial3");
  }

  delay(10);
  tsunami.stopAllTracks(); // in case Tsunami was already playing.
  tsunami.samplerateOffset(0, 0);
  tsunami.setReporting(true); // Enable track reporting from the Tsunami
  delay(100);                 // some time for Tsunami to respond with version string

  if (tsunami.getVersion(gTsunamiVersion, VERSION_STRING_LEN)) {
    Serial.print(gTsunamiVersion);
    Serial.print("\n");
    int gNumTracks = tsunami.getNumTracks();
    Serial.print("Number of tracks = ");
    Serial.print(gNumTracks);
    Serial.print("\n");
  } else
    Serial.print("WAV Trigger response not available");

  tsunami.masterGain(0, 0);
  tsunami.masterGain(1, 0);
  tsunami.trackLoop(255, true);
  tsunami.trackPlayPoly(255, 1, true);
  delay(1000);
  //tsunami.trackPlayPoly(42, 0, true);
  tsunami.update();

  delay(100);

}

void loop() {
  static unsigned long lastPlay1 = 0;
  static unsigned long lastPlay2 = 0;
  static unsigned long lastSwitch = 0;

  tsunami.update(); // will be done in isTrackPlaying
  delay(20);
  Serial.print("track(255) == ");
  Serial.print(tsunami.isTrackPlaying(255));
  delay(20);
  Serial.print("\ttrack(170) == ");
  Serial.println(tsunami.isTrackPlaying(170));
  delay(20);
//  if (!tsunami.isTrackPlaying(34))
//  {
//    delay(100);
//    tsunami.trackPlayPoly(34, 1, true);
//    tsunami.update();
//    delay(100);
//    Serial.println(tsunami.isTrackPlaying(34));
//  }

  //
    if (digitalRead(2) == LOW && millis() > lastSwitch  + 50)
    {
      tsunami.update();
      delay(50); // maybe needs some time after last query?
      tsunami.trackPlayPoly(170, 0, true);
      delay(50);
      tsunami.update();
      delay(100);
      Serial.println("footswitch track activated");
      lastSwitch = millis();
    }
  delay(20);

}
