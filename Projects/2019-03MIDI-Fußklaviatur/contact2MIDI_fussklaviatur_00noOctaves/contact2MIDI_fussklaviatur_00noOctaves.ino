#include <MIDI.h>
boolean noteOn[13] = {false};
// int note[] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72};
int note[] = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};

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

*/
static const uint8_t pins[] = {9, 10, 11, 5, 6, 7, 8, A5, A4, A3, A2, A1, A0};
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  //Serial.begin(31250);
  for (int i = 0; i < 13; i++)
  {
    pinMode(pins[i], INPUT_PULLUP);
  }
  pinMode(13, OUTPUT);
  /*pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(14, INPUT);
    pinMode(15, INPUT);
    pinMode(16, INPUT);
    pinMode(17, INPUT);
    pinMode(18, INPUT);
    pinMode(19, INPUT);*/


}

void loop() {

  //  for pins
  //  check on / off
  //  get keynumber
  //  keyID = 1 / 0 (boolean)

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
