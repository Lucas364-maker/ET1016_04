//Name:Myat Bhone Ko
//Adm:2539052
//Class:DCEP/FT/1A/04

//Name:Zheng Zhe Ming Jayvis
//Adm:2517155
//Class:DCEP/FT/1A/04

//The temperature and humidity senor are used to moniter the plant and depending on it, the led green will be shown, if water is not needed, and, led red will be shown if water is needed.
#define blue 6
#define blue_B 9

using namespace std;
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(blue, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(blue_B, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  blue_B = digitalRead(blue_B);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (blue_B == HIGH) {
    // turn LED on:
    digitalWrite(blue, HIGH);
  } else {
    // turn LED off:
    digitalWrite(blue, LOW);
  }
}
