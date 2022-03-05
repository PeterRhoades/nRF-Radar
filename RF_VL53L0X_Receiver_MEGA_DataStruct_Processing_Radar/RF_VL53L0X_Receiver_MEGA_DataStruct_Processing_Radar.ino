/* Peter Rhoades
Saturday 16/02/22:
nRF Reciver From Laser Range Transmitter MEGA®
18/02/22 pipe = 0x8675309ABCll changer to const byte address[6] = "00001";:
19/02/22 delay (100) changed to delay(105) Redused Angle reading 0:
 nRF Tranciver 
  1 = GRN  Black   
  2 = 3.3v Red
  3 = CE   Pin 7  Blue
  4 = CSN  Pin 8  Breen
  5 = SCK  Pin 52 Yellow
  6 = MOSI Pin 51 White
  7 = MISO Pin 50 Orange
  8 = UNUSED
   _______________________
  | 1 | 2 |              |
  | 3 | 4 |              | 
  | 5 | 6 |              |
  |_7_|_8_|______________|
*/

#include  <SPI.h>
#include "RF24.h"
int msg[1];
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
   while (radio.available()) 
    {                          
  radio.read( &myData, sizeof(myData) );// Get the payload
    }
  delay(16); //Delay to aid data sync with Sender:
    int i = myData.angle180; //Extract int i:
    Serial.print(i);
    Serial.print(",");
    int distance = myData.distanceMM; //Extract int distance:
    Serial.print(distance);
    Serial.print(".");
    
}




    
