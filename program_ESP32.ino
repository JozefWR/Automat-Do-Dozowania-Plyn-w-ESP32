#include <DFRobot_HX711_I2C.h>
#include <BluetoothSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adres I2C i rozmiar wyświetlacza
DFRobot_HX711_I2C MojaWaga;
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("AutomatDoNapoji"); // Nazwa urządzenia Bluetooth
  lcd.init();                          // Inicjalizacja wyświetlacza
  lcd.backlight();                     // Włączenie podświetlenia
  delay(20000);
  inicjalizujAutomat();
}

void loop() {
  wyslijNaLCD("Wybierz napoj");
  wyslijNaLCD2("Z menu w apce!");
  wyslij("Wybierz napoj z menu:");
  bool restartLoop = false;

  wyswietlMenu();
  int wyborMenu = pobierzWyborMenu();
  if (wyborMenu > 0 && wyborMenu <= 20) {
    if (tarujWage()) {
      if (!przygotujNapojNaPodstawieWyboru(wyborMenu)) {
        restartLoop = true;
      }
    }
  } else {
    wyslij("Nieprawidlowy wybor");
  }

  if (restartLoop) {
    return;
  }

  wyczyscBuforySzeregowe();
}

void inicjalizujAutomat() {
  MojaWaga.begin();
  MojaWaga.setCalibration(2236.f);

  pinMode(15, OUTPUT); // Sok pomarańczowy
  digitalWrite(15, HIGH);
  pinMode(16, OUTPUT); // Sok jabłkowy
  digitalWrite(16, HIGH);
  pinMode(17, OUTPUT); // Sok ananasowy
  digitalWrite(17, HIGH);
  pinMode(18, OUTPUT); // Woda gazowana
  digitalWrite(18, HIGH);
  pinMode(19, OUTPUT); // Mleko
  digitalWrite(19, HIGH);

  pinMode(32, OUTPUT); // Syrop malinowy
  digitalWrite(32, HIGH);
  pinMode(33, OUTPUT); // Cytryna wyciskana
  digitalWrite(33, HIGH);
  pinMode(25, OUTPUT); // Tonik
  digitalWrite(25, HIGH);
  pinMode(26, OUTPUT); // Cola
  digitalWrite(26, HIGH);
  pinMode(27, OUTPUT); // Lemoniada gazowana
  digitalWrite(27, HIGH);
}

void wyslij(String wiadomosc) {
  Serial.println(wiadomosc);
  SerialBT.println(wiadomosc);
}

void wyslijNaLCD(String wiadomosc) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(wiadomosc);
}

void wyslijNaLCD2(String wiadomosc) {
  lcd.setCursor(0, 1);
  lcd.print("                "); // Czyszczenie drugiej linii
  lcd.setCursor(0, 1);
  lcd.print(wiadomosc);
}

void wyswietlMenu() {
  wyslij("1. Orzeźwiający Mix");
  wyslij("2. Jesienna Harmonia");
  wyslij("3. Tropikalna Bryza");
  wyslij("4. Malinowa Rozkosz");
  wyslij("5. Cytrusowy Zing");
  wyslij("6. Klasyczna Cola Mix");
  wyslij("7. Lemoniadowe Orzeźwienie");
  wyslij("8. Klasyczna Cola Mix");
  wyslij("9. Pomarańczowa Fantazja");
  wyslij("10. Ananasowa Fuzja");
  wyslij("11. Lemon & Cola");
  wyslij("12. Słoneczny Koktajl");
  wyslij("12. Mleczny Twist");
  wyslij("13. Lekka Cola");
  wyslij("14. Cytrynowy Chłód");
  wyslij("15. Malinowy Dream");
  wyslij("16. Egzotyczny Mix");
  wyslij("17. Orzeźwiający Cytrus");
  wyslij("18. Lemoniada Plus");
  wyslij("19. Tropikalna Cola");
  wyslij("20. Malinowa Cola");
}

int pobierzWyborMenu() {
  while (!(SerialBT.available() || Serial.available())) {
    delay(10);
  }
  
  if (SerialBT.available()) {
    return SerialBT.parseInt();
  } else if (Serial.available()) {
    return Serial.parseInt();
  }
  
  return -1;
}

