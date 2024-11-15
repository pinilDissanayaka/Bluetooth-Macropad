void rotary_onButtonClick()
{
    static unsigned long lastTimePressed = 0; // Soft debouncing
    if (millis() - lastTimePressed < 500)
    {
            return;
    }
    lastTimePressed = millis();
    Serial.print("button pressed ");
    Serial.print(millis());
    Serial.println(" milliseconds after restart");
}

void rotary_loop()
{
    if (rotaryEncoder.encoderChanged())
    {
      new_state=rotaryEncoder.readEncoder();
      Serial.print("Value: ");
      Serial.println(new_state);

      


      if(new_state != pre_state){
        if (pre_state < new_state){
          set_volume_up();
        }
        else if (pre_state > new_state){
          set_volume_down();
        }
          pre_state = new_state;
      }
    }
    
    if (rotaryEncoder.isEncoderButtonClicked())
    {
      rotary_onButtonClick();
    }
}

void IRAM_ATTR readEncoderISR()
{
    rotaryEncoder.readEncoder_ISR();
}

