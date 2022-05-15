#include <analogWrite.h>

const int redLedPin = 33;
const int greenLedPin = 27;
const int blueLedPin = 14;

const int buzzerPin = 32;

class RGB {
  private:
    int redLedPin, greenLedPin, blueLedPin;
  
  public:
    RGB(int redPin, int greenPin, int bluePin) {
      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(bluePin, OUTPUT);

      redLedPin = redPin;
      greenLedPin = greenPin;
      blueLedPin = bluePin;
    }
  
    void red() {
      digitalWrite(this->redLedPin, !digitalRead(redLedPin));
    }

    void green() {
      digitalWrite(this->greenLedPin, !digitalRead(greenLedPin));
    }

    void blue() {
      digitalWrite(this->blueLedPin, !digitalRead(blueLedPin));
    }

    void rgb(int red, int green, int blue) {
      analogWrite(this->redLedPin, red);
      analogWrite(this->greenLedPin, green);
      analogWrite(this->blueLedPin, blue);
    }
};

RGB rgb(redLedPin, greenLedPin, blueLedPin);

void setup(){
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  
}
