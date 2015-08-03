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
  sktech adapted by Nicu FLORICA aka niq_ro 
  - http://www.tehnic.go.ro/
  - http://www.niqro.3x.ro
  - http://www.niq.go.ro
  - http://nicuflorica.blogspot.ro/
  - http://arduinotehniq.blogspot.com/
 */


int ledPin = 3;    // LED connected to digital pin 3
int timp = 1000;   // time (ms) between changes
int pas = 16;      // value for step;

void setup()  { 
   Serial.begin(9600);
} 

void loop()  { 
   // fade in from min to max :
    for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=pas) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);   
    Serial.println(fadeValue);
    // wait to see the dimming effect    
    delay(timp);                            
  } 

  // fade out from max to min:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=pas) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
        Serial.println(fadeValue);
    // wait to see the dimming effect    
    delay(timp);                            
  } 
}
