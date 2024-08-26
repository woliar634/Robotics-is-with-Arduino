// C++ code
//Soil moisture sensor
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
  int moisture=analogRead(sensor);
  Serial.println(moisture);
  
  if(moisture<=300){
  Red();
  }
  else if(moisture>=300 && moisture<600){
  Yellow();
  }
  else{
  Green();
  }
}