#include <IRremote.h>

int RECV_PIN = 4;

IRrecv irrecv(RECV_PIN);
decode_results results;
int d = 0;
int z = 0;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {


    doSothing();
    z = 1;

  } else {
    if (z != 0) {
      stopp();
      z = 0;
    }

  }
  irrecv.resume();

  delay(100);
}

void doSothing() {

  int num = results.value;

  Serial.println(num);
  if (num == d) {
    
    if(num == 4335){ // 4
        moveLeft();
        

    }else if(num == 23205){ //6
        moveRight();
        

    }else if(num == 19125){  // 8
        moveBack();
        

    }else if (num == 6375){  //2
        moveRight();
       

    }

  } else {
    d = num;
  }

  // Receive the next value


}
void moveForward() {
  Serial.println("moveForward");
}
void moveBack() {
  Serial.println("moveBack");

}
void moveRight() {
  Serial.println("moveRight");

}
void moveLeft() {
  Serial.println("moveLeft");

}

void stopp() {
  Serial.println("Stopp");

}




