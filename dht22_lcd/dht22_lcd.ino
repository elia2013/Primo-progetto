#include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>

#define pinsens  10
#define pinLED1 9
#define pinLED2 14

LiquidCrystal_I2C lcd(0x27, 2, 16);
SimpleDHT22 dht22(pinsens);


 float temp = 0;
  float umid = 0;
void setup() {
  Serial.begin(9600);
  lcd.backlight();
  lcd.init();
  lcd.init();

  pinMode(pinLED1, OUTPUT);
    pinMode(pinLED2, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
dht22.read2(&temp,&umid, NULL);
lcd.setCursor(0,0);
lcd.print("temp: ");
lcd.println(temp);
lcd.setCursor(0,1);
lcd.print("umid: ");
lcd.println(umid);

if(temp >= 30.00){
analogWrite(pinLED1,255);
  analogWrite(pinLED2,0);
}else{
  analogWrite(pinLED2,255);
  analogWrite(pinLED1,0);
}
delay(1000);
  // put your main code here, to run repeatedly:

}
