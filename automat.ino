//biblioteki
#include <LiquidCrystal.h> //biblioteka do wyświetlacza
#include <Stepper.h> //biblioteka do silnika krokowego
//stałe zmienne
#define STEPS 200 //wartość ze wzoru na steps by revolution
#define motorInterfaceType 1 //ma być na 1 bo korzystam ze sterownika do silnika
const int rs, en, d4, d5, d6, d7; //uzupełnić o odpowiednie wartości
LiquidCrystal lcd (rs, en, d4, d5, d6, d7); //info o które piny są podpięte do wyświetlacza
 
//funkcje prototypowe
void powitanie();
void menu();
void silnik();

//dzieje się raz przy uruchomieniu
void setup() {
  lcd.begin(16, 2); //deklaracja, że to wyświetlacz 16x2
  powitanie();
  //czekaj aż będzie pewność, że wszystko działa
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
  Stepper stepper(STEPS, 2, 3); //2 i 3 to piny arduino do których podpięty jest driver
  stepper.setSpeed(1000); //1000 RPM
}