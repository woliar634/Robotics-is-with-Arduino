//C++ code 
//Soccer Bot

int speeds;
char data;  //
//-------------------for Right side motor------------------
#define rm_ren 11
#define rm_len 12
#define rm_rpwm 5
#define rm_lpwm 6

//-------------------for Left side motor--------------------
#define lm_ren 7
#define lm_len 8
#define lm_rpwm 9
#define lm_lpwm 10

//--------------------create function for moving------------

//forward moving
void forward() {
  digitalWrite(rm_ren, HIGH);
  digitalWrite(rm_len, HIGH);
  analogWrite(rm_rpwm, speeds);
  analogWrite(rm_lpwm, 0);

  digitalWrite(lm_ren, HIGH);
  digitalWrite(lm_len, HIGH);
  analogWrite(lm_rpwm, speeds);
  analogWrite(lm_lpwm, 0);
}

//backward moving
void backward() {
  digitalWrite(rm_ren, HIGH);
  digitalWrite(rm_len, HIGH);
  analogWrite(rm_rpwm, 0);
  analogWrite(rm_lpwm, speeds);

  digitalWrite(lm_ren, HIGH);
  digitalWrite(lm_len, HIGH);
  analogWrite(lm_rpwm, 0);
  analogWrite(lm_lpwm, speeds);
}

//move to turn right
void turn_right() {
  digitalWrite(rm_ren, HIGH);
  digitalWrite(rm_len, HIGH);
  analogWrite(rm_rpwm, 0);
  analogWrite(rm_lpwm, speeds);

  digitalWrite(lm_ren, HIGH);
  digitalWrite(lm_len, HIGH);
  analogWrite(lm_rpwm, speeds);
  analogWrite(lm_lpwm, 0);
}

//move to turn left
void turn_left() {
  digitalWrite(rm_ren, HIGH);
  digitalWrite(rm_len, HIGH);
  analogWrite(rm_rpwm, speeds);
  analogWrite(rm_lpwm, 0);

  digitalWrite(lm_ren, HIGH);
  digitalWrite(lm_len, HIGH);
  analogWrite(lm_rpwm, 0);
  analogWrite(lm_lpwm, speeds);
}

//stop moving
void stop() {
  digitalWrite(rm_ren, LOW);
  digitalWrite(rm_len, LOW);

  digitalWrite(lm_ren, LOW);
  digitalWrite(lm_len, LOW);
}
//---------------------------------------------------------------

void setup() {
  pinMode(rm_ren, OUTPUT);
  pinMode(rm_len, OUTPUT);
  pinMode(rm_rpwm, OUTPUT);
  pinMode(rm_lpwm, OUTPUT);

  pinMode(lm_ren, OUTPUT);
  pinMode(lm_len, OUTPUT);
  pinMode(lm_rpwm, OUTPUT);
  pinMode(lm_lpwm, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();
    //----speed control----
    if (data >= 0 && data <= 9) {
      int value = (int)data;
      speeds = value * 28;
    }
    //----moving control---
    if (data == 'F') {
      forward();
    }
    if (data == 'B') {
      backward();
    }
    if (data == 'R') {
      turn_right();
    }
    if (data == 'L') {
      turn_left();
    }
    if (data == 'S') {
      stop();
    }
  }
}
