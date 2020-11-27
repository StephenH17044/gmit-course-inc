const int analogPin=A1; //Analog Sensor Pin
const int ledCount=2; //number of LED's
int ledPins[]={2,3}; //Array for defined Pins

void setup() {
for (int thisLed=0;thisLed<ledCount;thisLed++){
  pinMode(ledPins[thisLed],OUTPUT);//thispin=led number, sets as outputs

}
Serial.begin(9600);
}


void loop() {
  int sensorReading=analogRead(analogPin); //Reads value on Sensor pin A1 
  int ledLevel=map(sensorReading,0,1023,0,ledCount);//Compares sensor value to scale and applies to range of LED's
  Serial.println(sensorReading);
  for (int thisLed=0;thisLed<ledCount;thisLed++){
    if(thisLed<ledLevel){
      digitalWrite (ledPins[thisLed],HIGH);//As value increases from 0 to 1023, each led is turned on at specified points. 
    }
      else{
      digitalWrite (ledPins[thisLed],LOW);//else both are off  
      }
    }
  }
