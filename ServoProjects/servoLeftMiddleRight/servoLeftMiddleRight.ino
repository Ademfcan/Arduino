#include <Servo.h>
Servo myServo;
int pwmPin = 3;
int potPin = A0;
int val = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pwmPin,OUTPUT);
  Serial.begin(9600);
  myServo.attach(pwmPin);
}

void loop() {
  val = analogRead(potPin);            
  val = map(val, 0, 1023, 0, 180);    
  myServo.write(val);  
}
