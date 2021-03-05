// ++++++++++ Class Varibles Declaration ++++++++++

Blinker blink0 = Blinker(PIN_LED0, 1000, 500); 
Blinker blink1 = Blinker(PIN_LED1, 1000, 500); 
DistanceSensor DS = DistanceSensor(PIN_SENSOR,10);
ServoActuator SA = ServoActuator (PIN_SERVO, 10, 10, 20);

#include <Servo.h>

// ++++++++++ Program Setup ++++++++++

void setup() { 
  Serial.begin(9600);
  //Initialize Values in Array
  for (int i = 0; i < ArrElements; i++) {
    Readings[i] = 0;
  }
}      


// ++++++++++ Main Program ++++++++++

void loop() {
  Servo myservo;
  blink0.check();
  blink1.check();
  DS.Smooth();
  DS.Check();
  SA.setAngle(DS.getPolyDistance());
  SA.ActuateServo();
}