bool tarujWage() {
  wyslijNaLCD("Tarowanie...");
  wyslijNaLCD2("Ostroznie!");
  wyslij("Umieść szklankę na wadze i naciśnij 't', aby wytarować...");
  wyslij("Naciśnij 'm', aby anulować i wrócić do menu.");
  char result = czekajNaDaneZTimeoutem(15000, 't', 'm');
  if (result == 't') {
    MojaWaga.peel();
    wyslij("Waga wytarowana.");
    return true;
  } else if (result == 'm') {
    wyslij("Wybór anulowany, powrót do menu.");
    return false;
  } else {
    wyslij("Czas na tarowanie upłynął, powrót do menu.");
    return false;
  }
}

char czekajNaDaneZTimeoutem(unsigned long czasTimeoutu, char oczekiwanyZnak, char znakAnulujacy) {
  unsigned long czasStartu = millis();
  while (millis() - czasStartu < czasTimeoutu) {
    if (Serial.available() || SerialBT.available()) {
      char znak = Serial.available() ? Serial.read() : SerialBT.read();
      if (znak == oczekiwanyZnak || znak == znakAnulujacy) {
        wyczyscBuforySzeregowe();
        return znak;
      }
    }
    delay(10);
  }
  return 'x'; // Gdy czas się skończy, zwracamy 'x' jako sygnał upływu czasu
}

