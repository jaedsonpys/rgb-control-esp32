#include <analogWrite.h>
#include "rgb.h"

const int redLedPin = 33;
const int greenLedPin = 27;
const int blueLedPin = 14;

const int buzzerPin = 32;

RGB rgb(redLedPin, greenLedPin, blueLedPin);

void setup(){
  pinMode(buzzerPin, OUTPUT);
  rgb.red();
  rgb.green();
  rgb.blue();
}

void loop() {
  
}
