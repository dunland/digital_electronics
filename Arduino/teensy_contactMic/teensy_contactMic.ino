unsigned long lastBlink;

void setup() {
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  int pinValue = analogRead(A0);
  // int pinValue = digitalRead(2);
  Serial.println(pinValue);
  
  //if (digitalRead(2) == HIGH)
  if (pinValue > 750)
  {
    digitalWrite(13, HIGH);
    lastBlink = millis();
  }
  else //if (millis() > lastBlink + 50)
  {
    digitalWrite(13, LOW);
  }
  delay(10); // Teensy Serial object always communicates at 12 Mbit/sec USB speed. Many computers can not update the serial monitor window if there is no delay to limit the speed! 
}
