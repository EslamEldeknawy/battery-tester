void volt()
{
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(battr, 3);
  lcd.setCursor(5, 0);
  lcd.print("V");
//    lcd.setCursor(7, 0);
//    lcd.print(batti);


}

void amp()
{

  lcd.setCursor(0, 1);
  lcd.print(batta, 3);
  lcd.setCursor(5, 1);
  lcd.print("A");
 
}
void amp_charge()
{

  lcd.setCursor(0, 1);
  lcd.print(battac, 3);
  lcd.setCursor(5, 1);
  lcd.print("A");
 
}

void hold()
{
  if (batta > Max)
  {
    Max = batta;
  }
  lcd.setCursor(7, 0);
  lcd.print(Max, 3);
    lcd.setCursor(11, 0);
    lcd.print("A");
}
void hold_charge()
{
  if (battac > Maxc)
  {
    Maxc = battac;
  }
  lcd.setCursor(7, 0);
  lcd.print(Maxc, 3);
  //  lcd.setCursor(10, 0);
  //  lcd.print("mAh");
}

void bindli() //Li-ion Indicator-------------------------------------------------------------------------------
{

  lcd.setCursor(15, 1);
  if (battr >= 4.2)
  {
    lcd.write(byte(5));
  }
  else if (battr >= 4.1)
  {
    lcd.write(byte(4));
  }
  else if (battr >= 3.9)
  {
    lcd.write(byte(3));
  }
  else if (battr >= 3.7)
  {
    lcd.write(byte(2));
  }
  else if (battr >= 3.6)
  {
    lcd.write(byte(1));
  }
  else if (battr >= 3.5)
  {
    lcd.write(byte(0));
  }
  else
  {
    lcd.write(byte(6));
    
  }
}

void bindNi() //alkaine battery indicator -------------------------------------------------------
{

  lcd.setCursor(15, 1);
  if (battr == 1.5)
  {
    lcd.write(byte(5));
  }
  else if (battr >= 1.4)
  {
    lcd.write(byte(4));
  }
  else if (battr >= 1.3)
  {
    lcd.write(byte(3));
  }
  else if (battr >= 1.2)
  {
    lcd.write(byte(2));
  }
  else if (battr >= 1.1)
  {
    lcd.write(byte(1));
  }
  else if (battr >= 1)
  {
    lcd.write(byte(0));
  }
  else
  {
    lcd.write(byte(6));
    
  }
}
