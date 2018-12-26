#include "Arduino.h"
#include "motor.h"
Motor::Motor(){
  _Speed =3;
  _forward =4;
}
Motor::Motor(int SPEED, int FORWARD, int BACKWARD){
  pinMode(SPEED,OUTPUT);
  pinMode(FORWARD,OUTPUT);
  pinMode(BACKWARD,OUTPUT);

  _Speed =SPEED;
  _forward =FORWARD;
  _backward=BACKWARD;
}
void Motor::forward(){
  digitalWrite(_forward,HIGH);
  digitalWrite(_backward,LOW);  
  analogWrite(_Speed,161);
}
void Motor::backward(){
  digitalWrite(_forward,LOW);
  digitalWrite(_backward,HIGH);
  analogWrite(_Speed,161);
}
void Motor::hault(){
  digitalWrite(_backward,LOW);
  digitalWrite(_forward,LOW);
  analogWrite(_Speed,0);
}

