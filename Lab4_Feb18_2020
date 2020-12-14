/*
Lab 4
Robert Perrone
Computer Org & Arch
*/

//LEDs//
  const int switchPin = 9;
  unsigned long previousTime = 0;
  int switchState = 0;
  int prevSwitchState = 0;
  int led = 4;
  long interval = 2500;

//Song//
  float tempo = (612.24/2);
  //https://www.keyandpitch.com/tools/bpm-to-ms-calculator/
  //Tones
    float B2 = 123.5;
    //float C3 = 130.8;
    float D3 = 146.8;
    float Eb3 = 155.6;
    float E3 = 164.8;
    float F3 = 174.6;
    float G3 = 196.0;
    float Ab3 = 207.7;
    float An3 = 220.00;
    float Bb3 = 233.1;
    //float B3 = 246.9;
    float C4 = 261.6;
    float Cs4 = 277.2;
    /*float D4 = 293.7;
    float E4 = 329.6;
    float F4 = 349.2;*/
    float Fs4 = 370.0;
    /*float G4 = 392.0;
    float A4 = 440.0;
    float B4 = 493.9;
    float C5 = 523.3;
    float D5 = 554.4;*/
  
  //Note Lengths
    float sixteenth = (tempo/4);
    float eighth = (tempo/2);
    float dottedEighth = (eighth + eighth/2);
    float quarter = (tempo);
    float dottedQuarter = (tempo*1.5);
    float half = (tempo*2);
    float dottedHalf = (tempo*3);
    float whole = (tempo*4);
    
//Servo motor
  #include <Servo.h>
  Servo myServo;
  int pos=0;
  
void setup() {
  //LEDs 4=red, 5=green, 6=yellow, 7=blue
    for (int x=4; x<8; x++){
      pinMode(x,OUTPUT);
    }
    pinMode(switchPin,INPUT);
  //Speaker
    pinMode(8,OUTPUT);
  //Servo
    myServo.attach(10);
    myServo.write(pos);
  //Begin Serial  
    Serial.begin(9600);
}

void setTone(int pin, int note, int duration) {
  tone(pin, note, duration);
  delay(duration);
  noTone(pin);
}

