/*Peter Rhoades
Saturday 21/12/25:            [[[[RECEIVER]]]]
RF VL53L0X Receiver NANO DataStruct Processing Radar®
Folder nRF Radar/RF_VL53L0X_Receiver_MEGA_DataStruct_Processing_Radar
*/

#include  <SPI.h>
#include "RF24.h"
RF24 radio(7,8);
const byte address[6] = "00001";

struct dataStruct
{
  int  angle180;
  int  distanceMM;
} myData; //Holds Payload Data to be Recived:

void setup(void)
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,address);
  radio.startListening();
  radio.enableDynamicPayloads();
 }

void loop(void)
 {
  if (radio.available()) 
 {                          
 radio.read( &myData, sizeof(myData) );// Get the payload
 }
  delay(20); //Delay to aid data sync with Sender:
    int i = myData.angle180; //Extract int i:
    Serial.print(i);
    Serial.print(",");
    int distance = myData.distanceMM; //Extract int distance:
    Serial.print(distance);
    Serial.print(".");
 }




    
