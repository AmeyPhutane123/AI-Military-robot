
#include<SPI.h>
#include<RF24.h>
#include<nRF24L01.h>


RF24 radio(7,8);
const byte address[5] = "00002";
int array[6];


void setup() {
  // put your setup code here, to run once:
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 array[0]=analogRead(A4);
 array[1]=analogRead(A3);
 array[2]=analogRead(A2);
 array[3]=analogRead(A1);

  Serial.begin(9600);
  Serial.print(array[0]);
  Serial.print(array[1]);
   Serial.print(array[2]);
    Serial.print(array[3]);
  radio.write(&array,sizeof(array));
  
delay(5000);



}
