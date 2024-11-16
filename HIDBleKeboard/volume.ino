void set_volume(){
  if (previousEncoderCount < (int32_t)encoder.getCount()) {
    bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
    previousEncoderCount = (int32_t)encoder.getCount();
  }

  if (previousEncoderCount > (int32_t)encoder.getCount()) {
    bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
    previousEncoderCount = (int32_t)encoder.getCount();
  }
  delay(100);
  bleKeyboard.releaseAll();
}