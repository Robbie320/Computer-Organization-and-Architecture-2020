/*
Robert Perrone
Computer Organization and Architecture
*/
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int sensorPin = A0;
const int redSensorPin = A0;
const int blueSensorPin = A0;

//const float baselineTemp = 20.0;
int sensorVal;
float baselineVoltage;
float baselineTemp;
float maxTemp;

int redValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int blueSensorValue = 0;

float tempArray[5] = {0,0,0,0,0};

void setup(){
    Serial.begin(9600); //open a serial port
    
    sensorVal = analogRead(sensorPin);
    baselineVoltage = (sensorVal/1024.0) * 5.0; //convert ADC reading to voltage
    baselineTemp = (baselineVoltage - 0.5) * 100 ; // Converting to degrees
    
    maxTemp = baselineTemp + 6.0;
    
    Serial.println("");
    Serial.print("Baseline Temperature in Celcius: ");
    Serial.println(baselineTemp);
    Serial.print("Max Temperature in Celcius: ");
    Serial.println(maxTemp);
    
    pinMode(redLEDPin,OUTPUT);
    pinMode(blueLEDPin,OUTPUT);
}

void loop(){
  int counter = 0;
  int sum = 0;
  while (0<=counter<5){
    redSensorValue = analogRead(redSensorPin);
    blueSensorValue = analogRead(blueSensorPin);
    
    Serial.print("Sensor Value: ");
    Serial.println(sensorVal);
    
    float redVoltage = (redSensorValue/1024.0) * 5.0; //convert ADC reading to voltage
    float blueVoltage = (blueSensorValue/1024.0) * 5.0; //convert ADC reading to voltage
    
    Serial.print("Voltage: ");
    Serial.println(baselineVoltage);
    
    float redTemp = (redVoltage - 0.5) * 100 ; // Converting to degrees
    float blueTemp = (blueVoltage - 0.5) * 100; //Converting to degrees
    
    float temp = (redTemp + blueTemp)/2; //avg of blue and red temp readings
    
    Serial.print("tempArray:{");
      tempArray[counter] = temp;
      Serial.print(tempArray[counter]);
      Serial.print(",");
      sum += tempArray[counter];
      counter = counter++
    Serial.println("}");
    
    float tempAvg = sum/5;
    Serial.print("Temperature Average: ");
    Serial.println(tempAvg);
    
    redValue = map(tempAvg, baselineTemp, maxTemp, 0, 255);
    blueValue = 255 - redValue;
    
    Serial.println("LED Values:");
    Serial.print("Red: ");
    Serial.println(redValue);
    Serial.print("Blue: ");
    Serial.println(blueValue);
    
    if (tempAvg <= baselineTemp){
      redValue = 0;
      blueValue = 255;
    }
    else if (tempAvg >= maxTemp){
      redValue = 255;
      blueValue = 0;
    }
    
    //redValue = redSensorValue/4;
    //blueValue = blueSensorValue/4;
    
    analogWrite(redLEDPin, redValue);
    analogWrite(blueLEDPin, blueValue);
    delay(250);
  }
}
