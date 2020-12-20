int count = 0;
//0600E2264B89
char* a ={"0600E2264B89"};
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available())
  {
    count = 0; // Reset count to zero// Keep reading Byte by Byte from the Buffer till the Buffer is empty
    {
      char input = Serial.read();
      Serial.print(input);
      char* b ={input};
   //   count++; //
      delay(5); //
      if (a == input){
        Serial.println("FOUND");
      }else{Serial.println("NOT");}
    }
   
   
   
  }
}
