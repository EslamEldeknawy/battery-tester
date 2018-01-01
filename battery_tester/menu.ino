void menu()
{
  sw1s = digitalRead(sw1);
  sw2s = digitalRead(sw2);
  sw3s = digitalRead(sw3);

  if (sw1s == HIGH ) {

    counter++;
    delay(20);
    if ( counter == 5)
    {
      counter = 1;
    }
  }

  //  if (sw2s == HIGH) {
  //
  //    ok = counter;
  //    delay(200);
  //    counter = 0;
  //
  //  }

  if (sw3s == HIGH) {

    ok = 0;
    counter = 1;
    digitalWrite(discharge, LOW);
    digitalWrite(charge, LOW);

  }
  //================================================================menu button===========================================
  if (counter == 1)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("1-Readings");
    if (sw2s == HIGH) {
      lcd.clear();
      ok = counter;
      delay(300);
      counter = ok;
    }
  }
  if (counter == 2)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("2-Quick Test");
    delay(300);
    if (sw2s == HIGH) {
      lcd.clear();
      ok = counter;
      delay(300);
      counter = ok;
    }
  }
  if (counter == 3)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("3-Charge");
    delay(300);
    if (sw2s == HIGH) {
      lcd.clear();
      ok = counter;
      delay(300);
      counter = ok;
    }
  }
  if (counter == 4)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("4-Discharge");
    delay(100);
    if (sw2s == HIGH) {
      lcd.clear();
      ok = counter;
      delay(300);
      counter = ok;
    }
  }

  //===========================================================
  if (ok == 1)
  {

    counter = 0;
    if (battr >= 2.5 && battr <= 4.2)
    {
      volt();
      amp();
      bindli();

    }
    else if (battr >= 1 && battr <= 1.5)
    {
      volt();
      amp();
      bindNi();
    }
    else if (battr <= 1)
    {

      lcd.setCursor(15, 1);
      lcd.write(byte( 6));
      lcd.setCursor(0, 0);
      volt();
      amp();


    }
  }

  if (ok == 2)
  {
    counter = 0;
    volt();
    amp();
    hold();
    bindNi();
    bindli();
    button();
    if (state == HIGH)
    {
      digitalWrite(discharge, state);

      stopwatch();
    }
    else
      digitalWrite(discharge, state);


  }

  if (ok == 3)
  {
    counter = 0;
    volt();
    amp_charge();
    hold_charge();
    bindNi();
    bindli();
    button();
    if (state == HIGH)
    {
      if (Ni==true||li==true)
      {
        charging();
      }
    }
    else if (state == HIGH||battr>=4.2)
     {
      digitalWrite(charge,LOW);
     }


  }

 if (ok == 4)
  {
    counter = 0;
    volt();
    amp_charge();
    hold_charge();
    bindNi();
    bindli();
    button();
    if (state == HIGH)
    {
      if (Ni==true||li==true)
      {
        charging();
      }
    }
    else if (state == HIGH||battr>=4.2)
     {
      digitalWrite(charge,LOW);
     }


  }



  //==========================================================
}

