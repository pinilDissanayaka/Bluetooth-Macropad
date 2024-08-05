#include <BleKeyboard.h>
#include <Keypad.h>
#include <Wire.h>
#include <Encoder.h>
#include <Bounce2.h>
#include <Pangodream_18650_CL.h>

//Encoder
int SW = 19;
int DT = 0;
int CLK = 1;
Encoder volumeKnob(DT,CLK);
Bounce encoderButton = Bounce(SW,10);
int timeLimit = 500;
long oldPosition = -999;


int batteryLevel = 100;
//#define ADC_PIN 34
//#define CONV_FACTOR 1.7
//#define READS 20

const byte ROWS = 4; 
const byte COLS = 4; 
const int numStates = 4;
int currentState = 0;

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
  pinMode(CLK, INPUT_PULLUP);
  //Consumer.begin();
  bleKeyboard.begin();
}


void loop() {

  if (bleKeyboard.isConnected()) {
    char customKey = customKeypad.getKey();

    checkEncoder();

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

void changeStateUp(){
  currentState++;
  if (currentState == numStates){
    currentState = 0;
  }
  //Serial.print("State Changed. Current State: "); 
  //Serial.println(currentState);
  delay(100);
  return;
}

void changeStateDown(){
  currentState--;
  if (currentState == 0){
    currentState = numStates;
  }
 
  //Serial.print("State Changed. Current State: "); 
  //Serial.println(currentState);
  delay(100);
  return;
}

void checkEncoder(){
  //check encoder rotation
  long newPosition = volumeKnob.read();
  if(newPosition != oldPosition){
    Serial.print(newPosition);

    if((newPosition - oldPosition) > 0) {
      //volumeup
      Serial.println("volume up");
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
    } else {
      //volumedown
      Serial.println("volume down");
      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
    }
    oldPosition = newPosition;
    bleKeyboard.releaseAll();
    delay(200); //a delay of 200 seems to be the sweet spot for this encoder.
  }
}

