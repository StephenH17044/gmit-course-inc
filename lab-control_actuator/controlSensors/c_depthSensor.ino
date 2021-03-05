//++++++++++ Defining Pinouts ++++++++++
#define PIN_SENSOR A1

//++++++++++ Define PinMode ++++++++++
#define pinMode(PIN_READ, INPUT);

//++++++++++ Define Array Varibles ++++++++++
const int ArrElements = 20;               
int Readings[ArrElements]; 

//++++++++++ Define Distance Class ++++++++++
class DistanceSensor {
  private:                                                                    // Defining Private Varibles
    unsigned long nextChangeTime = 0;
    unsigned long OnTime;
    int Value;                             
    float Voltage;
    float Distance;
    float DistancePoly;
    int SensorAverage = 0;
    int Total = 0;   
    int ReadingIndex = 0;
    
  public:                                                                     // Passing data into private varibles
     DistanceSensor(int Value, unsigned long OnTime) {
        this->Value = Value;
        this->OnTime = OnTime;
    }
    
    void Check() {                                                           // Checks Value from sensor
      unsigned long currentTime = millis();
      
      if(currentTime >= nextChangeTime){                                      
        Voltage = SensorAverage * (5.0 / 1023.0);                             
        Distance = -21.75*(Voltage) + 58.021;                                 
        DistancePoly = 12.275*pow(Voltage,4) - 92.759*pow(Voltage,3)          
        + 252.03*pow(Voltage,2) - 303.81*(Voltage) + 156.35;
        nextChangeTime = currentTime + OnTime;                                
        Print();                                                              
      }
    }

    void Smooth() {                                                           //Smooths Analog Read Values             
      Total = Total - Readings[ReadingIndex];     
      Readings[ReadingIndex] = GetValue();     
      Total = Total + Readings[ReadingIndex];
      ReadingIndex = ReadingIndex + 1;
      if (ReadingIndex >= ArrElements) {
        ReadingIndex = 0;
      }
      SensorAverage = Total / ArrElements;
      delay (1);      
    }

    void Print() {                                                            //Prints Data aquired from sensor at equal intervals
       Serial.print("Distance (y=mx+c): ");                               
       Serial.print(Distance);
       Serial.print("     ");
       Serial.print("Distance Polynomial: ");  
       Serial.print(DistancePoly);                   
       Serial.println(" ");                                                
    }

    int GetValue(){                                                           // Read Analog Input 
      int Value = analogRead(PIN_SENSOR);                                                  
      return Value;
    }
};
