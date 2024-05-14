#include <Servo.h>

Servo ESC;
char t;
int IN1=10;
int IN2=9;
int IN3=5;
int IN4=6;
int clean=12;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(clean, OUTPUT);
  
  ESC.attach(11, 1000, 2000);
  Serial.begin(9600);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(clean, HIGH);
  ESC.write(0);
}

void loop() {
  if (Serial.available() > 0) {
    t = Serial.read();
    Serial.println(t);
  }
  else if (t == 'G'){
    ESC.write(50);
  }
  else if (t == 'I'){
    ESC.write(180);
  }
  else if (t == 'F') {
     digitalWrite(IN1,HIGH);
     digitalWrite(IN2,LOW);
     digitalWrite(IN3,HIGH);
     digitalWrite(IN4,LOW);
  } else if (t == 'B') {
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,HIGH);
     digitalWrite(IN3,LOW);
     digitalWrite(IN4,HIGH);
  } else if (t == 'R') {
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,HIGH);
     digitalWrite(IN3,HIGH);
     digitalWrite(IN4,LOW);
  } else if (t == 'L') {
     digitalWrite(IN1,HIGH);
     digitalWrite(IN2,LOW);
     digitalWrite(IN3,LOW);
     digitalWrite(IN4,HIGH);
  } else if (t == 'H') {
     digitalWrite(clean, LOW);
  } else if (t == 'J') {
     digitalWrite(clean, HIGH);
     ESC.write(0);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  delay(10);
}
