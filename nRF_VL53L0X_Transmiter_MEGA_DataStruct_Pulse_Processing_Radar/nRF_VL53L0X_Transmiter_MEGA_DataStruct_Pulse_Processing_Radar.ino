/*Peter Rhoades:
Saturday 05/03/22:
nRF Transmitter to Laser Range Reciver MEGA®
VL53L0X Address 0x29:
18/02/22 pipe = 0x8675309ABCll changer to const byte address[6] = "00001";:
05/03/22 Servo pulse 0°to60°to30°to90°etc:

°
 nRF Tranciver 
  1 = GRN  Black   
  2 = 3.3v Red
  3 = CE   Pin 7  Blue
  4 = CSN  Pin 8  Breen
  5 = SCK  Pin 52 Yellow
  6 = MOSI Pin 51 White
  7 = MISO Pin 50 Orange
   _______________________
  | 1 | 2 |              |
  | 3 | 4 |              | 
  | 5 | 6 |              |
  |_7_|___|______________|
*/

#include  <SPI.h>
#include "RF24.h"
#include <Servo.h>.   
int distance;//Measurement to Radar Display:
#include <Wire.h>
#include <VL53L0X.h> //Laser ToF
VL53L0X sensor;
Servo myServo; //Creates a servo object for controlling the servo motor  
const byte address[6] = "00001"; //Writing Message Only Pipe:
RF24 radio(7,8);

struct dataStruct
{
  int  angle180;
  int  distanceMM;
} myData; //Holds Payload Data to be Sent:

void setup() {  
  Serial.begin(9600); 
  Wire.begin();
  sensor.init();//Starts Sensor:
  sensor.startContinuous(); //Start continuous back-to-back mode:
  radio.begin();
  radio.openWritingPipe(address); //Writing Message Only:
  radio.enableDynamicPayloads();
  myServo.attach(3);//Defines on which pin is the servo motor attached: 
 }  
 
 void loop() {  
    for(int i=1;i<=60;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i; 
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i; //Add angle180 to myData:
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance; //Add distanceMM to myData:
  radio.write( &myData, sizeof(myData) ); //Sent myData:
  }
    for(int i=60;i>=30;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
    for(int i=30;i<=90;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
    for(int i=90;i>=60;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
    for(int i=60; i<=120;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
    for(int i=120; i>=90;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
    for(int i=90; i<=150;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
    for(int i=150; i>=120;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
    for(int i=90; i>=150;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
  for(int i=150; i<=120;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
  for(int i=120; i<=180;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
 //======================================================================== 
  }
     for(int i=180; i>=120;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
    for(int i=120; i<=150;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
     for(int i=150;i>90;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
     for(int i=90;i<120;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
    for(int i=120;i>60;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
     for(int i=60;i<90;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
     for(int i=90;i>30;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
     for(int i=30;i<60;i++){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
     for(int i=60;i>1;i--){ 
  delay (5);
  myServo.write(i);  
  distance = (sensor.readRangeContinuousMillimeters()); // Sensor metric reading:
  int angle180 = i;
  Serial.print(i);
  Serial.print(",");
  myData.angle180 = i;
  distance = distance / 10;// Turnes mm into cm:
  int distanceMM = distance;
  Serial.print(distance);
  Serial.print(".");
  myData.distanceMM = distance;
  radio.write( &myData, sizeof(myData) );
  }
 }
