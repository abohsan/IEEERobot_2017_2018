#include <Arduino.h>
#include "MyMotor.h"
#include "Robotic.h"

MyMotor::MyMotor(int pwm_1, int dir_1, int brk_1) {

  pwm = pwm_1;
  dir = dir_1;
  brk = brk_1;


}

MyMotor::~MyMotor() {}
void MyMotor::moveForward(char a, char b) {
  analogWrite(pwm, a);
  digitalWrite(dir, 1);

}
void MyMotor::moveBack(char a, char b) {
  analogWrite (pwm, a);
  digitalWrite(dir, 0);
}
void MyMotor::stopp () {
  analogWrite (pwm, 0);
  digitalWrite(dir, 0);
}



