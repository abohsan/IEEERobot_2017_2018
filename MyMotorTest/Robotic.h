
#ifndef ROBOTIC_H
#define ROBOTIC_H

class Robotic {

public:
MyMotor fr;
MyMotor fl;
MyMotor br;
MyMotor bl;
 Robotic(MyMotor,MyMotor,MyMotor,MyMotor);



     
     void moveForward();
};

#endif /* ROBOTIC_H */
