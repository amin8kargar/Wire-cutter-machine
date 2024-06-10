//wire cutting machine   code by m.h.vahabi
#include <LCDWIKI_GUI.h>
#include <LCDWIKI_SPI.h>
#include <Keypad.h>
#include <math.h>

const int stepdir = 3;
const int stepPin = 2;
const int cutdir = A1;
const int cutPin = 10;

const byte ROWS = 4;
const byte COLS = 3;


char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '<', '0', '>' }
};

byte rowPins[ROWS] = { 4, 5, 6, 7 };
byte colPins[COLS] = { 8, 9, A2 };
Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

//paramters define
#define MODEL ST7735S
#define CS A5
#define CD A3
#define RST A4
#define LED A0

long int num1 = 0;
long int num2 = 0;
long int num3 = 0;
long int num4 = 0;

LCDWIKI_SPI my_lcd(MODEL, CS, CD, RST, LED);
unsigned long show_start(void) {
  my_lcd.Set_Draw_color(255, 255, 255);
  my_lcd.Fill_Rectangle(0, 0, my_lcd.Get_Display_Width() - 1, my_lcd.Get_Display_Height() - 1);
  my_lcd.Set_Draw_color(255, 0, 0);
  my_lcd.Fill_Round_Rectangle(my_lcd.Get_Display_Width() / 2 - 1 - 72 + 1, my_lcd.Get_Display_Height() / 2 - 1 - 52 + 1, my_lcd.Get_Display_Width() / 2 - 1 + 72 - 1, my_lcd.Get_Display_Height() / 2 - 1 + 52 - 1, 5);
  my_lcd.Set_Text_colour(255, 255, 255);
  my_lcd.Set_Text_Size(2.5);
  my_lcd.Set_Text_Mode(1);
  my_lcd.Print_String("WIRE", CENTER, 35);
  my_lcd.Print_String("CUTTING", CENTER, 53);
  my_lcd.Print_String("MACHINE", CENTER, 71);
  delay(5000);
}
unsigned long menu(void) {
  my_lcd.Set_Draw_color(255, 0, 0);
  my_lcd.Fill_Rectangle(0, 0, my_lcd.Get_Display_Width() - 1, 20);
  my_lcd.Set_Draw_color(0, 0, 0);
  my_lcd.Draw_Rectangle(0, 0, my_lcd.Get_Display_Width() - 1, 19);
  my_lcd.Set_Text_colour(255, 255, 255);  //text on top
  my_lcd.Set_Text_Size(1.9);
  my_lcd.Set_Text_Mode(1);
  my_lcd.Print_String("WIRE CUTTING MACHINE", CENTER, 6);
  my_lcd.Set_Draw_color(255, 255, 255);
  my_lcd.Fill_Rectangle(0, 20, my_lcd.Get_Display_Width() - 1, my_lcd.Get_Display_Height() - 1);

  my_lcd.Set_Draw_color(255, 240, 0);
  my_lcd.Fill_Rectangle(10, 40, 30, 50);
  my_lcd.Fill_Rectangle(40, 40, 120, 50);
  my_lcd.Fill_Rectangle(130, 40, 150, 50);
  my_lcd.Set_Draw_color(0, 0, 0);  //yellow part
  my_lcd.Draw_Rectangle(10, 40, 30, 50);
  my_lcd.Draw_Rectangle(40, 40, 120, 50);
  my_lcd.Draw_Rectangle(130, 40, 150, 50);

  my_lcd.Set_Draw_color(224, 141, 40);
  my_lcd.Fill_Rectangle(31, 42, 39, 48);  //copper part
  my_lcd.Fill_Rectangle(121, 42, 129, 48);

  my_lcd.Set_Draw_color(0, 0, 0);
  my_lcd.Draw_Line(10, 55, 10, 65);
  my_lcd.Draw_Line(30, 55, 30, 65);
  my_lcd.Draw_Line(40, 55, 40, 65);
  my_lcd.Draw_Line(120, 55, 120, 65);
  my_lcd.Draw_Line(130, 55, 130, 65);
  my_lcd.Draw_Line(150, 55, 150, 65);
  my_lcd.Draw_Line(10, 65, 30, 65);
  my_lcd.Draw_Line(40, 65, 120, 65);
  my_lcd.Draw_Line(130, 65, 150, 65);
  my_lcd.Set_Text_colour(0, 0, 0);  //black lines
  my_lcd.Set_Text_Size(1.8);
  my_lcd.Set_Text_Mode(1);
  my_lcd.Print_String("<", 9, 62);
  my_lcd.Print_String("<", 39, 62);
  my_lcd.Print_String("<", 129, 62);
  my_lcd.Print_String(">", 26, 62);
  my_lcd.Print_String(">", 116, 62);
  my_lcd.Print_String(">", 146, 62);

  my_lcd.Set_Draw_color(255, 255, 150);
  my_lcd.Fill_Rectangle(5, 70, 35, 85);
  my_lcd.Fill_Rectangle(50, 70, 110, 85);
  my_lcd.Fill_Rectangle(125, 70, 155, 85);
  my_lcd.Set_Draw_color(0, 0, 0);  //text box
  my_lcd.Draw_Rectangle(10, 40, 30, 50);
  my_lcd.Draw_Rectangle(40, 40, 120, 50);
  my_lcd.Draw_Rectangle(130, 40, 150, 50);
  my_lcd.Set_Text_colour(0, 0, 0);
  my_lcd.Set_Text_Size(1.9);
  my_lcd.Set_Text_Mode(1);
  my_lcd.Print_String("mm", 9, 90);

  my_lcd.Print_String("NUMBER OF WIRES", 9, 110);
  my_lcd.Set_Draw_color(255, 255, 150);
  my_lcd.Fill_Rectangle(110, 105, 140, 120);


  // delay(5000);
}

