int inputPins[] = {2,3,4,5,6};
int outFrequencies[] = {500,1200,1500,1900,2300};
int buzzerOut = 13;
int numKeys = 5;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0;i<numKeys;i++){
    pinMode(inputPins[i],INPUT);
  }
  pinMode(buzzerOut,OUTPUT);
}

void loop() {
  // clear buzzer
  noTone(buzzerOut);
  int sumFreqs = 0;
  for(int i = 0;i<numKeys;i++){
     // sum up the frequencys of the pressed buttons, to achieve a effect where you can create combinations of the buttons being pressed
     int isOn = digitalRead(inputPins[i]);
     if(isOn == 1){
        sumFreqs+=outFrequencies[i];
     }
  }
  if(sumFreqs != 0){
    tone(buzzerOut,sumFreqs);
  }
  delay(100);
}
