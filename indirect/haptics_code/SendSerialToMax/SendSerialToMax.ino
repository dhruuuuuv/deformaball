/**************************************************************/
/* How to: Set up a serial connection between Arduino and MAX */           
/**************************************************************/

/*
 This code itself will not do anything
 Its simply a templete to help get you going
 This code is based on the Serial Tutorial from Processing
 Commented and edited by myself, Paul Strohmeier

 Just add whatever you want to be doing with arduino to this code
 It is set up for sending data to the
 Max file "SerialRead"
 In theory this should work without you having to screw around a lot

 Its probably a good idea to check out 
 the Max tutorial on serial communication.
 Thats where I have all my infos from

 Paul Strohmeier, 2011
*/

void setup() 
{ 
 Serial.begin(9600); // open the arduino serial port
} 


void loop() 
{ 
 

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
 
 Serial.print(value1); // print value 1 to serial
 Serial.print(" "); // print a space to serial
 Serial.print(value2); // print value 2 to serial
 Serial.print(" "); // print a space to serial
 Serial.print(value3); // print value 3 to serial

 
 // a linebrake tells max, that all files have been recieved
 
 Serial.println(); // print a line-break to serial
 
 // make sure that Max and Arduino are operating at same speed
 
 delay(100); // pause (this should match the metro speed in the MaxPatch)

} 
