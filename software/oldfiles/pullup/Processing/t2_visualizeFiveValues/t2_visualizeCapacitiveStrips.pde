// This program is set up to work with the 'basics' sketch in the arduino folder
// Code by Paul Strohmeier for the User Interface Technologies class at University of Copenhagen

import processing.serial.*; //include the serial library

Serial arduinoPort;  // The serial port at which we listen to data from the Arduino 
String rawIncomingValues; //this is where you dump the content of the serial port
int[] incomingValues = { 0, 0, 0, 0, 0 };     //this is where you will store the incoming values, so you can use them in your program
int token = 10; //10 is the linefeed number in ASCII
//You can replace it with whatever symbol marks the end of your line (http://www.ascii-code.com/)
boolean connectionEstablished = false;




void setup() {
  size(512, 512); //sets the size of the output window

  //here we specify which port our program should listen to

  // List all the available serial ports
  println("these are the available ports: ");
  printArray(Serial.list());
  //chose your serial port, by putting the correct number in the square brackets 
  //you might need to just trial and error this, the first time you do it
  String serialPort = Serial.list()[0];
  //check if you are using the port you think you are using
  println("You are using this port: " + serialPort);
  // Open the port with the same baud rate you set in your arduino
  arduinoPort = new Serial(this, serialPort, 9600);
}



void draw() {

  if (connectionEstablished) { //the things below only happen if we know we have a working connection

    for (int i = 0; i < incomingValues.length; i++) {
      if (i < 5) {
        fill(map(incomingValues[i], 0, 100, 0, 255)); 
        //map function works like this:
        // map(valueOfInterest, minimum expected value, maximum expected value, minimum wanted value, maximum wanted value)
        rect(50 * i + 50, 50, 50, 50);
      }
    }
  }
}