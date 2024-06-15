// int rowPins[8] = { A2, A1, A0, 0, 1, 2, 3, 4 };


// int rowPins[8] = { 13,12,11,10,9,8,7,6 };
// int colPins[8] = { A2, A1, A0, 0, 1, 2, 3, 4 };
int rowPins[8] = { 4,3,2,1,0,A0,A1,A2 };
int colPins[8] = { 6, 7, 8, 9, 10, 11, 12, 13 };
void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);  // Turn off all rows
  }

  // Initialize column pins as outputs
  for (int i = 0; i < 8; i++) {
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], LOW);  // Turn off all columns
  }
}

void loop() {
  // for (int row = 0; row < 8; row++) {
  //   for (int col = 0; col < 8; col++) {
  //     lightLed(row, col);
  //     delay(100);  // Adjust delay as needed
  //   }
  // }
}

void lightLed(int row, int col) {
  // Turn on the row
  digitalWrite(rowPins[row], LOW);
  // Turn on the column
  digitalWrite(colPins[col], HIGH);

  delay(500);  // Keep the LED on for a while

  // Turn off the row
  digitalWrite(rowPins[row], HIGH);
  // Turn off the column
  digitalWrite(colPins[col], LOW);
}