unsigned long keypadd(void) {
  while (1) {
    //   char Key = customKeypad.getKey();
    char x = 'k';
    int t = 5;
    my_lcd.Set_Text_colour(0, 0, 0);
    my_lcd.Set_Text_Size(1.8);
    my_lcd.Set_Text_Mode(1);
    //    my_lcd.Draw_Char(5,30,Key,1,1,1,0);
  }
}
int number(int x, int y) {
  int num = 0;

  //  char Key = customKeypad.getKey();
  //  num = (num*10)+(Key-'0');
  my_lcd.Set_Text_colour(210, 210, 210);
  my_lcd.Set_Text_Size(1.8);
  my_lcd.Set_Text_Mode(1);
  my_lcd.Print_Number_Int(num, x, y, 1, ' ', 10);
}

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(stepdir, OUTPUT);
  pinMode(cutPin, OUTPUT);
  pinMode(cutdir, OUTPUT);
  Serial.begin(9600);
  my_lcd.Init_LCD();
  my_lcd.Fill_Screen(0x0);
  my_lcd.Set_Rotation(1);
}

void loop() {
 // digitalWrite(cutdir, LOW);
  //digitalWrite(cutPin, LOW);
show_start();
again1:
  menu();

  while (1) {

    char key = keypad.getKey();

    if (key && key != '>' && key != '<') {
      num1 = (num1 * 10) + (key - '0');  //num1
      my_lcd.Set_Text_colour(0, 0, 0);
      my_lcd.Set_Text_Size(1.8);
      my_lcd.Set_Text_Mode(1);
      my_lcd.Print_Number_Int(num1, 10, 74, 1, ' ', 10);
    }
    if (key == '>') break;
    if (key == '<') {
      num1 = 0;
      num2 = 0;
      num3 = 0;
      num4 = 0;
      goto again1;
    }
  }

  while (1) {

    char key = keypad.getKey();

    if (key && key != '>' && key != '<') {
      num2 = (num2 * 10) + (key - '0');  //num2
      my_lcd.Set_Text_colour(0, 0, 0);
      my_lcd.Set_Text_Size(1.8);
      my_lcd.Set_Text_Mode(1);
      my_lcd.Print_Number_Int(num2, 55, 74, 1, ' ', 10);
    }
    if (key == '>') break;
    if (key == '<') {
      num1 = 0;
      num2 = 0;
      num3 = 0;
      num4 = 0;
      goto again1;
    }
  }

  while (1) {

    char key = keypad.getKey();

    if (key && key != '>' && key != '<') {
      num3 = (num3 * 10) + (key - '0');
      my_lcd.Set_Text_colour(0, 0, 0);  //num3
      my_lcd.Set_Text_Size(1.8);
      my_lcd.Set_Text_Mode(1);
      my_lcd.Print_Number_Int(num3, 130, 74, 1, ' ', 10);
    }
    if (key == '>') break;
    if (key == '<') {
      num1 = 0;
      num2 = 0;
      num3 = 0;
      num4 = 0;
      goto again1;
    }
  }

  while (1) {
    char key = keypad.getKey();

    if (key && key != '>' && key != '<') {
      num4 = (num4 * 10) + (key - '0');
      my_lcd.Set_Text_colour(0, 0, 0);  //num4
      my_lcd.Set_Text_Size(1.8);
      my_lcd.Set_Text_Mode(1);
      my_lcd.Print_Number_Int(num4, 115, 109, 1, ' ', 10);
    }
    if (key == '>') break;
    if (key == '<') {
      num1 = 0;
      num2 = 0;
      num3 = 0;
      num4 = 0;
      goto again1;
    }
  }

  digitalWrite(stepdir, LOW);

  for (int x = 0; x < num4; x++) {

    if (x == 0) {
      delay(1000);
      digitalWrite(cutdir, LOW);
      for (int y = 0; y < 25; y++) {
        digitalWrite(cutPin, HIGH);
        delayMicroseconds(3000);
        digitalWrite(cutPin, LOW);
        delayMicroseconds(3000);
      }
      delay(500);
      digitalWrite(cutdir, HIGH);
      for (int y = 0; y < 25; y++) {
        digitalWrite(cutPin, HIGH);
        delayMicroseconds(3000);
        digitalWrite(cutPin, LOW);
        delayMicroseconds(3000);
      }
      delay(1000);
    }

    for (int x = 0; x < floor((num1 * 621) / 100); x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(3000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(3000);
    }
    delay(200);
    digitalWrite(cutdir, LOW);
    for (int y = 0; y < 25; y++) {
      digitalWrite(cutPin, HIGH);
      delayMicroseconds(3000);
      digitalWrite(cutPin, LOW);
      delayMicroseconds(3000);
    }
    delay(200);
    digitalWrite(cutdir, HIGH);
    for (int y = 0; y < 25; y++) {
      digitalWrite(cutPin, HIGH);
      delayMicroseconds(3000);
      digitalWrite(cutPin, LOW);
      delayMicroseconds(3000);
    }
    delay(200);


    for (int x = 0; x < floor((num2 * 621) / 100); x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(3000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(3000);
    }

    delay(200);
    digitalWrite(cutdir, LOW);
    for (int x = 0; x < 25; x++) {
      digitalWrite(cutPin, HIGH);
      delayMicroseconds(5000);
      digitalWrite(cutPin, LOW);
      delayMicroseconds(5000);
    }
    delay(200);
    digitalWrite(cutdir, HIGH);
    for (int x = 0; x < 25; x++) {
      digitalWrite(cutPin, HIGH);
      delayMicroseconds(5000);
      digitalWrite(cutPin, LOW);
      delayMicroseconds(5000);
    }
    delay(200);

    for (int x = 0; x < floor((num3 * 621) / 100); x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(3000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(3000);
    }
    delay(200);
    digitalWrite(cutdir, LOW);
    for (int x = 0; x < 25; x++) {
      digitalWrite(cutPin, HIGH);
      delayMicroseconds(5000);
      digitalWrite(cutPin, LOW);
      delayMicroseconds(5000);
    }
    delay(200);
    digitalWrite(cutdir, HIGH);
    for (int x = 0; x < 25; x++) {
      digitalWrite(cutPin, HIGH);
      delayMicroseconds(5000);
      digitalWrite(cutPin, LOW);
      delayMicroseconds(5000);
    }
    delay(200);
  }
}