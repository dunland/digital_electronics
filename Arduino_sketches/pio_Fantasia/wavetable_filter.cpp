#include <Arduino.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=341,294
AudioSynthWaveform       waveform2;      //xy=345,355
AudioFilterStateVariable filter1;        //xy=508,314
AudioOutputI2S           i2s1;           //xy=662,331
AudioConnection          patchCord1(waveform1, 0, filter1, 0);
AudioConnection          patchCord2(waveform2, 0, filter1, 1);
AudioConnection          patchCord3(filter1, 0, i2s1, 0);
AudioConnection          patchCord4(filter1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=658,182
// GUItool: end automatically generated code


// GUItool: end automatically generated code

// GUItool: end automatically generated code

//SD CARD PINS
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  11
#define SDCARD_SCK_PIN   13

int PotPort1 = A0; // select the input pins for the potentiometers
int PotPort2 = A1;
int PotPort3 = A2;
int PotPort4 = A3;

int Boton1 = 2;    // pushbutton connected to digital pinS
int Boton2 = 5;
int Boton3 = 25;
int Boton4 = 27;
int Gate1 = 3;
int Gate2 = 6;
int Encoderbut = 4;

// Variables to store port values
float PotValue1 = 0;
float PotValue2 = 0;
float PotValue3 = 0;
float PotValue4 = 0;
int BotonValue1 = 0;
int BotonValue2 = 0;
int BotonValue3 = 0;
int BotonValue4 = 0;
int GateValue1 = 0;
int GateValue2 = 0;
int EncoderbutValue = 0;


const int16_t v1_array[256] = { -7160, -6917, -6553, -6432, -6189, -6068, -5825, -5825, -5825, -5825, -6068, -6068, -6068, -6068, -5946, -5946, -6068, -6310, -6310, -6432, -6310, -6068, -5825, -5461, -5582, -5218, -4975, -4611, -4126, -3883, -3762, -3276, -3155, -2912, -2669, -2427, -2184, -1941, -1820, -1820, -1334, -1213, -1334, -1213, -1213, -849, -728, -728, -728, -606, 0, -364, -485, -364, -121, -121, -121, 0, 0, -121, 121, 121, 242, 485, 849, 849, 849, 849, 970, 849, 849, 1456, 1334, 1577, 1699, 1820, 2184, 2305, 31675, 2912, 32525, 2791, 8859, 32768, 32161, 31797, 31311, 32525, 32161, 31918, 31675, 31675, 31918, 32161, 30947, 30947, 31675, 31918, 31918, 31797, 32525, 32646, 32525, 6796, 7160, 7160, 7403, 7645, 7767, 32646, 32282, 30340, 30947, 30826, 30947, 31190, 31675, 31190, 30826, 30340, 32768, 32282, 32646, 32161, 30826, 30462, 30583, 30826, 29733, 29733, 29733, 31675, 30462, 31311, 31432, 30340, 29855, 29855, 30098, 29976, 29733, 29612, 30219, 30219, 30340, 30704, 30704, 30219, 27670, 29369, 29612, 29612, 29127, 29491, 29976, 29976, 29005, 10315, 32161, 32282, 31797, 9466, 31675, 32403, 29248, 29491, 29612, 29855, 29733, 30219, 30098, 31190, 30704, 30462, 28156, 28398, 32282, 30583, 29855, 30704, 30826, 30704, 32646, 28763, 28884, 29248, 29127, 29855, 29612, 29976, 29612, 29733, 29733, 29612, 29127, 31311, 30098, 970, 485, 23787, 25607, 26093, 26699, 27185, 29369, 29127, 29005, 27792, 27670, 27792, 28398, 29976, 29855, 29733, 29248, 29127, 29248, 29855, 32525, 32768, 32646, 28641, 31918, 32161, 31068, 31190, 31797, 32403, 32282, 32282, 32282, 32403, 32525, 32403, 32525, 29855, 30219, 29733, 28884, 29248, 32646, 32039, 31675, 31554, 32525, 29248, 29369, 29855, 30704, 31068, 31675, 32282, 32525, 32403, 32646, 32525};



const int16_t phi1_array[256] =  {-5582, -5461, -5218, -4975, -4854, -4854, -4975, -4975, -5097, -5097, -5097, -5097, -4975, -5097, -5097, -5339, -5339, -5582, -5704, -5825, -5946, -6189, -6432, -6432, -6432, -6310, -6432, -6068, -5825, -5461, -5218, -4854, -4854, -4247, -4126, -3640, -3398, -3155, -3155, -2912, -2548, -2548, -2184, -2184, -2063, -2063, -2184, -1577, -1699, -1577, -1456, -1456, -1334, -1213, -1213, -970, -728, -849, -728, -728, -728, -606, -485, -364, -242, 242, 242, 364, 364, 485, 485, 364, 970, 970, 1213, 1334, 1456, 1820, 1820, 1820, 0, 2427, 2548, 2548, 2912, 2912, 3034, 2912, 3276, 3640, 3883, 3883, 4004, 4126, 4490, 4611, 5339, 5339, 5582, 5825, 6068, 6310, 6310, 6796, 7160, 7645, 7767, 7888, 8131, 8495, 8616, 8738, 8980, 9344, 9709, 10194, 10437, 10679, 10922, 11165, 11408, 11772, 11893, 12136, 12379, 12500, 12743, 12743, 12864, 13107, 13107, 12985, 13228, 13228, 13349, 13228, 13471, 13471, 13471, 13471, 13471, 13349, 13228, 13107, 13107, 12864, 12621, 12621, 12379, 12136, 11893, 11650, 11408, 11286, 11165, 10801, 10679, 10558, 10315, 10194, 9951, 9830, 9466, 9223, 8859, 8738, 8495, 8374, 8252, 7888, 7645, 7403, 7281, 7039, 6796, 6553, 6189, 5825, 5704, 5218, 4975, 4854, 4611, 4369, 4247, 4004, 3883, 3640, 3398, 3398, 2912, 2669, 2427, 2063, 1820, 0, 1092, 728, 364, 0, -242, -1092, -1699, -1941, -2063, -2427, -2548, -2791, -2912, -2912, -3155, -3276, -3398, -3762, -4004, -4247, -4490, -4733, -4975, -5218, -5582, -5946, -5946, -6189, -6432, -6674, -7039, -7281, -7767, -7888, -8252, -8616, -8738, -8980, -9344, -9344, -9830, -9951, -10073, -10437, -10437, -10922, -11286, -11529, -11529, -11893, -12014, -12136, -12136, -11893, -11772, -11529, -11529, -11529, -11044, -10558
                                 };

bool toggle = true;
int lastButtonState = 0;
bool toggle2 = true;
int lastButtonState2 = 0;
bool toggle3 = true;
int lastButtonState3 = 0;
bool toggle4 = true;
int lastButtonState4 = 0;


void setup() {
  //Audio setup
  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);
  sgtl5000_1.micGain(36);
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);

  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(Boton1, INPUT_PULLUP);    // sets the digital pin 2 as input
  pinMode(Boton2, INPUT_PULLUP);
  pinMode(Boton3, INPUT_PULLUP);
  pinMode(Boton4, INPUT_PULLUP);
  pinMode(Gate1, INPUT_PULLUP);
  pinMode(Gate2, INPUT_PULLUP);
  pinMode(Encoderbut, INPUT_PULLUP);



  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(9, OUTPUT);

  // Wavetable variables
  int wavetype = WAVEFORM_ARBITRARY;
  waveform1.begin(wavetype);
  waveform2.begin(wavetype);


  waveform1.amplitude(1);
  waveform2.amplitude(1);
  filter1.octaveControl(4);

}


