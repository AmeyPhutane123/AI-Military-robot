#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

int received[1];

void setup()   /****** SETUP: RUNS ONCE ******/
{
 pinMode(8, OUTPUT); 
 
 delay(1000);

 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening();;
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
 if ( radio.available() )
 {
   // Read the data payload until we've received everything
   bool done = false;
   while (!done)
   {
     // Fetch the data payload
     done = radio.read( received, sizeof(received) );

     if (received[0]==0)
       digitalWrite(8, LOW);
     else
       digitalWrite(8, HIGH);
   }
 }
}
