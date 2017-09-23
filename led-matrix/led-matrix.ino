int clock1 = 10;
int reset = 11;
int enable = 12;
int row;
int col;
int number;
int y;

int last = 0;

unsigned long serialdata;
int inbyte;

int width = 8;
int height = 10;

String readString;



#define space {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000}
#define A     {B00000000,B00111100,B01000010,B01000010,B01000010,B01111110,B01000010,B01000010,B01000010,B00000000}
#define B     {B00000000,B01111100,B01000010,B01000010,B01111100,B01000010,B01000010,B01000010,B01111100,B00000000}
#define C     {B00000000,B00111110,B01000000,B01000000,B01000000,B01000000,B01000000,B01000000,B00111110,B00000000}
#define D     {B00000000,B01111100,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B01111100,B00000000}
#define E     {B00000000,B01111110,B01000000,B01000000,B01111100,B01000000,B01000000,B01000000,B01111110,B00000000}
#define F     {B00000000,B01111110,B01000000,B01000000,B01111100,B01000000,B01000000,B01000000,B01000000,B00000000}
#define G     {B00000000,B00111100,B01000010,B01000010,B01000000,B01000111,B01000010,B01000010,B00111100,B00000000}
#define H     {B00000000,B01000010,B01000010,B01000010,B01111110,B01000010,B01000010,B01000010,B01000010,B00000000}
#define I     {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000}
#define J     {B00000000,B00011100,B00001000,B00001000,B00001000,B00001000,B01001000,B01001000,B00110000,B00000000}
#define K     {B00000000,B01000100,B01001000,B01010000,B01100000,B01010000,B01001000,B01000100,B01000010,B00000000}
#define L     {B00000000,B01000000,B01000000,B01000000,B01000000,B01000000,B01000000,B01000000,B01111110,B00000000}
#define M     {B00000000,B01000100,B10101010,B10010010,B10010010,B10000010,B10000010,B10000010,B10000010,B00000000}
#define N     {B00000000,B01000010,B01100010,B01010010,B01001010,B01001010,B01001010,B01000110,B01000010,B00000000}
#define O     {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000}
#define P     {B00000000,B00111100,B01000010,B01000010,B01000010,B01111100,B01000000,B01000000,B01000000,B00000000}
#define Q     {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001}
#define R     {B00000000,B00111100,B00100010,B00100010,B00111100,B00110000,B00101000,B00100100,B00100010,B00000000}                      
#define S     {B00000000,B00111100,B01000010,B01000000,B01000000,B00111100,B00000010,B01000010,B00111100,B00000000}
#define T     {B00000000,B11111110,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000}
#define U     {B00000000,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000}
#define V     {B00000000,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000}
#define W     {B00000000,B10000010,B10000010,B10000010,B10000010,B10010010,B10010010,B10101010,B01000100,B00000000}
#define X     {B00000000,B01000010,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B01000010,B00000000}
#define Y     {B00000000,B10000010,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000}
#define Z     {B00000000,B01111110,B00000010,B00000100,B00001000,B00010000,B00100000,B01000000,B01111110,B00000000}

#define zero {B00000000,B00111100,B01000110,B01001010,B01001010,B01001010,B01010010,B01100010,B00111100,B00000000}
#define one {B00000000,B00001000,B00011000,B00001000,B00001000,B00001000,B00001000,B00001000,B00011100,B00000000}
#define two {B00000000,B00111100,B01000010,B00000100,B00001000,B00010000,B00100000,B01000000,B01111110,B00000000}
#define three {B00000000,B01111110,B00000010,B00000010,B00011100,B00000010,B00000010,B01000010,B00111100,B00000000}
#define four {B00000000,B00000100,B00001100,B00010100,B00100100,B01000100,B01111110,B00000100,B00000100,B00000000}
#define five {B00000000,B01111110,B01000000,B01000000,B00111100,B00000010,B00000010,B00000010,B01111100,B00000000}
#define six {B00000000,B00111100,B01000000,B01000000,B01111100,B01000010,B01000010,B01000010,B00111100,B00000000}
#define seven {B00000000,B01111110,B00000010,B00000100,B00001000,B00010000,B00010000,B00010000,B00010000,B00000000}
#define eight {B00000000,B00111100,B01000010,B01000010,B00111100,B01000010,B01000010,B01000010,B00111100,B00000000}
#define nine {B00000000,B00111000,B01000100,B01000100,B01111100,B00000100,B00000100,B01000100,B00111000,B00000000}


