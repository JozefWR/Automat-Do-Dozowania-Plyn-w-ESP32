# Automat do Dozowania Płynów z Obsługą Zdalną (ESP32_BT)

## Opis projektu

Automat do dozowania płynów z możliwością obsługi zdalnej to zaawansowany projekt inżynierski, który łączy w sobie elektronikę i programowanie do stworzenia zintegrowanego systemu sterowania. Projekt został wykonany na Politechnice Koszalińskiej jako praca dyplomowa.

## Instalacja i konfiguracja

1. Sklonuj to repozytorium na swoje lokalne środowisko.
2. Zapoznaj się z dokumentacją techniczną zawartą w pliku `praca_inzynierska.pdf` dla szczegółów dotyczących budowy i działania urządzenia.
3. Zainstaluj wymagane oprogramowanie i biblioteki, jak opisano w dokumentacji.

## Schematy montażu i testowania

Nazwy elementów, moduły, zdjęcia i schematy montażu oraz testowania znajdują się w pliku `praca_inzynierska.pdf`. Wizualizacje te pomogą w zrozumieniu dokładnego procesu składania urządzenia i jego konfiguracji.

## Programowanie

Programowanie mikrokontrolera ESP32 odbywa się przez Arduino IDE. Kod źródłowy oraz szczegółowe instrukcje znajdują się w folderze i pliku `program_ESP32`.

## Zdjęcia i rysunki

 ![GotowyPrototyp](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/6b82a3e5-8fb9-43f4-ae07-17cd6abe718a) - zdjęcie gotowego prototypu urządzenia.
 ![SchematKomunikacji](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/98823d01-63ec-4637-b4b8-d46273226565)- schemat komunikacji.
 ![SchematPłytkiPCB](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/238f7fb2-c309-472e-9536-75cad8c688bf) - schemat elektroniczny płytki PCB.
 ![PłytkaPCB](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/aa223550-1295-42a3-861d-f1353d052397)- płytka PCB.
 ![SchematBlokowy](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/193d79a3-77b1-46d5-925e-b85749bd6f50) - schemat blokowy działania automatu.
 ![Menu](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/1ad8b6f9-afa7-42f7-b0db-a9129df20a21)
  ![Tarowanie](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/efe83c0e-f424-4523-b27d-a2d8f1781ea5)
  ![Nalewanie](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/ff76bfb1-848b-4e31-8148-5cf0905ada01)
- zrzuty ekranu z aplikacji mobilnej.

## Wykorzystane technologie

Projekt wykorzystuje następujące technologie:
- **Mikrokontroler ESP32**: Serce systemu, odpowiada za sterowanie działaniem urządzenia i komunikację zdalną.
- **Arduino IDE**: Środowisko programistyczne używane do pisania kodu dla mikrokontrolera.
- **Eagle CAD**: Oprogramowanie do projektowania płytek PCB, używane do tworzenia schematów elektronicznych i layoutów PCB.
- **Technologie mobilne**: Aplikacja mobilna umożliwia zdalne sterowanie urządzeniem i monitorowanie jego stanu.
- **Bluetooth**: Komunikacja bezprzewodowa między mikrokontrolerem a aplikacją mobilną.

