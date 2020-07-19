#include<SPI.h>
#include<RF24.h>
#include<nRF24L01.h>
RF24 radio(7,8);
//const byte address[][6]=["00001"];
const byte address[][6]={"0"};
//char x1;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  radio.begin();
  radio.setChannel(89);
  radio.setAutoAck(1);
  radio.openWritingPipe(address[0]); 
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
 // radio.startListening();
 //pinMode(3,output);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 const char text[100]="hello world";
 radio.write(&text,sizeof(text));
 Serial.print("hello");
 delay(1000);
}
