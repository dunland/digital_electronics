// include the ArduinoTapTempo library
#include <ArduinoTapTempo.h>
//#include <MIDI.h>
#include <Tsunami.h>

// make an ArduinoTapTempo object
ArduinoTapTempo tapTempo;

Tsunami tsunami;
char gTsunamiVersion[VERSION_STRING_LEN];    // Tsunami version string

//MIDI_CREATE_DEFAULT_INSTANCE();

boolean buttonDown;

/* ---------------------------------- CUSTOM PARAMETERS --------------------------------- */

const int noiseFloor = 512; // TODO: create function to assess noiseFloor upon startup
const int max_val = 1000;
const int globalThreshold = 50;
static const uint8_t pins[] = {A0, A1, A2, A3};
static const uint8_t leds[] = {LED_BUILTIN, LED_BUILTIN, LED_BUILTIN, LED_BUILTIN};
static const uint8_t numInputs = 1; // that makes 4 input since number 0 is counted as well
int vals[numInputs];

void setup() {

  Serial.begin(19200);
  while (!Serial);
  delay(10);

  // We should wait for the Tsunami to finish reset before trying to send
  // commands.
  delay(1000);

  // Tsunami startup at 57600
  tsunami.start();
  delay(100);

  // Send a stop-all command and reset the sample-rate offset, in case we have
  //  reset while the Tsunami was already playing.
  tsunami.stopAllTracks();
  tsunami.samplerateOffset(0, 0);

  // Enable track reporting from the Tsunami
  tsunami.setReporting(true);

  // Allow time for the Tsunami to respond with the version string and
  //  number of tracks.
  delay(100);

  //MIDI.begin(MIDI_CHANNEL_OMNI); // listen to all incoming MIDI messages

  // set all required pins
  for (int i = 0; i < numInputs; i++)
  {
    pinMode(leds[i], OUTPUT);
    //pinMode(pins[i], INPUT);
  }

  tapTempo.setMaxBPM(330);
  tapTempo.setMinBPM(30);

  pinMode(5, INPUT_PULLUP);
}

void loop() {

  tsunami.update();

  //Serial.println(analogRead(A0)); // debugging signal

  // get the state of the button
  //  int val = noiseFloor - analogRead(A0);
  //  val = abs(val); // positive values only
  //  val = map(val, 0, max_val, 0, 255); // 8-bit conversion
  //  if (val > globalThreshold)
  //  {
  //    digitalWrite(LED_BUILTIN, HIGH);
  //    buttonDown = true;
  //  }
  //  else
  //  {
  //    digitalWrite(LED_BUILTIN, LOW);
  //    buttonDown = false;
  //  }

  if (digitalRead(5) == LOW)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    buttonDown = true;
    if (!tsunami.isTrackPlaying(211))
    {
      int sr_offset;
      float r = tapTempo.getBPM() / 120;
      if (!(r > 2) && !(r < 0.5))
      {
        if (r >= 1)
        {
          sr_offset = 32767 * (r - 1);
        }
        else
        {
          sr_offset = -32768 + 32768 * 2 * (r - 0.5);
        }
      }
      tsunami.samplerateOffset(0, sr_offset);
      tsunami.masterGain(0, 0);
      tsunami.trackPlayPoly(211, 0, true);
    }

  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
    buttonDown = false;
  }


  // update ArduinoTapTempo
  tapTempo.update(buttonDown);


  Serial.print("bpm: ");
  //Serial.println(tapTempo.getBPM());

  // uncomment the block below to demo many of ArduinoTapTempo's methods
  // note that Serial.print() is not a fast operation, and using it decreases the accuracy of the the tap timing
  unsigned long dividend = (uint64_t)tapTempo.getBPM();
  unsigned long beat_interval = (60000 / dividend);
  Serial.println(beat_interval);
  if (millis() % beat_interval < 100)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }

  Serial.print("len:");
  Serial.print(tapTempo.getBeatLength());
  Serial.print(",\tbpm: ");
  Serial.print(tapTempo.getBPM());
  Serial.print(",\tchain active: ");
  Serial.print(tapTempo.isChainActive() ? "yes" : "no ");
  Serial.print(",\tlasttap: ");
  Serial.print(tapTempo.getLastTapTime());
  Serial.print(",\tprogress: ");
  Serial.print(tapTempo.beatProgress());
  Serial.print(",\tbeat: ");
  Serial.println(tapTempo.onBeat() ? "beat" : "    ");

  delay(10);

}
