# include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN  7
#define CSN_PIN 8

const byte slaveAddress[5] = {'R','x','A','A','A'};
RF24 radio(CE_PIN, CSN_PIN);
int joyStick[3];
int x,y,z;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0,slaveAddress);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(radio.available()){
    radio.read(&joyStick,sizeof(joyStick))
    x=joyStick[0];
    y=joyStick[1];
    z=joyStick[2];
    print("x:")
    println(x);
    print("y:")
    println(y);
    print("z:")
    println(z);
  }
}
