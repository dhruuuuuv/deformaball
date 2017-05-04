//Dummy Sketch for X-Y capacitive touch pad
#include <ADCTouch.h>

int x = 70;
int y = 80;
int ref0, ref1;     //reference values to remove offset


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // No pins to setup, pins can still be used regularly, although it will affect readings
  ref0 = ADCTouch.read(A0, 1000);    //create reference values to 0
  ref1 = ADCTouch.read(A1, 1000);    //create reference values to 1
}

void loop() {
  // put your main code here, to run repeatedly:
//  x = x + random (-2,3);
//  y = y + random (-1,2);j=99999

  int value0 = ADCTouch.read(A0);   //no second parameter
  int value1 = ADCTouch.read(A1);   //no second parameter
  value0 -= ref0;       //remove offset 0
  value1 -= ref1;       //remove offset

  float mapped_value0 = map(value0, 0, 1024, 0, 100);
  float mapped_value1 = map(value1, 0, 1024, 0, 100);
  
// Serial.print(value0);
// Serial.print(", ");
// Serial.print(value1);
// Serial.println(",");

/* This assumes you have 3 values to send to max.
 If you have more, then simply add another value
Like this:

Serial.print(valueX); // print valueX to serial
Serial.print(" "); // print a space

Make sure that the corresponding "unpack" function in Max
expects the amount of inputs you send out. 
e.g., (unpack 0 0) for two inputs
or (unpack 0 0 0 0) for four inputs 

*/
 
 Serial.print(value0); // print value 1 to serial
// Serial.print(" "); // print a space to serial
// Serial.print(value1); // print value 2 to serial
// Serial.print(" "); // print a space to serial
// Serial.print(value3); // print value 3 to serial

 
 // a linebrake tells max, that all files have been recieved
 
 Serial.println(); // print a line-break to serial
 
 // make sure that Max and Arduino are operating at same speed
 
 delay(100); // pause (this should match the metro speed in the MaxPatch)

}
