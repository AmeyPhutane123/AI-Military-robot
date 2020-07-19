#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   7
#define CSN_PIN 8

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

int high[1];
int low[1];

void setup()
{
 radio.begin();
 radio.openWritingPipe(pipe);

 high[0] = 1;
 low[0] = 0;
}

void loop()
{
 radio.write(high, sizeof(high));

 delay(2000);  
 
 radio.write(low, sizeof(low));

 delay(5000);  
}
