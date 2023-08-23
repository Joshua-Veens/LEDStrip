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
int c = 9999;
boolean NL = true;

const int redButtonPin = 4;
const int greenButtonPin = 5;
const int blueButtonPin = 6;
const int ledPin = 7;

int red = 0;
int green = 0;
int blue = 0;


void blink(){
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
}

void stripOn(){
  /*Function: SetColor()					        */
  /*Parameters: red:0~255 						    */
  /*            green:0~255						    */
  /*            blue:0~255						    */
  /*Note: the greater the value,the brighter the LED*/
  Driver1.begin();
  Driver1.SetColor(255, 35, 0); // red | green | blue
  Driver1.end();
  Driver2.begin();
  Driver2.SetColor(255, 35, 0); // red | green | blue
  Driver2.end();
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
}

void setup() {
  // put your setup code here, to run once:
  pinMode(redButtonPin, INPUT_PULLUP);
  pinMode(greenButtonPin, INPUT_PULLUP);
  pinMode(blueButtonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.begin(baudRate);
  BTserial.begin(baudRate);
  stripOn();
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

