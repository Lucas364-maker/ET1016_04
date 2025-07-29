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
void Bluebutton(int x);


void setup() {
  // put your setup code here, to run once:
	pinMode(blue,OUTPUT);
	pinMode(blue_B,INPUT);
}

void loop() {// Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  
}

void Bluebutton(int x)
{
	
  if (x == HIGH) {
    // turn LED on:
    digitalWrite(blue, HIGH);
  } else {
    // turn LED off:
    digitalWrite(blue, LOW);
  }
}
