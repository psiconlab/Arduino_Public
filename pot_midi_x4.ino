byte potPinArr[] = {A0,A1,A2,A3};    // select the input pin for the potentiometer
int analogValue = 0;       // variable to store the value coming from the sensor

int lastAnalogValueArr[] = {128,128,128,128};
int sensorValueArr[] = {0,0,0,0};

int sensorValue = 0;


void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  for (int i=0;i<4;i++)
  {
      sensorValue = analogRead(potPinArr[i]);    // read the value from the sensor
      analogValue = map(sensorValue, 0, 1023, 0, 127); 
    
      // potentiometer could be too sensitive and give different (+-1) values.
      // send CC only when the difference between last value is more than 1
     
      if ((analogValue-lastAnalogValueArr[i]) > 1 || (analogValue-lastAnalogValueArr[i]) < -1) 
      {
        // value changed?
        if (analogValue != lastAnalogValueArr[i]) 
        {
          int cNum = i+1;
          Serial.write(0xB0|1); //CC | Channel Num (channel num starts at 0 like arrays - note the | symbol to break cc ref and channel num)
          Serial.write(cNum); //Controller Num
          Serial.write(analogValue); // Val
           
          lastAnalogValueArr[i] = analogValue;
        }
     }
  }
  delay(1);
}
