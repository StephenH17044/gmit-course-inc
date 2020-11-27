int led = 9; // Defining Pinout used on Arduino Board
int brightness = 0; //Initial Value for brightness
int fadeAmount = 1; //Incremental Brightness Increase Amount


void setup() {
  pinMode(led, OUTPUT);//Defining the pinout number for the circuit
}
void loop() {
  analogWrite(led,brightness); //Output to Breadboard
  brightness=brightness+fadeAmount; //Brightness increases by fade amount each loop
  if (brightness==0||brightness==255){//if condition 
    fadeAmount=-fadeAmount;//changes direction of fade
  }
 delay(10);//0.01s delay between cycles
}
