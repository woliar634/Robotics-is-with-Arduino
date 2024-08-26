// C++ code
//Force sensor
int red=13,blue=12,green=11,sensor=A0;
void setup()
{
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void Red(){
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
}

void Yellow(){
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH); 
}

void Green(){
  digitalWrite(green,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
}

void loop()
{
  int force=analogRead(sensor);
  Serial.println(force);
  
  if(force<=200){
  Red();
  }
  else if(force>=200 && force<350){
  Yellow();
  }
  else{
  Green();
  }
}
