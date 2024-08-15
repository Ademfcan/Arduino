int leds[] = {5,6,7,8};
int ledC = 4;
int inputPin = 9;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0;i<ledC;i++){
    pinMode(leds[i],OUTPUT);
  }

  pinMode(inputPin,INPUT_PULLUP);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(inputPin) == 0){
    clearAll();
    runLedCycle();
  }
}

int startDelay = 200;
void clearAll(){
  for(int i = 0;i<ledC;i++){
    digitalWrite(leds[i],LOW);
  }
}

void runLedCycle(){
  int Stop = random(10,20);
  int indx = 1;
  digitalWrite(leds[0],HIGH);
  for(int i = 0;i<Stop;i++){
    int delayT = startDelay + i*10;
    int prevIndex = indx-1 >= 0 ? indx-1 : ledC-1;
    digitalWrite(leds[prevIndex],LOW);
    digitalWrite(leds[indx],HIGH);
    indx++;
    if(indx > ledC-1){
      indx = 0;
    }
    delay(delayT);
  }
  
}
