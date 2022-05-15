const int redLedPin = 33;
const int greenLedPin = 27;
const int blueLedPin = 14;

const int buzzerPin = 32;

class RGB {
  public:
    void red() {
      digitalWrite(redLedPin, !digitalRead(redLedPin));
    }

    void green() {
      digitalWrite(greenLedPin, !digitalRead(greenLedPin));
    }

    void blue() {
      digitalWrite(blueLedPin, !digitalRead(blueLedPin));
    }

    void rgb(int red, int green, int blue) {
      analogWrite(redLedPin, red);
      analogWrite(greenLedPin, green);
      analogWrite(blueLedPin, blue);
    }
};

RGB rgb;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  
}