bool przygotujNapojNaPodstawieWyboru(int wybor) {
  switch (wybor) {
    case 1: // Orzeźwiający Mix
      if (!nalejSkladnik("Sok pomaranczowy", 30, 15) || !nalejSkladnik("Woda gazowana", 20, 18) || !nalejSkladnik("Lemoniada gazowana", 10, 27) || !nalejSkladnik("Sok jablkowy", 40, 16)) {
        return false;
      }
      break;
    case 2: // Jesienna Harmonia
      if (!nalejSkladnik("Sok jablkowy", 40, 16) || !nalejSkladnik("Lemoniada gazowana", 30, 27) || !nalejSkladnik("Woda gazowana", 30, 18)) {
        return false;
      }
      break;
    case 3: // Tropikalna Bryza
      if (!nalejSkladnik("Sok ananasowy", 25, 17) || !nalejSkladnik("Sok pomaranczowy", 25, 15) || !nalejSkladnik("Tonik", 50, 25)) {
        return false;
      }
      break;
    case 4: // Malinowa Rozkosz
      if (!nalejSkladnik("Mleko", 50, 19) || !nalejSkladnik("Syrop malinowy", 20, 32) || !nalejSkladnik("Woda gazowana", 30, 18)) {
        return false;
      }
      break;
    case 5: // Cytrusowy Zing
      if (!nalejSkladnik("Sok pomaranczowy", 30, 15) || !nalejSkladnik("Sok cytrynowy", 20, 33) || !nalejSkladnik("Cola", 50, 26)) {
        return false;
      }
      break;
    case 6: // Klasyczna Cola Mix
      if (!nalejSkladnik("Cola", 60, 26) || !nalejSkladnik("Woda gazowana", 40, 18)) {
        return false;
      }
      break;
    case 7: // Lemoniadowe Orzeźwienie
      if (!nalejSkladnik("Lemoniada gazowana", 70, 27) || !nalejSkladnik("Sok jablkowy", 30, 16)) {
        return false;
      }
      break;
    case 8: // Pomarańczowa Fantazja
      if (!nalejSkladnik("Sok pomaranczowy", 50, 15) || !nalejSkladnik("Mleko", 25, 19) || !nalejSkladnik("Lemoniada gazowana", 25, 27)) {
        return false;
      }
      break;
    case 9: // Ananasowa Fuzja
      if (!nalejSkladnik("Sok ananasowy", 30, 17) || !nalejSkladnik("Tonik", 40, 25) || !nalejSkladnik("Lemoniada gazowana", 30, 27)) {
        return false;
      }
      break;
    case 10: // Lemon & Cola
      if (!nalejSkladnik("Cola", 50, 26) || !nalejSkladnik("Sok cytrynowy", 50, 33)) {
        return false;
      }
      break;
    case 11: // Słoneczny Koktajl
      if (!nalejSkladnik("Sok pomaranczowy", 50, 15) || !nalejSkladnik("Sok jablkowy", 25, 16) || !nalejSkladnik("Lemoniada gazowana", 25, 27)) {
        return false;
      }
      break;
    case 12: // Mleczny Twist
      if (!nalejSkladnik("Mleko", 70, 19) || !nalejSkladnik("Cola", 30, 26)) {
        return false;
      }
      break;
    case 13: // Lekka Cola
      if (!nalejSkladnik("Cola", 50, 26) || !nalejSkladnik("Woda gazowana", 50, 18)) {
        return false;
      }
      break;
    case 14: // Cytrynowy Chłód
      if (!nalejSkladnik("Tonik", 50, 25) || !nalejSkladnik("Sok cytrynowy", 25, 33) || !nalejSkladnik("Cola", 25, 26)) {
        return false;
      }
      break;
    case 15: // Malinowy Dream
      if (!nalejSkladnik("Syrop malinowy", 50, 32) || !nalejSkladnik("Mleko", 50, 19)) {
        return false;
      }
      break;
    case 16: // Egzotyczny Mix
      if (!nalejSkladnik("Sok ananasowy", 40, 17) || !nalejSkladnik("Sok pomaranczowy", 30, 15) || !nalejSkladnik("Lemoniada gazowana", 30, 27)) {
        return false;
      }
      break;
    case 17: // Orzeźwiający Cytrus
      if (!nalejSkladnik("Sok pomaranczowy", 40, 15) || !nalejSkladnik("Sok cytrynowy", 30, 33) || !nalejSkladnik("Cola", 30, 26)) {
        return false;
      }
      break;
    case 18: // Lemoniada Plus
      if (!nalejSkladnik("Lemoniada gazowana", 70, 27) || !nalejSkladnik("Sok jablkowy", 30, 16)) {
        return false;
      }
      break;
    case 19: // Tropikalna Cola
      if (!nalejSkladnik("Sok ananasowy", 35, 17) || !nalejSkladnik("Cola", 35, 26) || !nalejSkladnik("Tonik", 30, 25)) {
        return false;
      }
      break;
    case 20: // Malinowa Cola
      if (!nalejSkladnik("Syrop malinowy", 40, 32) || !nalejSkladnik("Cola", 60, 26)) {
        return false;
      }
      break;
    default:
      wyslij("Nieprawidłowy wybór. Spróbuj ponownie.");
      return false;
  }
  wyslij("Twój napój jest gotowy! Odbierz go!");
  wyslijNaLCD("Napoj gotowy!");
  wyslijNaLCD2("Odbierz go!");
  return true;
}

bool nalejSkladnik(String skladnik, int waga, int pin) {
  int startowaWaga = MojaWaga.readWeight();
  int aktualnaWaga;
  digitalWrite(pin, LOW); // Rozpoczęcie nalewania

  wyslijNaLCD(skladnik);
  delay(1000); // Czekaj sekundę, aby wyświetlić nazwę składnika

  do {
    aktualnaWaga = MojaWaga.readWeight();
    if (aktualnaWaga - startowaWaga >= waga) {
      break;
    }

    String komunikatLCD = String(aktualnaWaga - startowaWaga) + " g";
    String komunikatSerial = "Nalano " + skladnik + ": " + komunikatLCD;
    wyslij(komunikatSerial);
    wyslijNaLCD2("Nalano: "+komunikatLCD);

    if (Serial.available() || SerialBT.available()) {
      char znak = Serial.available() ? Serial.read() : SerialBT.read();
      if (znak == 'm') {
        digitalWrite(pin, HIGH); // Zakończenie nalewania
        wyslij("Przerwano, powrót do menu.");
        return false;
      }
    }
    delay(500);
  } while (true);

  digitalWrite(pin, HIGH); // Zakończenie nalewania
  return true;
}

void wyczyscBuforySzeregowe() {
  while (Serial.available() > 0) {
    Serial.read();
  }
  while (SerialBT.available() > 0) {
    SerialBT.read();
  }
}
