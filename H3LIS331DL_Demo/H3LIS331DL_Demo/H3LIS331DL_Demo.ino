/* get accelerate data of H3LIS331DL
 * Auth : lawliet(lawliet.zou@gmail.com)
 * version : 0.1
 */

#include <H3LIS331DL.h>
#include <Wire.h>

//please get these value by running H3LIS331DL_AdjVal Sketch.
#define VAL_X_AXIS  0
#define VAL_Y_AXIS  0
#define VAL_Z_AXIS  0

H3LIS331DL h3lis;

void setup(){
  Serial.begin(9600);
  h3lis.init();
  h3lis.importPara(VAL_X_AXIS,VAL_Y_AXIS,VAL_Z_AXIS);
  pinMode(5,OUTPUT);
}

void loop(){
  int16_t x,y,z;
  h3lis.readXYZ(&x,&y,&z);
  delay(500);
  Serial.print("x, y, z = ");
  delay(500);
  Serial.print(x);
  delay(500);
  Serial.print("\t");
  delay(500);
  Serial.print(y);
  delay(500);
  Serial.print("\t");
  delay(500);
  Serial.println(z);
  delay(500);
/*  if(x>220){
     digitalWrite(5,HIGH);
  }else{
    digitalWrite(5,LOW);
  }
   if(x<-220){
     digitalWrite(5,HIGH);
  }else{
    digitalWrite(5,LOW);
  }
 

  /*double xyz[3];
  h3lis.getAcceleration(xyz);
  Serial.print("accelerate of x, y, z = ");
  Serial.print(xyz[0]);
  Serial.print("g");
  Serial.print("\t");
  Serial.print(xyz[1]);
  Serial.print("g");
  Serial.print("\t");
  Serial.print(xyz[2]);
  Serial.println("g");*/
  
}
