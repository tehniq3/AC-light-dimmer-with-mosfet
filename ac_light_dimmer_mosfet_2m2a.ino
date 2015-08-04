/*
ORIGINAL:
 Fading
 This example shows how to fade an LED using the analogWrite() function.
  The circuit:
 * LED attached from digital pin 9 to ground.
 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe
 http://arduino.cc/en/Tutorial/Fading
 this example code is in the public domain.

CHANGED:
  Control a incandescent bulf thru optocoupler and mosfet transistor
  Schematic and info:
  - http://www.learningelectronics.net/circuits/dimmer-with-mosfet.html
  - http://www.instructables.com/id/safe-and-simple-AC-PWM-Dimmer-for-arduino-Raspberr/
  - https://creativearduinoproject.wordpress.com/2015/01/20/arduino-dimmer-for-lamp/
  sktech adabted by Nicu FLORICA aka niq_ro 
  - http://www.tehnic.go.ro/
  - http://www.niqro.3x.ro
  - http://www.niq.go.ro
  - http://nicuflorica.blogspot.ro/
  - http://arduinotehniq.blogspot.com/
 */


int ledPin = 3;    // LED connected to digital pin 3
int timp = 2000;   // time between changes
int pas = 8;      // value for step (maximum for all is 255)
byte treapta = 0;  // number of steps

void setup()  { 
   Serial.begin(9600);
} 

void loop()  { 
  treapta = 0;  // initial value for number of steps
   // fade in from min to max :
    for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=pas) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    Serial.print(treapta);
    Serial.print(" -> ");
    Serial.print(fadeValue);
    Serial.print("/255 -> ");
    Serial.print(fadeValue*100/255);
    Serial.println("%");
    // wait to see the dimming effect    
    delay(timp);                            
    treapta = treapta + 1;  // increase number of steps
  } 

  // fade out from max to min:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=pas) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    Serial.print(treapta);
    Serial.print(" -> ");
    Serial.print(fadeValue);
    Serial.print("/255 ->");
    Serial.print(fadeValue*100/255);
    Serial.println("%");
    // wait to see the dimming effect    
    delay(timp);                            
    treapta = treapta - 1;  // decrease number of steps
  } 
}
