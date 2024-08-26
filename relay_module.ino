// C++ code
// Relay module
int relay_pin=7;
void setup()
{
  pinMode(relay_pin, OUTPUT);
}

void loop()
{
  digitalWrite(relay_pin, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(relay_pin, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}