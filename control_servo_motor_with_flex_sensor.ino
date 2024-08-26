// C++ code
//Control Servo motor with Flex Sensor
#include <Servo.h>
int servo_pin=7,sensor=A0;

Servo myServo;
void setup()
{
  Serial.begin(9600);
  myServo.attach(servo_pin);
}

int Angle(){
  int sensor_value=analogRead(sensor);
  int angle=map(sensor_value,700,292,0,180);
  return angle;
}

void loop()
{
  int angle_value=Angle();
  myServo.write(angle_value);
  Serial.println(angle_value);
}