#include <Keypad.h>
#include<LiquidCrystal.h>
#include <Menu.h>
#include <GameController.h>

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

LiquidCrystal screen(rs, en, d4, d5, d6, d7);
Keypad keyPad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

String options[] = {"1.Bulls and Cows", "2.Dinosaur Game"};
int optionsCount = 2;
Menu menu(options, optionsCount, screen, keyPad);


void setup() {
  menu.print();

  GameController controller(menu.getOptions(), menu.getSelectedOption());
  controller.executeSelectedOption();
}

void loop() {
  

}
