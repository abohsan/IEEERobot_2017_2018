#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int xaxis = A0;
int yaxis = A1;
int button = 4;

RF24 radio(7, 8);
const byte address[6] = "00001";

void setup() {
  pinMode(13, OUTPUT);
  pinMode(4, INPUT);
  digitalWrite(4, HIGH);

  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

}

void loop() {
  read();
}


void read() {
  if (analogRead(yaxis) > 700 && analogRead(xaxis) > 700) {
    // Serial.println("rotate right");
    send("a"); // Rotate Right
  } else if (analogRead(yaxis) > 700 && analogRead(xaxis) < 300) {
    send("c"); // Rotate  left

  } else if (analogRead(yaxis) < 300 && analogRead(xaxis) < 300) {

    send("s");  // Stop
  } else if (analogRead(yaxis) < 300 && analogRead(xaxis) > 700) {
    send("s"); // Stop

  } else if (analogRead(yaxis) > 700) {
    send("f"); // Move Forward

  } else if (analogRead(yaxis) < 300) {
    send("b"); // Move backward

  } else if (analogRead(xaxis) > 700) {
    Serial.println("move right");
    send("r"); // Move Right

  } else if (analogRead(xaxis) < 300) {
    Serial.println("move left");
    send("l"); // Move Left

  } else {
    send("s"); // Stop
  }
}

void send( String a) {
  int str_len = a.length() + 1;
  char text[str_len];
  a.toCharArray(text, str_len);
  radio.writeFast(&text, sizeof(text));

}

