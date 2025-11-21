#include <Keypad.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4;
const byte COLS = 4;
byte indexPlus;
byte indexMulti;
byte indexDiv;
byte indexSub;
String input;
String input1;
String input2;
char hexaKeys[ROWS][COLS] = {
  { '7', '8', '9', '/' },
  { '4', '5', '6', '*' },
  { '1', '2', '3', '-' },
  { 'o', '0', '=', '+' }
};
byte rowPins[ROWS] = { 17, 18, 19, 20 };  //connect to the row pinouts of the keypad
byte colPins[COLS] = { 22, 23, 24, 25 };  //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}
void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {

    if (customKey == 'o') {
      lcd.clear();
      input = "";
      lcd.setCursor(0, 0);
      return;
    }

    if (customKey != '=') {
      input += customKey;
    }

    lcd.setCursor(0, 0);
    lcd.print(input);


    if (customKey == '=') {

      int indexPlus = input.indexOf('+', 1);
      int indexMulti = input.indexOf('*', 1);
      int indexDiv = input.indexOf('/', 1);
      int indexSub = input.indexOf('-', 1);
      bool calculation = false;
      bool error = false;
      long result = 0;
      long number1 = 0;
      long number2 = 0;

      lcd.setCursor(0, 1);

      if (indexPlus != -1) {
        input1 = input.substring(0, indexPlus);
        input2 = input.substring(indexPlus + 1);
        number1 = input1.toInt();
        number2 = input2.toInt();
        result = number1 + number2;
        calculation = true;
      } else if (indexMulti != -1) {
        input1 = input.substring(0, indexMulti);
        input2 = input.substring(indexMulti + 1);
        number1 = input1.toInt();
        number2 = input2.toInt();
        result = number1 * number2;
        calculation = true;
      } else if (indexDiv != -1) {
        input1 = input.substring(0, indexDiv);
        input2 = input.substring(indexDiv + 1);
        number1 = input1.toInt();
        number2 = input2.toInt();

        if (number2 == 0) {
          error = true;
        } else {
          result = number1 / number2;
          calculation = true;
        }
      } else if (indexSub != -1) {
        input1 = input.substring(0, indexSub);
        input2 = input.substring(indexSub + 1);
        number1 = input1.toInt();
        number2 = input2.toInt();
        result = number1 - number2;
        calculation = true;
      }

      if (error) {
        lcd.print("inf");
        input = "";
      } else if (calculation) {
        lcd.print(result);
        input = String(result);
      } else {
        lcd.print(input);
      }
    }
  }
}
