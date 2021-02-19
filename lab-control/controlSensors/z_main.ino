// ++++++++++ Class Varibles Declaration ++++++++++

Blinker blink0 = Blinker(PIN_LED0, 1000, 500); 
Blinker blink1 = Blinker(PIN_LED1, 1000, 500); 
DistanceSensor DS = DistanceSensor(PIN_SENSOR,500);

void setup() { 
Serial.begin(9600);
}

// ++++++++++ Main Program ++++++++++1`11`1``11`

void loop() {
  blink0.check();
  blink1.check();
  DS.Check();
}
