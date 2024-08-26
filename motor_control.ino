// C++ code
//motor control
int p=10,n=11;
void setup()
{
  pinMode(p, OUTPUT);
  pinMode(n, OUTPUT);
}

void loop()
{
  analogWrite(p, 150);//255 output voltage maximum=5v
  analogWrite(n, 0);//0 output voltage lowest=0v
  delay(2000); // Wait for 2000 millisecond(s)
  analogWrite(p, 0);
  analogWrite(n, 155);
   delay(2000); // Wait for 2000 millisecond(s)
}