//Name:Myat Bhone Ko
//Adm:2539052
//Class:DCEP/FT/1A/04

//Name:Zheng Zhe Ming Jayvis
//Adm:2517155
//Class:DCEP/FT/1A/04

//The temperature and humidity senor are used to moniter the plant and depending on it, the led green will be shown, if water is not needed, and, led red will be shown if water is needed.
#include <Wire.h>
#include "RichShieldTM1637.h"
#include "RichShieldKnob.h"

// Correct pins — make sure they match your wiring
#define KNOB_PIN A0
#define CLK 10     // CLK of TM1637
#define DIO 11     // DIO of TM1637
#define BUTTON_PIN 9
#define BLUE_LED 6

Knob knob(KNOB_PIN);
TM1637 disp(CLK, DIO);

bool buttonPressed = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 80;
#define LDR_SENSOR A2
#define HUMIDITY_SENSOR A1

#define GREEN_LED 5
#define BLUE_LED 6
#define YELLOW_LED 7
#define BUZZER 3

#include <Wire.h>
#include "RichShieldPassiveBuzzer.h"

PassiveBuzzer buz(BUZZER);
void waterplant();
void setup() {
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
 Serial.begin(9600);
  disp.init();
  disp.set(7); // Brightness (0–7)

  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
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
 waterplant();
  } else {
    digitalWrite(BLUE_LED, LOW);
   
    digitalWrite(GREEN_LED, HIGH);
  }

  delay(500);
  
  digitalWrite(GREEN_LED, LOW);
}

void waterplant()
{
  static int displayValue = 0;

  // Read knob and map to 0–200 range
  int knobValue = knob.getAngle();
  displayValue = map(knobValue, 0, 1023, 0, 200);
  disp.display(displayValue*10); // Show on 7-segment
  Serial.println(displayValue);

  // Read button state with debounce
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && !buttonPressed && (millis() - lastDebounceTime) > debounceDelay) {
    buttonPressed = true;
    lastDebounceTime = millis();

    // Reset display and show 0
    displayValue = 0;
    disp.display(displayValue);

    // Flash blue LED for 3 seconds (6 x 500ms)
    for (int i = 0; i < 6; i++) {
      digitalWrite(BLUE_LED, HIGH);
      delay(300);
      digitalWrite(BLUE_LED, LOW);
      delay(300);
    }
  }

  // Reset buttonPressed flag after button is released
  if (buttonState == HIGH && buttonPressed) {
    buttonPressed = false;
  }

  delay(500); // Small delay for display update
}
