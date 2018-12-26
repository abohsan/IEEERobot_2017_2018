int dd = 0x05;
int char11, page, idd, sd;
int charflage = 0;
int stepp = 0 ;


int red2 = 2;
int red3 = 3;
int red4 = 4;
int red5 = 5;
void setup() {
  Serial.begin(9600);
  
  pinMode(red2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(red4, OUTPUT);
  pinMode(red5, OUTPUT);
  while (!Serial) {}
  delay(3000);
}

void loop() {
  if (Serial.available() > 1)
  {
    if (stepp == 1) {
      page =  Serial.read();
      delay(10);
      idd =  Serial.read();
      delay(10);
      sd =  Serial.read();

      if (page == 0) {
        page0(idd);
      }


      stepp = 0;
    } else {
      char11 = Serial.read();
      if (char11 == 0x65) {
        stepp = 1;
      }
    }

  }
}


void page0(int id) {
  if (id == 1) {
    id0(sd);
  }else if (id == 2) {
    id1(sd);
  }else if (id == 3) {
    id2(sd);
  }else if (id == 4) {
    id3(sd);
  }
}

void id0(int sd) {
  //moveRight();
  if (sd == 1) {

    digitalWrite(red2, HIGH);
  } else {

    digitalWrite(red2, LOW);
  }

}
void id1(int sd) {
  // moveBackward();
  if (sd == 1) {

    digitalWrite(red3, HIGH);
  } else {

    digitalWrite(red3, LOW);
  }

}

void id2(int sd) {
  //moveLeft();
  if (sd == 1) {

    digitalWrite(red4, HIGH);
  } else {

    digitalWrite(red4, LOW);
  }

}
void id3(int sd) {
  //moveForward();
  if (sd == 1) {

    digitalWrite(red5, HIGH);
  } else {

    digitalWrite(red5, LOW);
  }

}




