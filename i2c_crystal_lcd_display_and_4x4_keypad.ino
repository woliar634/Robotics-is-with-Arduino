#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

//----------------------------LCD Display-------------------------
const int LCD_ADDRESS=0X27;
const int LCD_COLUMNS=16;
const int LCD_ROWS=2;
LiquidCrystal_I2C lcd(LCD_ADDRESS,LCD_COLUMNS,LCD_ROWS);

//-----------------------------keypad-----------------------------
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the key map (what each key represents)
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connect keypad ROW0, ROW1, ROW2, ROW3 to these Arduino pins
byte rowPins[ROWS] = {13,12,11,10};

// Connect keypad COL0, COL1, COL2, COL3 to these Arduino pins
byte colPins[COLS] = {9, 8, 7, 6};

// Create the keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight(); 
}
void loop()
{
  char key=keypad.getKey();
  if(key){
  lcd.setCursor(0,0);
  lcd.print(key);
  delay(500);
  Serial.println(key);
  }
}