int l1 = 0;
int l2 = 1;

void setup() {
  // set up pins
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  turnOffBoth();
}

void loop() {
  // go  back and forth
  setL1(true);
  delay(150);
  setL2(true);
  delay(350);

  turnOffBoth();

  setL2(true);
  delay(150);
  setL1(true);
  delay(350);

  turnOffBoth();

  
  

}

void setL1(bool turnOffL2){
  if(turnOffL2){
    digitalWrite(l2,LOW);
  }
  digitalWrite(l1,HIGH);
}

void setL2(bool turnOffL1){
  if(turnOffL1){
    digitalWrite(l1,LOW);
  }
  digitalWrite(l2,HIGH);
}

void turnOffBoth(){
    digitalWrite(l1,LOW);
    digitalWrite(l2,LOW);
}
