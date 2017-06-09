//INPUT_PULLUP sets a high-ohm resistor between Analog Input and VCC

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);   // current flows
}

void loop()
{
Serial.println(analogRead(A0));
}
