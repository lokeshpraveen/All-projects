const int bp = 2;
const int rl = 4;
int i=40;
int bs = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(rl,OUTPUT);
pinMode(bp,INPUT);
digitalWrite(4,HIGH);

}

void loop() {

bs = digitalRead(bp);
Serial.println(bp);
if(bs == 1 && i==40){
  digitalWrite(4,LOW);
  delay(400);
  digitalWrite(4,HIGH);
  Serial.println("ONNN");
  i++;
  
}

}
