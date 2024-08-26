// C++ code
//Temperature sensor
int temp_pin=A0,buzzer_pin=10;
void setup()
{
  Serial.begin(9600);
  pinMode(buzzer_pin,OUTPUT);
}

void loop()
{
  int temperature=Temperature();
  if(temperature>100||temperature<-10){
    digitalWrite(buzzer_pin,HIGH);
  }
  else digitalWrite(buzzer_pin,LOW);  
}

int Temperature(){
  int t=analogRead(temp_pin);
  int temperature=map(t,20,358,-40,125);
  return temperature;
}