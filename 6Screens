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
int contrastValue = 50;

int screenNum = -1;

int buttonState1 = 0;
int buttonState2 = 0;

int prevButtonState1 = 0;
int prevButtonState2 = 0;

void setup() {
  lcd.begin(16,2);
  analogWrite(contrastPin, contrastValue);
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
    //if both buttons are pushed at the same time
    if((prevButtonState1 != buttonState1) && (prevButtonState2!= buttonState2)){
      if ((buttonState1 == HIGH) && (buttonState2 == HIGH)){
        if ((screenNum == -1)|| (screenNum == 1) || (screenNum == 3) || (screenNum == 5)){
          screenNum = screenNum + 2;
          lcd.clear();
        }
        else if ((screenNum == 2) || (screenNum == 4) || (screenNum == 6)){
          screenNum = screenNum - 1;
          lcd.clear();
        }
        if ((screenNum > 6)){
          lcd.clear();
          screenNum = 1;
        }
        switch (screenNum){
          case 1:
            lcd.print("Screen 1");
            break;
          
          case 3:
            lcd.print("Screen 3");
            break;
          
          case 5:
            lcd.print("Screen 5");
            break;
        }
      }
    }
    if((screenNum == 1) || (screenNum == 3) || (screenNum == 5)){
      if(prevButtonState2 != buttonState2){
        if ((buttonState2 == HIGH) && (buttonState1 == LOW)){
          screenNum = screenNum +1;
          lcd.clear();
          if(screenNum > 6){
            lcd.clear();
            screenNum = 6;
          }
          switch (screenNum){
            case 2:
              lcd.print("Screen 2");
              break;
            
            case 4:
              lcd.print("Screen 4");
              break;
            
            case 6:
              lcd.print("Screen 6");
              break;
          }
        }
      }
    }
    if((screenNum == 2) || (screenNum == 4) || (screenNum == 6)){
      if(prevButtonState1 != buttonState1){
        if ((buttonState1 == HIGH) && (buttonState2 == LOW)){
          
        }
      }
      if(prevButtonState2 != buttonState2){
        if ((buttonState2 == HIGH) && (buttonState1 == LOW)){
          
        }
      }
    }
  prevButtonState1 = buttonState1;
  prevButtonState2 = buttonState2;
}
