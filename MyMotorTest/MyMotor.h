
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
    void moveForward (char , char );
    void moveBack (char a, char b);
   
 
};


#endif /* RELAYBOARD_H */
