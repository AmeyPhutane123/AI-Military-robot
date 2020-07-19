/* get accelerate data of H3LIS331DL
 * Auth : lawliet(lawliet.zou@gmail.com)
 * version : 0.1
 */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <H3LIS331DL.h>
#include <H3LIS331DL.h>
#include <Wire.h>
#include <Wire.h>
#define CE_PIN   9
#define CSN_PIN 10
const byte thisSlaveAddress[5] = {'R','x','A','A','A'};


//please get these value by running H3LIS331DL_AdjVal Sketch.
#define VAL_X_AXIS  0
#define VAL_Y_AXIS  0
#define VAL_Z_AXIS  0
#define VAL_X1_AXIS  0
#define VAL_Y1_AXIS  0
#define VAL_Z1_AXIS  0

H3LIS331DL h3lis;

void setup(){
  Serial.begin(9600);
  h3lis.init();
  h3lis.init();
  h3lis.importPara(VAL_X_AXIS,VAL_Y_AXIS,VAL_Z_AXIS);
  h3lis.importPara(VAL_X1_AXIS,VAL_Y1_AXIS,VAL_Z1_AXIS);
 
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  
  
}

void loop(){
 int16_t x,y,z;
  int16_t x1,y1,z1;
  h3lis.readXYZ(&x,&y,&z);
  x=analogRead(A4);
  y=analogRead(A5);
 h3lis.readXYZ(&x,&y,&z);
 h3lis.readXYZ(&x1,&y1,&z1);
  
  delay(50);
  Serial.print("x, y, z = ");
  Serial.print("");
  Serial.print("x1, y1, z1 = ");
  delay(500);
  Serial.print(x);
   //Serial.print("");
  //Serial.print(x1);
  delay(50);
  Serial.print("\t");
  delay(50);
  Serial.print(y);
   //Serial.println("");
  //Serial.print(y1);
  delay(50);
  Serial.print("\t");
  delay(50);
  Serial.println(z);
   //Serial.println("");
  //Serial.println(z1);
  delay(50);
  Serial.println();
  Serial.print("x1, y1, z1 = ");
  delay(50);
  Serial.print(x1);
  delay(50);
   Serial.print("\t");
   Serial.print(y1);
    delay(50);
    Serial.print("\t");
    Serial.println(z1);
    Serial.println();
  

  
}
