/*
  Smoothing

  Reads repeatedly from an analog input, calculating a running average and
  printing it to the computer. Keeps ten readings in an array and continually
  averages them. Only active when a push button as pressed (A trigger input).

  The circuit:
  - analog sensor (potentiometer will do) attached to analog input 0
  - Push button 

  created 22 Apr 2007
  by David A. Mellis  <dam@mellis.org>
  modified 9 Apr 2012
  by Tom Igoe
  modfied 29 Nov 2020
  by Stephen Higgins
   
  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Smoothing
*/

// Define the number of samples to keep track of. The higher the number, the
// more the readings will be smoothed, but the slower the output will respond to
// the input. Using a constant rather than a normal variable lets us use this
// value to determine the size of the readings array.
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;  //Defining A0 as "inputpin"
int Button = 3;     //Defining 3 as "Button"
int reading=0;      //Setting initial value for "reading" as 0

void setup() {
  pinMode(Button,INPUT); //Defining Digital I/O as a Input "Button" (3)
 
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}
  
void loop() {
  reading=digitalRead(Button); //Value High/Low from diPin 3 "Button" stored in int reading
  if (reading==1){ //if value at Button is HIGH reading is equal to 1 and runs serial read for as long as button is pressed. Else pauses.
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.println(average);
  delay(1);        // delay in between reads for stability
}
}
