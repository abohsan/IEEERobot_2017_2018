#ifndef motor_h
#define blinker_h

#include "Arduino.h"

class Motor
{
public:
  Motor();
  Motor(int Speed, int forward, int backward);
  void forward();
  void backward();
  void hault ();

private:
  int _Speed;
  int _forward;
  int _backward;
  
};
#endif

