
#ifndef ROBOTIC_H
#define ROBOTIC_H

class Robotic {

public:
MyMotor *fr2;
MyMotor *fl2;
MyMotor *br2;
MyMotor *bl2;

 Robotic(MyMotor,MyMotor,MyMotor,MyMotor);
     void moveForward(int);
     void moveBack(int);
     void moveRight(int);
     void moveLeft(int);
     void stopp();
};

#endif /* ROBOTIC_H */
