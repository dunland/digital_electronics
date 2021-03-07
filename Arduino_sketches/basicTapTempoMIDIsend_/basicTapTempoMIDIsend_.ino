//#include <elapsedMillis.h>

/* TODO:
   TapTempo forgetTime
   TapTempo minTime ?
*/

boolean firstHit = false;
unsigned long firstHitTime;
unsigned long beat_interval = 500;
unsigned long millisCounter = 0;
unsigned long lastMillis;
int bpm = 120;
boolean clockSent = false;

/* ---------------------------------- CUSTOM PARAMETERS --------------------------------- */

int noiseFloor = 260; // typical values: Arduino = 512, SPRESENSE = 260
const int max_val = 1000;
const int globalThreshold = 20; // typical values: Arduino = 50, SPRESENSE = 10-30
static const uint8_t pins[] = {A0, A1, A2, A3};
static const uint8_t leds[] = {LED_BUILTIN, LED_BUILTIN1, LED_BUILTIN2, LED_BUILTIN3};
static const uint8_t numInputs = 1; // that makes 4 input since number 0 is counted as well
int vals[numInputs];

void setup() {
  // Serial2 for UART2 pin on SPRESENSE --> "Serial" can be used for USB communication!

  Serial.begin(115200);
  // --------------------------------------- calculate noiseFloor
  int pinNum = 0;
  int totalSamples = 0;
  int led_idx = 0;
  for (int n = 0; n < 400; n++)
  {
    Serial.print(".");
    if (n % 100 == 0)
    {
      Serial.print("|");
      digitalWrite(leds[led_idx], HIGH);
      led_idx++;
    }
    pinNum = (pinNum + 1) % numInputs;
    totalSamples += analogRead(pins[pinNum]);
  }

  noiseFloor = totalSamples / 400;
  Serial.println("");
  Serial.print("noisefloor is at");
  Serial.println(noiseFloor);

  for (int i = 0; i < 4; i++) // turn LEDs off again
  {
    digitalWrite(leds[i], LOW);
  }


  // --------------------------------------- set pins up
  Serial2.begin(31250); // required clock rate for midi signals
  while (!Serial);

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
    firstHitTime = millis();
    firstHit = true;
  }

  if (val > globalThreshold && firstHit && (millis() - firstHitTime) > 50) // 50 ms debounce time
  {
    if ((millis() - firstHitTime) < 2000) // skip tap evaluation when time was too long
    {
      beat_interval = millis() - firstHitTime;
      bpm = 60000 / beat_interval;
      millisCounter = 0;
    }
    firstHit = false;
  }

  // -------------------------------------- blink LED
  if (millis() % beat_interval/3 < 100) // turns LED on for 100 ms
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

  //if (millis() % (beat_interval / 24) == 0)
  if (millisCounter == (beat_interval / (6 * 24)))
  {
    //if (!clockSent)
    //{
    Serial.print(millis());
    Serial.print(" interval:");
    Serial.print(beat_interval);
    Serial.print(" bpm: ");
    Serial.print(bpm);
    Serial.print(" interval/24: ");
    Serial.print(beat_interval / 24);
    Serial.print(" ms_modulo: ");
    Serial.println(millis() % (beat_interval / 24));
    clockSent = true;
    Serial.println("tap");
    Serial2.write(0xF8); // 0xF8 = 11110000 = dataByte for MIDI Timing Clock Realtime Message (https://www.midi.org/specifications-old/item/table-1-summary-of-midi-message)
    //}
    millisCounter = 0;
  }
  //else
  //{
  //clockSent = false;
  //}

  if (millis() != lastMillis)
  {
    millisCounter++;
    Serial.print(millisCounter);
    Serial.print(" / ");
    Serial.println(beat_interval);
  }
  lastMillis = millis();


}
