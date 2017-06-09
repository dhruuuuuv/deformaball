//Filtered Analog Input
//group 1 - user interface technology unit
//main code for deformaball
float incomingValue0;    // stores the value red from analog input
float incomingValue1;
float cleanValue0;       // stores the filtered value
float cleanValue1;       // stores the filtered value
float oldValue0 = 512;   // stores the previous clean value
float oldValue1 = 512;   // stores the previous clean value
float value0;
float value1;
int mapped_val_0;
int mapped_val_1;
float calibrate0;
float calibrate1;
int calibrateCounter = 0;
int calibrateIterations = 1000;
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
  
 incomingValue0 = analogRead(A0);       // read the input on analog pin 0:
  incomingValue1 = analogRead(A1); // read the input on analog pin 1
  cleanValue0 = oldValue0 + (incomingValue0 - oldValue0) * k; //filter i  t
  cleanValue1 = oldValue1 + (incomingValue1 - oldValue1) * k; //filter it
  oldValue0 = cleanValue0;
  oldValue1 = cleanValue1; // store value for later use

 if(calibrateCounter < calibrateIterations){

   calibrate0 += cleanValue0;
    calibrate1 += cleanValue1;
    calibrateCounter++;
    Serial.println(calibrateCounter);
    return;
  }
  else if(calibrateCounter == calibrateIterations){

   calibrate0 = calibrate0 / calibrateIterations;
    calibrate1 = calibrate1 / calibrateIterations;
    Serial.println(calibrate0);
    calibrateCounter++;
    return;
  }

 value0 = calibrate0 - cleanValue0;
 value1 = calibrate1 - cleanValue1;

 if(value0 < 15){
    value0 = 0;
  }
  if(value1 < 15){
    value1 = 0;
  }

// mapped_val_0 = map(value0, 250, 30, 0, 100);
//  mapped_val_1 = map(value1, 250, 30, 0, 100);
  
 Serial.print(value0);
 Serial.print(" ");
 Serial.println(value1);
  
 
 delay(1);        // slow down the speed at which its dumped to serial a bit...
                   // (beware: delay command can break timing-critical code!)
}
