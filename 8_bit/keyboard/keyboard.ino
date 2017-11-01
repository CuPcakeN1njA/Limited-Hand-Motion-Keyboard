#include "Keyboard.h"

int inPin = 3;
int val = 0; 
int bit1 = 0;
int bit2 = 0;
int bit3 = 0;
int bit4 = 0;
int bit5 = 0;
int bit6 = 0;
int bit7 = 0;
int bit8 = 0;
int __bin = 0;
int tot = 0;
int led = 17;
int _bit = 0;
char character;
String bin = "";

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inPin);   // read the input pin
  if (val == 1){
    flash();
    delay(2000);
    bit1 = b_read();
    bit2 = b_read();
    bit3 = b_read();
    bit4 = b_read();
    bit5 = b_read();
    bit6 = b_read();
    bit7 = b_read();
    bit8 = b_read();
    bin = bin + bit1 + bit2 + bit3 + bit4 + bit5 + bit6 + bit7 + bit8;
    __bin = convert(bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);
    character = char(__bin);
    if(__bin > 0){
      Keyboard.print(character);
    }
    bin = "";
  }
  //Serial.print(val);    // sets the LED to the button's value
  delay(500);
}

int b_read(){
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
  _bit = digitalRead(inPin);
  delay(500);
  digitalWrite(led, HIGH);
  delay(500);
  return _bit;
}

static void flash(){
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
}

int convert(int bit1, int bit2, int  bit3,int bit4,int bit5, int bit6, int bit7, int bit8){
  if(bit1 == 1){
    tot = tot + 128;
  }
  if(bit2 == 1){
    tot = tot + 64;
  }
  if(bit3 == 1){
    tot = tot + 32;
  }
  if(bit4 == 1){
    tot = tot + 16;   
  }
  if(bit5 == 1){
    tot = tot + 8;
  }
  if(bit6 == 1){
    tot = tot + 4;
  }
  if(bit7 == 1){
    tot = tot + 2;
  }
  if(bit8 == 1){
    tot = tot + 1;
  }
  return tot;
}

