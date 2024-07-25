int triggerPin = 10;
int sensorOut = A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(triggerPin, OUTPUT);
  pinMode(sensorOut, INPUT);
  Serial.begin(9600);
}

void loop() {
  // clear trigger pin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  sendShortPulse();
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(sensorOut, HIGH);
  // Calculating the distance
  int distance = duration / 148;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}

void sendShortPulse() {
  digitalWrite(triggerPin, HIGH);
  delay(.1);
  digitalWrite(triggerPin, LOW);
}
