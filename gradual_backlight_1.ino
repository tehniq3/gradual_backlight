// program scris de niq_ro & GeoMar, 7.2017
// ver.1 - buton care aprinde fundal afisaj si il stinge dupa un timp, progresiv

#define BUT3 7     // buton
#define fundal 9   // led de fundal

int inceput = 0;  // timpul in secunde cand s-a apasat butonul
int actual = 0;   // timpul actual in secunde
int ultimaapasare;  // se memoreaza timpul cand se apasa ultima dat abutonul
int timplumina = 7; // timp cant ramane fundalul aprins
byte fundalminim = 15;
byte fundalmaxim = 255;
byte nivelfundal = 15;
byte treaptanivel = 5;  // treapta scadere iluminare de la maxim la minim
byte apasat = 1;  // consideram butonul neapasat

void setup() {

Serial.begin(9600);
pinMode(BUT3, INPUT);
digitalWrite(BUT3, HIGH);

analogWrite(fundal, nivelfundal);  // se aprinde lumina de fundal la minim

inceput = millis()/1000;  // memoram timpul cand incepe sa ruleze programul (in secunde)
Serial.print("inceput = ");
Serial.println(inceput);
} // sfarsit program ce ruleaza la inceput si dupa resetare

void loop() {

 Serial.println(nivelfundal);

apasat = digitalRead(BUT3);  // verificam starea butonului

  if (apasat == 0)  // daca e apasat
    {
      nivelfundal = fundalmaxim;
      analogWrite(fundal, nivelfundal);  // se aprinde la maxim fundalul
      Serial.println("S-a apasat butonul .....");
      delay(50);     
      apasat = 1;  // consideram butonul neapasat
      ultimaapasare = millis()/1000;  // se memoreaza timpul cand s-a apasat ultima data butonul
    }

actual = millis()/1000;

if ((actual - ultimaapasare > timplumina) &&  (nivelfundal > fundalminim))  // daca a trecut timpul de aprindere lumina fundal la maxim si nu s-a stins la minim
{
  nivelfundal = nivelfundal - treaptanivel;   // nivel aprindere in scadere
  if (nivelfundal < fundalminim) nivelfundal = fundalminim; // nu trebuie sa scada valaorea sub minim
  analogWrite(fundal, nivelfundal);
  Serial.println(nivelfundal);
}

delay(100);
} // sfarsit program ce ruleaza incontinuu
