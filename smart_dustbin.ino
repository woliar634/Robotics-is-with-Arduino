#include <Servo.h>
Servo myservo;
int trig=5,echo=4,signal=7;

int distance(int echo,int trig){
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  int time=pulseIn(echo,HIGH);
  int distance=(0.034*time)/2;
  return distance;
}
void setup()
{
  Serial.begin(9600);
  myservo.attach(signal);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

void loop()
{
  Serial.println(distance(echo,trig));
  if(distance(echo,trig)<30){
myservo.write(180);
    delay(2000);
}
  else {
     myservo.write(0);
  }
}