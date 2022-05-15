#include "Arduino.h"
#include "rgb.h"
#include "analogWrite.h"

RGB::RGB(int redPin, int greenPin, int bluePin) {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  redLedPin = redPin;
  greenLedPin = greenPin;
  blueLedPin = bluePin;
}

void RGB::red() {
  digitalWrite(this->redLedPin, !digitalRead(redLedPin));
}

void RGB::green() {
  digitalWrite(this->greenLedPin, !digitalRead(greenLedPin));
}

void RGB::blue() {
  digitalWrite(this->blueLedPin, !digitalRead(blueLedPin));
}

void RGB::rgb(int red, int green, int blue) {
  analogWrite(this->redLedPin, red);
  analogWrite(this->greenLedPin, green);
  analogWrite(this->blueLedPin, blue);
}
