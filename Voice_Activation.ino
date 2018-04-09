//WIFI STUFF
//const char* ssid =     "my ssid";       //This is where you put in your home network's SSID to connect to
//const char* password = "my password";   //This is where you put in your home network's password

//Might need for json btc price extraction
//const String url = "http://api.coindesk.com/v1/bpi/currentprice.json";

void bitcoin() {
  const char* host = "api.coindesk.com";
  WiFiClient client;
  const int httpPort = 80;
  
  if (!client.connect(host,httpPort)){
    
   Serial.println("Can't connect to server");
    return;
    
  }
  
  string url = "v1/bpi/currentprice.json";
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
  "Host: " + host + "\r\n" +
  "Connection: close\r\n\r\n");
  
  //Reading the answer
  
  String answer;
  while (client.available()){
   String line = client.readStringUntil('\r');
    answer += line;
    
  }
  
  client.stop();
  Serial.println();
  Serial.println("Connection Closed");
  
}


String voice;
int led13 = 13;
//Might be needed for extracting prices from api
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
void setup() {
  Serial.println("Initializing...");
  Serial.begin(115200);
  pinMode(led13, OUTPUT);
}
//-----------------------------------------------------------------------//  
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    //Serial.println("Voice detected!");
    Serial.println(voice); 
//-----------------------------------------------------------------------//    
  if (voice == "on") {digitalWrite(led13, HIGH);}
    
  if (voice == "bitcoin price") {
    
    //call function
    //get price of btc using coindesk API
    //https://api.coindesk.com/v1/bpi/currentprice/BTC.json
  }
    
    if (voice == "ethereum price") {
    
    //call function
      
    //get price of ETH using coinmarketcap API
    //https://api.coinmarketcap.com/v1/ticker/ethereum/
    
  }  
    
  
  else if(voice == "off") {digitalWrite(led13, LOW);}
//-----------------------------------------------------------------------//  
voice="";}} //Reset the variable after initiating
