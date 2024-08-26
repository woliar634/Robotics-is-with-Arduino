#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

//----------------------------LCD Display--------------------------------
const int LCD_ADDRESS=0X27;
const int LCD_COLUMNS=16;
const int LCD_ROWS=2;
LiquidCrystal_I2C lcd(LCD_ADDRESS,LCD_COLUMNS,LCD_ROWS);

//-----------------------------keypad------------------------------------
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

// ------------------keypad object---------------------------------------
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//--------------------password-------------------------------------------
String input_pass="";
String system_pass="1234";
int pass_len=4;

//--------------------LOCK-----------------------------------------------
int relay=3;
void setup()
{
  //Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight(); 
}
void loop()
{
 pinMode(relay,OUTPUT);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Enter Your Pass:");
 int i=0;
 while(1){
   char key=keypad.getKey();
   if(key){
   	if(input_pass.length()<pass_len){
      input_pass=input_pass+key;
      lcd.setCursor(i+5,1);
      lcd.print(key);
      i++;
      if(input_pass.length()==pass_len){
      	if(input_pass==system_pass){
        	lcd.clear();
        	lcd.setCursor(0,0);
        	lcd.print("Door Unlocked!");
          	digitalWrite(relay,HIGH);
            delay(5000);
            lcd.clear();
  			lcd.setCursor(0,0);
  			lcd.print("Door gets locked again!");
          	delay(1500);
          	digitalWrite(relay,LOW);
            input_pass="";//Reset password
           break;
        }
        else{
            lcd.clear();
        	lcd.setCursor(0,0);
        	lcd.print("PASS DONT MATCH ");
            delay(1000);
            lcd.clear();
            lcd.setCursor(3,0);
            lcd.print("TRY AGAIN");
            input_pass="";//Reset password
            delay(1000);
           break;
        } 
      }
    }
  }
 } 
}