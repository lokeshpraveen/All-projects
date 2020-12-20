#include <Wire.h>
#include <Adafruit_SH1106.h>

#include <Adafruit_MLX90614.h>

#include <Adafruit_GFX.h>

#define OLED_WIDTH 128
#define OLED_HEIGHT 64

#define OLED_ADDR   0x3C
#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int IRSensor = 2;


void setup() {
  pinMode(5, OUTPUT);
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode(6, OUTPUT);
  Serial.begin(9600);

  Serial.println("TEMP : ");

  mlx.begin();
  display.begin(SH1106_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Sona Tech.");

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.println("Temp.Check");


  display.display();

  delay(3000);
}

void loop() {
  int statusSensor = digitalRead (IRSensor);
  int temp = mlx.readObjectTempF() + 8;
  display.clearDisplay();

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(3, 10);
  display.println("Stand.......");
  display.display();

  if (statusSensor == 1) {
    digitalWrite(5, HIGH);
  }
  else {
    Serial.println("on");
    digitalWrite(5, HIGH);
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Temp.");
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 25);
    display.print(temp); display.print(" * F");

    display.display();
    if (mlx.readObjectTempF() >= 101) {
      tone(6, 300);
      delay(3000);
      noTone(6);
    } else {
      noTone(6);
    }
    delay(5000);

  }
}
