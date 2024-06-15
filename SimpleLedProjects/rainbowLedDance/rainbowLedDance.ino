int l[] ={3,A5,A4,A3,A2,A1,A0,10,9,8,7,6,5,4};
int length = 14;
void setup() {
  // setting up the output pins
  for(int i =0;i<length;i++){
    pinMode(l[i],OUTPUT);
    digitalWrite(l[i],LOW);

  }
}
int timeout = 400;
void loop() {
  // put your main code here, to run repeatedly:
  // left to right turn on
  setSequential(true,true);
  // left to right turn off
  setAll(false);
  delay(timeout);
  // right to left turn on
  setSequential(false,true);
  // right to left turn off
  setAll(false);
  delay(timeout);
}
int ledTimeout = 150;
int maxDistance = 4;
void setSequential(bool isLeftToRight,bool isOn){
  if(isLeftToRight){
    for(int i =0;i<length;i++){
          digitalWrite(l[i],isOn ? HIGH : LOW);
          if(i-maxDistance >= 0 ){
            digitalWrite(l[i-maxDistance],isOn ? LOW : HIGH);
          }
          delay(ledTimeout);
    }
  }
  else{
      for(int i =length-1;i>=0;i--){
          digitalWrite(l[i],isOn ? HIGH : LOW);
          if(i+maxDistance <length){
            digitalWrite(l[i+maxDistance],isOn ? LOW : HIGH);
          }
          delay(ledTimeout);
      }
  }
}

void setAll(bool isOn){
  for(int i =0;i<length;i++){
        digitalWrite(l[i],isOn ? HIGH : LOW);
    }
}


