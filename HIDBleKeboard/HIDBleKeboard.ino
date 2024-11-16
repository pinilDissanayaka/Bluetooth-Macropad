#include <BleKeyboard.h>
#include <ESP32Encoder.h>

BleKeyboard bleKeyboard;
ESP32Encoder encoder;
int32_t previousEncoderCount;

void setup() {
  Serial.begin(115200);
  encoder.attachHalfQuad(22, 23);
  encoder.setCount(20);
  previousEncoderCount = (int32_t)encoder.getCount();
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    set_volume();
  }
}
