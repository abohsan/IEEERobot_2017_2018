#include <Arduino.h>
#include "MyMotor.h"

MyMotor::MyMotor(int pwm_11, int dir_11, int brk_11) {

  pwm = pwm_11;
  dir = dir_11;
  brk = brk_11;

}

MyMotor::~MyMotor() {}
void MyMotor::moveForward(char a) {
  analogWrite(pwm, a);
  digitalWrite(dir, 1);
 

}
void MyMotor::moveBack(char a) {
  analogWrite (pwm, a);
  digitalWrite(dir, 0);


}
void MyMotor::stopp () {
  analogWrite (pwm, 0);
  digitalWrite(dir, 0);



}



