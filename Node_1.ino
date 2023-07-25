#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "10000";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(4, INPUT);
}

void loop() {
  int temp = digitalRead(4);
  if(temp){
    const char text[] = "Detected Intruder ! at room 1";
    radio.write(&text, sizeof(text));
    delay(1000);
  }
  else{
    const char text[] = "No movement in room 1";
    radio.write(&text, sizeof(text));
    delay(1000);
  }
}
