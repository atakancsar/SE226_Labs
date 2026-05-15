#include <U8g2lib.h>

// LCD (ST7920 SPI - Ardukit'te en yaygın)
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, 13, 11, 10, 8);

int LED1pin = 43;
int LED2pin = 44;
int LED3pin = 45;
int LED4pin = 46;

int button1pin = 40; // ENTER
int button2pin = 41; // LEFT

bool systemON = false;
int mode = 1;

int prevButton1 = HIGH;
int prevButton2 = HIGH;

void setup() {

  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
  pinMode(LED3pin, OUTPUT);
  pinMode(LED4pin, OUTPUT);

  pinMode(button1pin, INPUT_PULLUP);
  pinMode(button2pin, INPUT_PULLUP);

  u8g2.begin();
}

void drawScreen() {

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);

  if (!systemON) {

    u8g2.drawStr(30, 30, "SYSTEM OFF");
  }
  else {

    u8g2.drawStr(10, 20, "Hamza hocam");
    u8g2.drawStr(10, 40, "cs gelin");

    if (mode == 1) u8g2.drawStr(10, 60, "MODE 1");
    if (mode == 2) u8g2.drawStr(10, 60, "MODE 2");
    if (mode == 3) u8g2.drawStr(10, 60, "MODE 3");
  }

  u8g2.sendBuffer();
}

void loop() {

  int button1 = digitalRead(button1pin);
  int button2 = digitalRead(button2pin);

  // ENTER -> ON/OFF
  if (button1 == LOW && prevButton1 == HIGH) {
    systemON = !systemON;
    delay(200);
  }

  // LEFT -> mode change
  if (button2 == LOW && prevButton2 == HIGH) {
    mode++;
    if (mode > 3) mode = 1;
    delay(200);
  }

  prevButton1 = button1;
  prevButton2 = button2;

  // LCD sürekli güncelle
  drawScreen();

  // SYSTEM OFF
  if (!systemON) {

    digitalWrite(LED1pin, LOW);
    digitalWrite(LED2pin, LOW);
    digitalWrite(LED3pin, LOW);
    digitalWrite(LED4pin, LOW);

    return;
  }

  // MODE 1
  if (mode == 1) {

    digitalWrite(LED1pin, HIGH);
    digitalWrite(LED2pin, HIGH);
    digitalWrite(LED3pin, HIGH);
    digitalWrite(LED4pin, HIGH);

    delay(200);

    digitalWrite(LED1pin, LOW);
    digitalWrite(LED2pin, LOW);
    digitalWrite(LED3pin, LOW);
    digitalWrite(LED4pin, LOW);

    delay(200);
  }

  // MODE 2
  else if (mode == 2) {

    digitalWrite(LED1pin, HIGH); delay(200); digitalWrite(LED1pin, LOW);
    digitalWrite(LED2pin, HIGH); delay(200); digitalWrite(LED2pin, LOW);
    digitalWrite(LED3pin, HIGH); delay(200); digitalWrite(LED3pin, LOW);
    digitalWrite(LED4pin, HIGH); delay(200); digitalWrite(LED4pin, LOW);
  }

  // MODE 3
  else if (mode == 3) {

    digitalWrite(LED4pin, HIGH); delay(200); digitalWrite(LED4pin, LOW);
    digitalWrite(LED3pin, HIGH); delay(200); digitalWrite(LED3pin, LOW);
    digitalWrite(LED2pin, HIGH); delay(200); digitalWrite(LED2pin, LOW);
    digitalWrite(LED1pin, HIGH); delay(200); digitalWrite(LED1pin, LOW);
  }
}