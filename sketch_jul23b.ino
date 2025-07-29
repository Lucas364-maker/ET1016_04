//Name:Myat Bhone Ko
//Adm:2539052
//Class:DCEP/FT/1A/04

//Name:Zheng Zhe Ming Jayvis
//Adm:2517155
//Class:DCEP/FT/1A/04

//The temperature and humidity senor are used to moniter the plant and depending on it, the led green will be shown, if water is not needed, and, led red will be shown if water is needed.
#define BLUE_LED 6
#define BLUE_BUTTON 9
void Bluebutton();

void setup() {
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BLUE_BUTTON, INPUT);
}

void loop() {
  Bluebutton();
}

// Function to check button and control LED
void Bluebutton() {
  int buttonState = digitalRead(BLUE_BUTTON);
  
  if (buttonState == HIGH) {
    digitalWrite(BLUE_LED, HIGH); // LED ON
  } else {
    digitalWrite(BLUE_LED, LOW);  // LED OFF
  }
}
