// ++++++++++ Class Varibles Declaration ++++++++++

Blinker blink0 = Blinker(PIN_LED0, 1000, 500); 
Blinker blink1 = Blinker(PIN_LED1, 1000, 500); 
DistanceSensor DS = DistanceSensor(PIN_SENSOR,50);

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
  blink0.check();
  blink1.check();
  DS.Smooth();
  DS.Check();
}
