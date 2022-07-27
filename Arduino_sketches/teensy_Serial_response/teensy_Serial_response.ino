int incomingByte = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);
}

void loop() {
  //static int i = 0;
  //Serial.println(i++);
  delay(100);

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
}