void loop() {
  BotonValue1 = digitalRead(Boton1);
  BotonValue2 = digitalRead(Boton2);
  BotonValue3 = digitalRead(Boton3);
  BotonValue4 = digitalRead(Boton4);
  GateValue1 = digitalRead(Gate1);
  GateValue2 = digitalRead(Gate2);
  EncoderbutValue = digitalRead(Encoderbut);

  // read the value from the pots:
  PotValue1 = (float)analogRead(PotPort1) / 1023.0;
  PotValue2 = (float)analogRead(PotPort2) / 1023.0;
  PotValue3 = (float)analogRead(PotPort3) / 1023.0;
  PotValue4 = (float)analogRead(PotPort4) / 1023.0;

  waveform1.arbitraryWaveform(v1_array, 300);
  waveform2.arbitraryWaveform(phi1_array, 200);

  if (toggle == true) {
    waveform1.frequency(PotValue1 * 30);
  }
  if (toggle == false) {
    waveform1.frequency(PotValue1 * 150);
  }
  if (toggle2 == true) {
    waveform2.frequency(PotValue2 * 100);
  }
  if (toggle2 == false) {
    waveform2.frequency(PotValue2 * 400);
  }
  if (toggle3 == true) {
    filter1.frequency(60 + PotValue3 * 100);
  }
  if (toggle3 == false) {
    filter1.frequency(60 + PotValue3 * 1111);
  }
  if (toggle4 == true) {
    filter1.resonance(0.7 + (PotValue4 * 5));
  }
  if (toggle4 == false) {
    filter1.resonance(0.7 + (PotValue4 * 1));
  }

  if (BotonValue1 != lastButtonState) {
    if (BotonValue1 == HIGH) {
      toggle = !toggle;
    }
  }
  lastButtonState = BotonValue1;

  if (BotonValue2 != lastButtonState2) {
    if (BotonValue2 == HIGH) {
      toggle2 = !toggle2;
    }
  }
  lastButtonState2 = BotonValue2;

  if (BotonValue3 != lastButtonState3) {
    if (BotonValue3 == HIGH) {
      toggle3 = !toggle3;
    }
  }
  lastButtonState3 = BotonValue3;

  if (BotonValue4 != lastButtonState4) {
    if (BotonValue4 == HIGH) {
      toggle4 = !toggle4;
    }
  }
  lastButtonState4 = BotonValue4;


}