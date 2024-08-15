const int key1In = 5;
const int key2In = 6;
const int key3In = 7;
const int buzzerPin = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(key1In,INPUT_PULLUP);
  pinMode(key2In,INPUT_PULLUP);
  pinMode(key3In,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int freq1 = digitalRead(key1In) == 0 ? 639 : 0;
  int freq2 = digitalRead(key2In) == 0 ? 230 : 0;
  int freq3 = digitalRead(key3In) == 0 ? 1000 : 0;
  int total = freq1 + freq2 + freq3;
  if(total > 0){
    tone(buzzerPin,total);
    delay(300);
    noTone(buzzerPin);

  }
  else{
    delay(50);
  }
  
}
