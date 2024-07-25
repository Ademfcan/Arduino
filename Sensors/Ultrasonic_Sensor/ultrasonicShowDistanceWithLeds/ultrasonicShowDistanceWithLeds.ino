int triggerPin = 10;
int sensorOut = A1;
int ledpins[] = {2,3,4,5,6,7,8,9,11,12,A0};
int ledCount = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(triggerPin, OUTPUT);
  pinMode(sensorOut, INPUT);
  for(int i = 0;i<ledCount;i++){
    pinMode(ledpins[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // clear trigger pin
  sendShortPulse();
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(sensorOut, HIGH);
  // Calculating the distance in inches
  int distance = duration / 500;
  lightUpLeds(distance);
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(200);
}

void sendShortPulse() {
  digitalWrite(triggerPin, HIGH);
  delay(.1);
  digitalWrite(triggerPin, LOW);
}


void lightUpLeds(int distance){
    for(int i = 0;i<ledCount;i++){
    digitalWrite(ledpins[i],LOW);
  }
    
    int diff = ledCount-distance;
    int numLedsOn = max(diff,0);
    for(int i = 0;i<numLedsOn;i++){
      digitalWrite(ledpins[i],HIGH);
    }
    for(int i = numLedsOn;i<ledCount;i++){
      digitalWrite(ledpins[i],LOW);
    }

}
