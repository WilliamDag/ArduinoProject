String voice;
int led13 = 13;

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
  if(voice == "on") {digitalWrite(led13, HIGH);}
  else if(voice == "off") {digitalWrite(led13, LOW);}
//-----------------------------------------------------------------------//  
voice="";}} //Reset the variable after initiating
