#include <Arduino.h>
#include "RGBdriver.h"
#include <SoftwareSerial.h>

#define CIN1 3//pins definitions for the driver        
#define DIN1 2
#define CIN2 5//pins definitions for the driver        
#define DIN2 4
RGBdriver Driver1(CIN1,DIN1);
RGBdriver Driver2(CIN2,DIN2);

SoftwareSerial BTserial(8, 9); // RX | TX
 
const long baudRate = 9600; 
char c = ' ';

int red = 0;
int green = 0;
int blue = 0;


void stripOn(){
  /*Function: SetColor()					        */
  /*Parameters: red:0~255 						    */
  /*            green:0~255						    */
  /*            blue:0~255						    */
  /*Note: the greater the value,the brighter the LED*/
  Driver1.begin();
  Driver1.SetColor(50, 255, 0); //  green | red | blue
  Driver1.end();
  Driver2.begin();
  Driver2.SetColor(255, 80, 0); // red | green | blue
  Driver2.end();
  delay(100);
}

void stripOff(){
  /*Function: SetColor()					        */
  /*Parameters: red:0~255 						    */
  /*            green:0~255						    */
  /*            blue:0~255						    */
  /*Note: the greater the value,the brighter the LED*/
  Driver1.begin();
  Driver1.SetColor(0, 0, 0);
  Driver1.end();
  Driver2.begin();
  Driver2.SetColor(0, 0, 0);
  Driver2.end();
  delay(100);
}

void setup() {
  delay(250);
  Serial.begin(baudRate);
  BTserial.begin(baudRate);
  stripOn();
  delay(250);
}

void loop() {
  // Read from the Bluetooth module and send to the Arduino Serial Monitor
  if (BTserial.available())
  {
      c = BTserial.parseInt();
      if(c == 1)
      {
        stripOn();
      }

      else if(c == 2)
      {
        stripOff();
      }
  }
}

