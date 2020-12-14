/*
Project Part 1
Robert Perrone
Computer Org & Arch
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11, 7, 8, 9, 10);
const int button1 = 3;
const int button2 = 4;
const int contrastPin = 6;

int screenNum = 0;

int buttonState1 = 0;
int buttonState2 = 0;

int prevButtonState1 = 0;
int prevButtonState2 = 0;

int cursorColumn = 0;
int cursorRow = 1;
  
//byte 1
byte byte1 = 00000000;
//byte 2
byte byte2 = 00000000;
//Solution byte
byte solution = 00000000;
//Contrast Value
int contrastVal = 50;

void setup() {
  lcd.begin(16,2);
  analogWrite(contrastPin, contrastVal);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  lcd.print("Hello User!");
  lcd.setCursor(0,1);
  lcd.print("ALU Ready!");
  //Begin Serial  
  Serial.begin(9600);
}

void loop() {
  Serial.print("screenNum:");
  Serial.println(screenNum);
  Serial.print("buttonState1:");
  Serial.println(buttonState1);
  Serial.print("buttonState2:");
  Serial.println(buttonState2);
  
  //Read button state (see if button is pressed)
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  //delay(50);
    //if both buttons are pushed at the same time progress to the next screen
    if((prevButtonState1 != buttonState1) && (prevButtonState2!= buttonState2)){
      if ((buttonState1 == HIGH) && (buttonState2 == HIGH)){
        screenNum = screenNum + 1;
        lcd.clear();
        if ((screenNum > 4)){
          lcd.clear();
          screenNum = 1;
        }
        cursorColumn = 0;
        switch (screenNum){
          case 1:
            lcd.print("Byte 1:");
            lcd.setCursor(cursorColumn,cursorRow);
            for(int i=0; i<=8; i++){
              lcd.print(byte1, BIN);
            }
            break;
          case 2:
            lcd.print("Byte 2:");
            lcd.setCursor(cursorColumn,cursorRow);
            for(int i=0; i<=8; i++){
              lcd.print(byte1,BIN);
            }
            break;
          case 3:
            lcd.print("Solution:");
            lcd.setCursor(0,1);
            for(int i=0; i<=8; i++){
              lcd.print(solution, BIN);
            }
            break;
          case 4:
            lcd.print("Contrast:");
            lcd.setCursor(0,1);
            lcd.print(contrastVal);
            break;
        }
      }
    }
    //Byte 1 & 2 screens controls
    if((screenNum == 1) || (screenNum == 2)){
      lcd.setCursor(cursorColumn, cursorRow);
      lcd.cursor();
      lcd.blink();
      //Change bit from 0 to 1 or 1 to 0
      if(prevButtonState1 != buttonState1){
        if ((buttonState1 == HIGH) && (buttonState2 == LOW)){
          
        }
      }
      //Move to next
      if(prevButtonState2 != buttonState2){
        if ((buttonState2 == HIGH) && (buttonState1 == LOW)){
          cursorColumn = cursorColumn + 1;
          if (cursorColumn == 9){cursorColumn=0;}
          lcd.setCursor(cursorColumn, cursorRow);
        }
      }
    }
    //Solution screen display
    if(screenNum == 3){
      lcd.noBlink();
      solution = byte1 + byte2;
      lcd.setCursor(0,1);
      for(int i=0; i<=sizeof(solution); i++){
        lcd.print(solution, BIN);
      }
      lcd.noCursor();
    }

    //Contrast screen controls
    if(screenNum == 4){
      if(prevButtonState1 != buttonState1){
        if ((buttonState1 == HIGH) && (buttonState2 == LOW)){
          lcd.clear();
          lcd.print("Contrast:");
          lcd.setCursor(0,1);
          lcd.print(contrastVal);
          if(contrastVal == 0){}
          else{
            contrastVal = contrastVal - 5;
            analogWrite(contrastPin, contrastVal);
          }
        }
      }
      if(prevButtonState2 != buttonState2){
        if ((buttonState2 == HIGH) && (buttonState1 == LOW)){
          lcd.clear();
          lcd.print("Contrast:");
          lcd.setCursor(0,1);
          lcd.print(contrastVal);
          if(contrastVal == 100){}
          else{
            contrastVal = contrastVal + 5;
            analogWrite(contrastPin, contrastVal);
          }
        }
      }
    }
  prevButtonState1 = buttonState1;
  prevButtonState2 = buttonState2;
}
