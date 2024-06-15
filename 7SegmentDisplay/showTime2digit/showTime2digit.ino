// Pin configuration (1-indexed for convenience)
int pins[] = {-10, 11, 10, 9, 8, 7, 2, 3, 4, 5, 6};
int pinC = 10;

// Digit pin mappings
struct DigitPins {
    int *pins;
    int count;
};
// these are the pins to activate to light up each digit
// refer to datasheet for more information (page 5)
// https://www.lcsc.com/datasheet/lcsc_datasheet_2203101903_ARKLED-Wuxi-ARK-Tech-Elec-SN720362W-16_C2980910.pdf
DigitPins digits[] = {
    {new int[6]{3, 9, 8, 6, 7, 4}, 6},   // 0
    {new int[2]{9, 8}, 2},              // 1
    {new int[5]{3, 9, 6, 7, 1}, 5},     // 2
    {new int[5]{3, 9, 8, 6, 1}, 5},     // 3
    {new int[4]{9, 8, 4, 1}, 4},        // 4
    {new int[5]{3, 8, 6, 4, 1}, 5},     // 5
    {new int[6]{3, 8, 6, 7, 4, 1}, 6},  // 6
    {new int[3]{3, 9, 8}, 3},           // 7
    {new int[7]{3, 9, 8, 6, 7, 4, 1}, 7}, // 8
    {new int[6]{3, 9, 8, 6, 4, 1}, 6}   // 9
};

// Delays
int counterDelay = 1000;
int switchDelay = 5;

void setup() {
    // set up all pins for output
    for (int i = 1; i <= pinC; i++) {
        pinMode(pins[i], OUTPUT);
    }
}

void loop() {
    for (int i = 0; i < 99; i++) {
        // calculate what digit to show on either side
        int right = i % 10;
        int left = i / 10;
        bool isLeft = true;
        // set each left/right sides on/off very quickly to make it appear as both sides are on at the same time
        // this is the only way due to the display having shared pins
        for (int j = 0; j < counterDelay; j += switchDelay) {
            if (isLeft) {
                setDigit(true, left, false);
            } else {
                setDigit(false, right, false);
            }
            isLeft = !isLeft;
            delay(switchDelay);
        }
    }
}

void setDigit(bool isLeft, int num, bool isDot) {
    clearAllPins();
    // refer to datasheet at start of program for more info
    int groundPin = isLeft ? 10 : 5;
    digitalWrite(pins[groundPin], LOW);
    // pin #2 is the dot pin
    digitalWrite(pins[2], isDot ? HIGH : LOW);

    setPins(digits[num].pins, digits[num].count);
}

void clearAllPins() {
    for (int i = 1; i <= pinC; i++) {
        digitalWrite(pins[i], LOW);
    }
    // turn ground pins "off" aswell
    digitalWrite(pins[5], HIGH);
    digitalWrite(pins[10], HIGH);
}

void setPins(int pinIndxs[], int pinC) {
    for (int i = 0; i < pinC; i++) {
        digitalWrite(pins[pinIndxs[i]], HIGH);
    }
}