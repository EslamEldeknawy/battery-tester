    void charging()
{
  if (Ni == true)
  {

    if (battr >= 1.49)
    {
      digitalWrite(charge, LOW);
    }
    else if (battr <= 1.4&&battr>=1.3)
    {
      analogWrite(charge, 30);
    }
    else if (battr <= 1.3&&battr>=1.2)
    {
      analogWrite(charge, 40);
    }
    else if (battr <= 1.2&&battr>=1.1)
    {
      analogWrite(charge, 6);
    }
    else if (battr <= 1.1&&battr>=1)
    {
      analogWrite(charge, 4);
    }
    else if (battr <= 1&&battr>=9)
    {
      analogWrite(charge, 2);
    }
    else
    {
      digitalWrite(charge, LOW);

    }
  }


  if (li == true)
  {

    if (battr > 4.2)
    {
      
      digitalWrite(charge, LOW);
    }
    else if (battr >= 4.1&&battr<4.19)
    {
      analogWrite(charge, 20);
    }
    else if (battr >= 3.9&&battr<=4.1)
    {
      analogWrite(charge, 150);
    }
    else if (battr >= 3.7&&battr<=3.9)
    {
      analogWrite(charge, 255);
    }
    else if (battr >= 3.6&&battr<=3.7)
    {
      analogWrite(charge, 100);
    }
    else if (battr >= 2.5&&battr<3.6)
    {
      analogWrite(charge, 80);
    }
    else
    {
      digitalWrite(charge, LOW);
    }
  }









}

