#include <Servo.h>

Servo s,s1, s2, s3, s4, s5, s6;
int i1 = 90, i2 = 90, i3 = 90, i4 = 90, i5 = 90, i6 = 20;
char data;
int angle;
void runServo(Servo &s, int &angle) {
  if (angle >= 180) {
    angle = 180;
  }
  if (angle <= 0) {
    angle = 0;
  }
  s.write(angle);
}
void setup() {
  // put your setup code here, to run once:
  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);
  s5.attach(10);
  s6.attach(11);

  s1.write(i1);
  s2.write(i2);
  s3.write(i3);
  s4.write(i4);
  s5.write(i5);
  s6.write(i6);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    data = Serial.read();
    Serial.print(data);
    //-----------------------servo 1 ------------------------------
    if (data == 'L') {
      i1++;
      runServo(s1, i1);
      Serial.print(" S1 L ");
    }
    if (data == 'R') {
      i1--;
      runServo(s1, i1);
      Serial.print(" S1 R ");
    }
    //-----------------------servo 2 ------------------------------
    if (data == 'F') {
      i2++;
      runServo(s2, i2);
      Serial.print(" S2 U ");
    }
    if (data == 'B') {
      i2--;
      runServo(s2, i2);
      Serial.print(" S2 D ");
    }
    //-------------------------servo 6 ----------------------------
    if (data == 'V') {
      s6.write(93);
      Serial.print(" S6 C ");
    }
    if (data == 'v') {
      s6.write(20);
      Serial.print(" S6 O ");
    }
    //---------------------servo 3 to servo 1 ----------------------
    if (data == 'W') {
      while (1) {
        data = Serial.read();
        Serial.print(data);
        //-------------------servo 3 ------------------------------
        if (data == 'F') {
          i3++;
          runServo(s3, i3);
          Serial.print(" S3 U ");
        }
        if (data == 'B') {
          i3--;
          runServo(s3, i3);
          Serial.print(" S3 D ");
        }
        //-----------------------servo 1 ---------------------------
        if (data == 'L') {
          i1++;
          runServo(s1, i1);
          Serial.print(" S1 L ");
        }
        if (data == 'R') {
          i1--;
          runServo(s1, i1);
          Serial.print(" S1 R ");
        }
        if (data == 'w') {
          break;
        }
        Serial.println("");
      }
    }
    //-----------servo 4 and servo 5 -------------------------------
    if (data == 'U') {
      while (1) {
        data = Serial.read();
        Serial.print(data);
        //-----------------------servo 4 -------------------------
        if (data == 'F') {
          i4++;
          runServo(s4, i4);
          Serial.print(" S4 U ");
        }
        if (data == 'B') {
          i4--;
          runServo(s4, i4);
          Serial.print(" S4 D ");
        }
        //----------------------servo 5 --------------------------
        if (data=='L') {
        i5++;
        runServo(s5,i5);
        Serial.print(" S5 L ");
        }
        if(data=='R'){
          i5--;
          runServo(s5,i5);
          Serial.print(" S5 R ");
        }
        if(data=='u'){
          break;
        }
        Serial.println("");
      }
    }
    Serial.println("");
  }
}
