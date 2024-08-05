#include <BleKeyboard.h>
#include <Keypad.h>
#include <Pangodream_18650_CL.h>

int batteryLevel = 100;

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

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); 
BleKeyboard bleKeyboard("Macropad", "Espressif", batteryLevel);
Pangodream_18650_CL BL;
//Pangodream_18650_CL BL(ADC_PIN, CONV_FACTOR, READS);

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

void getBatteryLevel(){
  Serial.print("Value from pin: ");
  Serial.println(analogRead(34));
  Serial.print("Average value from pin: ");
  Serial.println(BL.pinRead());
  Serial.print("Volts: ");
  Serial.println(BL.getBatteryVolts());
  Serial.print("Charge level: ");
  batteryLevel = BL.getBatteryChargeLevel();
  Serial.println(batteryLevel);
  Serial.println("");
  delay(1000);
}

