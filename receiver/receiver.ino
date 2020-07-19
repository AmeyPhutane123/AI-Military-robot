#include<SPI.h>
#include<RF24.h>
#include<nRF24L01.h>
RF24 radio(7,8);
//const byte address[][6]=["00001"];
const byte address[][6]={"0"};
char text;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
  radio.begin();
  radio.setChannel(1);
  radio.openReadingPipe(1,address[0]);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(radio.available())
  {
    radio.read(&text,sizeof(text));
    Serial.println(text);
    delay(2000);
    
  }
}
