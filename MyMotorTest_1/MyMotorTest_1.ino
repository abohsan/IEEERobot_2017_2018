#include "MyMotor.h"
#include "Robotic.h"

int pwm_1 = 9;
int dir_1 = 8;
int brk_1 = 0;

int pwm_2 = 11;
int dir_2 = 12;
int brk_2 = 0;

int pwm_3 = 6;
int dir_3 = 7;
int brk_3 = 0;

int pwm_4 = 5;
int dir_4 = 4;
int brk_4 = 0;

MyMotor fr(pwm_1, dir_1, brk_1);
MyMotor fl(pwm_2, dir_2, brk_2);
MyMotor br(pwm_3, dir_3, brk_3);
MyMotor bl(pwm_4, dir_4, brk_4);

Robotic robotic(fr, fl, br, bl);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  pinMode(pwm_1, OUTPUT);
  pinMode(dir_1, OUTPUT);
//  pinMode(brk_1, OUTPUT);

  pinMode(pwm_2, OUTPUT);
  pinMode(dir_2, OUTPUT);
  //pinMode(brk_2, OUTPUT);

  pinMode(pwm_3, OUTPUT);
  pinMode(dir_3, OUTPUT);
  //pinMode(brk_3, OUTPUT);

  pinMode(pwm_4, OUTPUT);
  pinMode(dir_4, OUTPUT);
  //pinMode(brk_4, OUTPUT);

}

void loop() {

//
//  if (Serial.available()) {
//    char s = Serial.read();
//    dd(s);

//
//  }

 if (Serial.available()) {
    char s = Serial.read();
    //moveRobotic(s);
    moveRoboticInMain(s);
    //dd(s);

  }



}
void moveRobotic(char a) {
  Serial.println("MoveRobotic method");
  if (a == 'a') {
    robotic.moveRight(100);

  } else if ( a == 'b') {
    robotic.moveBack(100);


  } else if ( a == 'c') {
    robotic.moveLeft(100);



  } else if ( a == 'd') {
    robotic.moveForward(100);



  } else {
    robotic.stopp();

    
  }

}


void moveRoboticInMain(char a) {
  Serial.println("MoveRobotic method");
  if (a == 'a') {
    moveRight(100);

  } else if ( a == 'b') {
    moveBack(100);


  } else if ( a == 'c') {
    moveLeft(100);



  } else if ( a == 'd') {
    moveForward(100);



  } else {
    stopp();

    
  }

}



void dd(char val) {
  switch (val)
  {
    case 'a':          //front left forward

      fl.moveForward(160);

      break;

    case 'b':         //fornt left back

      fl.moveBack(160);

      break;

    case 'c':         //front right forward
      fr.moveForward(160);


      break;

    case 'd':         //fornt right back
      fr.moveBack(160);


      break;
    case 'e':         //back right forward
      br.moveForward(160);


      break;
    case 'f':         //back right back
      br.moveBack(160);


      break;
    case 'g':         //back left forward
      bl.moveForward(160);


      break;

    case 'h':         //back left back
      bl.moveBack(160);
      break;

    case 's':         //back left back
      fr.stopp();
      fl.stopp();
      br.stopp();
      bl.stopp();


      break;

  }
}
void moveForward(int a){
  fr.moveBack(50);
  fl.moveForward(50);
  bl.moveBack(50);
  br.moveBack(50);

}
void moveBack(int a){
  fr.moveForward(50);
  fl.moveBack(50);
  bl.moveForward(50);
  br.moveForward(50);

}

void moveRight(int a){
  fr.moveForward(50);
  fl.moveForward(50);
  bl.moveBack(50);
  br.moveForward(50);

}

void moveLeft(int a){
  
  fr.moveBack(50);
  fl.moveBack(50);
  bl.moveForward(50);
  br.moveBack(50);

}
void stopp(){
  fr.stopp();
  fl.stopp();
  bl.stopp();
  br.stopp();

}
