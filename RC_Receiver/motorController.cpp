#include "Arduino.h"
#include "motorController.h"



motorController::motorController(Motor m1, Motor m2, Motor m3, Motor m4){
  _M1=m1;
  _M2=m2;
  _M3=m3;
  _M4=m4;
  
}
void motorController::forwards(){
  _M1.forward();
  _M2.forward();
  _M3.backward();
  _M4.backward();
}
void motorController::backwards(){

   _M1.backward();
  _M2.backward();
  _M3.forward();
  _M4.forward();
}
void motorController::rotateRight(){

  _M1.backward();
  _M2.backward();
  _M3.backward();
  _M4.backward();
}
void motorController::rotateLeft(){

  _M1.forward();
  _M2.forward();
  _M3.forward();
  _M4.forward();
}
void motorController::right(){
  _M1.backward();
  _M2.forward();
  _M3.forward();
  _M4.backward();
}
void motorController::left(){
  _M1.forward();
  _M2.backward();
  _M3.backward();
  _M4.forward();
}
void motorController::diagonalLeftUp(){
  _M1.forward();
  _M4.forward();
}
void motorController::diagonalRightUp(){
  _M2.forward();
  _M3.forward();
}
void motorController::haults(){
  _M1.hault();
  _M2.hault();
  _M3.hault();
  _M4.hault();
}