byte alphas[37][10] = {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,space,zero,one,two,three,four,five,six,seven,eight,nine};
byte pattern[] = {B10000000,B01000000,B00100000,B00010000,B00001000,B00000100,B00000010,B00000001};
byte patterns[2][10];

byte design[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};


void setup()
{
  DDRD = B11111110;  // sets Arduino pins 1 to 7 as outputs, pin 0 as input
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
  while (! Serial);
  Serial.println("Enter LED Number 0 to 7 or 'x' to clear");

  
}

void loop()
{
  checkForInput();
}



void checkForInput1()
{
  Serial.println("printing for matrix");
  readString = "";
  int pos = 0;
  bool number = false;
  while(true)
  {
    if(Serial.available())
    {
      char ch = Serial.read();
      if(ch == '\n')
      {
        break;
      }

      if(pos < 1000)
      {
        readString+=ch;
        pos++;
      }
    }
  }

  Serial.println(readString);
  int loop = 0;

  
  for(int i=0; i<10; i++)
        {
            design[i] = B00000000;
        }


        
  if(readString[0] != '/')
  {
    getSerial();
    while(!Serial.available())
    {
      
       show1();
    }
  }
  
}


void checkForInput()
{
  readString = "";
  int pos = 0;
  bool number = false;
  while(true)
  {
    if(Serial.available())
    {
      char ch = Serial.read();
      if(ch == 'a')
      {
        checkForInput1();
        return;
      }
      Serial.println("printing for text");
      if(ch == '\n')
      {
        break;
      }

      if(pos < 100)
      {
        if(ch < 58 && number )
        {
          readString+=' '; 
        }
        readString+=ch;
        pos++;
        number = true;
      }
    }
  }

  Serial.println(readString);
  int loop = 0;
  while(loop < 2)
  {
    show();
    delay(1000);
    loop++;
  }
}


void show()
{
  int total = readString.length();
  int index = 0;
  int ascii;
  for(int i = 0; i < total; i+=2)
  {
    char c1 = readString[i];
    if (c1 < 58 )
    {
      ascii = 21;
    }

    else
    {
      ascii = 65;
    }
    index = c1 - ascii;
    
    if(c1 == ' ')
    {
       index = 26;
    }
    int j = 0;
    while(j<10)
    {
       patterns[0][j] = alphas[index][j];
       j+=1;
    }

    if((i+1) == total)
    {
      readString+=' ';
    }
    
    char c2 = readString[i+1];
    index = c2 - 65;
    
    if(c2 == ' ')
    {
       index = 26;
    }
    j = 0;
    while(j<10)
    {
       patterns[1][j] = alphas[index][j];
       j+=1;
    }
    
    for (int z=0;z<8;z++)
    { 
      for(int t=0;t<10;t++)
      {
        for(y=0;y<10;y++)
        {
              byte temp = patterns[0][y]; 
              byte temp_2=patterns[1][y];
              byte temp3 = (temp<<z)+(temp_2>>7-z);
              digitalWrite(2,temp3 & pattern[7]);
              digitalWrite(3,temp3 & pattern[6]);
              digitalWrite(4,temp3 & pattern[5]);
              digitalWrite(5,temp3 & pattern[4]);
              digitalWrite(6,temp3 & pattern[3]);
              digitalWrite(7,temp3 & pattern[2]);
              digitalWrite(8,temp3 & pattern[1]);
              digitalWrite(9,temp3 & pattern[0]); 
              
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

              delay(1);
       }
        
      }
  
    }
  
  }
  
}

void getSerial()
{
  serialdata = 0;
  last = 0;
  while (last < readString.length())
  {
    delay(2);
    char c1 = readString[last];
    if (c1 != '/')
    {
      inbyte = c1 - 48;
      serialdata = serialdata * 10 + inbyte;
    }

    else
    {
      number = serialdata;
      row = int(int(number) / width );
      col = int(number) - (row*width);
      design[row] = design[row] | pattern[col];
      serialdata = 0;
    }
    last++;
  }
}

void show1()
{ 

  
          digitalWrite(enable,LOW);
          digitalWrite(reset,HIGH);
          delayMicroseconds(5);
          digitalWrite(reset,LOW);          
         for(y=0;y<10;y++)
         {  
            byte temp = design[y]; 
           
            digitalWrite(2,temp & pattern[7]);
            digitalWrite(3,temp & pattern[6]);
            digitalWrite(4,temp & pattern[5]);
            digitalWrite(5,temp & pattern[4]);
            digitalWrite(6,temp & pattern[3]);
            digitalWrite(7,temp & pattern[2]);
            digitalWrite(8,temp & pattern[1]);
            digitalWrite(9,temp & pattern[0]); 
            
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


}








