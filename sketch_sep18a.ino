// code uses work from tronixstuff.com
#include <LiquidCrystal.h> // we need this library for the LCD commands
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4,5,6,7,8,9); // LCD pins in use
 
int a = 63;
int delaytime1 = 3000; // used for display delayfloat
float b = 3.1415926;
 
void setup()
{
  lcd.begin(16, 2); // LCD column and row QTY
  lcd.clear();      // LCD clear
}
 
void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  // start point LCD column 0 row 0
  lcd.print("Dicks out");
  // prints "Hello" at the LCD's cursor position defined above
  lcd.setCursor(0,1);
  // start point on LCD column 0 row 1
  lcd.println("for Harambe     ");
  delay(delaytime1);
}
