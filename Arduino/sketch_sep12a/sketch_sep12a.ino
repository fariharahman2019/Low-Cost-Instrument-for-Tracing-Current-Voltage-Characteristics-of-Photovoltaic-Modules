#include<LiquidCrystal.h>

LiquidCrystal lcd(11,10,5,4,3,2);

const int currentPin = A0;
const int currentPin1 = A1;
int sensitivity = 66;
int adcValue= 0;
double adcV=0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double adcVoltage2 = 0;
double currentValue = 0;
float a=2;
float b=0; 
void setup() 
{ 
  Serial.begin(9600);
  Serial.println("IV Charecteristics");
  lcd.begin(16,2);
}
 
void loop()
{  
  adcValue = analogRead(currentPin); // 0-1024
  adcVoltage = (adcValue / 1024.0) * 5000; 
  adcV = analogRead(currentPin1);
  adcVoltage2 = (adcV / 1024.0) * 12;
  currentValue = ( (adcVoltage - offsetVoltage) / sensitivity );
  int loadvoltage = currentValue * 12;

  lcd.print(adcVoltage2); 
  lcd.setCursor(0,1);
  lcd.print(currentValue);
  lcd.setCursor(0,0);

  delay(400);
  Serial.println(adcVoltage2);
  Serial.println(currentValue);

}
