#include <AccelStepper.h>
#include <LiquidCrystal_I2C.h>  // dołączenie pobranej biblioteki I2C dla LCD

//przypisanie pinów digital (A0 - analog 0)
#define krancowka A0
#define odleglosc 200
#define predkosc 400
#define prawo 1
#define lewo -1
#define przycisk_wyboru_gora 4
#define przycisk_wyboru_dol 2
#define przycisk_potwierdzenia 3
#define pompa1 5
#define pompa2 6
#define pompa3 7
#define pompa4 8

enum soki {
  jablko,
  gruszka,
  pomarancza,
  limonka
};

soki opcje = jablko;

AccelStepper stepper(AccelStepper::FULL4WIRE, 9, 10, 11, 12); //tworzenie instancji silnika 4 kabelkowego na pinach 9-12)
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27

void setup() {
  pinMode(krancowka, INPUT_PULLUP);
  pinMode(przycisk_wyboru_gora, INPUT_PULLUP);
  pinMode(przycisk_wyboru_dol, INPUT_PULLUP);
  pinMode(przycisk_potwierdzenia, INPUT_PULLUP);
  stepper.setMaxSpeed(1000);     // maksymalna prędkosć
  stepper.setAcceleration(500);  // maksymalne przyspieszenie
  lcd.begin(16, 2);  // Inicjalizacja LCD 2x16
  lcd.backlight();   // załączenie podświetlania
  pinMode(pompa1, OUTPUT);
  digitalWrite(pompa1, LOW);
  pinMode(pompa2, OUTPUT);
  digitalWrite(pompa2, LOW);
  pinMode(pompa3, OUTPUT);
  digitalWrite(pompa3, LOW);
  pinMode(pompa4, OUTPUT);
  digitalWrite(pompa4, LOW);
}

