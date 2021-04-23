#define PinA 2
#define PinB 3
#define PinC 4
#define PinD 5
#define NUMBER_OF_STEPS_PER_REV 512
int i=0;

void setup() {
  //pinMode(ForwardButton,INPUT); 
  //pinMode(ReverseButton,INPUT); 
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
  for(int i=0;i<512;i++){
    stepForward(5);
  }
  for(int i=0;i<512;i++){
    stepBackward(5);
  }
}
