
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  4;      // the number of the LED pin
int i=40;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == 1 &&  i==40) {
    // turn LED on:
    
    digitalWrite(4, HIGH);
    delay(200);
    Serial.println("ONNNN");
    Serial.println(i);
    digitalWrite(4,LOW);
    i++;
    Serial.println(i);
  } 
}