void loop() {
  unsigned long startTime1 = millis();  // Dostęp do aktualnego czasu w milisekundach

  switch (opcje) {
    case jablko:
      lcd.setCursor(0, 0);  // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
      lcd.print("Wybierz sok");
      lcd.setCursor(0, 1);
      lcd.print("Jablkowy");
      if (digitalRead(przycisk_wyboru_gora) == LOW) {
        delay(200);
        opcje = gruszka;  //Powrót do ostatniej opcji
        lcd.clear();
      }
      if (digitalRead(przycisk_wyboru_dol) == LOW) {
        delay(200);
        opcje = limonka;  //Powrót do ostatniej opcji
        lcd.clear();
      }
      if (digitalRead(przycisk_potwierdzenia) == LOW) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Przemieszczam");
        lcd.setCursor(0, 1);
        lcd.print("szklanke");

        //ruszanie szklanką
        while (millis() - startTime1 < 1000) {
          stepper.setSpeed(lewo * predkosc);
          stepper.runSpeed();
        }
        //lanie wody
        lanie_wody(opcje);
        delay(2000);
        zatrzymanie();

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Nalewam sok");

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sok nalany");
      }
      break;

    case gruszka:
      lcd.setCursor(0, 0);  // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
      lcd.print("Wybierz sok");
      lcd.setCursor(0, 1);
      lcd.print("Gruszkowy");
      if (digitalRead(przycisk_wyboru_gora) == LOW) {
        delay(200);
        opcje = pomarancza;  //Powrót do ostatniej opcji
        lcd.clear();
      }
      if (digitalRead(przycisk_wyboru_dol) == LOW) {
        delay(200);
        opcje = jablko;  //Powrót do ostatniej opcji
        lcd.clear();
      }
      if (digitalRead(przycisk_potwierdzenia) == LOW) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Przemieszczam");
        lcd.setCursor(0, 1);
        lcd.print("szklanke");

        //ruszanie szklanką
        while (millis() - startTime1 < 4100) {
          stepper.setSpeed(lewo * predkosc);
          stepper.runSpeed();
        }
        //lanie wody
        lanie_wody(opcje);
        delay(2000);
        zatrzymanie();
       
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sok nalany");
        
      }
      break;

    case pomarancza:
      lcd.setCursor(0, 0);  // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
      lcd.print("Wybierz sok");
      lcd.setCursor(0, 1);
      lcd.print("Pomaranczowy");
      if (digitalRead(przycisk_wyboru_gora) == LOW) {
        delay(200);
        opcje = limonka;  //Powrót do ostatniej opcji
        lcd.clear();
      }
      if (digitalRead(przycisk_wyboru_dol) == LOW) {
        delay(200);
        opcje = gruszka;  //Powrót do ostatniej opcji
        lcd.clear();
      }
      if (digitalRead(przycisk_potwierdzenia) == LOW) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Przemieszczam");
        lcd.setCursor(0, 1);
        lcd.print("szklanke");

        //ruszanie szklanką
        while (millis() - startTime1 < 6900) {
          stepper.setSpeed(lewo * predkosc);
          stepper.runSpeed();
        }
        //lanie wody
        lanie_wody(opcje);
        delay(2000);
        zatrzymanie();

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sok nalany");
      }
      break;

    case limonka:
      lcd.setCursor(0, 0);  // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
      lcd.print("Wybierz sok");
      lcd.setCursor(0, 1);
      lcd.print("Limonkowy");
      if (digitalRead(przycisk_wyboru_gora) == LOW) {
        delay(200);
        opcje = jablko;  //Powrót do pierwszej opcji
        lcd.clear();
      }
      if (digitalRead(przycisk_wyboru_dol) == LOW) {
        delay(200);
        opcje = pomarancza;  //Powrót do ostatniej opcji
        lcd.clear();
      }
      if (digitalRead(przycisk_potwierdzenia) == LOW) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Przemieszczam");
        lcd.setCursor(0, 1);
        lcd.print("szklanke");

        //ruszanie szklanką
        while (millis() - startTime1 < 9800) {
          stepper.setSpeed(lewo * predkosc);
          stepper.runSpeed();
        }
        //lanie wody
        lanie_wody(opcje);
        delay(2000);
        zatrzymanie();

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sok nalany");
      }
      break;
  }
}

void zatrzymanie() {
  do {
      stepper.setSpeed(prawo * predkosc);
      stepper.runSpeed();
    } while (digitalRead(krancowka) != LOW); //obracaj się w lewo (do początku platformy), aż nie dotknie krańcówki
}

void lanie_wody(soki wybor) {
//stepper.disableOutputs() i stepper.enableOutputs() wyłącza i włącza piny na których jest silnik, jest to potrzebne bo bez tego za mało mocy jest na lanie wody
  switch(wybor){ 
    case 0:
      stepper.disableOutputs();
      digitalWrite(pompa1, HIGH); //Włączenie pompy 1
      delay(4000); //Leje się 4 sekundy
      digitalWrite(pompa1, LOW); //Wyłączenie pompy 1
      stepper.enableOutputs();
    break;
    case 1:
      stepper.disableOutputs();
      digitalWrite(pompa2, HIGH); //Włączenie pompy 2 
      delay(4000); //Leje się 4 sekundy
      digitalWrite(pompa2, LOW); //Wyłączenie pompy 2
      stepper.enableOutputs();
    break;
    case 2:
      stepper.disableOutputs();
      digitalWrite(pompa3, HIGH); //Włączenie pompy 3
      delay(4000); //Leje się 4 sekundy
      digitalWrite(pompa3, LOW); //Wyłączenie pompy 3
      stepper.enableOutputs();
    break;
    case 3:
      stepper.disableOutputs();
      digitalWrite(pompa4, HIGH); //Włączenie pompy 4 
      delay(4000); //Leje się 4 sekundy
      digitalWrite(pompa4, LOW); //Wyłączenie pompy 4
      stepper.enableOutputs();
    break;
  } 
}
