int pinButton = 8; //the pin where we connect the button
int LED = 2; //the pin we connect the LED


void setup() {
  Serial.begin(9600);
  pinMode(pinButton, INPUT); //set the button pin as INPUT
  pinMode(LED, OUTPUT); //set the LED pin as OUTPUT
}

void loop() {
  int stateButton = digitalRead(pinButton); //read the state of the button
  if(stateButton == 0) { //if is pressed
     digitalWrite(LED, HIGH); //write 1 or HIGH to led pin
   
     Serial.println("LED ON");
  } 
}
