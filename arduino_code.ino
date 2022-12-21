#include <SPI.h>
#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal my_lcd(rs, en, d4, d5, d6, d7);
bool p1 = false;
bool p2 = false;
bool p3 = false;
bool p4 = false;
int counter; 
char buff [255];
volatile byte indx;
volatile boolean process;

byte customCheck[8] = {
  B00000,
  B00000,
  B00001,
  B00001,
  B00010,
  B01010,
  B00100,
  B00000
};
 
void setup (void) {
   Serial.begin (9600);
   pinMode(MISO, OUTPUT); // have to send on master in so it set as output
   pinMode(6,OUTPUT);
   SPCR |= _BV(SPE); // turn on SPI in slave mode
   indx = 0; // buffer empty
   process = false;
   SPI.attachInterrupt(); // turn on interrupt

  my_lcd.begin(16,2);
  my_lcd.createChar(1, customCheck);
  

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}
 
ISR (SPI_STC_vect) // SPI interrupt routine 
{ 
   byte c = SPDR; // read byte from SPI Data Register
   if (indx < sizeof(buff)) {
      buff[indx++] = c; // save data in the next index in the array buff
      if (c == '\n') { 
        buff[indx - 1] = 0; // replace newline ('\n') with end of string (0)
        process = true;
        counter = 4; 
       
        if(buff[0] == '0'){
          counter--;
          p1 = false;
        }
        
        else 
        p1 = true;
       
        
        if(buff[1] == '0'){
          counter--;
          p2 = false;
        }
        
        else 
        p2 = true;
        

        if(buff[2] == '0'){
          counter--;
          p3 = false;
        }
        
        else 
        p3 = true;
        

        if(buff[3] == '0'){
          counter--;
          p4 = false;
        }
        
        else 
        p4 = true;
        
       
        
        

        
      }
   } 
}
 







void loop() {
  if (process) {
      process = false; //reset the process
      Serial.println (buff); 


  my_lcd.setCursor(0,0);    
  my_lcd.print(" AVAILABLE : ");
  my_lcd.print(counter); 

  my_lcd.setCursor(0,1);
  my_lcd.print("1:");
  if(p1) {
  my_lcd.write((byte)1);
  analogWrite(9, 255);
  analogWrite(8, 0);
  }
  else  {
  my_lcd.print("X");
  analogWrite(9, 0);
  analogWrite(8, 255);
  }

  //my_lcd.setCursor(0,4);
  my_lcd.print(" 2:");
  if(p2){
  my_lcd.write((byte)1);
  analogWrite(A0, 255);
  analogWrite(A1, 0);
  }
  
  else {
  my_lcd.print("X");
  analogWrite(A0, 0);
  analogWrite(A1, 255);
  }

  my_lcd.print(" 3:");
  if(p3) {
  my_lcd.write((byte)1);
  analogWrite(A2, 255);
  analogWrite(A3, 0);
  }
  else {
  my_lcd.print("X");
  analogWrite(A2, 0);
  analogWrite(A3, 255);
  }

  my_lcd.print(" 4:");
  if(p4) {
  my_lcd.write((byte)1);
  analogWrite(A4, 255);
  analogWrite(A5, 0);
  }
  else {
  my_lcd.print("X");
  analogWrite(A4, 0);
  analogWrite(A5, 255);
  }
  

 indx= 0;
  }
}
  
