

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "motorController.h"
RF24 radio(7, 8);

const byte address[6] = "00001";



volatile boolean taskDone = false;
int taskNumber = 0;
Motor motor1(2, 26, 22);
Motor motor2(3, 27, 23);
Motor motor3(4, 28, 24);
Motor motor4(5, 29, 25);

motorController myController(motor1, motor2, motor3, motor4);


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(13, OUTPUT);
  //pinMode(2,INPUT);
  attachInterrupt(0, stageFinished, CHANGE);
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    if (text[0] == 'a') {
      myController.rotateRight();  // RotateRight
    } else if (text[0] == 'c') {
      myController.rotateLeft();  // RotateLeft
    } else if (text[0] == 'f') {
      myController.forwards();    // MoveForward ;
    } else if (text[0] == 'b') {
      myController.backwards();  // MoveBackward
    } else if (text[0] == 'r') {
      myController.right();      // MoveRight
    } else if (text[0] == 'l') {
      myController.left();       //  MoveLeft
    } else {
      myController.haults();     // Stop
    }
  }
}
void moveFuntion() {
  switch (taskNumber) {
    case 0:
      Serial.println("waiting forIR code");
      break;

    case 1:
      Serial.println("walking over to Press button");

      break;

    case 2:
      Serial.println("navigating to pressureplate");
      myController.forwards();
      break;

    case 3:
      Serial.println("picking up box");
      myController.backwards();
      break;

    default:
      Serial.println(taskNumber);
      myController.haults();

  }
}
void stageFinished() {
  //  if (taskDone) {
  //    delay(500);
  //    Serial.println(taskNumber);
  //    digitalWrite(13, LOW);
  //    taskDone = false;
  //  } else {
  //    delay(500);
  //    digitalWrite(13, HIGH);
  //    taskNumber++;
  //    taskDone = true;
  //  }
}

