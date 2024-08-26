// C++ code
//LDR sensor
int light=10;
void setup()
{
  Serial.begin(9600);
  pinMode(light, OUTPUT);
}

void loop()
{
  int resistance=analogRead(A0);
  Serial.println(resistance);
  if(resistance<400){
    digitalWrite(light,HIGH);
    delay(1000);// Wait for 1000 millisecond(s)
  }
  else{
    digitalWrite(light,LOW);
  }
}