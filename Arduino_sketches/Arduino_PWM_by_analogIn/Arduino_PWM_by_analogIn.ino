void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  static int pwm;
  pwm = analogRead(A0) / 4;
  Serial.println(pwm);
  //analogWrite(10, pwm);

  digitalWrite(10, HIGH);
  delay(500);
  digitalWrite(10,LOW);
  delay(500);
}
