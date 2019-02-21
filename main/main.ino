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

LiquidCrystal screen(rs, en, d4, d5, d6, d7);
Keypad keyPad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void printMenu();
void scrollableMenu();

void setup() {
  screen.begin(16,2);
  screen.print("Welcome User!");
  delay(1000);
  printMenu();

}

void loop() {
  

}



void printMenu(){
  String options[] = {"1.Bulls and Cows", "2.Dinosaur Game"};
  screen.clear();
  screen.print("Menu: ");
  screen.setCursor(0,1);
  screen.print("2/8-up/down *-select");
  delay(500);
  
  for(int i = 0;i < 5;i++){
    screen.scrollDisplayLeft();
    delay(500);
  }

  delay(500);
  screen.clear();
  screen.print("Menu:");
  screen.setCursor(0,1);

  scrollableMenu(options);
  
}

void scrollableMenu(String options[]){
  char key = '1';
  
  int optionIndex = 0;
  
  while(key && key != '*'){
    
    screen.clear();
    screen.print("Menu:");
    screen.setCursor(0,1);
    screen.print(options[optionIndex]);

    if(key == '2'){
      optionIndex--;
    }else if(key == '8'){
      optionIndex++;
    }
    
    if(optionIndex > 1 || optionIndex < 0){
      optionIndex = 0;
    }
    key = keyPad.getKey();
    while(!key){
      key = keyPad.getKey();
    }
  }
  screen.clear();
  screen.print("Option: ");
  screen.print(optionIndex + 1);  
  
}
