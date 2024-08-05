#include <BleKeyboard.h>
#include <Keypad.h>

BleKeyboard bleKeyboard("Macropad");

const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'a', 'b', 'c', 'd'},
  {'e', 'f', 'g', 'h'},
  {'i', 'k', 'l', 'm'},
  {'n', 'o', 'p', 'q'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {

  if (bleKeyboard.isConnected()) {
    char customKey = customKeypad.getKey();

    bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
    delay(2000);

    
  }
}
