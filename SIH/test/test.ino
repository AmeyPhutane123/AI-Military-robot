
// include the library code:
#include <LiquidCrystal.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN  9
#define CSN_PIN 10

const byte slaveAddress[5] = {'R','x','A','A','A'};
RF24 radio(CE_PIN, CSN_PIN);
int joyStick[3];

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 6, 5, 4, 3, 2);

// for joystick
int VRx = A0;
int VRy = A1;
int SW = 7;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

// for pot
int pot1=A4;
int pot2=A5; 

int potReading1=0;
int potReading2=0;

int mapPot1=0;
int mapPot2=0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  Serial.begin(9600);
  radio.begin();
  
  radio.openWritingPipe(slaveAddress);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening(); 
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 

}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);

  potReading1 = analogRead(pot1);
  potReading2 = analogRead(pot2);

    mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  mapPot1 = map(potReading1, 0, 1023, -38, 180);

    joyStick[0]=mapX;
  joyStick[1]=mapY;
  joyStick[2]=SW_state;
  joyStick[3]=mapPot1;
  joyStick[4]=potReading2;

  Serial.print("X: ");
  Serial.print(joyStick[0]);
  Serial.print(" | Y: ");
  Serial.print(joyStick[1]);
  Serial.print(" | Button: ");
  Serial.println(joyStick[2]);
/*
  Serial.print("pot1-> ");
  Serial.println(mapPot1);
  Serial.print("pot2-> ");
  Serial.println(potReading2);
*/
  radio.write(&joyStick,sizeof(joyStick));
  delay(2000);
}
