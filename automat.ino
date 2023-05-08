//pomysły:
//po wyświetleniu menu() w aplikacji powinno móc się wybrać napój, wtedy odpalić funkcje int wybor() której wynik będzie przekazywany do silnika, aby poruszył się w //odpowiednie miejsce 

//biblioteki
#include <LiquidCrystal.h> //biblioteka do wyświetlacza
#include <AccelStepper.h> //biblioteka do silnika krokowego
//stałe zmienne
#define motorInterfaceType 8
AccelStepper silnik(motorInterfaceType,) //w nawiasie wpisac piny
const int rs, en, d4, d5, d6, d7; //piny ekranu lcd
const int button1, button2 //piny przycisków
LiquidCrystal lcd (rs, en, d4, d5, d6, d7); //info o które piny są podpięte do wyświetlacza
 
//funkcje prototypowe
void powitanie();
void menu();
void silnik();
void wykrywanie_objetosci();
bool wykrywanie_szklanki();

//dzieje się raz przy uruchomieniu
void setup() {
  lcd.begin(16, 2); //deklaracja, że to wyświetlacz 16x2
  powitanie();
  /*if (wykrywanie_szklanki() == true){  //czekaj aż będzie pewność, że wszystko działa
 
  }
  else
  */
}
 
 //dzieje się cały czas
void loop() {
  menu();
  silnik();
}

void powitanie() {
  lcd.clear(); 
  lcd.setCursor(0, 0);
  lcd.print("Zapraszamy!")
}

void menu(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dostepne napoje")
  delay(5000); //5 sekund
  lcd.clear();
  lcd.print("wisnia, jablko");
  lcd.setCursor(0, 1);
  lcd.print("truskawka");
}

void silnik(){
  silnik.setMaxSpeed(1000); //1000 RPM
  //na razie zrobione na przycisk, ale przerobić aby działało na input z aplikacji
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  if( (digitalRead(button1) == HIGH) && (digitalRead(button2) == LOW) ){ //przycisk 1 włączony, przycisk 2 wyłączony
    silnik.setSpeed(100); //clockwise
    silnik.runSpeed();
  }
  else if( (digitalRead(button2) == HIGH) && (digitalRead(button2) == LOW) ){ //przycisk 2 włączony, przycisk 1 wyłączony
    silnik.setSpeed(-100); //counter clockwise
    silnik.runSpeed();
  }
}

void wykrywanie_objetosci(){ //opcjonalne
 ;
}

bool wykrywanie_szklanki(){
  bool wykryta = false;
  /*if (wykryta == true)
      return true;
    else
      return false;
  */
}
