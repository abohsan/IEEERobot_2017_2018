
#ifndef MYMOTOR_H
#define MYMOTOR_H

class MyMotor {

public:
     int pwm;
     int dir;
     int brk;
     int aaa;
      MyMotor(int,int,int);
     ~MyMotor();
   
    void stopp();
    void moveForward (char );
    void moveBack (char);
   
 
};


#endif /* RELAYBOARD_H */
