//++++++++++ Defining Pinouts ++++++++++

#define PIN_LED0 2
#define PIN_LED1 3

//++++++++++ Define Class ++++++++++

class Blinker {
  
  private:                                                                        // Defining Private Varibles
    
    byte pinLED;
    boolean ledState = LOW;
    unsigned long timeLedOn;
    unsigned long timeLedOff;
    unsigned long nextChangeTime = 0;

  public:                                                                         // Passing data into private varibles
  
    Blinker(byte pinLED, unsigned long timeLedOn, unsigned long timeLedOff) {
      this->pinLED = pinLED;
      this->timeLedOn = timeLedOn;
      this->timeLedOff = timeLedOff;

      pinMode(pinLED, OUTPUT);                                                    // Declaring the PinMode to Output
    }

                                                                                  // Checks whether it is time to turn on or off the LED.
    void check() {
      unsigned long currentTime = millis();

      if(currentTime >= nextChangeTime) {                                         // If time is greaterthan or equal to the values passed do this

        if(ledState) {                                                            // If the LED is On turn it Off
          ledState = LOW;
          nextChangeTime = currentTime + timeLedOff;
        }
        else{                                                                     // If the LED is OFF turn it ON
          ledState = HIGH;
          nextChangeTime = currentTime + timeLedOn;
        }

        digitalWrite(pinLED, ledState);                                           //Change LED Stated to the output stated
      }
    }
};
