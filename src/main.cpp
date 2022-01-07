#include <Arduino.h>

#include "AHT20.h"
#include "rgb_lcd.h"

rgb_lcd lcd;

AHT20 AHT; // Temperature and humidity sensor

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.println("AHT20 DEMO");
  AHT.begin();

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop()
{
  // put your main code here, to run repeatedly:

  float humi, temp;

  int ret = AHT.getSensor(&humi, &temp);

  if (ret) // GET DATA OK
  {
    Serial.print("humidity: ");
    Serial.print(humi * 100);
    Serial.print("%\t temperature: ");
    Serial.println(temp);

    // print to LCD
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 0);
    lcd.print("Humi: ");
    lcd.print(humi * 100);
    lcd.print(" %RH");
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" C");
  }
  else // GET DATA FAIL
  {
    Serial.println("GET DATA FROM AHT20 FAIL");
  }

  delay(100);
}
