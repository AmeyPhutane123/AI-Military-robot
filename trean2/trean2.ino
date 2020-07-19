
#include<SPI.h>
#include "RF24.h"

RF24 radio(7,8);
const byte address[][6]={"0"};

struct package
{
  int id=1;
  float temperature=18.3;
  char text[100]="text to be transmited";
 };

typedef struct package package;
package data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.setChannel(115);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(address[0]);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  radio.write(&data.id,sizeof(data.id));
  Serial.print("\n package");
  Serial.print(data.id);
  Serial.print("\n");
  Serial.println(data.temperature);
  Serial.print(data.text);
  data.id=data.id+1;
  data.temperature=data.temperature+0.1;
  delay(1000);
  
  
}
