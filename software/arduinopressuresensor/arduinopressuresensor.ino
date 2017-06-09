//Filtered Analog Input
//This Sketch is designed for playing with Pencil-drawn voltage dividers
//it uses an aggressive low-pass filter to stabalize the readings.
//Written by Paul Strohmeier (paul.strohmeier@gmail.com) 
//for the User Interface Technologies class at University of Copenhagen

float incomingValue;    // stores the value red from analog input
float incomingValue2;
float cleanValue;       // stores the filtered value
float cleanValue2;       // stores the filtered value
float oldValue = 512;   // stores the previous clean value
float oldValue2 = 512;   // stores the previous clean value
int mapped_val_1;
int mapped_val_2;
float k = 0.1;          // sets the ration of new-to-old signal. 1 == no filter 0 == no signal

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
 pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
//we don't really need the following print statements, 
//but they make the visualization of the serial plotter nicer
  //Serial.print(0); 
  //Serial.print(", ");
  //Serial.print(1025);
  //Serial.print(", ");
  
  incomingValue = analogRead(A0);       // read the input on analog pin 0:
  incomingValue2 = analogRead(A1); // read the input on analog pin 1
  cleanValue = oldValue + (incomingValue - oldValue) * k; //filter i  t
  cleanValue2 = oldValue2 + (incomingValue2 - oldValue2) * k; //filter it
  oldValue = cleanValue;
  oldValue2 = cleanValue2; // store value for later use

  mapped_val_1 = map(cleanValue, 250, 30, 0, 100);
  mapped_val_2 = map(cleanValue2, 250, 30, 0, 100); 

//  if(cleanValue2 > 390 && cleanValue2 < 440){
//    Serial.print(0);
//  }else{
//    Serial.print(mapped_val_1);
    Serial.print(cleanValue);
//  }
  
  Serial.print(" ");
//  if(cleanValue > 289 && cleanValue < 350){
//    Serial.println(0);
//  }else{
//  Serial.println(mapped_val_2);
  Serial.println(cleanValue2);
//  Serial.print(" ");
//  Serial.println(cleanValue2);  // print the filtered value

//  }
  
  delay(1);        // slow down the speed at which its dumped to serial a bit...
                   // (beware: delay command can break timing-critical code!)
}