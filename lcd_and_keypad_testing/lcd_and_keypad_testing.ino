#include <Keypad.h>
#include<LiquidCrystal.h>


const byte ROWS = 4; 
const byte COLS = 3;
const int rs = 5, en = 4, d4 = 3, d5 = 2, d6 = 1, d7 = 0;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {13, 12, 11, 10}; 
byte colPins[COLS] = {9, 8, 7};

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Elapsed seconds: ");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  
  char customKey = customKeypad.getKey();
  
  if (customKey){
    lcd.print(customKey);
  }

}
