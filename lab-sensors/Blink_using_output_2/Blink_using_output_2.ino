//Program starts when board is powered on or reset.
void setup() {
  //initialize digital pin LED_BUILTIN as an output.
pinMode (2,OUTPUT);
}
//the main loop function runs over and over again forever.
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(2,HIGH);
delay(1000);
digitalWrite(2,LOW);
delay(1000);
}
