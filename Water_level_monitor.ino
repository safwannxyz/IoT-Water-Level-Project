#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
int trig=D4;
int echo=D5;
int buzzer=D3;
void setup(){
Serial.begin(9600);
Wire.begin(D2,D1);
lcd.init();
lcd.begin(16, 2);
 pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);  
  pinMode(buzzer,OUTPUT);
lcd.home();
lcd.backlight(); 
delay(10);
}
void loop(){
  digitalWrite(trig,0);
  delayMicroseconds(1);
  digitalWrite(trig,1);
  delayMicroseconds(1);
  digitalWrite(trig,0);
  float duration=pulseIn(echo,1);
  duration=duration/2;
  float distance=(0.034)*(duration/2);
  Serial.println(distance);
  if(distance<5) {
    digitalWrite(buzzer,1);
    Serial.println("Full");
    lcd.print("Full");
    delay(500);
    lcd.clear();
      } 
      else{
        digitalWrite(buzzer,0);
        Serial.println("Empty");
        lcd.print("Empty");
        delay(500);
        lcd.clear();
      }
  delay(50);
}

