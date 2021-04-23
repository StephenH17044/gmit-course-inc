#define PinA 2
#define PinB 3
#define PinC 4
#define PinD 5
#define Button 8
#define NUMBER_OF_STEPS_PER_REV 512
int i=0;

void setup() { 
  pinMode (Button,INPUT); 
  pinMode (PinA,OUTPUT);
  pinMode (PinB,OUTPUT);
  pinMode (PinC,OUTPUT);
  pinMode (PinD,OUTPUT);
}

void forward(int a, int b,int c, int d){
  digitalWrite(PinA,a);
  digitalWrite(PinB,b);
  digitalWrite(PinC,c);
  digitalWrite(PinD,d);
  
}

void reverse(int a, int b,int c, int d){
  digitalWrite(PinA,a);
  digitalWrite(PinB,b);
  digitalWrite(PinC,c);
  digitalWrite(PinD,d);
  
}

void stepForward(int delayValue){
  forward(1,0,0,0);
  delay(delayValue);
  forward(1,1,0,0);
  delay(delayValue);
  forward(0,1,0,0);
  delay(delayValue);
  forward(0,1,1,0);
  delay(delayValue);
  forward(0,0,1,0);
  delay(delayValue);
  forward(0,0,1,1);
  delay(delayValue);
  forward(0,0,0,1);
  delay(delayValue);
  forward(1,0,0,1);
  delay(delayValue);
  
}

void stepBackward(int delayValue){
  reverse(1,0,0,1);
  delay(delayValue);
  reverse(0,0,0,1);
  delay(delayValue);
  reverse(0,0,1,1);
  delay(delayValue);
  reverse(0,0,1,0);
  delay(delayValue);
  reverse(0,1,1,0);
  delay(delayValue);
  reverse(0,1,0,0);
  delay(delayValue);
  reverse(1,1,0,0);
  delay(delayValue);
  reverse(1,0,0,0);
  delay(delayValue);
  
}

void loop() {
  bool buttonSignal=digitalRead(Button);
  int rawValue=analogRead(A0);
  int delayValue = map(rawValue,0,1023,5,100);
  
  if (buttonSignal==HIGH){
    stepForward(delayValue);
  }
  else{
    stepBackward(delayValue);
  }
}
