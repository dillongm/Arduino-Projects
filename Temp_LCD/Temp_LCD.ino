/******************************************************************
SHT15 Example + LCD modification

Connections:
GND  -> A2
Vcc  -> A3
DATA -> A4
SCK  -> A5

******************************************************************************/
#include <SHT1X.h> //STH15 lib
#include <LiquidCrystal.h> // LCD lib
//variables for storing values
LiquidCrystal lcd(4,5,6,7,8,9); // LCD pins in use

float tempC = 0;
float tempF = 0;
float humidity = 0;

//Create an instance of the SHT1X sensor
SHT1x sht15(A4, A5);//Data, SCK

//declare output pins for powering the sensor
int power = A3;
int gnd = A2;

void setup()
{
  Serial.begin(9600); // Open serial connection to report values to host

  lcd.begin (16, 2); // LCD column by row size
  lcd.clear(); // Clears anything on LCD
  
  pinMode(power, OUTPUT);
  pinMode(gnd, OUTPUT);

  digitalWrite(power, HIGH);
  digitalWrite(gnd, LOW);
}
//-------------------------------------------------------------------------------------------
void loop()
{
  readSensor();
  printOut();
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);

    lcd.print("Temp= ");
    lcd.print(tempF);
    lcd.print("F");

  lcd.setCursor(0,1);

    lcd.print("Humidity= ");
    lcd.print(humidity);
    lcd.print("%");
    
  
}
//-------------------------------------------------------------------------------------------
void readSensor()
{
  // Read values from the sensor
  tempC = sht15.readTemperatureC();
  tempF = sht15.readTemperatureF();
  humidity = sht15.readHumidity();  
}
//-------------------------------------------------------------------------------------------
void printOut()
{
  Serial.print(" Temp = ");
  Serial.print(tempF);
  Serial.print("F, ");
  Serial.print(tempC);
  Serial.println("C");
  Serial.print(" Humidity = ");
  Serial.print(humidity); 
  Serial.println("%");
}
