////#include <H3LIS331DL.h>
////#include <H3LIS331DL.h>
////#include <Wire.h>
////#include <Wire.h>
//#include<SPI.h>
//#include<RF24.h>
////#include <nRF24L01.h>
//
//// ce, csn pins
//RF24 radio(9,10);
///*
//#define VAL_X_AXIS  5
//#define VAL_Y_AXIS  0
//#define VAL_Z_AXIS  0
//
//#define VAL_X1_AXIS  0
//#define VAL_Y1_AXIS  0
//#define VAL_Z1_AXIS  0
//
//H3LIS331DL h3lis;
//
//const int num=3;
// int array[num];
// int array1[num];
//*/
//void setup(void){
//  Serial.begin(9600);
//  radio.begin();
//  radio.setPALevel(RF24_PA_MAX);
//  radio.setDataRate( RF24_1MBPS);
//  radio.setChannel(0x76); //It was creating problem while communicating with Raspberry Pi
//  radio.openWritingPipe(0xF0F0F0F0E1);//Previously the address was 0x65646f4e31
//  radio.enableDynamicPayloads(); //It was creating problem while communicating with Raspberry Pi
// // h3lis.init();
////  h3lis.importPara(VAL_X_AXIS,VAL_Y_AXIS,VAL_Z_AXIS);
// // h3lis.importPara(VAL_X1_AXIS,VAL_Y1_AXIS,VAL_Z1_AXIS); 
//  //pinMode(A0,INPUT);
//  radio.stopListening(); 
//  radio.powerUp();
//
//}
//
//void loop(void){
//   const  char text[]  = "hello";
//  radio.write(&text, sizeof(text));
//  delay(1000);
///*
//    int16_t x,y,z,x1,y1,z1;
//  x=analogRead(A0);
//  h3lis.readXYZ(&x,&y,&z);
//  h3lis.readXYZ(&x1,&y1,&z1);
//  Serial.print("x, y, z = ");
//  Serial.print(x);
//  Serial.print("\t");
//  Serial.print(y);
//  Serial.print("\t");
//  Serial.println(z);
//
//   // delay(5000);
///*  Serial.print("x1, y1, z1 = ");
//  Serial.print(x1);
//  Serial.print("\t");
//  Serial.print(y1);
//  Serial.print("\t");
//  Serial.println(z1);
// // delay(5000);*/
//
////  double xyz[3];
////  array[0]=x;
////  array[1]=y;
////  array[2]=z;
//
////  array1[0]=x1;
// // array1[1]=y1;
// // array1[2]=z1;
//
//  
// // radio.write(&array,sizeof(array));
// // delay(5000);
// // radio.write(&array1,sizeof(array1));
// // delay(5000);
// // h3lis.getAcceleration(xyz);*/
//}



#include<SPI.h>
#include<RF24.h>

// ce, csn pins
RF24 radio(9, 10);

void setup(void){
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(0x76);
  radio.openWritingPipe(0xF0F0F0F0E1LL);
  radio.enableDynamicPayloads();
  radio.powerUp();
  radio.stopListening();

}

void loop(void){
    const char text[] = "Hello World is awesome";
  radio.write(&text, sizeof(text));
  delay(1000);

}
















//#include<SPI.h>
//#include<RF24.h>

// ce, csn pins
//RF24 radio(9, 10);

//void setup(void){
//  radio.begin();
//  radio.setPALevel(RF24_PA_MAX);
//  radio.setChannel(0x76);
//  radio.setDataRate(RF24_1MBPS);
//  radio.openWritingPipe(0xF0F0F0F0E1LL);
//  radio.enableDynamicPayloads();
//  radio.powerUp();
//  
//
//}
//
//void loop(void){
//    const char text[] = "b";
//  radio.write(&text, sizeof(text));
//  delay(1000);
//
//}
