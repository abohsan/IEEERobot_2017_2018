
#include <Arduino.h>
#include "MyMotor.h"
#include "Robotic.h"


Robotic::Robotic(MyMotor fr1, MyMotor fl1, MyMotor br1, MyMotor bl1){
*fr2 =  fr1;
*fl2 =  fl1;
*bl2 =  bl1;
*br2 =  br1;

}

void Robotic::moveForward(int a){
  fr2->moveBack(100);
  fl2->moveForward(100);
  bl2->moveForward(100);
  br2->moveBack(100);

}
void Robotic::moveBack(int a){
  fr2->moveForward(100);
  fl2->moveBack(100);
  bl2->moveBack(100);
  br2->moveForward(100);

}

void Robotic::moveRight(int a){
  fr2->moveForward(100);
  fl2->moveForward(100);
  bl2->moveBack(100);
  br2->moveBack(100);

}

void Robotic::moveLeft(int a){
  
  fr2->moveBack(100);
  fl2->moveBack(100);
  
  bl2->moveForward(100);
  br2->moveForward(100);

}
void Robotic::stopp(){
  fr2->stopp();
  fl2->stopp();
  bl2->stopp();
  br2->stopp();

}

