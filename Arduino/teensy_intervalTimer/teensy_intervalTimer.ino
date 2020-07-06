// Create an IntervalTimer object 
IntervalTimer myTimer;

const int ledPin = LED_BUILTIN;  // the pin with a LED

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  myTimer.begin(blinkLED, 150000);  // blinkLED to run every 0.15 seconds
}

// The interrupt will blink the LED, and keep
// track of how many times it has blinked.
int ledState = LOW;
volatile unsigned long blinkCount = 0; // use volatile for shared variables

// functions called by IntervalTimer should be short, run as quickly as
// possible, and should avoid calling other functions if possible.
void blinkLED() {
  if (ledState == LOW) {
    ledState = HIGH;
    blinkCount = blinkCount + 1;  // increase when LED turns on
  } else {
    ledState = LOW;
  }
  digitalWrite(ledPin, ledState);
}

// The main program will print the blink count
// to the Arduino Serial Monitor
void loop() {
  unsigned long blinkCopy;  // holds a copy of the blinkCount

  // to read a variable which the interrupt code writes, we
  // must temporarily disable interrupts, to be sure it will
  // not change while we are reading.  To minimize the time
  // with interrupts off, just quickly make a copy, and then
  // use the copy while allowing the interrupt to keep working.
  noInterrupts();
  blinkCopy = blinkCount;
  interrupts();

  Serial.print("blinkCount = ");
  Serial.println(blinkCopy);
  delay(100);
}
