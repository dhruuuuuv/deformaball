//this code reads the resistance at 10 locations using one analog input.
//this is the basis of building a matrix-style sensor (consider it a single line of a matrix sensor).
//This sketch assumes that there are 5 pressure sensor. 
//Each sensor is attached to A0 on one side and a unique digital pin on the other side.
//When the unique pin is set to OUTPUT and pulled LOW, its sensor is active, 
// when it is set to INPUT it is not

int resistanceValues[] = {0, 0, 0, 0, 0 }; //array for storing resistance values


void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);   // current flows
  pinMode(2, INPUT); 
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
}

void loop()
{

  for (int i = 2; i < 7; i++) {
    pinMode(i, OUTPUT); //OUTPUT allows current to flow through that pin
    digitalWrite(i, LOW);
    resistanceValues[i - 2] = analogRead(A0);
    pinMode(i, INPUT); //INPUT prevents current from flowing (the pin is set to 'high impedence')
  }

  for (int i = 0; i < 5; i++) {
    Serial.print(resistanceValues[i]);
    
    Serial.print(", ");
  }
  Serial.println();

}
