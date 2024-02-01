#include <Adafruit_LiquidCrystal.h>
// C++ code
//


#define temp A0
#define heater 5
#define fan 3

float val=0;
Adafruit_LiquidCrystal lcd(0);
void setup()
{
  lcd.begin(16,2);
  lcd.setBacklight(1);
  lcd.print("Temp ");
  
  pinMode(temp, INPUT);
  pinMode(heater, OUTPUT);
  pinMode(fan, OUTPUT);
}

void loop()
{
  
  val = analogRead(temp);
  
  val=map(val,102,358,0,125);
  lcd.setCursor(0,0);
  lcd.print("Temp in C = ");
  lcd.print(val);
  delay(1000);
  
  while(val>24)
  {
    val = analogRead(temp);
    val=map(val,102,358,0,125);
    lcd.setCursor(0,1);
    analogWrite(fan, val );
    lcd.print("FAN: ON");
    lcd.setCursor(0,0);
    lcd.print("Temp in C = ");
    lcd.print(val);
	
    
  }
   
  while(val<20) 
  {
    val = analogRead(temp);
    val=map(val,102,358,0,125);
    lcd.setCursor(0,1);
    analogWrite(heater, val);
    lcd.print("ISITICI: ON");
    lcd.setCursor(0,0);
    lcd.print("Temp in C = ");
    lcd.print(val);
    
    
  }
  
  lcd.clear();


}