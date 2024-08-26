// C++ code
//RGB LED
int red=13,blue=12,green=11;
void setup()
{
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void rgbBlink(){
  digitalWrite(red, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(red, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(blue, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(blue, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(green, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(green, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

void yellowBlink(){
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  delay(2000); // Wait for 2000 millisecond(s)  
}

void pinkBlink(){
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  delay(2000); // Wait for 2000 millisecond(s)  
}
void loop()
{
  rgbBlink();
  //yellowBlink();
  //pinkBlink();
}