#include <AcceleroMMA7361.h>

//ACCEL
AcceleroMMA7361 accelero;

int x;
int y;
int z;

const int sleepPin = 13;
const int selfTestPin = 12;
const int zeroGPin = 11;
const int gSelectPin = 10;
const int xPin = A0;
const int yPin = A1;
const int zPin = A2;

int lastX = 128;
int lastY = 128;
int lastZ = 128;

boolean delayIt = false;
boolean outputMIDI = true; //output serial or MIDI ?

void setup()
{
 Serial.begin(115200);//was 9600 //115200
 accelero.begin(sleepPin, selfTestPin, zeroGPin, gSelectPin, xPin, yPin, zPin); 
 accelero.setARefVoltage(5); //sets the AREF voltage to 3.3V
 accelero.setSensitivity(LOW); //sets the sensitivity to +/-6G
 
 //if (outputMIDI == false)
 //{
   accelero.calibrate();
 //}
}

void loop()
{
   delay(50); 
   delayIt = false;
  
   x = accelero.getXAccel();
   y = accelero.getYAccel();
   z = accelero.getZAccel();
   
  
   
   if (x >127)
   {
      x = 127; 
   }
   
   if (y >127)
   {
      y = 127; 
   }
   
   if (z >127)
   {
      z = 127; 
   }
   
   if (x < 0)
   {
      x = 0; 
   }
   
   if (y < 0)
   {
      y = 0; 
   }
   
   if (z < 0)
   {
      z = 0; 
   }
   
   z = 127 - z;
 
  if (x != lastX) 
  {
     if (outputMIDI)
     {
       Serial.write(0xB0);
       Serial.write(1);
       Serial.write(x);
     }
    
    lastX = x;
    
    delayIt = true;
  }
  
  if (y != lastY) 
  {
    if (outputMIDI)
   {
     Serial.write(0xB0);
     Serial.write(2);
     Serial.write(y);
   }
 
     
    lastY = y;
    
    delayIt = true;
  }
    
  if (z != lastZ) 
  {
     if (outputMIDI)
     {
       Serial.write(0xB0);
       Serial.write(3);
       Serial.write(z);
     }

    lastZ = z;
    
    delayIt = true;
  }

  if (delayIt)
  {
     delay(50);
     if (outputMIDI == false)
     {
       Serial.print("accX :");
       Serial.print(x);
       Serial.print(" \taccY :");
       Serial.print(y);
       Serial.print(" \taccZ :");
       Serial.println(z);
       //Serial.print("\tG*10^-2");
     }
  }
}
