//Program starts when board is powered on or reset.
int Button=8; //Name Pin 8 Button
int Led=9; //Name Pin 9 Led

void setup() {
  //initialize digital pin LED_BUILTIN as an output.

pinMode (Led,OUTPUT); //Led Pin is an output
pinMode (Button,INPUT); // Button Pin is a input
}
//the main loop function runs over and over again forever.
void loop() {
int reading=digitalRead(Button);//Take Reading from Pin 8 Button and save value as a interger
if (reading==1){ // If loop for while button is pressed led is on
  digitalWrite(Led,1);
}
else
  digitalWrite(Led,0);
}
