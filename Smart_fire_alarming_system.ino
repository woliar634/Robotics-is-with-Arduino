int gas_sensor=A0,flame_sensor=4,buzzer=13;
void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(flame_sensor,INPUT);
}

void loop() {
  if(!digitalRead(flame_sensor)){
    Serial.println("Fire Detected");
    digitalWrite(buzzer, HIGH);
  }
  else {
    Serial.println("No Fire Detected");
    digitalWrite(buzzer, LOW);
  }

  int gas=analogRead(A0);
  //Serial.println(gas);
  if(gas>14){
    Serial.println("Smoke Detected");
    digitalWrite(buzzer,HIGH);
  }
  else{
    Serial.println("Smoke not Detected");
    digitalWrite(buzzer,LOW);
  }
  
}
