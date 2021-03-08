#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Encoder.h>

/* LCD pinout:
1   Vss       GND
2   Vss       +5V
3   LCD Drive poti power
4   RS        11
5   R/W       GND
6   EN        12
7   D0        --
8   D1        --
9   D2        --
10  D3        --
11  D4        2
12  D5        3
13  D6        4
14  D7        5
15  A         +5V
16  K         GND

*/

// LCD pins <--> Arduino pins
const int RS = 11, EN = 12, D4 = 8, D5 = 9, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// ENCODER:
// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(2, 3);
//   avoid using pins with LEDs attached

byte customChar[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000,
    0b00000};

void setup()
{
  pinMode(6, INPUT_PULLUP);

  Serial.begin(9600);

  lcd.begin(16, 2); // set up number of columns and rows
  // lcd.createChar(0, customChar); // create a new custom character
  // lcd.setCursor(2, 0); // move cursor to (2, 0)
  // lcd.write((byte)0);  // print the custom char at (2, 0)

  // lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  // lcd.print("Arduino");        // print message at (0, 0)
  // lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  // lcd.print("GetStarted.com"); // print message at (2, 1)
}

void loop()
{
  static int save_value;
  static long encoder_oldPosition = -999;
  static long encoder_last_measure = 0;
  static int encoder_count = 0;
  static int encoder_previous_count = 0;
  long encoder_newPosition = myEnc.read();

  // ROTARY ENCODER:
  if (encoder_oldPosition != encoder_newPosition && millis() > encoder_last_measure + 0)
  {
    if (encoder_oldPosition > encoder_newPosition)
    {

      if (encoder_count > 0)
        encoder_count--;
      encoder_oldPosition = encoder_newPosition;
      encoder_last_measure = millis();
      if (encoder_count < 100 && encoder_previous_count >= 100)
        lcd.clear();
      encoder_previous_count = encoder_count;
    }
    else
    {
      if (encoder_count < 127)
        encoder_count++;
      encoder_oldPosition = encoder_newPosition;
      encoder_last_measure = millis();
    }
  }

  // PUSH BUTTON:
  if (digitalRead(6) == LOW)
    save_value = encoder_count;

  // LCD SETUP:
  lcd.setCursor(0, 0);      // move cursor to   (0, 0)
  lcd.print(encoder_count); // print message at (0, 0)

  lcd.setCursor(4, 0);
  lcd.print(save_value);

  lcd.setCursor(2, 1);                              // move cursor to   (2, 1)
  lcd.print("Joguslaw JAroslaw Kabelbart Toaster"); // print message at (2, 1)
  // delay(200);
  // lcd.autoscroll();
}
