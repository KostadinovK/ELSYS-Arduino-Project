#include <Keypad.h>
#include<LiquidCrystal.h>
#include <Menu.h>
#include <GameController.h>
#include <BullsAndCowsGameEngine.h>
#include <DinosaurGameEngine.h>
#include <YourOwnGameEngine.h>

#define ROWS 4
#define COLS 4
#define RS 5
#define EN 4
#define D4 3
#define D5 2
#define D6 A1
#define D7 A0
 
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {13, 12, 11, 10}; 
byte colPins[COLS] = {9, 8, 7};

LiquidCrystal screen(RS, EN, D4, D5, D6, D7);
Keypad keyPad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

GameEngine* bullsAndCows = new BullsAndCowsGameEngine(keyPad, screen);
GameEngine* dinosaurGame = new DinosaurGameEngine(keyPad, screen);
GameEngine* ownEngine = new YourOwnGameEngine(keyPad, screen);

MenuItem options[] = {MenuItem("1.Bulls And Cows", bullsAndCows), MenuItem("2.Dinosaur Game", dinosaurGame), MenuItem("3.Your Own Game", ownEngine)};
int optionsCount = 3;
Menu menu(options, optionsCount, screen, keyPad);


void setup() {
  Serial.begin(9600);
  menu.print();
  GameController controller(keyPad, screen, menu.getOptions(), menu.getSelectedOption());
  controller.executeSelectedOption();
}

void loop() {
  

}
