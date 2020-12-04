

//--Int converter 4(int) -> "04"(String) 
String getString_2digit(int number) {
  if (number < 10) {
    return "0" + String(number);

  } else {
    return String(number);
  }
}
//--------------------------------


void  Time_screen() {
  bool firstloadScreen = true;
  int sec;
  while (switchscreen() == false) {

    if (sec != second() | firstloadScreen) {
      firstloadScreen = false;
      M5.Lcd.fillRect(0, 17, 160, 63, BLACK);
      sec = second();

      String timedatenow = getString_2digit(hour()) + ":" + getString_2digit(minute()) + ":" + getString_2digit(second());
      M5.Lcd.setCursor(1, 49);
      M5.Lcd.setTextColor(WHITE, BLACK);
      M5.Lcd.setFreeFont(&beta15pt7b);
      M5.Lcd.print(timedatenow);

      timedatenow = getString_2digit(day()) + "/" + getString_2digit(month()) + "/" + String(year());
      M5.Lcd.setCursor(1, 64);
      M5.Lcd.setFreeFont(&beta10pt7b);
      M5.Lcd.print(timedatenow);
    }
  }
}
