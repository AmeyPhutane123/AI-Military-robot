#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   7
#define CSN_PIN 8

const byte thisSlaveAddress[5] = {'R','x','A','A','A'};

RF24 radio(CE_PIN, CSN_PIN);
int array[3];
int array1[3];
int x,y,z,x1,y1,z1;



//char dataReceived[10]; // this must match dataToSend in the TX
bool newData = false;

//===========

void setup() {

    Serial.begin(9600);

    Serial.println("SimpleRx Starting");
    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.openReadingPipe(1, thisSlaveAddress);
    radio.startListening();
}

//=============

void loop() {
    getData();
    showData();
}

//==============

void getData() {
    if ( radio.available() ) {
        radio.read( &array, sizeof(array) );
        delay(5000);
        radio.read(&array1,sizeof(array1));
        delay(5000);
       
        newData = true;
    }
}

void showData() {
    if (newData == true) {
        Serial.print("Data received ");
        //Serial.println(dataReceived);
        //newData = false;
         x=array[0];
        y=array[1];
        z=array[2];

         x1=array1[0];
        y1=array1[1];
        z1=array1[2];
        Serial.println(x);
        Serial.println(y);
        Serial.println(z);

        Serial.println(x1);
        Serial.println(y1);
        Serial.println(z1);
    }
    }
   
