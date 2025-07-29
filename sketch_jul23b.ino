//Name:Myat Bhone Ko
//Adm:2539052
//Class:DCEP/FT/1A/04

//Name:Zheng Zhe Ming Jayvis
//Adm:2517155
//Class:DCEP/FT/1A/04

//The temperature and humidity senor are used to moniter the plant and depending on it, the led green will be shown, if water is not needed, and, led red will be shown if water is needed.

using namespace std;



void setup() {
  // put your setup code here, to run once:
disp.init();  
	dht.begin();
}

void loop() {// Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    displayError();
  } 
  else{
    displayTemperature((int8_t)t);//
    delay(3000);
    displayHumidity((int8_t)h);//
    delay(2000);
  

}
