// C++ code
int relay=8;
int pir=7;
void setup()
{
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(pir, INPUT);
}

void loop()
{
  if(digitalRead(pir)==HIGH){
    Serial.println("Motion detected");
    digitalWrite(relay,HIGH);
  }
  else
  {
    Serial.println("Not Detected");
     digitalWrite(relay,LOW);
  }
}