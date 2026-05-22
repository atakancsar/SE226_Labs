#include <LiquidCrystal.h>

// LCD
LiquidCrystal lcd(36, 37, 26, 27, 28, 29);

#define backlight_pin 31

// Segment pinleri
int aPin = 2;
int bPin = 3;
int cPin = 4;
int dPin = 5;
int ePin = 6;
int fPin = 7;
int gPin = 8;
int dP   = 9;

// Digit GND pinleri
int dig1Pin = 10;
int dig2Pin = 11;
int dig3Pin = 12;
int dig4Pin = 13;

// Counter digitleri
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;

void setup() {

  // LCD ışığı
  pinMode(backlight_pin,OUTPUT);
  analogWrite(backlight_pin,255);

  // Segment pinleri
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(dP, OUTPUT);

  // Digit pinleri
  pinMode(dig1Pin, OUTPUT);
  pinMode(dig2Pin, OUTPUT);
  pinMode(dig3Pin, OUTPUT);
  pinMode(dig4Pin, OUTPUT);

  // LCD
  lcd.begin(16,2);

  lcd.setCursor(0,0);
  lcd.print("Counter:");
}

// Sayı gösterme
void displayNumber(int num){

  switch(num){

    case 0:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, HIGH);
      break;

    case 1:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      break;

    case 2:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, LOW);
      break;

    case 3:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, LOW);
      break;

    case 4:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      break;

    case 5:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      break;

    case 6:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      break;

    case 7:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      break;

    case 8:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      break;

    case 9:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      break;
  }
}

// Multiplexing
void showDigits(){

  digitalWrite(dig1Pin, HIGH);
  displayNumber(dig1);
  delay(4);
  digitalWrite(dig1Pin, LOW);

  digitalWrite(dig2Pin, HIGH);
  displayNumber(dig2);
  delay(4);
  digitalWrite(dig2Pin, LOW);

  digitalWrite(dig3Pin, HIGH);
  displayNumber(dig3);
  delay(4);
  digitalWrite(dig3Pin, LOW);

  digitalWrite(dig4Pin, HIGH);
  displayNumber(dig4);
  delay(4);
  digitalWrite(dig4Pin, LOW);
}

// Counter
void incrementCounter(){

  dig1++;

  if(dig1 >= 10){
    dig1 = 0;
    dig2++;
  }

  if(dig2 >= 10){
    dig2 = 0;
    dig3++;
  }

  if(dig3 >= 10){
    dig3 = 0;
    dig4++;
  }

  if(dig4 >= 10){
    dig4 = 0;
  }
}

// LCD update
void updateLCD(){

  lcd.setCursor(0,1);

  lcd.print(dig4);
  lcd.print(dig3);
  lcd.print(dig2);
  lcd.print(dig1);
  lcd.print(" ");
}

void loop() {

  for(int i=0; i<50; i++){
    showDigits();
  }

  incrementCounter();

  updateLCD();

  delay(1000);
}
