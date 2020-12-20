#include "HX711.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int smokeA0 = A1;
// Your threshold value
int sensorThres = 450;

HX711 scale(6, 5);
 
int rbutton = 7; // this button will be used to reset the scale to 0.
float weight;
float calibration_factor = 101525; // for me this vlaue works just perfect 419640
                
void setup() {
lcd.init(); 
  pinMode(8, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  pinMode(rbutton, INPUT_PULLUP); 
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("");
  lcd.setCursor(0,1);
  lcd.print("Weighing Scale");
  delay(3000);
  lcd.clear();
    
  
}

void loop() {
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
 
  weight = scale.get_units(7); 
 
  lcd.setCursor(0, 0);
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print(weight);
  lcd.print(" KG  ");
  delay(2000);
  lcd.clear();
  
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" KG");
  Serial.println();
  
 
  if ( digitalRead(rbutton) == LOW)
{
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
}
 
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
    lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(8, LOW);
    delay(3000);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Gas Leaked");
    
    
  }
  else
  {
    digitalWrite(8, HIGH);
    
  }
  delay(100);
}
