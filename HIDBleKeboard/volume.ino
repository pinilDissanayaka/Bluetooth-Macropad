void set_volume_up(){
    Serial.println("Sending Vol UP media key...");
    bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
    delay(1000);
    bleKeyboard.releaseAll();
}

void set_volume_down(){
  Serial.println("Sending Vol DOWN media key...");
  bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
  delay(1000);
  bleKeyboard.releaseAll();
}