/**
 * 09/2017 Test LCD on NodeMCU
 * 
 * I2C Backpack | NodeMCU
 * SCL          | D1
 * SDA          | D2
 * VCC          | VU
 * GND          | G
 * 
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
long count = 1;

/**
 * 
 */
void setup()
{
  Wire.begin( D2 /*sda*/, D1 /*scl*/); // defaults on Nodecu are: SDA=D2, SCL=D1
    
  lcd.begin(16,2); // Should match the number provided to the constructor.
  lcd.init();
  lcd.backlight(); // Turn on the backlight.
}


/**
 * 
 */
void loop() 
{
  lcd.setCursor(5, 0);
  lcd.print("Hello ");
  lcd.setCursor(5, 1);      
  lcd.print(String("World ") + count++);
  
  delay(5000);
}



