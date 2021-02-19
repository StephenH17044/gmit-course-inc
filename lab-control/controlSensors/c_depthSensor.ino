//++++++++++ Defining Pinouts ++++++++++

#define PIN_SENSOR A1

//++++++++++ Define PinMode ++++++++++

#define pinMode(PIN_READ, INPUT);

//++++++++++ Define Class ++++++++++

class DistanceSensor {
  private:                                                                    // Defining Private Varibles
    unsigned long nextChangeTime = 0;
    unsigned long OnTime; 
    float SensorValue;                            
    float Voltage;
    float Distance;
    float DistancePoly;
    
   
  public:                                                                     // Passing data into private varibles
     DistanceSensor(float SensorValue, unsigned long OnTime) {
        this->SensorValue = SensorValue;
        this->OnTime = OnTime;
    }
    
    void Check() {
      unsigned long currentTime = millis();
      
      if(currentTime >= nextChangeTime){                                      // If time is greaterthan or equal to the values passed do this
        SensorValue=analogRead(PIN_SENSOR);                                   // Read Analog Input
        Voltage = SensorValue * (5.0 / 1023.0);                               // Convert to voltage
        Distance = -21.75*(Voltage) + 58.021;                                 // Calculate Distance y=mx+c
        DistancePoly = 12.275*pow(Voltage,4) - 92.759*pow(Voltage,3)          // Calculate Distance Polynomial
        + 252.03*pow(Voltage,2) - 303.81*(Voltage) + 156.35;
        nextChangeTime = currentTime + OnTime;                                //Increase Time by passed value, equal intervals
        Print();                                                              //Goto Routine Print
      }
    }

    void Print() {                                                            //Prints Data aquired from sensor at equal intervals
       Serial.print("Distance (y=mx+c): ");                               
       Serial.println(Distance);
       Serial.print("Distance Polynomial: ");  
       Serial.print(DistancePoly);                   
       Serial.println(" ");                                                
    }
};
