
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 pinMode(11, INPUT);
 pinMode(12, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValueTw = digitalRead(12);
 int sensorValueTh = digitalRead(13);
 Serial.print("PIN 11 = ");
 Serial.print(sensorValueTw, DEC);
 Serial.print("  |  PIN 12 = ");
 Serial.println(sensorValueTh, DEC);
}
