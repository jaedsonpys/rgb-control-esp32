#ifndef RGB_h
#define RGB_h

class RGB {
  private:
    int redLedPin, greenLedPin, blueLedPin;

  public:
    RGB(int redPin, int greenPin, int bluePin);
    
    void red();
    void green();
    void blue();

    void rgb(int red, int green, int blue);
};

#endif
