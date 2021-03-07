#include <elapsedMillis.h>

/* TODO:
   TapTempo forgetTime
   TapTempo minTime ?
*/

boolean firstHit = false;
elapsedMillis firstHitTime;
unsigned long beat_interval = 500;
int bpm = 120;
boolean clockSent = false;

/* ---------------------------------- CUSTOM PARAMETERS --------------------------------- */

int noiseFloor = 260; // typical values: Arduino = 512, SPRESENSE = 260
const int max_val = 1000;
const int globalThreshold = 20; // typical values: Arduino = 50, SPRESENSE = 10-30
static const uint8_t pins[] = {A0, A1, A2, A3};
static const uint8_t leds[] = {LED_BUILTIN, LED_BUILTIN, LED_BUILTIN, LED_BUILTIN};
static const uint8_t numInputs = 1; // that makes 4 input since number 0 is counted as well
int vals[numInputs];

void setup() {

  // --------------------------------------- calculate noiseFloor
  int pinNum = 0;
  int totalSamples = 0;
  int led_idx = 0;
  for (int n = 0; n < 400; n++)
  {
    if (n % 100 == 0)
    {
      digitalWrite(leds[led_idx], HIGH);
      led_idx++;
    }
    pinNum = (pinNum + 1) % numInputs;
    totalSamples += analogRead(pins[pinNum]);
  }

  noiseFloor = totalSamples / 400;
  //Serial.println("noisefloor is at ");
  //Serial.println(noiseFloor);

  for (int i = 0; i < 4; i++) // turn LEDs off again
  {
    digitalWrite(leds[i], LOW);
  }


  // --------------------------------------- set pins up
  Serial2.begin(31250); // required clock rate for midi signals
  while (!Serial2);

  // set all required pins
  for (int i = 0; i < numInputs; i++)
  {
    pinMode(leds[i], OUTPUT);
    //pinMode(pins[i], INPUT);
  }

}

void loop() {

  //Serial.println(analogRead(A0)); // debugging signal

  // -------------------------------------- read button
  int val = noiseFloor - analogRead(A0);
  val = abs(val); // positive values only
  val = map(val, 0, max_val, 0, 255); // 8-bit conversion

  // -------------------------------------- tap tempo
  if (val > globalThreshold && !firstHit)
  {
    //digitalWrite(LED_BUILTIN, HIGH);
    firstHitTime = 0;
    firstHit = true;
  }

  if (val > globalThreshold && firstHit && firstHitTime > 50) // 50 ms debounce time
  {
    if (firstHitTime < 2000) // skip tap evaluation when time was too long
    {
      beat_interval = firstHitTime;
      bpm = 60000 / firstHitTime;
    }
    firstHit = false;
  }

  // -------------------------------------- blink LED
  if (millis() % beat_interval < 100) // turns LED on for 100 ms
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }

  // -------------------------------------- MIDI sync
  /* MIDI Clock events are sent at a rate of 24 pulses per quarter note
     one tap beat equals one quarter note
     only one midi clock signal should be send per 24th quarter note
  */
  if (millis() % (beat_interval / 24) == 0)
  {
    if (!clockSent)
    {
      clockSent = true;
      Serial2.write(0xF8); // 0xF8 = 11110000 = dataByte for MIDI Timing Clock Realtime Message (https://www.midi.org/specifications-old/item/table-1-summary-of-midi-message)
    }
  }
  else
  {
    clockSent = false;
  }

}
