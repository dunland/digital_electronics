// Yellowsnow's Oscilloscope Free for use..instructions  https://www.youtube.com/watch?v=VQwh-y2jW_c

#define pin A0
int sample[1000];
int x = 0;
unsigned long startTime = 0;
unsigned long stopTime = 0;

int startSample = 0;
int sampleTime = 1000;                  // sample time length in microseconds
int samplesTaken = 0; 
char incomingMess = 0; 
int dump = 0;  

void setup() {
  
 
  pinMode(pin, INPUT);
  Serial.begin(115200);
}

void loop() {
  
  if (Serial.available() > 0) {
    incomingMess = Serial.read();    
    messDo();
  }
  
  
  if(startSample == 1) {
    x = 0;
    startTime = micros();
    stopTime = startTime + sampleTime;
    while(micros() <= stopTime && x <= 999) {
      sample[x] = analogRead(pin);
      x = x + 1;
      }
    samplesTaken = x;
    startSample = 0;
  }
  
}



void messDo() {
  if(incomingMess == 'T') {           // T=start
    startSample = 1;
  }
  if(incomingMess == 'S') {           // S=sendsample
    sendSample();
  }
  if(incomingMess == 'A') {          // A=send amount of samples taken    
    sendAmount();
  }
}

void sendSample() {
  x = 0;
  while(x <= samplesTaken) {
    dump = sample[x];
    Serial.println(dump);
    x = x + 1;
     
  }
  Serial.println("8888");
}

void sendAmount() {
  Serial.println(samplesTaken);
}
