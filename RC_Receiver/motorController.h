#ifndef motorController_h
#define motorcontroller_h

#include "Arduino.h"
#include "motor.h"

class motorController
{
public:
  motorController(Motor motor1, Motor motor2, Motor motor3, Motor motor4);
  void forwards();
  void backwards();
  void haults();
  void right();
  void rotateRight();
  void rotateLeft();
  void left();
  void diagonalLeftUp();
  void diagonalRightUp();
private:
  Motor _M1;
  Motor _M2;
  Motor _M3;
  Motor _M4;
  
};

#endif

