int clock1 = 10;
int reset = 11;
int enable = 12;



void setup() {
  
  DDRD = B11111110;  
  DDRD = DDRD | B11111100;
  DDRB = B00000011;
  Serial.begin(9600);
  pinMode(clock1,OUTPUT);
  pinMode(reset,OUTPUT);
  pinMode(enable,OUTPUT);
  digitalWrite(enable,LOW);
  digitalWrite(reset,HIGH);
  delayMicroseconds(5);
  digitalWrite(reset,LOW);

}

void loop() {

    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH); 
    
    delayMicroseconds(800);
    
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW); 
    
    digitalWrite(clock1,HIGH);
    delayMicroseconds(5);
    digitalWrite(clock1,LOW);

}

