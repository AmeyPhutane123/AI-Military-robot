/* get accelerate data of H3LIS331DL
 * Auth : lawliet(lawliet.zou@gmail.com)
 * version : 0.1
 */

#include <H3LIS331DL.h>
#include <Wire.h>
#include <H3LIS331DL.h>
#include <Wire.h>

//please get these value by running H3LIS331DL_AdjVal Sketch.
#define VAL_X_AXIS  203
#define VAL_Y_AXIS  165
#define VAL_Z_AXIS  371

#define VAL_X1_AXIS  203
#define VAL_Y1_AXIS  165
#define VAL_Z1_AXIS  371

H3LIS331DL h3lis;

void setup(){
  Serial.begin(9600);
  h3lis.init();
  h3lis.importPara(VAL_X_AXIS,VAL_Y_AXIS,VAL_Z_AXIS);
   h3lis.importPara(VAL_X1_AXIS,VAL_Y1_AXIS,VAL_Z1_AXIS);
}

void loop(){
  int16_t x,y,z;
    int16_t x1,y1,z1;
  
  h3lis.readXYZ(&x,&y,&z);
   h3lis.readXYZ(&x1,&y1,&z1);
  /*Serial.print("x, y, z = ");
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.println(z);*/

  double xyz[3];
  double x1y1z1[3];
 
  h3lis.getAcceleration(xyz);
   h3lis.getAcceleration(x1y1z1);
  Serial.print("accelerate of x, y, z = ");
  Serial.print(xyz[0]);
  Serial.print("g");
  Serial.print("\t");
  Serial.print(xyz[1]);
  Serial.print("g");
  Serial.print("\t");
  Serial.print(xyz[2]);
  Serial.println("g"); 
delay(1000);
    
    Serial.print("accelerate of x1, y1, z1 = ");
  Serial.print(x1y1z1[0]);
  Serial.print("g");
  Serial.print("\t");
  Serial.print(x1y1z1[1]);
  Serial.print("g");
  Serial.print("\t");
  Serial.print(x1y1z1[2]);
  Serial.println("g");
  
  delay(1000);
}
