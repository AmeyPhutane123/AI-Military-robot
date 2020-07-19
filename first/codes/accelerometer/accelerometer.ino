


const int xpin=A3;
const int ypin=A2;
const int zpin=A1;
const int powerpin=19;
const int groundpin=18 ;
const int th1=90; 
const int th2=90; 
const int th3=90; 
int X,Y,Z;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);
  pinMode(zpin,INPUT);

  pinMode(powerpin,OUTPUT);
  pinMode(groundpin,OUTPUT);

  digitalWrite(powerpin,HIGH);
  digitalWrite(groundpin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  //printing the values of the reading of accelerometer
  X=analogRead(xpin);
  Y=analogRead(ypin);
  Z=analogRead(zpin);
  Serial.print(X);
  Serial.println();
  Serial.print(Y);
  Serial.println();
  Serial.print(Z);
  Serial.println();


  if(X>th1 && Y<th2 && Z<th3){
    //pinmodes of the motors drivers....
  }
  if(X<th1 && Y>th2 && Z<th3){
    
  }
  if(X<th1 && Y<th2 && Z>th3){
    
  }
    
  

}
