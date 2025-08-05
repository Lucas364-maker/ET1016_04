//Name:Myat Bhone Ko
//Adm:2539052
//Class:DCEP/FT/1A/04

//Name:Zheng Zhe Ming Jayvis
//Adm:2517155
//Class:DCEP/FT/1A/04

//The temperature and humidity senor are used to moniter the plant and depending on it, the led green will be shown, if water is not needed, and, led red will be shown if water is needed.
#define LDR_SENSOR A2
#define HUMIDITY_SENSOR A1

#define GREEN_LED 5
#define BLUE_LED 6
#define YELLOW_LED 7
#define BUZZER 3

#include <Wire.h>
#include "RichShieldPassiveBuzzer.h"

PassiveBuzzer buz(BUZZER);

void setup() {
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  checkLight();
  checkHumidity();
  delay(1000); 
}



void checkLight() {
  int lightVal = analogRead(LDR_SENSOR);
  float lightPercent = (lightVal / 1023.0) * 100;

  Serial.print("Light: ");
  Serial.print(lightPercent);
  Serial.println(" %");

  if (lightPercent < 75.0) {
    
    digitalWrite(YELLOW_LED, HIGH);
    buz.playTone(1000, 200); 
  delay(300);              

  
  buz.playTone(1200, 200);
  delay(1000);   
    delay(100);
    digitalWrite(YELLOW_LED, LOW);
  } else {
    
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(BUZZER, LOW);
    delay(1000);
    digitalWrite(YELLOW_LED, LOW);
  }
}

void checkHumidity() {
  int humidityVal = analogRead(HUMIDITY_SENSOR);
  float humidityPercent = (humidityVal / 1023.0) * 100;

  Serial.print("Humidity: ");
  Serial.print(humidityPercent);
  Serial.println(" %");

  if (humidityPercent < 70.0) {
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
 
  } else {
    digitalWrite(BLUE_LED, LOW);
   
    digitalWrite(GREEN_LED, HIGH);
  }

  delay(500);
  
  digitalWrite(GREEN_LED, LOW);
}
