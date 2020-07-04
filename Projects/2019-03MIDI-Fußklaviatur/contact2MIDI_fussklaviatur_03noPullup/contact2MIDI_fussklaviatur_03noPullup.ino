#include <elapsedMillis.h>
#include <MIDI.h>
boolean noteOn[13] = {false};
int noteBase[] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
/* int note2[] = {36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48};
  int note3[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60};
  int note4[] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72};
  int note5[] = {72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84}; */
int note[] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
//int note[] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72};

int shift = 0; //shifts octaves up or down
/*
  Physical | IDE  | Taste | Farbe | Ton
  15 = D9 = note01 = grau = C
  16 = D10 = note02 = weiß = C#
  17 = D11 = note03 = grün-rot = D
  11 = D5 = note04 = rot-schwarz = D#
  12 = D6 = note05 = schwarz = E
  13 = D7 = note06 = braun = F
  14 = D8 = note07 = rot/rot-gelb = F#
  28 = A5 = note08 = orange = G
  27 = A4 = note09 = gelb/gelb-schwarz = G#
  26 = A3 = note10 = lila = A
  25 = A2 = note11 = hellblau = A#
  24 = A1 = note12 = blau = H
  23 = A0 = note13 = grün-orange = C

  lila-orange = Vcc
  orange-blau = Vcc
  hellgrün x2 = GND

  TX = Serial Out
  04 = D2 = Octave Down // muss so, da interrupts
  05 = D3 = Octave Up
*/
static const uint8_t pins[] = {9, 10, 11, 5, 6, 7, 8, A5, A4, A3, A2, A1, A0};
static const uint8_t down = 2;
static const uint8_t up = 3;

elapsedMillis now = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 150;

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  //Serial.begin(31250);
  for (int i = 0; i < 13; i++)
  {
    pinMode(pins[i], INPUT_PULLUP);
  }
  pinMode(13, OUTPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);

}

void loop() {

  //---------------------------------------- Octave Shifts
  // OCTAVE UP
  if (digitalRead(up) == HIGH && now  debounceDelay)
  {
    if (shift < 72)
    {
      shift += 12;
      for (int i = 0; i < 13; i++)
      {
        if (!noteOn[i])
        {
          note[i] = noteBase[i] + shift;
        }
      }
    }
    lastDebounceTime = millis();
  }

  if (digitalRead(down) == HIGH && millis() - lastDebounceTime > debounceDelay)
  {
    if (shift > 0)
    {
      shift -= 12;
      for (int i = 0; i < 13; i++)
      {
        if (!noteOn[i])
        {
          note[i] = noteBase[i] + shift;
        }
      }
    }
    lastDebounceTime = millis();
  }


  //---------------------------------------- Tasten
  /*  for pins
      check on / off
      get keynumber
      keyID = 1 / 0 (boolean) */

  for (int i = 0; i < 13; i++)
  {
    if (digitalRead(pins[i]) == LOW && !noteOn[i])
    {
      noteOn[i] = true;
      digitalWrite(13, HIGH);
      MIDI.sendNoteOn(note[i], 127, 2);
    }
  }

  for (int i = 0; i < 13; i++)
  {
    if (digitalRead(pins[i]) == HIGH)
    {
      noteOn[i] = false;
      digitalWrite(13, LOW);
      MIDI.sendNoteOff(note[i], 127, 2);
      note[i] = noteBase[i] + shift;
    }
  }

  //Serial.println(digitalRead(2));

  //    int  note = int(random(60, 70));
  //
  //  if (digitalRead(2) == LOW && !noteOn)
  //  {
  //    noteOn = true;
  //    digitalWrite(13, HIGH);
  //    MIDI.sendNoteOn(70, 127, 2); //(pitch, velocity, channel)
  //    //  }
  //
  //  } else if (digitalRead(2) == HIGH)
  //  {
  //    noteOn = false;
  //    digitalWrite(13, LOW);
  //    MIDI.sendNoteOff(70, 127, 2);
  //  }

  //delay(10);
}
