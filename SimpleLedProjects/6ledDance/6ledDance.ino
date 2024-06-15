int l[] = {2,3,4,5,6,7};
int length = 6;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0;i<length;i++){
      pinMode(l[i],OUTPUT);
      digitalWrite(l[i],LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0;i<length;i++){
    turnOnLed(i);
    delay(200);
  }
  // avoid endpoints so we dont turn on same led twice
  for(int i = length-2;i>0;i--){
    turnOnLed(i);
    delay(200);

  }
}

void turnOnLed(int i){
    // check two neighbors to be off
    if(i-1>-1){
      digitalWrite(l[i-1],LOW);
    }
    if(i+1<length){
      digitalWrite(l[i+1],LOW);
    }
    digitalWrite(l[i],HIGH);
}


