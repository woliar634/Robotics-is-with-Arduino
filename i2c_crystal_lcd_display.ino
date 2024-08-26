#include <LiquidCrystal_I2C.h>
const int LCD_ADDRESS=0X27;
const int LCD_COLUMNS=16;
const int LCD_ROWS=2;
LiquidCrystal_I2C lcd(LCD_ADDRESS,LCD_COLUMNS,LCD_ROWS);

void setup()
{
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("Hello ");
  lcd.setCursor(5,1);
  lcd.print("World! ");
}
void loop()
{
}