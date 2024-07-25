int REDPin = 3;    // RED pin of the LED to PWM pin 4
int GREENPin = 5;  // GREEN pin of the LED to PWM pin 5
int BLUEPin = 6;   // BLUE pin of the LED to PWM pin 6
int increment = 5;  // brightness increment

void setup()
{
  pinMode(REDPin, OUTPUT);
  pinMode(GREENPin, OUTPUT);
  pinMode(BLUEPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // for(int i = 0;i<255+increment;i+=increment){
  //   for(int j = 0;j<255+increment;j+=increment){
  //     for(int k = 0;k<255+increment;k+=increment){
  //       analogWrite(REDPin, i);
  //       analogWrite(GREENPin, j);
  //       analogWrite(BLUEPin, k);

  //     }
  //   }

  // }
  setRed();
  delay(500);  
  setGreen();
  delay(500);  
  setBlue();
  delay(500);  

  
}

void setRed(){
  analogWrite(REDPin, 255);
  analogWrite(GREENPin, 0);
  analogWrite(BLUEPin, 0);
}

void setGreen(){
  analogWrite(REDPin, 0);
  analogWrite(GREENPin, 255);
  analogWrite(BLUEPin, 0);
}

void setBlue(){
  analogWrite(REDPin, 0);
  analogWrite(GREENPin, 0);
  analogWrite(BLUEPin, 255);
}