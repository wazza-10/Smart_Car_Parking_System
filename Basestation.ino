/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[][6] = {"10000", "20000","30000"};
// const byte address2[6] = "00002";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address[0]);
  radio.openReadingPipe(1, address[1]);
  radio.openReadingPipe(2, address[2]);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(4, INPUT);
}

void loop() {
  if (radio.available()) {
    char text[64] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
  int temp = digitalRead(4);
  if(temp){
    const char text[] = "Detected Intruder ! at Base Station !";
    Serial.println(text);
    delay(1000);
        }
  else{
    const char text[] = "No movement at Base Station !";
    Serial.println(text);
    delay(1000);
  }
}