void loop() {
    unsigned long currentTime = millis();
    int i = 0;
    if(currentTime - previousTime > interval){
      previousTime = currentTime;
      digitalWrite(led,HIGH);
      led++;
      if(led==8){
        i=1;
      }
    }
    switchState = digitalRead(switchPin);
    if(switchState != prevSwitchState){
      for(int x = 4; x<8; x++){
        digitalWrite(x,LOW);
      }
      led = 4;
      previousTime = currentTime;
    }
    prevSwitchState = switchState;
    

    while (i == 1){
    //Song "Good Ol' A Cappella"
    tempo = (612.24/2);
      //Turn off LEDs
      for(int x = 4; x<8; x++){
        digitalWrite(x,LOW);
      }
      //Measure 1
      digitalWrite(5,HIGH);
      setTone(8, G3, quarter);
      digitalWrite(5,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, Ab3, eighth);
      digitalWrite(5,LOW);
      
      digitalWrite(7,HIGH);
      setTone(8, C4, dottedQuarter);
      digitalWrite(7,LOW);
      
      digitalWrite(6,HIGH);
      setTone(8, Bb3, quarter);
      digitalWrite(6,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, quarter);
      digitalWrite(5,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, eighth);
      digitalWrite(5,LOW);
      
      digitalWrite(6,HIGH);
      setTone(8, Bb3, quarter);
      digitalWrite(6,LOW);
      
      digitalWrite(6,HIGH);
      setTone(8, Bb3, dottedQuarter);
      digitalWrite(6,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, quarter);
      digitalWrite(5,LOW);
      
      digitalWrite(6,HIGH);
      setTone(8, Bb3, quarter);
      digitalWrite(6,LOW);
      
      digitalWrite(7,HIGH);
      setTone(8, C4, quarter);
      digitalWrite(7,LOW);
      
      digitalWrite(6,HIGH);
      setTone(8, Bb3, quarter);
      digitalWrite(6,LOW);
      
      digitalWrite(6,HIGH);
      setTone(8, Bb3, quarter);
      digitalWrite(6,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, eighth);
      digitalWrite(5,LOW);
      
      digitalWrite(6,HIGH);
      setTone(8, Bb3, dottedQuarter);
      digitalWrite(6,LOW);
      
      //quarter rest
      delay(quarter);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, quarter);
      digitalWrite(5,LOW);
      
      digitalWrite(6,HIGH);
      setTone(8, Bb3, quarter);
      digitalWrite(6,LOW);
      
      digitalWrite(7,HIGH);
      setTone(8, C4, quarter);
      digitalWrite(7,LOW);
      
      digitalWrite(6,HIGH);
      setTone(8, Bb3, eighth);
      digitalWrite(6,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, eighth);
      digitalWrite(5,LOW);
      
      digitalWrite(6,HIGH);
      setTone(8, Bb3, quarter);
      digitalWrite(6,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, eighth);
      digitalWrite(5,LOW);
      
      digitalWrite(6,HIGH);
      setTone(8, Bb3, dottedQuarter);
      digitalWrite(6,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, quarter);
      digitalWrite(5,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, eighth);
      digitalWrite(5,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, eighth);
      digitalWrite(5,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, quarter);
      digitalWrite(5,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, eighth);
      digitalWrite(5,LOW);
      
      digitalWrite(5,HIGH);
      setTone(8, G3, dottedQuarter);
      digitalWrite(5,LOW);
      
      digitalWrite(4,HIGH);
      setTone(8, F3, quarter);
      digitalWrite(4,LOW);
      
      digitalWrite(4,HIGH);
      setTone(8, Eb3, eighth);
      digitalWrite(4,LOW);
      
      digitalWrite(4,HIGH);
      setTone(8, Eb3, dottedQuarter);
      digitalWrite(4,LOW);
      
      delay(whole);
      
    //Song "Movement" by Hozier
    tempo = 1090.91;//tempo in milliseconds 
      //Measure 1
      setTone(8, B2, eighth);
      setTone(8, An3, eighth);
      setTone(8, G3, (quarter*.6667));//Quarter note triplet
      setTone(8, F3, (quarter*.6667));//Quarter note triplet
      setTone(8, E3, (eighth*.33335));//eighth note triplet
      setTone(8, D3, (eighth*.33335));//eighth note triplet
      //Measure 2
      setTone(8, D3, dottedQuarter);
      setTone(8, E3, (eighth + half));
      //Measure 3
      delay(eighth);//eighth note rest
      setTone(8, B2, eighth);
      setTone(8, B2, eighth);
      setTone(8, An3, eighth);
      setTone(8, G3, eighth);
      setTone(8, F3, eighth);
      setTone(8, E3, eighth);
      setTone(8, D3, eighth);
      //Meaure 4
      setTone(8, D3, quarter);
      setTone(8, E3, quarter);
      setTone(8, B2, quarter);
      setTone(8, B2, eighth);
      setTone(8, F3, sixteenth);
      setTone(8, E3, (sixteenth + dottedQuarter));//tie into next measure
      //Measure 5
      setTone(8, An3, eighth);
      setTone(8, G3, (quarter*.6667));//Quarter note triplet
      setTone(8, F3, (quarter*.6667));
      setTone(8, E3, (quarter*.6667));
      //Measure 6
      setTone(8, D3, quarter);
      setTone(8, D3, sixteenth);
      //setTone(8, 
      
      
      i=2;
    }
    
    while (i == 2){
    //Turn Servo Motor
      for (pos = 0; pos < 360; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myServo.write(pos);              // tell servo to go to position in variable 'pos'
      }
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myServo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      
      //Turn off LEDs
      for(int x = 4; x<8; x++){
        digitalWrite(x,LOW);
      }
      led = 4;
      previousTime = currentTime;
      
      //reset values to restart cycle
      pos = 0;
      i=0;
    }
      
}
