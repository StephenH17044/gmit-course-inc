//++++++++++ Include Lib's ++++++++++

#include <Servo.h>
Servo RunServo;

//++++++++++ Defining Pinouts ++++++++++

#define PIN_SERVO 8

//++++++++++ Defining Class ++++++++++

class ServoActuator{
  private:
    byte Value;
    float Angle;
    int Min;
    int Max;
    unsigned long nextChangeTime = 0;
    unsigned long OnTime;

  public:
    ServoActuator(byte Value, unsigned long timeOn, int Min, int Max){
      this->Value=Value;
      this->OnTime=OnTime;
      this->Min=Min;
      this->Max=Max;
   
      pinMode(Value,OUTPUT);
    }
    
    void setAngle(float PolyDistance){
        Angle = map(PolyDistance*1000, Min*1000, Max*1000, 0.00, 180.00);
      return;
    }

    float getAngle(){
      return Angle;
    }
    
    void ActuateServo(){
      unsigned long currentTime = millis();
      
      if(currentTime >= nextChangeTime){                                       
        if (getAngle()>=0.00 && getAngle()<=180.00){
          RunServo.attach(PIN_SERVO,470,2235);
          RunServo.write(getAngle());
          delay (1);
        }
        nextChangeTime = currentTime + OnTime;
      }              
      return; 
    }
};
