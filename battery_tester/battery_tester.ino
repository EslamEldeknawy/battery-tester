#include <Time.h>
#include <TimeLib.h>

/*Battery tester ver 0.1  30/11/2017 11:22AM By Eslam Eldeknawy   -  Eslam's Lab youtube Channel
   this battery tester designed fir Li-ion 3.7v and alkalin,ni-mh , ni-cd batteries
   the testing amps shouldn't ecxeeds 5 amps
   and the input voltage not more than 50 volts
   the current measure circuit 1ohm 3W to the GND and the other end to A1 also A1 works as GND output so don't connect anything you want to measure it's current to the GND Directly
   another 1ohm 3W resistor connected to the A0 as load and the other end connected to mosfet source pin
   the battery+ connected to A1 via voltage divider  and also connected to mosfet Drain pin
   mosfet gate connected to arduino pin D8 via Diode
   arduino pin 2 connected to the ground via 10K 1/4W res and the switch connected to V+ from arduino

*/



#include <LiquidCrystalISP.h>

//==========================TIME VARIABLES========================================
unsigned long seconds = millis();
//==========================TIME=========================================
//------------------------------------------------BUTTONS----------------------------------------------------
int sw1 = 2;         // the number of the input pin
int sw2 = 3;
int sw3 = 4;
int counter = 0;
int ok = 0;
int sw1s = 0;
int sw2s = 0;
int sw3s = 0;

int discharge = 5;       // the number of the output pin
int charge = 6;
int state = LOW;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers
//------------------------------------END OF BUTTONS--------------------------------------------------------

//battery type
bool Ni ;
bool li ;

//------------------- VOLT READING ----------------------------------------------------
int batt = A1;
float battv = 0;
float battr = 0;
float R1 = 97900;
float R2 = 9740;

float vmax = 0;
float vmin = 1024;
float vavg = 0;
//------------------- AMP READING -----------------------------------------------------
int battc = A0;
float batti = 0;
float batta = 0;
float Max = 0;
//----------------------- amp charging----------------------------------------------------
int battch = A2;
float battic = 0;
float battac = 0;
float Maxc = 0;
//------------------- BATTERY LEVEL SYMBOL -----------------------------------------------------------------------
byte bat0[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
};
byte bat20[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111
};
byte bat40[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111,
  B11111
};
byte bat60[8] = {
  B01110,
  B11011,
  B10001,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111
};
byte bat80[8] = {
  B01110,
  B11011,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111

};
byte bat90[8] = {
  B01110,
  B11011,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte bat100[8] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte batx[8] = {
  B01110,
  B11011,
  B10101,
  B10101,
  B10101,
  B10001,
  B10101,
  B11111
};
// ------------------------------------------------- END OF BATTERY LEVEL SYMBOL --------------------------------------------------------------
LiquidCrystal lcd(9); // LCD CONNECTED VIA 74HC595
void setup() {
  lcd.begin(16, 2);
  lcd.print("Battery Tester ");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("By Eslam's Lab");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press");
  lcd.setCursor(0, 1);
  lcd.print("any key...");


  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(discharge, OUTPUT);
  pinMode(charge, OUTPUT);


  Serial.begin(9600);

  lcd.createChar(0, bat0);
  lcd.createChar(1, bat20);
  lcd.createChar(2, bat60);
  lcd.createChar(3, bat80);
  lcd.createChar(4, bat90);
  lcd.createChar(5, bat100);
  lcd.createChar(6, batx);
}



void loop() {


  battv = analogRead(batt);
  battr = ((battv) * (R2 / (R1 + R2)) / 1.65  );
if (battr>vmax)
{
  vmax = battr;
  
}
if(battr<vmin)
  {
    vmin = battr;
    if (vmin<battr)
    vmin=battr;
  }
  vavg=(vmax+vmin)/2;

  batti = analogRead(battc);
  batta = (batti * 0.03166666666666666666666666666667); //this multiplyer works well for me with 1 ohm res

  battic = analogRead(battch);
  battac = (battic * 0.03166666666666666666666666666667); //this multiplyer works well for me with 1 ohm res



  //  if (battr >= 2.5 && battr <= 4.2)
  //  {
  //    volt();
  //    amp();
  //    hold();
  //    bindli();
  //
  //  }
  //  else if (battr >= 1 && battr <= 1.5)
  //  {
  //    volt();
  //    amp();
  //    hold();
  //    bindNi();
  //  }
  //  else if (battr <= 1)
  //  {
  //    //    lcd.clear();
  //    lcd.setCursor(15, 1);
  //    lcd.write(byte( 6));
  //    lcd.setCursor(0, 0);
  //    volt();
  //    amp();
  //    hold();
  //
  //  }

  //  button();
  menu();
  lcd.setCursor(14, 1);
  lcd.print(li);
  lcd.setCursor(13, 1);
  lcd.print(Ni);

  if (battr >= 2.5 && battr <= 4.19)
  {
    li = true;
    lcd.setCursor(14, 0);
    lcd.print("Li");
  }
  else
  {
    li = false;
  }
  if (battr >= 0.9 && battr < 1.49)
  {
    Ni = true;
    lcd.setCursor(14, 0);
    lcd.print("Ni");
  }
  else
  {
    Ni = false;
  }








}
