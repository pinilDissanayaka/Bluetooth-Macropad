void layout1(char key){
  switch (key) {
    case 'a':
      Serial.print(1);
      break;
    case 'b':
      Serial.print(1);
      break;
    case 'd':
      Serial.print(1);
      break;
    case 'e':
      Serial.print(1);
      break;
    case 'g':
      Serial.print(1);
      break;
    case 'h':
      Serial.print(1);
      break;
    case 'i':
      Serial.print(1);
      break;
    case 'j':
      Serial.print(1);
      break;
    case 'k':
      Serial.print(1);
      break;
    case 'l':
      Serial.print(1);
      break;
    case 'm':
      Serial.print(1);
      break;
    case 'n':
      Serial.print(1);
      break;
    case 'o':
      Serial.print(1);
      break;
    case 'p':
      Serial.print(1);
      break;
    case 'q':
      Serial.print(1);
      break;
    default:
      bleKeyboard.releaseAll();
  }
}