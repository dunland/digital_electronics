static const uint8_t pins[] = {A0, A1, A2, A3};

void setup() {

  Serial.begin(19200);

  int numInputs = 4;
  int pinNum = 0;
  int totalSamples = 0;
  for (int n = 0; n < 400; n++)
  {
    pinNum = (pinNum + 1) % numInputs;
    totalSamples += analogRead(pins[pinNum]);
  }

  int noiseFloor = totalSamples / 400;
  Serial.println("noisefloor is at ");
  Serial.println(noiseFloor);
}

void loop() {
  // put your main code here, to run repeatedly:

}
