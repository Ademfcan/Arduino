
#include "UnoJoy.h"

void setup(){
  setupPins();
  setupUnoJoy();
  Serial.begin(9600);
}

void loop(){
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  // Set all the digital pins as inputs
  // with the pull-up enabled, except for the 
  // two serial line pins
  for (int i = 2; i <= 12; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);
}

dataForController_t getControllerData(void){
  
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins
  controllerData.triangleOn = !digitalRead(2);
  controllerData.circleOn = !digitalRead(3);
  controllerData.squareOn = !digitalRead(4);
  controllerData.crossOn = !digitalRead(5);
  controllerData.dpadUpOn = !digitalRead(6);
  controllerData.dpadDownOn = !digitalRead(7);
  controllerData.dpadLeftOn = !digitalRead(8);
  controllerData.dpadRightOn = !digitalRead(9);
  // controllerData.l1On = !digitalRead(A4);
  // controllerData.r1On = !digitalRead(A5);
  controllerData.selectOn = !digitalRead(12);
  controllerData.startOn = !digitalRead(10);
  controllerData.homeOn = !digitalRead(11);
  
  // Set the analog sticks
  //  Since analogRead(pin) returns a 10 bit value,
  //  we need to perform a bit shift operation to
  //  lose the 2 least significant bits and get an
  //  8 bit number that we can use  
  // int mapped = constrain(map(analogRead(A0),559,602,0,255),0,255);
  
  // controllerData.leftStickX = mapped;
  controllerData.leftStickY = analogRead(A1) >> 2;
  controllerData.rightStickX = analogRead(A2) >> 2;
  controllerData.rightStickY = analogRead(A3) >> 2;
  controllerData.r1On = analogRead(A4) >> 2;
  controllerData.l1On = analogRead(A5) >> 2;
  // And return the data!
  return controllerData;
}
