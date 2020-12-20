#include<SoftwareSerial.h>
char* tag[12]={"0700105896D9"};

SoftwareSerial myserial(3,4);
int read_count=0, tag_count =0;
int j=0,k=0;
char data_temp,RFID_data[12];

void setup(){
  myserial.begin(9600);
  Serial.begin(9600);
}

void loop(){
if(myserial.available() > 0){

  data_temp=myserial.read();
  RFID_data[read_count]= data_temp;
  read_count++;
  if(read_count==12){
    for(k=tag_count;k<=tag_count;k++)
    {
      for(j=0;j<12;j++){
        Serial.write(RFID_data[j]);
        if(tag[0] != RFID_data[j]){
          Serial.println("FOUND");
        }
        
      }
    }
    read_count=0;tag_count++;
    delay(1000);
  }
}
}
