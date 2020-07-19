#include<Stepper.h>
#include<SPI.h>
#include<RF24.h>
#include<nRF24L01.h>

RF24 radio(7,8);

const byte address[5]="00002";

int const StepperperRevolution=200;
int th,th1,th2,th4,th5,th6,th7;
int array[4];
void setup() {
  // put your setup code here, to run once:
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();

  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  int x1=0,x2=0,x3=0,x4=0;
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (radio.available())
  {
    radio.read(&array,sizeof(array));
   int x1=array[0];
   int x2=array[1];
   int x3=array[2];
   int x4=array[3];
   
 
  }
  while(true)
  {
    switch(th)
    {
      case 1: if(x1>th)
      {
        digital.write(10,"HIGH");
        digital.write(11,"HIGH");
        digital.write(12,"HIGH");
        digital.write(9,"HIGH"); 
      }
      else{
        digital.write(10,"LOW");
        digital.write(11,"LOW");
        digital.write(12,"LOW");
        digital.write(9,"LOW"); 
      }
    }

    switch(th1)
    {
      case 1: if(x2>th1)
      {
        digital.write(10,"LOW");
        digital.write(11,"LOW");
        digital.write(12,"HIGH");
        digital.write(9,"HIGH"); 
      }
      else{
        digital.write(10,"LOW");
        digital.write(11,"LOW");
        digital.write(12,"LOW");
        digital.write(9,"LOW"); 
      }
    }

    switch(th2)
    {
      case 1: if(x3>th2)
      {
        digital.write(10,"HIGH");
        digital.write(11,"HIGH");
        digital.write(12,"LOW");
        digital.write(9,"LOW"); 
      }
      else{
        digital.write(10,"LOW");
        digital.write(11,"LOW");
        digital.write(12,"LOW");
        digital.write(9,"LOW"); 
      }
    }
  }

  

}
